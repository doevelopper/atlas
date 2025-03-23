

#!/usr/bin/env python3
"""
Git Information Extractor for C++ Projects

This script extracts Git repository information and generates a C++ header file
with preprocessor definitions that can be included in your project.

Example
    python git_info_extractor.py --output version_info.h --namespace ProjectVersion
    --output or -o: Specify the output header file name (default: "git_info.h")
    --namespace or -n: Specify the C++ namespace (default: "GitInfo")

Integration
    #include "git_info.h"

    void printVersionInfo() {
        std::cout << "Version: " << GitInfo::COMMIT_HASH_SHORT << std::endl;
        std::cout << "Branch: " << GitInfo::BRANCH << std::endl;
        std::cout << "Build date: " << GitInfo::COMMIT_DATE << std::endl;
    }
"""

import os
import subprocess
import datetime
import argparse
import re


def run_git_command(command):
    """Execute a git command and return its output."""
    try:
        result = subprocess.run(
            command,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=True
        )
        return result.stdout.strip()
    except subprocess.CalledProcessError as e:
        print(f"Warning: Git command failed: {' '.join(command)}")
        print(f"Error: {e.stderr.strip()}")
        return ""


def get_git_info():
    """Collect comprehensive information about the Git repository."""
    git_info = {}

    # Check if we're in a git repository
    if not os.path.exists(".git"):
        print("Warning: Not a git repository or not in the root directory.")
        return git_info

    # Basic repository information
    git_info["BRANCH"] = run_git_command(["git", "rev-parse", "--abbrev-ref", "HEAD"])
    git_info["COMMIT_HASH"] = run_git_command(["git", "rev-parse", "HEAD"])
    git_info["COMMIT_HASH_SHORT"] = run_git_command(["git", "rev-parse", "--short", "HEAD"])
    git_info["COMMIT_TIMESTAMP"] = run_git_command(["git", "show", "-s", "--format=%ct", "HEAD"])

    # If we have a timestamp, convert it to ISO format
    if git_info["COMMIT_TIMESTAMP"]:
        try:
            timestamp = int(git_info["COMMIT_TIMESTAMP"])
            git_info["COMMIT_DATE"] = datetime.datetime.fromtimestamp(timestamp).strftime("%Y-%m-%d")
            git_info["COMMIT_TIME"] = datetime.datetime.fromtimestamp(timestamp).strftime("%H:%M:%S")
        except ValueError:
            git_info["COMMIT_DATE"] = ""
            git_info["COMMIT_TIME"] = ""

    # Additional commit information
    git_info["COMMIT_SUBJECT"] = run_git_command(["git", "show", "-s", "--format=%s", "HEAD"])
    git_info["COMMIT_BODY"] = run_git_command(["git", "show", "-s", "--format=%b", "HEAD"])
    git_info["AUTHOR_NAME"] = run_git_command(["git", "show", "-s", "--format=%an", "HEAD"])
    git_info["AUTHOR_EMAIL"] = run_git_command(["git", "show", "-s", "--format=%ae", "HEAD"])
    git_info["COMMITTER_NAME"] = run_git_command(["git", "show", "-s", "--format=%cn", "HEAD"])
    git_info["COMMITTER_EMAIL"] = run_git_command(["git", "show", "-s", "--format=%ce", "HEAD"])

    # Repository information
    git_info["REPO_URL"] = run_git_command(["git", "config", "--get", "remote.origin.url"])

    # Sanitize URL to handle potential SSH format
    if git_info["REPO_URL"]:
        # Convert SSH URL to HTTPS format for consistency
        ssh_pattern = r"git@([^:]+):(.+)\.git"
        match = re.match(ssh_pattern, git_info["REPO_URL"])
        if match:
            host, path = match.groups()
            git_info["REPO_URL"] = f"https://{host}/{path}"

        # Extract repository name
        git_info["REPO_NAME"] = os.path.basename(git_info["REPO_URL"].rstrip(".git"))

    # Tag information
    git_info["LATEST_TAG"] = run_git_command(["git", "describe", "--tags", "--abbrev=0"])

    # Status information - detect if working directory is clean
    status_output = run_git_command(["git", "status", "--porcelain"])
    git_info["IS_CLEAN"] = "true" if not status_output else "false"

    # Count commits
    git_info["COMMIT_COUNT"] = run_git_command(["git", "rev-list", "--count", "HEAD"])

    # Check if we're in a detached HEAD state
    head_ref = run_git_command(["git", "symbolic-ref", "-q", "HEAD"])
    git_info["IS_DETACHED"] = "true" if not head_ref else "false"

    return git_info


