
#include <com/github/doevelopper/atlas/lic/utils/LicenseInfo.hpp>

using namespace com::github::doevelopper::atlas::lic::utils;

log4cxx::LoggerPtr LicenseInfo::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.lic.LicenseInfo"));



LicenseInfo::LicenseInfo() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

LicenseInfo::~LicenseInfo()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool LicenseInfo::isExpired(const std::chrono::system_clock::time_point& now) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_expirationDate <= now;
}

bool LicenseInfo::isInGracePeriod(const std::chrono::system_clock::time_point& now) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (!isExpired(now))
        {
        return false;
    }
    auto expired_seconds = std::chrono::duration_cast<std::chrono::seconds>(
        now - this->m_expirationDate);
    return expired_seconds <= this->m_gracePeriod;
}

std::chrono::seconds LicenseInfo::getRemainingGraceTime(const std::chrono::system_clock::time_point& now) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (!isExpired(now))
    {
        return std::chrono::seconds(0);
    }

    auto expired_seconds = std::chrono::duration_cast<std::chrono::seconds>(
        now - this->m_expirationDate);

    if (expired_seconds >= this->m_gracePeriod)
    {
        return std::chrono::seconds(0);
    }
    return this->m_gracePeriod - expired_seconds;
}

const std::string & LicenseInfo::id() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_id;
}

void LicenseInfo::id(const std::string & id)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_id = id;
}

const std::string & LicenseInfo::userId() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_userId;
}

void LicenseInfo::userId(const std::string & user_id)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_userId = user_id;
}

const std::chrono::system_clock::time_point & LicenseInfo::issueDate() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_issueDate;
}

void LicenseInfo::issueDate(const std::chrono::system_clock::time_point & issue_date)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_issueDate = issue_date;
}

const std::chrono::system_clock::time_point & LicenseInfo::expirationDate() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_expirationDate;
}

void LicenseInfo::expirationDate(const std::chrono::system_clock::time_point & expiration_date)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_expirationDate = expiration_date;
}

const std::string & LicenseInfo::boundHardwareId() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_boundHardwareId;
}

void LicenseInfo::boundHardwareId(const std::string & bound_hardware_id)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_boundHardwareId = bound_hardware_id;
}

const std::vector<std::string> & LicenseInfo::enabledFeatures() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_enabledFeatures;
}

void LicenseInfo::enabledFeatures(const std::vector<std::string> & enabled_features)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_enabledFeatures = enabled_features;
}

const std::unordered_map<std::string, std::string> & LicenseInfo::properties() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_properties;
}

void LicenseInfo::properties(const std::unordered_map<std::string, std::string> & properties)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_properties = properties;
}

const std::chrono::seconds & LicenseInfo::gracePeriod() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return this->m_gracePeriod;
}

void LicenseInfo::gracePeriod(const std::chrono::seconds & grace_period)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_gracePeriod = grace_period;
}