
#include <com/github/doevelopper/atlas/launcher/args/IOption.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;

log4cxx::LoggerPtr IOption::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.IOption"));


IOption::IOption() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IOption::~IOption() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

// template<typename Type>
// Type IOption::get(char const* name) const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     return boost::any_cast<Type>(get(name));
// }