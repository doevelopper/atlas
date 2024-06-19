
#include <com/github/doevelopper/atlas/launcher/args/AbstractConfigurationMock.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;
using namespace com::github::doevelopper::atlas::launcher::args::test;

log4cxx::LoggerPtr AbstractConfigurationMock::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.AbstractConfigurationMock"));


AbstractConfigurationMock::AbstractConfigurationMock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

AbstractConfigurationMock::~AbstractConfigurationMock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
