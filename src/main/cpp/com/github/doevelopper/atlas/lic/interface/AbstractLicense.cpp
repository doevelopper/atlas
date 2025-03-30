
#include <algorithm>
#include <chrono>

#include <com/github/doevelopper/atlas/lic/interface/AbstractLicense.hpp>

using namespace com::github::doevelopper::atlas::lic::interface;
using namespace com::github::doevelopper::atlas::lic::utils;

log4cxx::LoggerPtr AbstractLicense::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.lic.interface.AbstractLicense"));

AbstractLicense::AbstractLicense() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

AbstractLicense::~AbstractLicense()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

AbstractLicense::AbstractLicense(const LicenseInfo& info)
    : info_(info),
      cachedStatus_(LicenseStatus::NotActivated),
      lastStatusCheck_(std::chrono::system_clock::time_point::min())
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // Initially update the status
    updateStatus();
}

std::string AbstractLicense::getId() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return info_.id;
}

LicenseType AbstractLicense::getType() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return info_.type;
}

LicenseStatus AbstractLicense::getStatus() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // Cache status for a short period to avoid repeated checks
    auto now = std::chrono::system_clock::now();

    if (now - lastStatusCheck_ > std::chrono::seconds(5))
    {
        cachedStatus_ = updateStatus();
        lastStatusCheck_ = now;
    }
    return cachedStatus_;
}

std::string AbstractLicense::getUser() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return info_.userId;
}

std::chrono::system_clock::time_point AbstractLicense::getIssueDate() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return info_.issueDate;
}

std::chrono::system_clock::time_point AbstractLicense::getExpirationDate() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return info_.expirationDate;
}

bool AbstractLicense::isFeatureEnabled(const std::string& featureName) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return std::find(info_.enabledFeatures.begin(),
                    info_.enabledFeatures.end(),
                    featureName) != info_.enabledFeatures.end();
}

std::vector<std::string> AbstractLicense::getEnabledFeatures() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return info_.enabledFeatures;
}

std::string AbstractLicense::getBoundHardwareId() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return info_.boundHardwareId;
}

std::unordered_map<std::string, std::string> AbstractLicense::getProperties() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return info_.properties;
}

bool AbstractLicense::isInGracePeriod() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return info_.isInGracePeriod(std::chrono::system_clock::now());
}

std::chrono::seconds AbstractLicense::getRemainingGraceTime() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return info_.getRemainingGraceTime(std::chrono::system_clock::now());
}

LicenseStatus AbstractLicense::updateStatus() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto now = std::chrono::system_clock::now();

    // Check expiration
    if (info_.isExpired(now))
    {
        // Check grace period
        if (info_.isInGracePeriod(now))
        {
            return LicenseStatus::GracePeriod;
        }
        return LicenseStatus::Expired;
    }

    // If we get here, the license is valid
    return LicenseStatus::Valid;
}