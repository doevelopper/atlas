
#include <com/github/doevelopper/atlas/launcher/args/ConfigurationMock.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;
using namespace com::github::doevelopper::atlas::launcher::args::test;

log4cxx::LoggerPtr ConfigurationMock::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.ConfigurationMock"));


ConfigurationMock::ConfigurationMock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ConfigurationMock::~ConfigurationMock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
