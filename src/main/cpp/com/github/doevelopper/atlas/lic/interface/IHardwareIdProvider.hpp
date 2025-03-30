
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LIC_INTERFACE_IHARDWAREIDPROVIDER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LIC_INTERFACE_IHARDWAREIDPROVIDER_HPP

#include <optional>
#include <string>
#include <com/github/doevelopper/atlas/logging/LoggingInitializer.hpp>

namespace com::github::doevelopper::atlas::lic::interface
{
    /**
     * @brief Abstract base class for all license types
     *
     * Follows the Interface Segregation Principle by providing a focused interface
     * that derived classes must implement.
     */
    class IHardwareIdProvider
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
 public:
        IHardwareIdProvider() noexcept;
        IHardwareIdProvider(const IHardwareIdProvider&) noexcept = default;
        IHardwareIdProvider(IHardwareIdProvider&&) noexcept =  default;
        IHardwareIdProvider& operator=(const IHardwareIdProvider&) noexcept = default;
        IHardwareIdProvider& operator=(IHardwareIdProvider&&) noexcept = default;
        virtual ~IHardwareIdProvider() noexcept;
        /**
         * @brief Get a unique hardware identifier
         * @return Hardware ID string
         */
        virtual std::string getHardwareId() = 0;

        /**
         * @brief Get individual components used to generate hardware ID
         * @return Vector of component identifiers
         */
        virtual std::vector<std::string> getHardwareComponents() = 0;

        /**
         * @brief Check if current hardware matches the given hardware ID
         * @param hardwareId Hardware ID to check against
         * @return true if matching, false otherwise
         */
        virtual bool matchesHardwareId(const std::string& hardwareId) = 0;

        /**
         * @brief Get a fingerprint that's more stable across minor hardware changes
         *
         * Unlike getHardwareId(), this method generates an ID that's more tolerant
         * to minor hardware changes (like adding USB devices).
         *
         * @return Stable hardware fingerprint
         */
        virtual std::string getStableFingerprint() = 0;
    protected:
    private:

    };
}
#endif
