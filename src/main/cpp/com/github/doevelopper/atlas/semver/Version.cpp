
/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Main entry point of application
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

#include <regex>
#include <string>
#include <iomanip>

#include <com/github/doevelopper/atlas/semver/Version.hpp>

using namespace com::github::doevelopper::atlas::semver;

log4cxx::LoggerPtr Version::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.semver.Version"));

Version::Version() noexcept
    : m_hex_version(0x0000000000000000)
    , m_major(0)
    , m_minor(0)
    , m_patch(0)
//     , m_releaseType(ReleaseLevel::SNAPSHOOT)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Version::Version(const std::uint64_t value)
    : m_hex_version(value)
    , m_major(this->minor())
    , m_minor(this->minor())
    , m_patch(this->patch())
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Version::Version(std::uint8_t major, std::uint8_t minor, std::uint8_t patch,
        std::uint8_t preRelease, std::uint8_t preReleaseCount,
        std::uint8_t buildMetadata, std::uint8_t buildCount,
        std::uint8_t additionalFlags) noexcept
    : m_hex_version(0)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // this->major(major);
    // this->minor(minor);
    // this->patch(patch);
    // this->preRelease(preRelease);
    // this->preReleaseCount(preReleaseCount);
    // this->buildMetadata(buildMetadata);
    // this->buildCount(buildCount);
    // this->additionalFlags(additionalFlags);

    this->m_hex_version = (static_cast<uint64_t>(major) << MAJOR_SHIFT) |
                   (static_cast<uint64_t>(minor) << MINOR_SHIFT) |
                   (static_cast<uint64_t>(patch) << PATCH_SHIFT) |
                   (static_cast<uint64_t>(preRelease) << PRE_RELEASE_SHIFT) |
                   (static_cast<uint64_t>(preReleaseCount) << PRE_RELEASE_COUNT_SHIFT) |
                   (static_cast<uint64_t>(buildMetadata) << BUILD_METADATA_SHIFT) |
                   (static_cast<uint64_t>(buildCount) << BUILD_COUNT_SHIFT) |
                   (static_cast<uint64_t>(additionalFlags) << ADDITIONAL_FLAGS_SHIFT);
}

Version::~Version() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

auto Version::bits(int highBit, int lowBit, std::uint8_t value) -> void
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // std::uint64_t mask = ((1ULL << (highBit - lowBit + 1)) - 1) << lowBit;
    // this->m_hex_version = (this->m_hex_version & ~mask) | ((static_cast<std::uint64_t>(value) << lowBit) & mask);
    std::uint64_t mask = (((1ULL << (highBit - lowBit + 1)) - 1) << lowBit);
    this->m_hex_version = (this->m_hex_version & ~mask) | ((static_cast<std::uint64_t>(value) << lowBit) & mask);
}

auto Version::bits(int highBit, int lowBit) const -> std::uint8_t
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // std::uint64_t mask = ((1ULL << (highBit - lowBit + 1)) - 1) << lowBit;
    // return static_cast<std::uint8_t>((this->m_hex_version & mask) >> lowBit);
    std::uint64_t mask = (((1ULL << (highBit - lowBit + 1)) - 1) << lowBit);
    return static_cast<std::uint8_t>((this->m_hex_version & mask) >> lowBit);
}

auto Version::rawVersion(std::uint64_t value) -> void
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_hex_version = value;
}

auto Version::rawVersion() const -> std::uint64_t
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_hex_version;
}

std::string Version::releaseLevelToString(ReleaseLevel level)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    switch (level)
    {
    case ReleaseLevel::SNAPSHOOT: return "SNAPSHOT";
    case ReleaseLevel::ALPHA:     return "ALPHA";
    case ReleaseLevel::BETA:      return "BETA";
    case ReleaseLevel::CANDIDATE: return "RC";
    case ReleaseLevel::FINAL:     return "FINAL";
    default:                      return "UNKNOWN";
    }
}

