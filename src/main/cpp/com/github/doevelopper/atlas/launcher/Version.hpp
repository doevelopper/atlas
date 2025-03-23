#ifndef VERSION_H
#define VERSION_H

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <regex>
#include <log4cxx/logger.h>

namespace com::github::doevelopper::atlas::launcher
{
    /**
     * @class Version
     * @brief Represents a semantic version with major, minor, patch, and build components.
     *
     * The Version class implements semantic versioning functionality, allowing
     * for parsing, comparison, and manipulation of version strings in the format
     * major.minor.patch.build or major.minor.patch-buildMetadata.
     */
    class Version {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:
        /**
         * @brief Default constructor
         *
         * Initializes version to 0.0.0.0
         */
        Version() :
            major_(0),
            minor_(0),
            patch_(0),
            build_(0),
            buildMetadata_() {
            LOG4CXX_DEBUG(logger, "Created default Version (0.0.0.0)");
        }

        /**
         * @brief Constructor with version components
         *
         * @param major Major version number
         * @param minor Minor version number
         * @param patch Patch version number
         * @param build Build version number
         */
        Version(unsigned int major, unsigned int minor, unsigned int patch, unsigned int build = 0) :
            major_(major),
            minor_(minor),
            patch_(patch),
            build_(build),
            buildMetadata_() {
            LOG4CXX_DEBUG(logger, "Created Version " << major << "." << minor << "." << patch << "." << build);
        }

        /**
         * @brief Constructor from version string
         *
         * @param versionStr Version string in format "major.minor.patch.build" or "major.minor.patch-buildMetadata"
         * @throw std::invalid_argument If the version string format is invalid
         */
        explicit Version(const std::string& versionStr) {
            try {
                if (versionStr.empty()) {
                    throw std::invalid_argument("Version string cannot be empty");
                }

                parseVersionString(versionStr);
                LOG4CXX_DEBUG(logger, "Created Version from string: " << versionStr);
            } catch (const std::exception& e) {
                LOG4CXX_ERROR(logger, "Error creating Version from string: " << versionStr << ". " << e.what());
                throw;
            }
        }

        /**
         * @brief Copy constructor
         *
         * @param other The Version object to copy
         */
        Version(const Version& other) :
            major_(other.major_),
            minor_(other.minor_),
            patch_(other.patch_),
            build_(other.build_),
            buildMetadata_(other.buildMetadata_) {
            LOG4CXX_DEBUG(logger, "Copied Version " << other.toString());
        }

        /**
         * @brief Move constructor
         *
         * @param other The Version object to move
         */
        Version(Version&& other) noexcept :
            major_(std::exchange(other.major_, 0)),
            minor_(std::exchange(other.minor_, 0)),
            patch_(std::exchange(other.patch_, 0)),
            build_(std::exchange(other.build_, 0)),
            buildMetadata_(std::move(other.buildMetadata_)) {
            LOG4CXX_DEBUG(logger, "Moved Version " << toString());
        }

        /**
         * @brief Destructor
         */
        ~Version() {
            LOG4CXX_DEBUG(logger, "Destroyed Version " << toString());
        }

        /**
         * @brief Copy assignment operator
         *
         * @param other The Version object to copy
         * @return Reference to this Version
         */
        Version& operator=(const Version& other) {
            if (this != &other) {
                major_ = other.major_;
                minor_ = other.minor_;
                patch_ = other.patch_;
                build_ = other.build_;
                buildMetadata_ = other.buildMetadata_;
                LOG4CXX_DEBUG(logger, "Assigned Version " << other.toString());
            }
            return *this;
        }

        /**
         * @brief Move assignment operator
         *
         * @param other The Version object to move
         * @return Reference to this Version
         */
        Version& operator=(Version&& other) noexcept {
            if (this != &other) {
                major_ = std::exchange(other.major_, 0);
                minor_ = std::exchange(other.minor_, 0);
                patch_ = std::exchange(other.patch_, 0);
                build_ = std::exchange(other.build_, 0);
                buildMetadata_ = std::move(other.buildMetadata_);
                LOG4CXX_DEBUG(logger, "Move-assigned Version " << toString());
            }
            return *this;
        }

        /**
         * @brief Convert version to string
         *
         * @return Version string in format "major.minor.patch.build" or "major.minor.patch-buildMetadata"
         */
        std::string toString() const {
            std::ostringstream oss;
            oss << major_ << "." << minor_ << "." << patch_;

            if (!buildMetadata_.empty()) {
                oss << "-" << buildMetadata_;
            } else if (build_ > 0) {
                oss << "." << build_;
            }

            return oss.str();
        }

        /**
         * @brief Get major version component
         *
         * @return Major version number
         */
        unsigned int getMajor() const {
            return major_;
        }

        /**
         * @brief Get minor version component
         *
         * @return Minor version number
         */
        unsigned int getMinor() const {
            return minor_;
        }

        /**
         * @brief Get patch version component
         *
         * @return Patch version number
         */
        unsigned int getPatch() const {
            return patch_;
        }

        /**
         * @brief Get build version component
         *
         * @return Build version number
         */
        unsigned int getBuild() const {
            return build_;
        }

        /**
         * @brief Get build metadata
         *
         * @return Build metadata string
         */
        std::string getBuildMetadata() const {
            return buildMetadata_;
        }

        /**
         * @brief Set major version component
         *
         * @param major Major version number
         */
        void setMajor(unsigned int major) {
            major_ = major;
        }

        /**
         * @brief Set minor version component
         *
         * @param minor Minor version number
         */
        void setMinor(unsigned int minor) {
            minor_ = minor;
        }

