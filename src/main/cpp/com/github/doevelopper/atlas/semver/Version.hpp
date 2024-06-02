
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_VERSION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_VERSION_HPP

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::semver
{
    class Version
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DISABLE_COPY_MOVE(Version)
    public:

        Version() noexcept;
        // Version(const Version &)             = delete;
        // Version(Version &&)                  = delete;
        // Version & operator=(const Version &) = delete;
        // Version & operator=(Version &&)      = delete;
        virtual ~Version() noexcept;

        Version(std::uint8_t major, std::uint8_t minor, std::uint8_t patch, const std::string& pre_release = "", const std::string& build_metadata = "") noexcept;
        explicit Version(const std::string& version) noexcept;

        // Comparison operators
        bool operator==(const Version& other) const;
        bool operator!=(const Version& other) const;
        bool operator<(const Version& other) const;
        bool operator<=(const Version& other) const;
        bool operator>(const Version& other) const;
        bool operator>=(const Version& other) const;
    protected:

    private:
        std::uint8_t m_major;
        std::uint8_t m_minor;
        std::uint8_t m_patch;
        std::string m_pre_release;
        std::string m_build_metadata;
    };
}
#endif