
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_ITYPES_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_ITYPES_HPP

#include <optional>
#include <string>

#include <com/github/doevelopper/atlas/logging/LoggingInitializer.hpp>

namespace com::github::doevelopper::atlas::lic::interface
{

    /**
     * @brief Enum representing different license types
     */
    enum class LicenseType: std::uint8_t
    {
        Trial,        ///< Time-limited trial version
        Permanent,    ///< Permanent (perpetual) license
        Subscription, ///< Recurring subscription license
        NodeLocked,   ///< License locked to specific hardware
        Floating,     ///< License that can be shared among multiple users, Shared license with concurrent usage limits
        Node,         ///< License bound to specific hardware
        Volume,          // Multi-seat license for organizations
        Custom        ///< Customizable license with specific parameters
    };

    /**
     * @brief Enum representing license status
     */
    enum class LicenseStatus : std::uint8_t
    {
        Valid,             ///< License is valid and active
        Invalid,           ///< License is invalid (e.g., tampered with)
        Expired,           ///< License has expired
        GracePeriod,       ///< License has expired but in grace period
        NotActivated,      ///< License has not been activated yet
        ActivationExpired, ///< Activation has expired
        HardwareMismatch   ///< Hardware ID doesn't match the license
    };

    class ITypes
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
 public:
        ITypes() noexcept;
        ITypes(const ITypes&) noexcept = default;
        ITypes(ITypes&&) noexcept =  default;
        ITypes& operator=(const ITypes&) noexcept = default;
        ITypes& operator=(ITypes&&) noexcept = default;
        virtual ~ITypes() noexcept;
    protected:
    private:
    };
}
#endif
