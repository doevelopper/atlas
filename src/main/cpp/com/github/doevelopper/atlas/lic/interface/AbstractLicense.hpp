
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LIC_INTERFACE_ABSTRACTLICENSE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LIC_INTERFACE_ABSTRACTLICENSE_HPP

#include <com/github/doevelopper/atlas/lic/interface/ILicense.hpp>
#include <com/github/doevelopper/atlas/lic/utils/LicenseInfo.hpp>

namespace com::github::doevelopper::atlas::lic::interface
{

    /**
     * @brief Base implementation of the License interface
     *
     * This class provides common functionality for all license types.
     */
    class AbstractLicense : ILicense
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
 public:
        AbstractLicense() noexcept;
        AbstractLicense(const AbstractLicense&) noexcept = default;
        AbstractLicense(AbstractLicense&&) noexcept =  default;
        AbstractLicense& operator=(const AbstractLicense&) noexcept = default;
        AbstractLicense& operator=(AbstractLicense&&) noexcept = default;
        ~AbstractLicense() noexcept override;

        /**
         * @brief Construct a new Base License
         * @param info License information
         */
        explicit AbstractLicense(const utils::LicenseInfo& info);

        std::string getId() const override;
        LicenseType getType() const override;
        LicenseStatus getStatus() const override;
        std::string getUser() const override;
        std::chrono::system_clock::time_point getIssueDate() const override;
        std::chrono::system_clock::time_point getExpirationDate() const override;
        bool isFeatureEnabled(const std::string& featureName) const override;
        std::vector<std::string> getEnabledFeatures() const override;
        std::string getBoundHardwareId() const override;
        std::unordered_map<std::string, std::string> getProperties() const override;
        bool isInGracePeriod() const override;
    protected:
        utils::LicenseInfo info_;
        mutable LicenseStatus cachedStatus_;
        mutable std::chrono::system_clock::time_point lastStatusCheck_;

        /**
         * @brief Update the cached license status
         * @return Current license status
         */
        virtual LicenseStatus updateStatus() const;
    private:

    };
}
#endif
