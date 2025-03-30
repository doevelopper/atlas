
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LIC_INTERFACE_IVALIDATOR_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LIC_INTERFACE_IVALIDATOR_HPP

#include <string>

#include <com/github/doevelopper/atlas/lic/interface/ILicense.hpp>

namespace com::github::doevelopper::atlas::lic::interface
{
    /**
     * @brief Interface for license validation
     *
     * Responsible for validating licenses against various criteria.
     */
    class IValidator
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
 public:
        IValidator() noexcept;
        IValidator(const IValidator&) noexcept = default;
        IValidator(IValidator&&) noexcept =  default;
        IValidator& operator=(const IValidator&) noexcept = default;
        IValidator& operator=(IValidator&&) noexcept = default;
        virtual ~IValidator() noexcept;

        /**
         * @brief Validates a license
         * @param license The license to validate
         * @return Status of the license
         */
        virtual LicenseStatus validate(const ILicensePtr& license) = 0;

        /**
         * @brief Validates a license and returns detailed validation results
         * @param license The license to validate
         * @return Vector of validation messages (empty if validation successful)
         */
        virtual std::vector<std::string> validateWithDetails(const ILicensePtr& license) = 0;

    protected:
    private:
    };
    // Smart pointer type for Validator objects
    using IValidatorPtr = std::shared_ptr<IValidator>;
}
#endif
