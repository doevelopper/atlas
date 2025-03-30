#include <algorithm>
#include <chrono>
#include <stdexcept>

#include <com/github/doevelopper/atlas/lic/LicenseManager.hpp>

using namespace com::github::doevelopper::atlas::lic;
using namespace com::github::doevelopper::atlas::lic::utils;

log4cxx::LoggerPtr LicenseManager::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.lic.LicenseManager"));

LicenseManager::LicenseManager() noexcept
    : m_initialized(false)
    , m_validator(nullptr)
    , m_activator(nullptr)
    , m_currentLicense(nullptr)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

LicenseManager::~LicenseManager() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

LicenseManager& LicenseManager::getInstance()
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    static LicenseManager instance;
    return instance;
}

void LicenseManager::initialize(interface::IValidatorPtr validator, interface::IActivatorPtr activator)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::lock_guard<std::mutex> lock(this->m_mutex);

    if (!validator)
    {
        throw std::invalid_argument("Validator cannot be null");
    }

    if (!activator)
    {
        throw std::invalid_argument("Activator cannot be null");
    }

    this->m_validator = validator;
    this->m_activator = activator;
    this->m_initialized = true;
}

bool LicenseManager::isInitialized() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::lock_guard<std::mutex> lock(this->m_mutex);
    return this->m_initialized;
}

interface::ActivationResult LicenseManager::activateLicense(const std::string& activationKey)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::lock_guard<std::mutex> lock(this->m_mutex);

    if (!this->m_initialized)
    {
        return {false, "License manager not initialized", nullptr};
    }

    interface::ActivationResult result = this->m_activator->activateWithKey(activationKey);

    if (result.success && result.license)
    {
        this->m_currentLicense = result.license;

        // Notify about status change
        if (this->m_statusChangeCallback)
        {
            this->m_statusChangeCallback(this->m_currentLicense->getStatus());
        }
    }

    return result;
}

interface::ActivationResult LicenseManager::activateLicense(
    const std::string& activationKey,
    const std::string& userId)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    std::lock_guard<std::mutex> lock(this->m_mutex);

    if (!this->m_initialized)
    {
        return {false, "License manager not initialized", nullptr};
    }

    interface::ActivationResult result = this->m_activator->activateWithKeyAndUser(activationKey, userId);

    if (result.success && result.license)
    {
        this->m_currentLicense = result.license;

        // Notify about status change
        if (this->m_statusChangeCallback)
        {
            this->m_statusChangeCallback(this->m_currentLicense->getStatus());
        }
    }

    return result;
}

interface::ILicensePtr LicenseManager::loadLicense(const std::string& licenseData)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // Implementation for loading license from serialized data
    // This would typically involve deserializing the data and validating it
    // For brevity, this implementation is omitted

    // Placeholder implementation
    return nullptr;
}

interface::ILicensePtr LicenseManager::getCurrentLicense() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::lock_guard<std::mutex> lock(this->m_mutex);
    return this->m_currentLicense;
}

interface::LicenseStatus LicenseManager::validateCurrentLicense()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::lock_guard<std::mutex> lock(this->m_mutex);

    if (!this->m_initialized)
    {
        return interface::LicenseStatus::Invalid;
    }

    if (!this->m_currentLicense)
    {
        return interface::LicenseStatus::Invalid;
    }

    interface::LicenseStatus status = this->m_validator->validate(this->m_currentLicense);

    // Notify about status change if needed
    if (this->m_statusChangeCallback && status != this->m_currentLicense->getStatus())
    {
        this->m_statusChangeCallback(status);
    }

    return status;
}

bool LicenseManager::isFeatureEnabled(const std::string& featureName) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::lock_guard<std::mutex> lock(this->m_mutex);

    if (!this->m_initialized || !this->m_currentLicense) {
        return false;
    }

    // Only check features if license is valid or in grace period
    interface::LicenseStatus status = this->m_currentLicense->getStatus();
    if (status != interface::LicenseStatus::Valid && status != interface::LicenseStatus::GracePeriod)
    {
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        return false;
    }

    return this->m_currentLicense->isFeatureEnabled(featureName);
}

void LicenseManager::setStatusChangeCallback( std::function<void(interface::LicenseStatus)> callback)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::lock_guard<std::mutex> lock(this->m_mutex);
    this->m_statusChangeCallback = callback;
}