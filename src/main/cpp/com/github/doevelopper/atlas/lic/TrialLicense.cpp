
#include <chrono>
#include <ctime>
#include <random>
#include <iomanip>
#include <sstream>

#include <com/github/doevelopper/atlas/lic/TrialLicense.hpp>
using namespace com::github::doevelopper::atlas::lic;

log4cxx::LoggerPtr TrialLicense::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.lic.TrialLicense"));

const std::string TrialLicense::PROPERTY_MAX_USAGE_HOURS = "max_usage_hours";
const std::string TrialLicense::PROPERTY_CURRENT_USAGE_HOURS = "current_usage_hours";

TrialLicense::TrialLicense() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TrialLicense::~TrialLicense()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TrialLicense::TrialLicense(const LicenseInfo& info)
    : BaseLicense(info) {
    // Ensure this is a trial license
    if (info.type != LicenseType::Trial) {
        throw std::invalid_argument("License info must be of trial type");
    }
}

LicensePtr TrialLicense::create(
    const std::string& userId,
    int durationDays,
    const std::vector<std::string>& features) {

    // Generate a unique license ID
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 0xFFFFFFFF);

    std::stringstream ss;
    ss << "TRIAL-" << std::hex << std::setfill('0') << std::setw(8) << distrib(gen);

    // Create license info
    LicenseInfo info;
    info.id = ss.str();
    info.userId = userId;
    info.type = LicenseType::Trial;
    info.issueDate = std::chrono::system_clock::now();
    info.expirationDate = info.issueDate + std::chrono::hours(24 * durationDays);
    info.enabledFeatures = features;
    info.gracePeriod = std::chrono::hours(24); // 1 day grace period

    // Set usage properties
    info.properties[PROPERTY_MAX_USAGE_HOURS] = std::to_string(24 * durationDays);
    info.properties[PROPERTY_CURRENT_USAGE_HOURS] = "0";

    return std::make_shared<TrialLicense>(info);
}

LicenseStatus TrialLicense::updateStatus() const
{
    // First check the basic status from the base class
    LicenseStatus baseStatus = BaseLicense::updateStatus();

    if (baseStatus != LicenseStatus::Valid && baseStatus != LicenseStatus::GracePeriod)
    {
        return baseStatus;
    }

    // Then check additional trial-specific constraints
    if (getCurrentUsageHours() > getMaxUsageHours()) {
        return LicenseStatus::Expired;
    }

    return baseStatus;
}

int TrialLicense::getMaxUsageHours() const
{
    auto it = info_.properties.find(PROPERTY_MAX_USAGE_HOURS);
    if (it != info_.properties.end())
    {
        return std::stoi(it->second);
    }
    return 0;
}

int TrialLicense::getCurrentUsageHours() const
{
    auto it = info_.properties.find(PROPERTY_CURRENT_USAGE_HOURS);
    if (it != info_.properties.end())
    {
        return std::stoi(it->second);
    }
    return 0;
}
