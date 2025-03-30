
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LIC_INTERFACE_ILICENSE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LIC_INTERFACE_ILICENSE_HPP

#include <optional>
#include <string>

#include <com/github/doevelopper/atlas/logging/LoggingInitializer.hpp>
#include <com/github/doevelopper/atlas/lic/interface/ITypes.hpp>

namespace com::github::doevelopper::atlas::lic::interface
{
    /**
     * @brief Abstract base class for all license types
     *
     * Follows the Interface Segregation Principle by providing a focused interface
     * that derived classes must implement.
     */
    class ILicense
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
 public:
        ILicense() noexcept;
        ILicense(const ILicense&) noexcept = default;
        ILicense(ILicense&&) noexcept =  default;
        ILicense& operator=(const ILicense&) noexcept = default;
        ILicense& operator=(ILicense&&) noexcept = default;
        virtual ~ILicense() noexcept;

    /**
     * @brief Get the unique identifier for this license
     * @return License ID as string
     */
    virtual std::string getId() const = 0;

    /**
     * @brief Get the type of this license
     * @return LicenseType enum value
     */
    virtual LicenseType getType() const = 0;

    /**
     * @brief Check if the license is currently valid
     * @return Current license status
     */
    virtual LicenseStatus getStatus() const = 0;

    /**
     * @brief Get the user information associated with this license
     * @return User ID or name
     */
    virtual std::string getUser() const = 0;

    /**
     * @brief Get the issue date of the license
     * @return Time point when the license was issued
     */
    virtual std::chrono::system_clock::time_point getIssueDate() const = 0;

    /**
     * @brief Get the expiration date (if applicable)
     * @return Time point when the license expires, or max time for permanent licenses
     */
    virtual std::chrono::system_clock::time_point getExpirationDate() const = 0;

    /**
     * @brief Check if a specific feature is enabled by this license
     * @param featureName Name of the feature to check
     * @return true if feature is enabled, false otherwise
     */
    virtual bool isFeatureEnabled(const std::string& featureName) const = 0;

    /**
     * @brief Get all features enabled by this license
     * @return Vector of enabled feature names
     */
    virtual std::vector<std::string> getEnabledFeatures() const = 0;

    /**
     * @brief Get the hardware ID this license is bound to (if applicable)
     * @return Hardware ID string or empty string if not hardware-bound
     */
    virtual std::string getBoundHardwareId() const = 0;

    /**
     * @brief Get custom license properties
     * @return Map of property names to values
     */
    virtual std::unordered_map<std::string, std::string> getProperties() const = 0;

    /**
     * @brief Check if the license is in grace period
     * @return true if in grace period, false otherwise
     */
    virtual bool isInGracePeriod() const = 0;

    /**
     * @brief Get remaining grace period time
     * @return Remaining time in seconds, or 0 if not in grace period
     */
    virtual std::chrono::seconds getRemainingGraceTime() const = 0;
    protected:
    private:
    };
    using ILicensePtr = std::shared_ptr<ILicense>;
}
#endif
