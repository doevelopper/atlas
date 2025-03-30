#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LIC_IINTERFACE_ACTIVATOR_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LIC_INTERFACE_IACTIVATOR_HPP

#include <com/github/doevelopper/atlas/lic/interface/ILicense.hpp>

namespace com::github::doevelopper::atlas::lic::interface
{
    /**
     * @brief Result of an activation attempt
     */
    struct ActivationResult
    {
        bool success;                ///< Whether activation was successful
        std::string message;         ///< Informational message about activation result
        ILicensePtr license;          ///< Activated license (if successful)
    };
    /**
     * @brief Interface for license activation
     *
     * Responsible for activating licenses through various methods.
     */
    class IActivator
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
 public:
        IActivator() noexcept;
        IActivator(const IActivator&) noexcept = default;
        IActivator(IActivator&&) noexcept =  default;
        IActivator& operator=(const IActivator&) noexcept = default;
        IActivator& operator=(IActivator&&) noexcept = default;
        virtual ~IActivator() noexcept;

        /**
         * @brief Activates a license using a key
         * @param activationKey The key to use for activation
         * @return Activation result
         */
        virtual ActivationResult activateWithKey(const std::string& activationKey) = 0;

        /**
         * @brief Activates a license using a key and user information
         * @param activationKey The key to use for activation
         * @param userId User identifier
         * @return Activation result
         */
        virtual ActivationResult activateWithKeyAndUser(
            const std::string& activationKey,
            const std::string& userId) = 0;

        /**
         * @brief Deactivates a license
         * @param license The license to deactivate
         * @return true if deactivation was successful, false otherwise
         */
        virtual bool deactivate(const ILicensePtr& license) = 0;

        /**
         * @brief Checks if online activation is available
         * @return true if online activation is available
         */
        virtual bool isOnlineActivationAvailable() = 0;

        /**
         * @brief Generates a request code for offline activation
         * @param activationKey The key to use for activation
         * @param userId User identifier
         * @return Request code string to be used for offline activation
         */
        virtual std::string generateOfflineActivationRequest(
            const std::string& activationKey,
            const std::string& userId) = 0;

        /**
         * @brief Activates using an offline response code
         * @param responseCode The response code from offline activation process
         * @return Activation result
         */
        virtual ActivationResult activateWithOfflineResponse( const std::string& responseCode) = 0;
    protected:
    private:
    };
    // Smart pointer type for Activator objects
    using IActivatorPtr = std::shared_ptr<IActivator>;
}
#endif
