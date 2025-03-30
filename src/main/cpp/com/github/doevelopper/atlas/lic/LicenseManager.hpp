#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LIC_LICENSEMANAGER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LIC_LICENSEMANAGER_HPP

#include <memory>
#include <mutex>
#include <vector>
#include <string>
#include <functional>

#include <com/github/doevelopper/atlas/lic/interface/IActivator.hpp>
#include <com/github/doevelopper/atlas/lic/interface/IValidator.hpp>
#include <com/github/doevelopper/atlas/lic/interface/AbstractLicense.hpp>

namespace com::github::doevelopper::atlas::lic
{
/**
 * @brief Singleton class for managing licenses
 *
 * This class is the main entry point for the license framework.
 * It provides methods for activating, validating, and managing licenses.
 */
class LicenseManager
{
    LOG4CXX_DECLARE_STATIC_LOGGER
public:
    /**
     * @brief Get the singleton instance
     * @return Reference to the LicenseManager instance
     */
    static LicenseManager& getInstance();

    // Prevent copying or moving the singleton
    LicenseManager(const LicenseManager&) = delete;
    LicenseManager& operator=(const LicenseManager&) = delete;
    LicenseManager(LicenseManager&&) = delete;
    LicenseManager& operator=(LicenseManager&&) = delete;
    ~LicenseManager() noexcept;

    /**
     * @brief Initialize the license manager
     * @param validator Validator to use for license validation
     * @param activator Activator to use for license activation
     */
    void initialize(interface::IValidatorPtr validator, interface::IActivatorPtr activator);

    /**
     * @brief Check if the license manager is initialized
     * @return true if initialized, false otherwise
     */
    bool isInitialized() const;

    /**
     * @brief Activate a license with a key
     * @param activationKey The key to use for activation
     * @return Activation result
     */
    interface::ActivationResult activateLicense(const std::string& activationKey);

    /**
     * @brief Activate a license with a key and user info
     * @param activationKey The key to use for activation
     * @param userId User identifier
     * @return Activation result
     */
    interface::ActivationResult activateLicense(
        const std::string& activationKey,
        const std::string& userId);

    /**
     * @brief Load an existing license
     * @param licenseData Serialized license data
     * @return Loaded license or nullptr if loading failed
     */
    interface::ILicensePtr loadLicense(const std::string& licenseData);

    /**
     * @brief Get the current active license
     * @return Currently active license or nullptr if no license is active
     */
    interface::ILicensePtr getCurrentLicense() const;

    /**
     * @brief Validate the current license
     * @return License status
     */
    interface::LicenseStatus validateCurrentLicense();

    /**
     * @brief Check if a specific feature is enabled
     * @param featureName Name of the feature to check
     * @return true if feature is enabled in the current license, false otherwise
     */
    bool isFeatureEnabled(const std::string& featureName) const;

    /**
     * @brief Set a callback to be called when license status changes
     * @param callback Function to call on status change
     */
    void setStatusChangeCallback(
        std::function<void(interface::LicenseStatus)> callback);

private:
    // Private constructor for singleton
    LicenseManager() noexcept;

    // Internal state
    bool m_initialized{false};
    interface::IValidatorPtr m_validator;
    interface::IActivatorPtr m_activator;
    interface::ILicensePtr m_currentLicense;
    mutable std::mutex m_mutex;
    std::function<void(interface::LicenseStatus)> m_statusChangeCallback;
};
}
#endif
