
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_VERSION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_VERSION_HPP

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>
#include <com/github/doevelopper/atlas/semver/GitRevision.hpp>


/*
* These helper macros generate a numerical and alphanumerical (see http://www.semver.org) representation of the library
* version number, i.e
*
To address the limitations mentioned earlier, we'll need to expand the bit size from 32 bits to something larger, like 64 bits, to accommodate more significant versions and metadata. Here's a suggested table for mapping Semantic Versioning (SemVer) strings to 64-bit numerical values:

* | Component	        |  Bit Position	|    Range
* |-------------------------------------|-------------
* | Major Version	|    63-56	|    0x00-0xFF
* | Minor Version	|    55-48	|    0x00-0xFF
* | Patch Version	|    47-40	|    0x00-0xFF
* | Pre-release	        |    39-32	|    0x00-0xFF
* | Pre-release Count	|    31-24	|    0x00-0xFF
* | Build Metadata	|    23-16	|    0x00-0xFF
* | Build Count	        |    15-08	|    0x00-0xFF
* | Additional Flags	|    07-00	|    0x00-0xFF


* | SemVer	                        |     64-Bit Value    |   Description
* |-------------------------------------|--------------------------
* | 0.0.1	                        | 0x0000000000000001  | Initial release
* | 0.2.1	                        | 0x000000000000001F  | Minor update
* | 1.0.0-alpha	                        | 0x0100000000000001  | First alpha release
* | 1.0.0-alpha1                        | 0x0100000000000002  | Second alpha release
* | 1.0.0                               | 0x01000000000000FF  | Major release
* | 1.0.1                               | 0x01000000000001FF  | Minor update
* | 1.3.7+build.2.b8f12d7               | 0x0103000700020303  | Build with commit hash
* | 1.3.7+build.11.e0f985a              | 0x01030007000B0311  | Build with commit hash
* | 2.1.0	                        | 0x02010000000000FF  | Final
* | 2.1.1-beta                          | 0x0201010000000002  | First pre-release
* | 2.1.1	                        | 0x02010100000000FF  | Final
* | 2.1.1-alpha	                        | 0x0201010000000001  | First alpha release
* | 2.1.1-alpha.1                       | 0x0201010000000002  | Second alpha release
* | 2.1.1-beta.1                        | 0x0201010000000003  | First beta release
* | 2.1.1-rc1                           | 0x0201010000000003  | First release candidate
* | 2.1.1-fresh	                        | 0x0201010000000004  | Fresh release (no changes)
* | 2.1.1-hotfix                        | 0x0201010000000005  | Hotfix release
* | 2.1.1-hotfix.1                      | 0x0201010000000006  | First hotfix release
* | 2.2.0	                        | 0x02020000000000FF  | Final
* | 2.2.0-rc.1-rc1-7de458254-dirty      | 0x0202000000010112  | Release candidate with commit hash and dirty flag
*/

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

        [[nodiscard]] std::uint8_t get_m_major() const;
        void set_m_major(const std::uint8_t major);
        [[nodiscard]] std::uint8_t get_m_minor() const;
        void set_m_minor(const std::uint8_t minor);
        [[nodiscard]] std::uint8_t get_m_patch() const;
        void set_m_patch(const std::uint8_t patch);
        [[nodiscard]] std::uint8_t get_m_tweak() const;
        void set_m_tweak(const std::uint8_t tweak);
        [[nodiscard]] ReleaseLevel get_m_release_type() const;
        void set_m_release_type(const ReleaseLevel release_type);

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