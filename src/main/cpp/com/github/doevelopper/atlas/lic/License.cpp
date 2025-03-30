
#include <algorithm>
#include <chrono>

#include <com/github/doevelopper/atlas/lic/License.hpp>
using namespace com::github::doevelopper::atlas::lic;
using namespace com::github::doevelopper::atlas::lic::utils;
log4cxx::LoggerPtr License::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.lic.License"));

License::License() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

License::~License()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

License::License(const LicenseInfo& info)
    : m_info(info),
      m_cachedStatus(interface::LicenseStatus::NotActivated),
      m_lastStatusCheck(std::chrono::system_clock::time_point::min())
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // Initially update the status
    this->updateStatus();
}

std::string License::getId() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_info.id();
}

interface::LicenseType License::getType() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_info.type();
}

interface::LicenseStatus License::getStatus() const
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

std::string License::getUser() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_info.userId();
}

std::chrono::system_clock::time_point License::getIssueDate() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_info.issueDate();
}

std::chrono::system_clock::time_point License::getExpirationDate() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_info.expirationDate();
}

bool License::isFeatureEnabled(const std::string& featureName) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return std::find(this->m_info.enabledFeatures().begin(),
                    this->m_info.enabledFeatures().end(),
                    featureName) != info_.enabledFeatures.end();
}

std::vector<std::string> License::getEnabledFeatures() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_info.enabledFeatures();
}

std::string License::getBoundHardwareId() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_info.boundHardwareId();
}

std::unordered_map<std::string, std::string> License::getProperties() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_info.properties();
}

bool License::isInGracePeriod() const
{
    return this->m_info.isInGracePeriod(std::chrono::system_clock::now());
}

std::chrono::seconds License::getRemainingGraceTime() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_info.getRemainingGraceTime(std::chrono::system_clock::now());
}

LicenseStatus License::updateStatus() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto now = std::chrono::system_clock::now();

    // Check expiration
    if (this->m_info.isExpired(now))
    {
        // Check grace period
        if (this->m_info.isInGracePeriod(now))
        {
            return LicenseStatus::GracePeriod;
        }
        return LicenseStatus::Expired;
    }

    // If we get here, the license is valid
    return LicenseStatus::Valid;
}
