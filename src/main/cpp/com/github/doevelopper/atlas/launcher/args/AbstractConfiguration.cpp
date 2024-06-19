#include <com/github/doevelopper/atlas/launcher/args/AbstractConfiguration.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;

log4cxx::LoggerPtr AbstractConfiguration::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.AbstractConfiguration"));


AbstractConfiguration::AbstractConfiguration() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

AbstractConfiguration::~AbstractConfiguration() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

