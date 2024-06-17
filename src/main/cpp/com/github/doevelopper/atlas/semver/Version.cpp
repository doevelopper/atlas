
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

#include <com/github/doevelopper/atlas/semver/Version.hpp>

using namespace com::github::doevelopper::atlas::semver;

log4cxx::LoggerPtr Version::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.semver.Version"));

Version::Version() noexcept
    : m_major(0)
    , m_minor(0)
    , m_patch(0)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Version::~Version() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Version::Version(std::uint8_t major, std::uint8_t minor, std::uint8_t patch, const std::string& pre_release, const std::string& build_metadata) noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Version::Version(const std::string& version) noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::regex semverRegex(R"(^(?P<major>\d+)\.(?P<minor>\d+)\.(?P<patch>\d+)(?:-(?P<preRelease>[0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*))?(?:\+(?P<build>[0-9A-Za-z-]+(?:\.[0-9A-Za-z-]+)*))?$)");
    std::smatch match;

    if (std::regex_match(version, match, semverRegex))
    {
        // this->m_major = std::stoi(std::string(match["major"]));
        // this->m_minor = std::stoi(std::string(match["minor"]));
        // this->m_patch = std::stoi(std::string(match["patch"]));
        // this->m_major = std::stoi(match["major"].str());
        // this->m_minor = std::stoi(match["minor"].str());
        // this->m_patch = std::stoi(match["patch"].str());

        // if (!match["preRelease"].str().empty())
        // {
        //     std::istringstream iss(match["preRelease"]);
        //     std::string item = std::string("");
        //
        //     while (std::getline(iss, item, '.'))
        //     {
        //         this->m_pre_release.push_back(item);
        //     }
        // }
        //
        // if (!match["build"].str().empty())
        // {
        //     std::istringstream iss(match["build"]);
        //     std::string item = std::string("");
        //     while (std::getline(iss, item, '.'))
        //     {
        //         this->m_build_metadata.push_back(item);
        //     }
        // }
    }
    else
    {
        LOG4CXX_ERROR(logger,"Invalid Semver 2.0.0 version string");
    }
}

std::uint8_t Version::get_m_major() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_major;
}

void Version::set_m_major(const std::uint8_t major)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_major = major;
}

std::uint8_t Version::get_m_minor() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_minor;
}

void Version::set_m_minor(const std::uint8_t minor)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_minor = minor;
}

std::uint8_t Version::get_m_patch() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_patch;
}

void Version::set_m_patch(const std::uint8_t patch)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_patch = patch;
}

std::uint8_t Version::get_m_tweak() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_tweak;
}

void Version::set_m_tweak(const std::uint8_t tweak)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_tweak = tweak;
}

ReleaseLevel Version::get_m_release_type() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_releaseType;
}

void Version::set_m_release_type(const ReleaseLevel release_type)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_releaseType = release_type;
}
