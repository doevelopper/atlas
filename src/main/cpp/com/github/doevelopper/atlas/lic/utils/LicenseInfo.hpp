
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LIC_UTILS_LICENSEINFO_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LIC_UTILS_LICENSEINFO_HPP

#include <com/github/doevelopper/atlas/lic/interface/ITypes.hpp>

namespace com::github::doevelopper::atlas::lic::utils
{
    /**
     * @brief Data structure representing license information
     *
     * This struct is used to create or load license data.
     */
    class LicenseInfo
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:
        LicenseInfo() noexcept;
        LicenseInfo(const LicenseInfo&) noexcept = default;
        LicenseInfo(LicenseInfo&&) noexcept =  default;
        LicenseInfo& operator=(const LicenseInfo&) noexcept = default;
        LicenseInfo& operator=(LicenseInfo&&) noexcept = default;
        virtual ~LicenseInfo() noexcept;

        [[nodiscard]] const std::string & id() const;
        void id(const std::string & id);
        [[nodiscard]] const std::string & userId() const;
        void userId(const std::string & user_id);
        [[nodiscard]] const com::github::doevelopper::atlas::lic::interface::LicenseType & type() const;
        void type(const com::github::doevelopper::atlas::lic::interface::LicenseType & type);
        [[nodiscard]] const std::chrono::system_clock::time_point & issueDate() const;
        void issueDate(const std::chrono::system_clock::time_point & issue_date);
        [[nodiscard]] const std::chrono::system_clock::time_point & expirationDate() const;
        void expirationDate(const std::chrono::system_clock::time_point & expiration_date);
        [[nodiscard]] const std::string & boundHardwareId() const;
        void boundHardwareId(const std::string & bound_hardware_id);
        [[nodiscard]] const std::vector<std::string> & enabledFeatures() const;
        void enabledFeatures(const std::vector<std::string> & enabled_features);
        [[nodiscard]] const std::unordered_map<std::string, std::string> & properties() const;
        void properties(const std::unordered_map<std::string, std::string> & properties);
        [[nodiscard]] const std::chrono::seconds & gracePeriod() const;
        void gracePeriod(const std::chrono::seconds & grace_period);

        // Helper methods for common operations
        bool isExpired(const std::chrono::system_clock::time_point& now) const;
        bool isInGracePeriod(const std::chrono::system_clock::time_point& now) const;
        std::chrono::seconds getRemainingGraceTime(const std::chrono::system_clock::time_point& now) const;
    protected:
    private:
        std::string m_id;                                      ///< Unique license identifier
        std::string m_userId;                                  ///< User ID or name
        com::github::doevelopper::atlas::lic::interface::LicenseType m_type; ///< Type of license
        std::chrono::system_clock::time_point m_issueDate;     ///< Date when license was issued
        std::chrono::system_clock::time_point m_expirationDate; ///< Expiration date (if applicable)
        std::string m_boundHardwareId;                         ///< Hardware ID (if node-locked)
        std::vector<std::string> m_enabledFeatures;            ///< Features enabled by this license
        std::unordered_map<std::string, std::string> m_properties; ///< Custom properties
        std::chrono::seconds m_gracePeriod{0};                 ///< Grace period duration
    };
}
#endif
