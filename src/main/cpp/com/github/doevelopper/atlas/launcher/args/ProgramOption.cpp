#include <com/github/doevelopper/atlas/launcher/args/ProgramOption.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;

log4cxx::LoggerPtr ProgramOption::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.ProgramOption"));


ProgramOption::ProgramOption() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ProgramOption::~ProgramOption() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void ProgramOption::parseArguments(
    boost::program_options::options_description const & description, int argc, char const * argv[])
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void ProgramOption::parseEnvironment(
    boost::program_options::options_description const & description, char const * prefix)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void ProgramOption::parseFile(
    boost::program_options::options_description const & description, std::string const & filename)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool ProgramOption::is_set(const char * name) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return AbstractOption::is_set(name);
}

bool ProgramOption::get(const char * name, bool default_) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return AbstractOption::get(name, default_);
}

std::string ProgramOption::get(const char * name, const char * default_) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return AbstractOption::get(name, default_);
}

int ProgramOption::get(const char * name, int default_) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return AbstractOption::get(name, default_);
}

const boost::any & ProgramOption::get(const char * name) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return AbstractOption::get(name);
}

