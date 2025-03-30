#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LIC_LICENSE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LIC_LICENSE_HPP


#include <com/github/doevelopper/atlas/lic/utils/LicenseInfo.hpp>
#include <com/github/doevelopper/atlas/lic/interface/AbstractLicense.hpp>

namespace com::github::doevelopper::atlas::lic
{
    /**
     * @brief Base implementation of the License interface
     *
     * This class provides common functionality for all license types.
     */
    class License : AbstractLicense
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
 public:
        License() noexcept;
        License(const License&) noexcept = default;
        License(License&&) noexcept =  default;
        License& operator=(const License&) noexcept = default;
        License& operator=(License&&) noexcept = default;
        virtual ~License() noexcept;

        explicit License(const utils::LicenseInfo& info);

        // Implement License interface
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
        std::chrono::seconds getRemainingGraceTime() const override;
    protected:
    private:
        /**
         * @brief Update the cached license status
         * @return Current license status
         */
        virtual LicenseStatus updateStatus() const;

        utils::LicenseInfo m_info;
        mutable LicenseStatus m_cachedStatus;
        mutable std::chrono::system_clock::time_point m_lastStatusCheck;
    };

}
#endif
