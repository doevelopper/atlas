#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LIC_TRIALLICENSE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LIC_TRIALLICENSE_HPP

#include <com/github/doevelopper/atlas/lic/ILicense.hpp>
#include <com/github/doevelopper/atlas/lic/utils/LicenseInfo.hpp>

#include "AbstractLicense.hpp"

namespace com::github::doevelopper::atlas::lic
{
    /**
     * @brief Trial license implementation
     *
     * A time-limited license for trial purposes.
     */
    class TrialLicense : AbstractLicense
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
 public:
        TrialLicense() noexcept;
        TrialLicense(const TrialLicense&) noexcept = default;
        TrialLicense(TrialLicense&&) noexcept =  default;
        TrialLicense& operator=(const TrialLicense&) noexcept = default;
        TrialLicense& operator=(TrialLicense&&) noexcept = default;
        virtual ~TrialLicense() noexcept;

        /**
         * @brief Construct a new Trial License
         * @param info License information
         */
        explicit TrialLicense(const utils::LicenseInfo& info);

        /**
         * @brief Factory method to create a trial license
         * @param userId User identifier
         * @param durationDays Duration of trial in days
         * @param features Features to enable in the trial
         * @return Shared pointer to created license
         */
        static ILicensePtr create(
            const std::string& userId,
            int durationDays,
            const std::vector<std::string>& features = {});

    protected:
        /**
         * @brief Update the cached license status
         * @return Current license status
         */
        LicenseStatus updateStatus() const override;

        /**
         * @brief Get maximum allowed usage time
         * @return Maximum usage time in hours
         */
        int getMaxUsageHours() const;

        /**
         * @brief Get current usage time
         * @return Current usage in hours
         */
        int getCurrentUsageHours() const;
    private:
        static const std::string PROPERTY_MAX_USAGE_HOURS;
        static const std::string PROPERTY_CURRENT_USAGE_HOURS;
    };

}
#endif