std::uint8_t Version::major() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return this->bits(63, 56);;
    // return (this->m_hex_version >> MAJOR_SHIFT) & 0xFF;
    return static_cast<std::uint8_t>((this->m_hex_version & MAJOR_MASK) >> MAJOR_SHIFT);
}

void Version::major(const std::uint8_t major)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // this->bits(63, 56, major);
    this->m_hex_version = (this->m_hex_version & ~(0xFFULL << MAJOR_SHIFT)) | (static_cast<uint64_t>(major) << MAJOR_SHIFT);
}

std::uint8_t Version::minor() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return this->bits(63, 56);
    // return (this->m_hex_version >> MINOR_SHIFT) & 0xFF;
    return static_cast<uint8_t>((this->m_hex_version & MINOR_MASK) >> MINOR_SHIFT);
}

void Version::minor(const std::uint8_t minor)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // this->bits(55, 48, minor);
    // this->m_minor = minor;
    this->m_hex_version = (this->m_hex_version & ~(0xFFULL << MINOR_SHIFT)) | (static_cast<uint64_t>(minor) << MINOR_SHIFT);
}

std::uint8_t Version::patch() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return this->bits(47, 40);
    // return (this->m_hex_version >> PATCH_SHIFT) & 0xFF;
    return static_cast<uint8_t>((this->m_hex_version & PATCH_MASK) >> PATCH_SHIFT);
}

void Version::patch(const std::uint8_t patch)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // this->bits(47, 40, patch);
    // this->m_patch = patch;
    this->m_hex_version = (this->m_hex_version & ~(0xFFULL << PATCH_SHIFT)) | (static_cast<uint64_t>(patch) << PATCH_SHIFT);
}

void Version::preRelease(std::uint8_t preRelease)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // this->bits(39, 32, preRelease);
    this->m_hex_version = (this->m_hex_version & ~(0xFFULL << PRE_RELEASE_SHIFT)) | (static_cast<uint64_t>(preRelease) << PRE_RELEASE_SHIFT);
}

std::uint8_t Version::preRelease() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return this->bits(39, 32);
    // return (this->m_hex_version >> PRE_RELEASE_SHIFT) & 0xFF;
    return static_cast<uint8_t>((this->m_hex_version & PRERELEASE_MASK) >> PRE_RELEASE_SHIFT);
}

void Version::preReleaseCount(std::uint8_t preReleaseCount)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // this->bits(31, 24, preReleaseCount);
    this->m_hex_version = (this->m_hex_version & ~(0xFFULL << PRE_RELEASE_COUNT_SHIFT)) | (static_cast<uint64_t>(preReleaseCount) << PRE_RELEASE_COUNT_SHIFT);
}

std::uint8_t Version::preReleaseCount() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return this->bits(31, 24);
    // return (this->m_hex_version >> PRE_RELEASE_COUNT_SHIFT) & 0xFF;
    return static_cast<uint8_t>((this->m_hex_version & PRERELEASE_COUNT_MASK) >> PRE_RELEASE_COUNT_SHIFT);
}

void Version::buildMetadata(std::uint8_t buildMetadata)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // this->bits(23, 16, buildMetadata);
    this->m_hex_version = (this->m_hex_version & ~(0xFFULL << BUILD_METADATA_SHIFT)) | (static_cast<uint64_t>(buildMetadata) << BUILD_METADATA_SHIFT);
}

std::uint8_t Version::buildMetadata() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return this->bits(23, 16);
    // return (this->m_hex_version >> BUILD_METADATA_SHIFT) & 0xFF;
    return static_cast<uint8_t>((this->m_hex_version  & BUILD_METADATA_MASK) >> BUILD_METADATA_SHIFT);
}

void Version::buildCount(std::uint8_t buildCount)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // this->bits(15, 8, buildCount);
    this->m_hex_version = (this->m_hex_version & ~(0xFFULL << BUILD_COUNT_SHIFT)) | (static_cast<uint64_t>(buildCount) << BUILD_COUNT_SHIFT);
}

