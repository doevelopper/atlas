#include <com/github/doevelopper/atlas/launcher/args/IConfiguration.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;

log4cxx::LoggerPtr IConfiguration::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.AbstractOption"));


IConfiguration::IConfiguration() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IConfiguration::~IConfiguration() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

