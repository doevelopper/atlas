
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_VERSION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_VERSION_HPP

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>
#include <com/github/doevelopper/atlas/semver/GitRevision.hpp>

namespace com::github::doevelopper::atlas::semver
{
    constexpr int LSL = -1;
    constexpr int ESL = 0;
    constexpr int USL = 1;
    /*!
     * @brief ReleaseLevel indicates the release level of this API
     *          This enum follows the release level convention used by python.
     * @ref https://docs.python.org/3/c-api/apiabiversion.html
     * @ref https://docs.python.org/3.7/c-api/apiabiversion.html
     * @ref https://hg.python.org/cpython/file/3.6/Include/patchlevel.h
     */

    enum class ReleaseLevel : std::uint8_t
    {
        SNAPSHOOT = 0xD, /**< API is not tested, work in progress. */
        ALPHA     = 0xA, /**< API is in alpha state, i.e. work in progress. */
        BETA      = 0xB, /**< API is in beta state, i.e. close to be finished. */
        CANDIDATE = 0xC, /**< API is in release candidate state. */
        FINAL     = 0xF, /**< API is in final state, i.e. officially approved. */
    };

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
        // clang-format off
        std::uint8_t m_major;           ///< Major version, change only on incompatible API modifications.
        std::uint8_t m_minor;           ///< Minor version, change on backwards-compatible API modifications.
        std::uint8_t m_patch;           ///< Patch version, change only on bugfixes.
        std::uint8_t m_tweak;           ///< CI Build Identification.
        ReleaseLevel m_releaseType;     ///< Release identification.
        std::string m_pre_release;
        std::string m_extra;            ///< GI sha1
        std::string m_build_metadata;   ///< Major.Minor.Patch-[RC|Alpha|...]-Build[0-9]
        std::ostringstream oss;
        // clang-format on
    };
}
#endif