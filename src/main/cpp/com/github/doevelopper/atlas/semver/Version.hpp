
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_VERSION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_VERSION_HPP

#include <optional>

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
        STABLE          = 0,        /**< None (stable) */
        ALPHA           = 1,         /**< API is in alpha state, i.e. work in progress. */
        BETA            = 2,        /**< API is in beta state, i.e. close to be finished. */
        CANDIDATE       = 3,        /**< API is in release candidate state. */
        PREVIEW         = 4,        /**< preview */
        DEV             = 5,        /**< dev */
        NIGHTLY         = 6,        /**< nightly */
        EXPERIMENTAL    = 7,        /**< experimental */
        CUSTOM          = 8,        /**< custom (8-255) */
        // Existing entries from the original enum, adjusted to fit the new scheme:
        SNAPSHOOT       = 0xD,      /**< API is not tested, work in progress. (part of custom range) */
        FINAL           = 0xF       /**< API is in final state, i.e. officially approved. (part of custom range) */
    };

    class Version
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DISABLE_COPY_MOVE(Version)

        // Bit masks for each component
        static constexpr uint64_t MAJOR_MASK            = 0xFF00000000000000;
        static constexpr uint64_t MINOR_MASK            = 0x00FF000000000000;
        static constexpr uint64_t PATCH_MASK            = 0x0000FF0000000000;
        static constexpr uint64_t PRERELEASE_MASK       = 0x000000FF00000000;
        static constexpr uint64_t PRERELEASE_COUNT_MASK = 0x00000000FF000000;
        static constexpr uint64_t BUILD_METADATA_MASK   = 0x0000000000FF0000;
        static constexpr uint64_t BUILD_COUNT_MASK      = 0x000000000000FF00;
        static constexpr uint64_t ADDITIONAL_FLAGS_MASK = 0x00000000000000FF;

        // Shift constants for each component's bit position
        static constexpr int MAJOR_SHIFT                = 56;
        static constexpr int MINOR_SHIFT                = 48;
        static constexpr int PATCH_SHIFT                = 40;
        static constexpr int PRE_RELEASE_SHIFT          = 32;
        static constexpr int PRE_RELEASE_COUNT_SHIFT    = 24;
        static constexpr int BUILD_METADATA_SHIFT       = 16;
        static constexpr int BUILD_COUNT_SHIFT          = 8;
        static constexpr int ADDITIONAL_FLAGS_SHIFT     = 0;
    public:

        // Exception class for version parsing errors
        class VersionException : public std::runtime_error
        {
        public:
            explicit VersionException(const std::string& message)
                : std::runtime_error(message) {}
        };

        Version() noexcept;
        // Version(const Version &)             = delete;
        // Version(Version &&)                  = delete;
        // Version & operator=(const Version &) = delete;
        // Version & operator=(Version &&)      = delete;
        virtual ~Version() noexcept;
        /*!
         * @brief Constructor with explicit version number
         * @param version The 64-bit version number
         */
        explicit Version(std::uint64_t value);
        /*!
         * @brief Constructor with individual components
         * @param major Major version number
         * @param minor Minor version number
         * @param patch Patch version number
         * @param preRelease Pre-release identifier
         * @param preReleaseCount Pre-release count
         * @param buildMetadata Build metadata identifier
         * @param buildCount Build count
         * @param additionalFlags Additional flags
         */
        Version(std::uint8_t major, std::uint8_t minor, std::uint8_t patch,
                std::uint8_t preRelease, std::uint8_t preReleaseCount,
                std::uint8_t buildMetadata, std::uint8_t buildCount,
                std::uint8_t additionalFlags) noexcept;

        // Version(std::uint8_t major
        //         , std::uint8_t minor
        //         , std::uint8_t patch
        //         , const std::string& pre_release = ""
        //         , const std::string& build_metadata = "") noexcept;
        // explicit Version(const std::string& version) noexcept;
        // Version(std::uint8_t major
        //     , std::uint8_t minor
        //     , std::uint8_t patch
        //     , std::uint8_t preRelease
        //     , std::uint8_t preReleaseCount
        //     , std::uint8_t buildMetadata
        //     , std::uint8_t buildCount
        //     , std::uint8_t flags) noexcept;
        // Version(int major
        //     , int minor
        //     , int patch
        //     , std::optional<std::string> preRelease = std::nullopt
        //     , std::optional<std::string> build = std::nullopt);

        /*!
         * @brief Sets the raw 64-bit version number
         * @param version The new version number
         */
        auto rawVersion(std::uint64_t version) -> void;

        /*!
         * @brief Gets the raw 64-bit version number
         * @return uint64_t The raw version number
         */
        [[nodiscard]] auto rawVersion() const -> std::uint64_t;


        [[nodiscard]] std::uint8_t major() const;
        void major(const std::uint8_t major);
        [[nodiscard]] std::uint8_t minor() const;
        void minor(const std::uint8_t minor);
        [[nodiscard]] std::uint8_t patch() const;
        void patch(const std::uint8_t patch);

        void preRelease(std::uint8_t preRelease);
        [[nodiscard]] std::uint8_t preRelease() const;
        void preReleaseCount(std::uint8_t preReleaseCount);
        [[nodiscard]] std::uint8_t preReleaseCount() const;
        void buildMetadata(std::uint8_t buildMetadata);
        [[nodiscard]] std::uint8_t buildMetadata() const;
        void buildCount(std::uint8_t buildCount);
        [[nodiscard]] std::uint8_t buildCount() const;
        void additionalFlags(std::uint8_t additionalFlags);
        [[nodiscard]] std::uint8_t additionalFlags() const;

        std::string toString() const;
        std::string fullVersionFromString() const;
        /*!
         * @brief Compare this version with another version
         * @param other The other version to compare with
         * @return int Negative if this < other, 0 if equal, positive if this > other
         */
        int compare(const Version& other) const;

        /**
         * @brief Convert version to hex string representation
         * @return std::string The version as a hex string
         */
        std::string toHexString() const;

        // Comparison operators
        bool operator==(const Version& other) const {
            return compare(other) == 0;
        }

        bool operator!=(const Version& other) const {
            return compare(other) != 0;
        }

        bool operator<(const Version& other) const {
            return compare(other) < 0;
        }

        bool operator<=(const Version& other) const {
            return compare(other) <= 0;
        }

        bool operator>(const Version& other) const {
            return compare(other) > 0;
        }

        bool operator>=(const Version& other) const {
            return compare(other) >= 0;
        }

        // [[nodiscard]] std::uint8_t tweak() const;
        // void tweak(const std::uint8_t tweak);
        // [[nodiscard]] ReleaseLevel get_m_release_type() const;
        // void set_m_release_type(const ReleaseLevel release_type);
        //
        // std::uint64_t value() const { return m_value; }
        // std::string getPreRelease() const;
        // std::string getBuild() const;
        // // Returns the full version string
        // std::string toString() const;
        //
        // std::string toSemVer() const;
        // Version fromSemVer(const std::string& semver);
        // // Returns the 64-bit numerical representation
        // std::uint64_t toNumericalValue() const;
        // // Compares this version with another based on SemVer precedence
        // int compare(const Version& other) const;
    protected:

    private:
        std::uint64_t m_hex_version;

        auto bits(int highBit, int lowBit, std::uint8_t value) -> void;
        auto bits(int highBit, int lowBit) const -> std::uint8_t;

        std::string releaseLevelToString(ReleaseLevel level);

        // // Helper to split a string by a delimiter
        // std::vector<std::string> split(const std::string& s, char delimiter) const;
        // std::uint8_t encodePreReleaseIdentifier(const std::string& id, size_t index) const;
        // void validateNumeric(const std::string& num, const std::string& field) const;
        // std::uint8_t computePreReleaseValue() const;
        // std::uint8_t computePreReleaseCount() const;
        // std::uint8_t computeBuildMetadata() const;
        // std::uint8_t computeBuildCount() const;
        // std::uint8_t computeFlags() const;
        // clang-format off
        std::uint8_t m_major;           ///< Major version, change only on incompatible API modifications.
        std::uint8_t m_minor;           ///< Minor version, change on backwards-compatible API modifications.
        std::uint8_t m_patch;           ///< Patch version, change only on bugfixes.
        // std::uint8_t m_tweak;           ///< CI Build Identification.
        // ReleaseLevel m_releaseType;     ///< Release identification.
        // std::string m_pre_release;
        // std::string m_extra;            ///< GI sha1
        // std::string m_build;
        // std::string m_build_metadata;   ///< Major.Minor.Patch-[RC|Alpha|...]-Build[0-9]
        // std::ostringstream oss;
        // std::uint64_t m_value;
        // clang-format on
    };
}
#endif