std::uint8_t Version::buildCount() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return this->bits(15, 8);
    // return (this->m_hex_version >> BUILD_COUNT_SHIFT) & 0xFF;
    return static_cast<uint8_t>((this->m_hex_version & BUILD_COUNT_MASK) >> BUILD_COUNT_SHIFT);
}

std::uint8_t Version::additionalFlags() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return this->bits(7, 0);
    // return (this->m_hex_version >> ADDITIONAL_FLAGS_SHIFT) & 0xFF;
    return static_cast<uint8_t>((this->m_hex_version & ADDITIONAL_FLAGS_MASK) >> ADDITIONAL_FLAGS_SHIFT);
}

void Version::additionalFlags(std::uint8_t additionalFlags)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // this->bits(7, 0, additionalFlags);
    this->m_hex_version = (this->m_hex_version & ~(0xFFULL << ADDITIONAL_FLAGS_SHIFT)) | (static_cast<uint64_t>(additionalFlags) << ADDITIONAL_FLAGS_SHIFT);
}

std::string Version::toString() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::ostringstream oss;
    oss << +this->major() << "." << +this->minor() << "." << +this->patch()
            << "-" << +this->preRelease() << "." << +this->preReleaseCount()
            << "+" << +this->buildMetadata() << "." << +this->buildCount()
            << "[" << +this->additionalFlags() << "]";
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " String representation of the version: " << oss.str());
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Raw Version: 0x" << std::hex << std::setw(16) << std::setfill('0') << this->rawVersion() << std::dec);
    return oss.str();
}

std::string Version::fullVersionFromString() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::stringstream ss;
    ss << static_cast<int>(major()) << "."
       << static_cast<int>(minor()) << "."
       << static_cast<int>(patch());

    if (preRelease() > 0)
    {
        ss << "-";
        //ss << this->releaseLevelToString(preRelease());
        // switch (preRelease())
        // {
        //     case 1: ss << "alpha"; break;
        //     case 2: ss << "beta"; break;
        //     case 3: ss << "rc"; break;
        //     default: ss << "pre" << static_cast<int>(preRelease());
        // }

        if (this->preReleaseCount() > 0)
        {
            ss << "." << static_cast<int>(this->preReleaseCount());
        }
    }

    if (this->buildMetadata() > 0 || this->buildCount() > 0)
    {
        ss << "+" << static_cast<int>(this->buildMetadata());
        if (this->buildCount() > 0)
        {
            ss << "." << static_cast<int>(this->buildCount());
        }
    }

    return ss.str();
}

std::string Version::toHexString() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::stringstream ss;
    ss << "0x" << std::hex << std::setfill('0') << std::setw(16) << this->m_hex_version;
    return ss.str();
}

int Version::compare(const Version& other) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    if (this->major() != other.major())
    {
        return this->major() - other.major();
    }

    if (this->minor() != other.minor())
    {
        return this->minor() - other.minor();
    }

    if (this->patch() != other.patch())
    {
        return this->patch() - other.patch();
    }

    // Pre-release versions have lower precedence than the associated normal version
    bool thisHasPreRelease = this->preRelease() > 0;
    bool otherHasPreRelease = other.preRelease() > 0;

    if (thisHasPreRelease != otherHasPreRelease) {
        return thisHasPreRelease ? -1 : 1;
    }

    // Compare pre-release identifiers
    if (this->preRelease() != other.preRelease())
    {
        return this->preRelease() - other.preRelease();
    }

    // Compare pre-release count
    if (this->preReleaseCount() != other.preReleaseCount())
    {
        return this->preReleaseCount() - other.preReleaseCount();
    }

    // Build metadata does not affect precedence
    return 0;
}

