#include <com/github/doevelopper/atlas/launcher/args/PositionalOption.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;

log4cxx::LoggerPtr PositionalOption::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.PositionalOption"));

PositionalOption::PositionalOption() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
PositionalOption::PositionalOption(const std::vector<std::string>& args)
    : m_positionalArgs(args)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

PositionalOption::~PositionalOption() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void PositionalOption::process()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}