        /**
         * @brief Set patch version component
         *
         * @param patch Patch version number
         */
        void setPatch(unsigned int patch) {
            patch_ = patch;
        }

        /**
         * @brief Set build version component
         *
         * @param build Build version number
         */
        void setBuild(unsigned int build) {
            build_ = build;
        }

        /**
         * @brief Set build metadata
         *
         * @param metadata Build metadata string
         */
        void setBuildMetadata(const std::string& metadata) {
            buildMetadata_ = metadata;
        }

        /**
         * @brief Increment major version
         *
         * Increments major version and resets minor, patch, and build to 0
         */
        void incrementMajor() {
            ++major_;
            minor_ = 0;
            patch_ = 0;
            build_ = 0;
            buildMetadata_.clear();
        }

        /**
         * @brief Increment minor version
         *
         * Increments minor version and resets patch and build to 0
         */
        void incrementMinor() {
            ++minor_;
            patch_ = 0;
            build_ = 0;
            buildMetadata_.clear();
        }

        /**
         * @brief Increment patch version
         *
         * Increments patch version and resets build to 0
         */
        void incrementPatch() {
            ++patch_;
            build_ = 0;
            buildMetadata_.clear();
        }

        /**
         * @brief Increment build version
         *
         * Increments build version
         */
        void incrementBuild() {
            ++build_;
            buildMetadata_.clear();
        }

        /**
         * @brief Equality operator
         *
         * @param other Version to compare with
         * @return true if versions are equal, false otherwise
         */
        bool operator==(const Version& other) const {
            return major_ == other.major_ &&
                   minor_ == other.minor_ &&
                   patch_ == other.patch_ &&
                   build_ == other.build_;
            // Note: buildMetadata is deliberately excluded from equality comparison per SemVer
        }

        /**
         * @brief Inequality operator
         *
         * @param other Version to compare with
         * @return true if versions are not equal, false otherwise
         */
        bool operator!=(const Version& other) const {
            return !(*this == other);
        }

        /**
         * @brief Less than operator
         *
         * @param other Version to compare with
         * @return true if this version is less than other, false otherwise
         */
        bool operator<(const Version& other) const {
            if (major_ != other.major_) {
                return major_ < other.major_;
            }
            if (minor_ != other.minor_) {
                return minor_ < other.minor_;
            }
            if (patch_ != other.patch_) {
                return patch_ < other.patch_;
            }
            return build_ < other.build_;
            // Note: buildMetadata is deliberately excluded from comparison per SemVer
        }

        /**
         * @brief Greater than operator
         *
         * @param other Version to compare with
         * @return true if this version is greater than other, false otherwise
         */
        bool operator>(const Version& other) const {
            return other < *this;
        }

        /**
         * @brief Less than or equal operator
         *
         * @param other Version to compare with
         * @return true if this version is less than or equal to other, false otherwise
         */
        bool operator<=(const Version& other) const {
            return !(other < *this);
        }

        /**
         * @brief Greater than or equal operator
         *
         * @param other Version to compare with
         * @return true if this version is greater than or equal to other, false otherwise
         */
        bool operator>=(const Version& other) const {
            return !(*this < other);
        }

    private:
        /**
         * @brief Parse a version string into components
         *
         * @param versionStr The version string to parse
         * @throw std::invalid_argument If the version string format is invalid
         */
        void parseVersionString(const std::string& versionStr) {
            try {
                // Define regex patterns for two version formats
                std::regex numericPattern(R"(^(\d+)\.(\d+)\.(\d+)(?:\.(\d+))?$)");
                std::regex semverPattern(R"(^(\d+)\.(\d+)\.(\d+)(?:-([0-9A-Za-z\-.]+))?$)");

                std::smatch matches;

                // Try numeric pattern first (major.minor.patch.build)
                if (std::regex_match(versionStr, matches, numericPattern)) {
                    major_ = std::stoul(matches[1].str());
                    minor_ = std::stoul(matches[2].str());
                    patch_ = std::stoul(matches[3].str());
                    build_ = matches[4].matched ? std::stoul(matches[4].str()) : 0;
                    buildMetadata_.clear();
                    return;
                }

                // Try SemVer pattern (major.minor.patch-buildMetadata)
                if (std::regex_match(versionStr, matches, semverPattern)) {
                    major_ = std::stoul(matches[1].str());
                    minor_ = std::stoul(matches[2].str());
                    patch_ = std::stoul(matches[3].str());
                    build_ = 0;
                    buildMetadata_ = matches[4].matched ? matches[4].str() : "";
                    return;
                }

                // If we get here, the string didn't match either pattern
                throw std::invalid_argument("Invalid version format: " + versionStr);
            } catch (const std::invalid_argument& e) {
                LOG4CXX_ERROR(logger, "Invalid argument in version parsing: " << e.what());
                throw;
            } catch (const std::out_of_range& e) {
                LOG4CXX_ERROR(logger, "Number out of range in version parsing: " << e.what());
                throw std::invalid_argument("Version component out of range: " + versionStr);
            } catch (const std::exception& e) {
                LOG4CXX_ERROR(logger, "Error parsing version string: " << e.what());
                throw std::invalid_argument("Error parsing version: " + versionStr);
            }
        }

        unsigned int major_;        ///< Major version component
        unsigned int minor_;        ///< Minor version component
        unsigned int patch_;        ///< Patch version component
        unsigned int build_;        ///< Build version component
        std::string buildMetadata_; ///< Build metadata (for SemVer)
    };

    // Define the static logger
    //LOG4CXX_DEFINE_STATIC_LOGGER(Version::logger, "Version");
}
#endif // VERSION_H