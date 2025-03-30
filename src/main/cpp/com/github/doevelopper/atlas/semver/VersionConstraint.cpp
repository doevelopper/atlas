
#include <com/github/doevelopper/atlas/semver/VersionConstraint.hpp>

using namespace com::github::doevelopper::atlas::semver;

log4cxx::LoggerPtr VersionConstraint::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.ipc.VersionConstraint"));

VersionConstraint::VersionConstraint() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

VersionConstraint::VersionConstraint(std::optional<Version> lower, bool lowerInc,
                      std::optional<Version> upper, bool upperInc)
    // : m_lowerBound(lower)
    // , m_lowerInclusive(lowerInc)
    // , m_upperBound(upper)
    // , m_upperInclusive(upperInc)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

VersionConstraint::VersionConstraint(const std::string& constraint_str)
//     : this->m_targetVersion()
//     , this->m_operator(Operator::EQUAL)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->parse(constraint_str);
}

VersionConstraint::~VersionConstraint() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool VersionConstraint::isSatisfiedBy(const Version& version) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    switch (this->m_operator)
    {
        case Operator::EQUAL:
            return version == this->m_targetVersion;
        case Operator::NOT_EQUAL:
            return version != this->m_targetVersion;
        case Operator::GREATER_THAN:
            return version > this->m_targetVersion;
        case Operator::LESS_THAN:
            return version < this->m_targetVersion;
        case Operator::GREATER_OR_EQUAL:
            return version >= this->m_targetVersion;
        case Operator::LESS_OR_EQUAL:
            return version <= this->m_targetVersion;
        default:
            return false;
    }
    // // Check lower bound if it exists
    // if (this->m_lowerBound)
    // {
    //     if (this->m_lowerInclusive)
    //     {
    //         if (version < *this->m_lowerBound)
    //             return false;  // version >= lowerBound
    //     }
    //     else
    //     {
    //         if (version <= *this->m_lowerBound)
    //             return false; // version > lowerBound
    //     }
    // }
    // // Check upper bound if it exists
    // if (this->m_upperBound)
    // {
    //     if (this->m_upperInclusive)
    //     {
    //         if (version > *this->m_upperBound)
    //             return false;  // version <= upperBound
    //     }
    //     else
    //     {
    //         if (version >= *this->m_upperBound)
    //             return false; // version < upperBound
    //     }
    // }
    // return true;
}

std::string VersionConstraint::toString() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    std::string op_str;
    switch (this->m_operator)
    {
        case Operator::EQUAL:
            op_str = "==";
        break;
        case Operator::NOT_EQUAL:
            op_str = "!=";
        break;
        case Operator::GREATER_THAN:
            op_str = ">";
        break;
        case Operator::LESS_THAN:
            op_str = "<";
        break;
        case Operator::GREATER_OR_EQUAL:
            op_str = ">=";
        break;
        case Operator::LESS_OR_EQUAL:
            op_str = "<=";
        break;
        default:
            op_str = "?";
        break;
    }
    return op_str + this->m_targetVersion.toString();
    // std::string result;
    // // Lower bound
    // if (this->m_lowerBound)
    // {
    //     result += (this->m_lowerInclusive ? "[" : "(") + this->m_lowerBound->toString();
    // }
    // else
    // {
    //     result += "(";
    // }
    // result += ", ";
    // // Upper bound
    // if (this->m_upperBound)
    // {
    //     result += this->m_upperBound->toString() + (this->m_upperInclusive ? "]" : ")");
    // }
    // else
    // {
    //     result += ")";
    // }
    // return result;
}

void VersionConstraint::parse(const std::string& constraint_str)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::string trimmed = constraint_str;
    trimmed.erase(0, trimmed.find_first_not_of(" \t")); // Trim whitespace

    // Check for operator prefixes
    if (trimmed.starts_with("==")) {
        this->m_operator = Operator::EQUAL;
        parseVersion(trimmed.substr(2));
    }
    else if (trimmed.starts_with("!=")) {
        this->m_operator = Operator::NOT_EQUAL;
        parseVersion(trimmed.substr(2));
    }
    else if (trimmed.starts_with(">=")) {
        this->m_operator = Operator::GREATER_OR_EQUAL;
        parseVersion(trimmed.substr(2));
    }
    else if (trimmed.starts_with("<=")) {
        this->m_operator = Operator::LESS_OR_EQUAL;
        parseVersion(trimmed.substr(2));
    }
    else if (trimmed.starts_with(">")) {
        this->m_operator = Operator::GREATER_THAN;
        parseVersion(trimmed.substr(1));
    }
    else if (trimmed.starts_with("<")) {
        this->m_operator = Operator::LESS_THAN;
        parseVersion(trimmed.substr(1));
    }
    else {
        // Default to exact match
        this->m_operator = Operator::EQUAL;
        parseVersion(trimmed);
    }
}

void VersionConstraint::parseVersion(const std::string& version_str)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    try
    {
        // this->m_targetVersion = Version(version_str); // FIXME! Add constructor to Version(const & std::string)
    }
    catch (const std::invalid_argument&)
    {
        throw std::invalid_argument("Invalid version format in constraint");
    }
}

/*
int main() {
    Version v1(2, 3, 5);
    Version v2(1, 9, 0);

    VersionConstraint constraint1(">=2.0.0");
    VersionConstraint constraint2("<=1.5.0");

    std::cout << std::boolalpha;
    std::cout << "v1 satisfies >=2.0.0: " << constraint1.isSatisfiedBy(v1) << std::endl; // true
    std::cout << "v2 satisfies <=1.5.0: " << constraint2.isSatisfiedBy(v2) << std::endl; // false

    try {
        VersionConstraint invalid("invalid_constraint");
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
 */