// Version::Version(std::uint8_t major, std::uint8_t minor, std::uint8_t patch, const std::string& pre_release, const std::string& build_metadata) noexcept
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }
//
// Version::Version(std::uint8_t major, std::uint8_t minor, std::uint8_t patch, std::uint8_t preRelease, std::uint8_t preReleaseCount, std::uint8_t buildMetadata, std::uint8_t buildCount, std::uint8_t flags) noexcept
// : m_value(static_cast<uint64_t>(major) << 56 |
//                  static_cast<uint64_t>(minor) << 48 |
//                  static_cast<uint64_t>(patch) << 40 |
//                  static_cast<uint64_t>(preRelease) << 32 |
//                  static_cast<uint64_t>(preReleaseCount) << 24 |
//                  static_cast<uint64_t>(buildMetadata) << 16 |
//                  static_cast<uint64_t>(buildCount) << 8 |
//                  static_cast<uint64_t>(flags))
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }
//
// Version::Version(uint64_t value)
// : m_value(value)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }
//
// Version::Version(const std::string& version) noexcept
// {
//
//         //*this = this->fromSemVer(semver);
//  //-------------------------------
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     //std::regex semverRegex(R"(^(?P<major>\d+)\.(?P<minor>\d+)\.(?P<patch>\d+)(?:-(?P<preRelease>[0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*))?(?:\+(?P<build>[0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*))?$)");
//     const std::regex semverRegex(R"(^(\d+)\.(\d+)\.(\d+)(?:-([0-9A-Za-z-]+(\.[0-9A-Za-z-]+)*))?(?:\+([0-9A-Za-z-]+(\.[0-9A-Za-z-]+)*))?$)");
//     std::smatch match;
//
//     if (std::regex_match(version, match, semverRegex))
//     {
//         // this->m_major = std::stoi(std::string(match["major"]));
//         // this->m_minor = std::stoi(std::string(match["minor"]));
//         // this->m_patch = std::stoi(std::string(match["patch"]));
//         // this->m_major = std::stoi(match["major"].str());
//         // this->m_minor = std::stoi(match["minor"].str());
//         // this->m_patch = std::stoi(match["patch"].str());
//
//         // if (!match["preRelease"].str().empty())
//         // {
//         //     std::istringstream iss(match["preRelease"]);
//         //     std::string item = std::string("");
//         //
//         //     while (std::getline(iss, item, '.'))
//         //     {
//         //         this->m_pre_release.push_back(item);
//         //     }
//         // }
//         //
//         // if (!match["build"].str().empty())
//         // {
//         //     std::istringstream iss(match["build"]);
//         //     std::string item = std::string("");
//         //     while (std::getline(iss, item, '.'))
//         //     {
//         //         this->m_build_metadata.push_back(item);
//         //     }
//         // }
//
//         // Lambda to validate numeric identifiers (no leading zeros unless "0")
//         auto checkNumeric = [](const std::string& str) {
//             if (str.size() > 1 && str[0] == '0') {
//                 //throw std::invalid_argument("Invalid numeric identifier with leading zeros: " + str);
//                 LOG4CXX_ERROR(logger,"Invalid numeric identifier with leading zeros:" <<  str);
//             }
//         };
//
//         std::string major_str = match[1].str();
//         checkNumeric(major_str);
//         this->m_major = std::stoull(major_str);
//
//         // Parse and validate minor version
//         std::string minor_str = match[2].str();
//         checkNumeric(minor_str);
//         this->m_minor = std::stoull(minor_str);
//
//         // Parse and validate patch version
//         std::string patch_str = match[3].str();
//         checkNumeric(patch_str);
//         this->m_patch = std::stoull(patch_str);
//
//         // Handle pre-release, if present
//         if (match[4].matched)
//         {
//             std::string pre_release_str = match[4].str();
//             auto identifiers = split(pre_release_str, '.');
//             for (const auto& id : identifiers)
//             {
//                 // If the identifier is all digits, it must not have leading zeros
//                 if (std::all_of(id.begin(), id.end(), ::isdigit))
//                 {
//                     checkNumeric(id);
//                 }
//                 // Regex ensures characters are [0-9A-Za-z-], no additional check needed
//             }
//             m_pre_release = pre_release_str;
//         }
//         else
//         {
//             m_pre_release = "";
//         }
//
//         // Handle build metadata, if present
//         if (match[5].matched)
//         {
//             m_build = match[5].str();
//             // No additional validation needed; regex ensures valid characters and structure
//         }
//         else
//         {
//             m_build = "";
//         }
//     }
//     else
//     {
//         LOG4CXX_ERROR(logger,"Invalid Semver 2.0.0 version string" << version);
//     }
// }
//
// std::uint8_t Version::encodePreReleaseIdentifier(const std::string& id, size_t index) const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     if (std::all_of(id.begin(), id.end(), ::isdigit))
//     {
//         return std::min(static_cast<std::uint8_t>(std::stoul(id)), std::uint8_t(255));
//     }
//     // Simplified mapping for common identifiers
//     if (id == "alpha") return 1 + index;
//     if (id == "beta") return 2 + index;
//     if (id == "rc") return 3 + index;
//     if (id == "hotfix") return 4 + index;
//     if (id == "fresh") return 5 + index;
//     // Fallback: use first character
//     return id.empty() ? 0 : static_cast<std::uint8_t>(id[0]);
// }
//
// void Version::validateNumeric(const std::string& num, const std::string& field) const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     if (num.size() > 1 && num[0] == '0')
//     {
//         //throw std::invalid_argument("Invalid " + field + " with leading zeros: " + num);
//     }
//
//     unsigned long val = std::stoul(num);
//
//     if (val > 255)
//     {
//         //throw std::invalid_argument(field + " exceeds 8-bit range: " + num);
//     }
// }
//
// std::uint8_t Version::computePreReleaseValue() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     if (this->m_pre_release.empty()) return 0;
//     auto ids = this->split(this->m_pre_release, '.');
//     return ids.empty() ? 0 : encodePreReleaseIdentifier(ids[0], 0);
// }
//
// std::uint8_t Version::computePreReleaseCount() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     if (this->m_pre_release.empty()) return 0xFF; // Final release
//     auto ids = this->split(this->m_pre_release, '.');
//     if (ids.size() <= 1) return 1;
//     return this->encodePreReleaseIdentifier(ids[1], 1);
// }
//
// std::uint8_t Version::computeBuildMetadata() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     if (this->m_build.empty()) return 0;
//     auto ids = this->split(this->m_build, '.');
//     return ids.empty() ? 0 : (ids[0] == "build" && ids.size() > 1 ? std::min(static_cast<std::uint8_t>(std::stoul(ids[1])), std::uint8_t(255)) : static_cast<std::uint8_t>(ids[0][0]));
// }
//
// std::uint8_t Version::computeBuildCount() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     if (this->m_build.empty()) return 0;
//     auto ids = this->split(this->m_build, '.');
//     return std::min(static_cast<std::uint8_t>(ids.size()), std::uint8_t(255));
// }
//
// std::uint8_t Version::computeFlags() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     if (this->m_build.find("dirty") != std::string::npos) return 0x01; // Example flag for dirty state
//     return 0;
// }
//
// std::uint64_t Version::toNumericalValue() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     std::uint64_t value = 0;
//
//     // Core components
//     value |= static_cast<std::uint64_t>(this->m_major) << 56;
//     value |= static_cast<std::uint64_t>(this->m_minor) << 48;
//     value |= static_cast<std::uint64_t>(this->m_patch) << 40;
//
//     // Pre-release
//     value |= static_cast<std::uint64_t>(computePreReleaseValue()) << 32;
//     value |= static_cast<std::uint64_t>(computePreReleaseCount()) << 24;
//
//     // Build metadata
//     value |= static_cast<std::uint64_t>(computeBuildMetadata()) << 16;
//     value |= static_cast<std::uint64_t>(computeBuildCount()) << 8;
//
//     // Flags
//     value |= static_cast<std::uint64_t>(computeFlags());
//     return value;
// }
//
// int Version::compare(const Version& other) const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     // Compare core components
//     if (this->m_major != other.m_major) return this->m_major - other.m_major;
//     if (this->m_minor != other.m_minor) return this->m_minor - other.m_minor;
//     if (this->m_patch != other.m_patch) return this->m_patch - other.m_patch;
//
//     // Compare pre-release (empty pre-release is greater)
//     if (this->m_pre_release.empty() && other.m_pre_release.empty()) return 0;
//     if (this->m_pre_release.empty()) return 1;
//     if (other.m_pre_release.empty()) return -1;
//
//     auto ids1 = this->split(this->m_pre_release, '.');
//     auto ids2 = this->split(other.m_pre_release, '.');
//
//     for (size_t i = 0; i < std::min(ids1.size(), ids2.size()); ++i)
//     {
//         bool isNum1 = std::all_of(ids1[i].begin(), ids1[i].end(), ::isdigit);
//         bool isNum2 = std::all_of(ids2[i].begin(), ids2[i].end(), ::isdigit);
//
//         if (isNum1 && isNum2)
//         {
//             int n1 = std::stoi(ids1[i]);
//             int n2 = std::stoi(ids2[i]);
//             if (n1 != n2) return n1 - n2;
//         }
//         else if (!isNum1 && !isNum2)
//         {
//             if (ids1[i] != ids2[i]) return ids1[i].compare(ids2[i]);
//         }
//         else
//         {
//             return isNum1 ? -1 : 1; // Numeric < Alphanumeric
//         }
//     }
//     return ids1.size() - ids2.size();
// }
//

