#include <com/github/doevelopper/atlas/launcher/args/DefaultConfiguration.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;

log4cxx::LoggerPtr DefaultConfiguration::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.DefaultConfiguration"));


DefaultConfiguration::DefaultConfiguration() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

DefaultConfiguration::~DefaultConfiguration() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

DefaultConfiguration::DefaultConfiguration(int argc, char const * argv[])
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

DefaultConfiguration::DefaultConfiguration(int argc, char const * argv[], std::string const & config_file)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

DefaultConfiguration::DefaultConfiguration(
    int argc, char const * argv[], std::function<void(int argc, char const * const * argv)> const & handler)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

DefaultConfiguration::DefaultConfiguration(
    int argc, char const * argv[], std::function<void(int argc, char const * const * argv)> const & handler,
    std::string const & config_file)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

boost::program_options::options_description_easy_init DefaultConfiguration::addOptions()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

std::shared_ptr<AbstractOption> DefaultConfiguration::options() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return AbstractConfiguration::options();
}

void DefaultConfiguration::addPlatformOptions()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void DefaultConfiguration::parseArguments(
    boost::program_options::options_description desc, ProgramOption & options, int argc, char const * argv[]) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void DefaultConfiguration::parseEnvironment(
    boost::program_options::options_description & desc, ProgramOption & options) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void DefaultConfiguration::parseConfigFile(
    boost::program_options::options_description & desc, ProgramOption & options) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

