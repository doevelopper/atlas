
#include <com/github/doevelopper/atlas/launcher/args/AbstractOptionMock.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;
using namespace com::github::doevelopper::atlas::launcher::args::test;

log4cxx::LoggerPtr AbstractOptionMock::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.AbstractOptionMock"));


AbstractOptionMock::AbstractOptionMock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

AbstractOptionMock::~AbstractOptionMock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