def create_header_file(git_info, output_file="git_info.h", namespace="GitInfo"):
    """Generate a C++ header file with the git information."""
    with open(output_file, "w") as f:
        # Write the header guard
        header_guard = f"{output_file.upper().replace('.', '_')}"

        # Current timestamp for header generation
        generation_time = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        # Write header with documentation
        f.write(f"""/**
 * @file {output_file}
 * @brief Git repository information for this project.
 *
 * This file was automatically generated on {generation_time}
 * by the git_info_extractor.py script.
 *
 * Do not edit this file directly as it will be overwritten.
 */

#ifndef {header_guard}
#define {header_guard}

namespace {namespace} {{

""")

        # Add string literals for all git information
        for key, value in git_info.items():
            # Escape quotes in the value
            escaped_value = value.replace('"', '\\"')
            f.write(f'    constexpr const char* {key} = "{escaped_value}";\n')

        # Add special handling for boolean values
        if "IS_CLEAN" in git_info:
            f.write(f'    constexpr bool IS_WORKING_DIRECTORY_CLEAN = {git_info["IS_CLEAN"]};\n')

        if "IS_DETACHED" in git_info:
            f.write(f'    constexpr bool IS_DETACHED_HEAD = {git_info["IS_DETACHED"]};\n')

        # Add commit count as an integer
        if "COMMIT_COUNT" in git_info and git_info["COMMIT_COUNT"]:
            try:
                commit_count = int(git_info["COMMIT_COUNT"])
                f.write(f'    constexpr int COMMIT_COUNT_VALUE = {commit_count};\n')
            except ValueError:
                pass

        # Close the namespace and header guard
        f.write(f"""
}} // namespace {namespace}

#endif // {header_guard}
""")

        print(f"Generated C++ header file: {output_file}")


def main():
    parser = argparse.ArgumentParser(description="Extract Git information and generate a C++ header file.")
    parser.add_argument("--output", "-o", default="git_info.h", help="Output header file name")
    parser.add_argument("--namespace", "-n", default="GitInfo", help="C++ namespace for the git information")
    args = parser.parse_args()

    git_info = get_git_info()

    if not git_info:
        print("Error: Failed to retrieve git information. Make sure you're in a git repository.")
        return 1

    create_header_file(git_info, args.output, args.namespace)
    return 0


if __name__ == "__main__":
    exit(main())