// std::uint8_t Version::tweak() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     return this->m_tweak;
// }
//
// void Version::tweak(const std::uint8_t tweak)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     this->m_tweak = tweak;
// }
//
// ReleaseLevel Version::get_m_release_type() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     return this->m_releaseType;
// }
//
// void Version::set_m_release_type(const ReleaseLevel release_type)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     this->m_releaseType = release_type;
// }
//
// std::string Version::getPreRelease() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     return  this->m_pre_release;
// }
//
// std::string Version::getBuild() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     return  this->m_build;
// }
//
// std::string Version::toString() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     std::string result = std::to_string(m_major) + "." +
//                          std::to_string(m_minor) + "." +
//                          std::to_string(m_patch);
//
//     if (!m_pre_release.empty())
//     {
//         result += "-" + m_pre_release;
//     }
//
//     if (!m_build.empty())
//     {
//         result += "+" + m_build;
//     }
//     return result;
// }
//
// std::vector<std::string> Version::split(const std::string& s, char delimiter) const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     std::vector<std::string> tokens;
//     std::string token;
//     std::istringstream tokenStream(s);
//     while (std::getline(tokenStream, token, delimiter))
//     {
//         tokens.push_back(token);
//     }
//     return tokens;
// }
//
// std::string Version::toSemVer() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     std::stringstream ss;
//     ss << static_cast<int>(get_m_major()) << "." << static_cast<int>(get_m_minor()) << "." << static_cast<int>(get_m_patch());
//
//     // if (get_m_release_type() != 0) {
//     //     ss << "-";
//     //     switch (get_m_release_type()) {
//     //     case 1: ss << "alpha"; break;
//     //     case 2: ss << "beta"; break;
//     //     case 3: ss << "rc"; break;
//     //     case 4: ss << "fresh"; break;
//     //     case 5: ss << "hotfix"; break;
//     //     default: ss << "pre"; break;
//     //     }
//     //     if(preReleaseCount() != 0)
//     //         ss << static_cast<int>(preReleaseCount());
//     // }
//     //
//     // if (buildMetadata() != 0 || buildCount() != 0 || flags() != 0) {
//     //     ss << "+build.";
//     //     ss << static_cast<int>(buildCount());
//     //     if(buildMetadata() != 0){
//     //         ss << "." << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(buildMetadata());
//     //     }
//     //
//     //     if(flags() != 0){
//     //         ss << "." << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(flags());
//     //     }
//     // }
//     return ss.str();
// }
//
// Version Version::fromSemVer(const std::string& semver)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     //std::regex semverRegex(R"(^(?P<major>\d+)\.(?P<minor>\d+)\.(?P<patch>\d+)(?:-(?P<preRelease>[0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*))?(?:\+(?P<build>[0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*))?$)");
//     std::regex semverRegex(R"(^(\d+)\.(\d+)\.(\d+)(?:-([a-zA-Z]+)(\d*))?(?:\+build\.(\d+)(?:\.([0-9a-fA-F]+))?(?:\.([0-9a-fA-F]+))?)?$)");
//     std::smatch match;
//
//     if (std::regex_match(semver, match, semverRegex))
//     {
//         // Parse and validate core components
//         this->validateNumeric(match[1].str(), "major");
//         this->m_major = static_cast<std::uint8_t>(std::stoul(match[1].str()));
//         this->validateNumeric(match[2].str(), "minor");
//         this->m_minor = static_cast<std::uint8_t>(std::stoul(match[2].str()));
//         this->validateNumeric(match[3].str(), "patch");
//         this->m_patch = static_cast<std::uint8_t>(std::stoul(match[3].str()));
//
//         // Pre-release
//         this->m_pre_release = match[4].matched ? match[4].str() : "";
//         if (!this->m_pre_release.empty())
//         {
//             auto ids = this->split(this->m_pre_release, '.');
//             for (const auto& id : ids)
//             {
//                 if (std::all_of(id.begin(), id.end(), ::isdigit))
//                 {
//                     this->validateNumeric(id, "pre-release numeric identifier");
//                 }
//             }
//         }
//
//         // Build metadata
//         this->m_build = match[5].matched ? match[5].str() : "";
//         std::uint8_t preRelease = 0;
//         std::uint8_t preReleaseCount = 0;
//         std::uint8_t buildCount = 0;
//         std::uint8_t buildMetadata = 0;
//         std::uint8_t flags = 0;
// /*
//         std::uint8_t major = static_cast<std::uint8_t>(std::stoi(match[1].str()));
//         std::uint8_t minor = static_cast<std::uint8_t>(std::stoi(match[2].str()));
//         std::uint8_t patch = static_cast<std::uint8_t>(std::stoi(match[3].str()));
//
//         if (match[4].matched)
//         {
//             std::string preReleaseStr = match[4].str();
//             if (preReleaseStr == "alpha") preRelease = 1;
//             else if (preReleaseStr == "beta") preRelease = 2;
//             else if (preReleaseStr == "rc") preRelease = 3;
//             else if (preReleaseStr == "fresh") preRelease = 4;
//             else if (preReleaseStr == "hotfix") preRelease = 5;
//             else preRelease = 6;
//
//             if (match[5].matched)
//             {
//                 preReleaseCount = static_cast<uint8_t>(std::stoi(match[5].str()));
//             }
//         }
// */
//         if (match[6].matched)
//         {
//             buildCount = static_cast<uint8_t>(std::stoi(match[6].str()));
//         }
//
//         if(match[7].matched)
//         {
//             buildMetadata = static_cast<uint8_t>(std::stoul(match[7].str(), nullptr, 16));
//         }
//
//         if(match[8].matched)
//         {
//             flags = static_cast<uint8_t>(std::stoul(match[8].str(), nullptr, 16));
//         }
//
//         //return Version(m_major, m_minor, m_patch, preRelease, preReleaseCount, buildMetadata, buildCount, flags);
//     } else {
//         //throw std::invalid_argument("Invalid SemVer string");
//     }
// }

