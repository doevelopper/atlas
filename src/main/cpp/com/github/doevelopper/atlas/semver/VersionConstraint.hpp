#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_VERSIONCONSTRAINT_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_VERSIONCONSTRAINT_HPP

#include <optional>
#include <string>

#include <com/github/doevelopper/atlas/logging/LoggingInitializer.hpp>
#include <com/github/doevelopper/atlas/semver/Version.hpp>

namespace com::github::doevelopper::atlas::semver
{
    constexpr int LSL = -1;
    constexpr int ESL = 0;
    constexpr int USL = 1;

    /*!
     * @class VersionConstraint
     * @brief A class to define and enforce version compatibility constraints.
     *
     * This class represents a version constraint that can specify a range of acceptable versions,
     * including exact matches, minimum versions, maximum versions, or bounded ranges.
     * It uses std::optional to represent optional lower and upper bounds and boolean flags
     * to indicate inclusivity or exclusivity of those bounds.
     */
    class VersionConstraint
    {
        enum class Operator : std::uint8_t
        {
            EQUAL,
            NOT_EQUAL,
            GREATER_THAN,
            LESS_THAN,
            GREATER_OR_EQUAL,
            LESS_OR_EQUAL
        };
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        VersionConstraint() noexcept;
        VersionConstraint(const VersionConstraint&) = default;
        VersionConstraint(VersionConstraint&&) = default;
        VersionConstraint& operator=(const VersionConstraint&) = default;
        VersionConstraint& operator=(VersionConstraint&&) = default;
        virtual ~VersionConstraint() noexcept;

        /**
         * @brief Constructs a VersionConstraint with optional lower and upper bounds.
         * @param lower The lower bound version (default: none)
         * @param lowerInc Whether the lower bound is inclusive (default: true)
         * @param upper The upper bound version (default: none)
         * @param upperInc Whether the upper bound is inclusive (default: false)
        */
        explicit VersionConstraint(std::optional<Version> lower = std::nullopt, bool lowerInc = true,
                                   std::optional<Version> upper = std::nullopt, bool upperInc = false);

        VersionConstraint(const std::string& constraint_str);
        /**
             * @brief Creates a constraint requiring an exact version match.
             * @param v The exact version to match
             * @return A VersionConstraint object representing [v, v]
             */
        // static VersionConstraint exact(const Version& v)
        // {
        //     return VersionConstraint(v, true, v, true);
        // }
        //
        // /**
        //  * @brief Creates a constraint requiring at least a minimum version.
        //  * @param v The minimum acceptable version
        //  * @return A VersionConstraint object representing [v, )
        //  */
        // static VersionConstraint atLeast(const Version& v)
        // {
        //     return VersionConstraint(v, true, std::nullopt, false);
        // }
        //
        // /**
        //  * @brief Creates a constraint requiring versions less than a maximum version.
        //  * @param v The maximum version (exclusive)
        //  * @return A VersionConstraint object representing (, v)
        //  */
        // static VersionConstraint lessThan(const Version& v)
        // {
        //     return VersionConstraint(std::nullopt, true, v, false);
        // }
        //
        // /**
        //  * @brief Creates a constraint for a range of versions.
        //  * @param min The minimum version
        //  * @param max The maximum version
        //  * @param minInc Whether the minimum is inclusive (default: true)
        //  * @param maxInc Whether the maximum is inclusive (default: false)
        //  * @return A VersionConstraint object representing [min, max) or similar
        //  */
        // static VersionConstraint range(const Version& min, const Version& max,
        //                                bool minInc = true, bool maxInc = false)
        // {
        //     return VersionConstraint(min, minInc, max, maxInc);
        // }
        /**
         * @brief Checks if a given version satisfies this constraint.
         * @param version The version to check
         * @return True if the version satisfies the constraint, false otherwise
        */
        bool isSatisfiedBy(const Version& version) const;

        /**
         * @brief Returns a string representation of the constraint in interval notation.
         * @return A string like "[1.2.3, 2.0.0)" or "(, 1.0.0)"
        */
        std::string toString() const;
    protected:
    private:
        void parseVersion(const std::string& version_str);
        void parse(const std::string& constraint_str);
        std::optional<Version> m_lowerBound;    ///< The lower bound of the version range, if any
        bool m_lowerInclusive;                  ///< True if lower bound is inclusive (>=), false if exclusive (>)
        std::optional<Version> m_upperBound;    ///< The upper bound of the version range, if any
        bool m_upperInclusive;                  ///< True if upper bound is inclusive (<=), false if exclusive (<)

        Version m_targetVersion;
        Operator m_operator;
    };
}
#endif

/*

int main() {
// Assume Version class constructor takes major, minor, patch
Version v1_2_3(1, 2, 3);
Version v1_3_0(1, 3, 0);
Version v2_0_0(2, 0, 0);

// Define constraints
auto exactConstraint = VersionConstraint::exact(v1_2_3);
auto minConstraint = VersionConstraint::atLeast(v1_2_3);
auto rangeConstraint = VersionConstraint::range(v1_2_3, v2_0_0);

// Check compatibility
Version currentVersion(1, 2, 3);
if (exactConstraint.isSatisfiedBy(currentVersion)) {
std::cout << "Version satisfies " << exactConstraint.toString() << "\n";
}
if (minConstraint.isSatisfiedBy(currentVersion)) {
std::cout << "Version satisfies " << minConstraint.toString() << "\n";
}
if (rangeConstraint.isSatisfiedBy(currentVersion)) {
std::cout << "Version satisfies " << rangeConstraint.toString() << "\n";
}

return 0;
}#
*/