# import subprocess
# import datetime
#
# def get_git_info():
#     try:
#         # Get the current commit hash (full)
#         full_revision = subprocess.check_output(['git', 'rev-parse', 'HEAD']).strip().decode('utf-8')
#
#         # Get the short commit hash
#         revision = subprocess.check_output(['git', 'rev-parse', '--short', 'HEAD']).strip().decode('utf-8')
#
#         # Get the current branch name
#         branch_name = subprocess.check_output(['git', 'rev-parse', '--abbrev-ref', 'HEAD']).strip().decode('utf-8')
#
#         # Get the latest tag (if any)
#         try:
#             tag = subprocess.check_output(['git', 'describe', '--tags', '--exact-match'], stderr=subprocess.STDOUT).strip().decode('utf-8')
#         except subprocess.CalledProcessError:
#             tag = "NoTag"
#
#         # Check if the repository is dirty (uncommitted changes)
#         status = subprocess.check_output(['git', 'status', '--porcelain']).strip().decode('utf-8')
#         is_dirty = "-dirty" if status else ""
#
#         # Combine full revision with dirty flag
#         full_revision += is_dirty
#
#     except Exception as e:
#         print(f"Error retrieving Git information: {e}")
#         full_revision = "Unknown"
#         revision = "Unknown"
#         branch_name = "Unknown"
#         tag = "Unknown"
#         is_dirty = ""
#
#     return full_revision, revision, branch_name, tag
#
# def generate_version_hpp():
#     # Predefined constants
#     API_LIB_NAME_STR = "Wanhive IoT Platform"
#     API_LIB_VERSION_STR = "1.0.0"
#     API_LIB_DESCRIPTION_STR = "A robust IoT platform for connected devices."
#     API_LIB_COPYRIGHT_STR = "Copyright (C) 2020 Wanhive Systems Private Limited"
#     API_LIB_COPYRIGHT_FULL_STR = "This program is part of the Wanhive IoT Platform. Check the COPYING file for the license."
#
#     API_LIB_PROJECT_STR = "Wanhive IoT Platform"
#     API_LIB_PACKAGE_STR = "wanhive-iot"
#     API_LIB_AUTHOR_STR = "Wanhive Systems Private Limited"
#     API_LIB_RELEASE_EMAIL = "info@wanhive.com"
#     API_LIB_RELEASE_URL = "https://wanhive.com"
#
#     # Extract Git information
#     full_revision, revision, branch_name, tag = get_git_info()
#
#     # Parse version components
#     major, minor, patch = API_LIB_VERSION_STR.split('.')
#     API_LIB_MAJOR_REVISION = major
#     API_LIB_MINOR_REVISION = minor
#     API_LIB_PATCHLEVEL = patch
#
#     # Current date and time
#     now = datetime.datetime.now()
#     API_LIB_RELEASE_ISODATE_STR = now.isoformat()
#     API_LIB_RELEASE_YEAR_STR = str(now.year)
#     API_LIB_RELEASE_DATE_STR = now.strftime("%Y-%m-%d")
#     API_LIB_RELEASE_TIME_STR = now.strftime("%H:%M:%S")
#
#     # Generate the header file
#     with open('version.hpp', 'w') as f:
#         f.write("/*\n")
#         f.write(" * version.hpp\n")
#         f.write(" *\n")
#         f.write(" * Package information\n")
#         f.write(" *\n")
#         f.write(" *\n")
#         f.write(" * Copyright (C) 2020 Wanhive Systems Private Limited (info@wanhive.com)\n")
#         f.write(" * This program is part of the Wanhive IoT Platform.\n")
#         f.write(" * Check the COPYING file for the license.\n")
#         f.write(" *\n")
#         f.write(" */\n\n")
#
#         f.write(f"#define API_LIB_NAME_STR            \"{API_LIB_NAME_STR}\"\n")
#         f.write(f"#define API_LIB_VERSION_STR         \"{API_LIB_VERSION_STR}\"\n")
#         f.write(f"#define API_LIB_DESCRIPTION_STR     \"{API_LIB_DESCRIPTION_STR}\"\n")
#         f.write(f"#define API_LIB_COPYRIGHT_STR       \"{API_LIB_COPYRIGHT_STR}\"\n")
#         f.write(f"#define API_LIB_COPYRIGHT_FULL_STR  \"{API_LIB_COPYRIGHT_FULL_STR}\"\n\n")
#
#         f.write(f"#define API_LIB_PROJECT_STR         \"{API_LIB_PROJECT_STR}\"\n")
#         f.write(f"#define API_LIB_PACKAGE_STR         \"{API_LIB_PACKAGE_STR}\"\n")
#         f.write(f"#define API_LIB_AUTHOR_STR          \"{API_LIB_AUTHOR_STR}\"\n")
#         f.write(f"#define API_LIB_RELEASE_ISODATE_STR \"{API_LIB_RELEASE_ISODATE_STR}\"\n")
#         f.write(f"#define API_LIB_RELEASE_YEAR_STR    \"{API_LIB_RELEASE_YEAR_STR}\"\n")
#         f.write(f"#define API_LIB_RELEASE_DATE_STR    \"{API_LIB_RELEASE_DATE_STR}\"\n")
#         f.write(f"#define API_LIB_RELEASE_TIME_STR    \"{API_LIB_RELEASE_TIME_STR}\"\n")
#         f.write(f"#define API_LIB_RELEASE_URL         \"{API_LIB_RELEASE_URL}\"\n\n")
#
#         f.write(f"#define API_LIB_FULL_REVISION_STR   \"{full_revision}\"\n")
#         f.write(f"#define API_LIB_REVISION_STR        \"{revision}\"\n")
#         f.write(f"#define API_LIB_MAJOR_REVISION      {API_LIB_MAJOR_REVISION}\n")
#         f.write(f"#define API_LIB_MINOR_REVISION      {API_LIB_MINOR_REVISION}\n")
#         f.write(f"#define API_LIB_PATCHLEVEL          {API_LIB_PATCHLEVEL}\n\n")
#
#         f.write(f"#define API_LIB_RELEASE_VERSION     PACKAGE_VERSION\n")
#         f.write(f"#define API_LIB_RELEASE_YEAR        INCEPTION_YEAR\n")
#         f.write(f"#define API_LIB_RELEASE_EMAIL       PACKAGE_BUGREPORT\n")
#         f.write(f"#define API_LIB_RELEASE_URL         PACKAGE_URL\n")
#
# if __name__ == "__main__":
#     generate_version_hpp()
#
# # import subprocess
# #
# # def get_git_info():
# #     try:
# #         # Get the current commit hash
# #         commit_hash = subprocess.check_output(['git', 'rev-parse', 'HEAD']).strip().decode('utf-8')
# #
# #         # Get the current branch name
# #         branch_name = subprocess.check_output(['git', 'rev-parse', '--abbrev-ref', 'HEAD']).strip().decode('utf-8')
# #
# #         # Get the latest tag (if any)
# #         tag = subprocess.check_output(['git', 'describe', '--tags', '--exact-match'], stderr=subprocess.STDOUT).strip().decode('utf-8')
# #     except subprocess.CalledProcessError:
# #         tag = "NoTag"
# #
# #     # Check if the repository is dirty (uncommitted changes)
# #     status = subprocess.check_output(['git', 'status', '--porcelain']).strip().decode('utf-8')
# #     is_dirty = "true" if status else "false"
# #
# #     return commit_hash, branch_name, tag, is_dirty
# #
# # def generate_header_file(commit_hash, branch_name, tag, is_dirty):
# #     # with open('GitRevision.hpp', 'w') as f:
# #     with open('src/main/cpp/com/github/doevelopper/atlas/semver/GitRevision.hpp', 'w') as f:
# #         f.write("#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_GITREVISION_HPP\n")
# #         f.write("#define COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_GITREVISION_HPP\n\n")
# #         f.write(f"const char* GIT_COMMIT_HASH = \"{commit_hash}\";\n")
# #         f.write(f"const char* GIT_BRANCH_NAME = \"{branch_name}\";\n")
# #         f.write(f"const char* GIT_LATEST_TAG = \"{tag}\";\n")
# #         f.write(f"const bool GIT_IS_DIRTY = {is_dirty};\n\n")
# #         f.write("#endif // COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_GITREVISION_HPP\n")
# #
# # if __name__ == "__main__":
# #     commit_hash, branch_name, tag, is_dirty = get_git_info()
# #     generate_header_file(commit_hash, branch_name, tag, is_dirty)