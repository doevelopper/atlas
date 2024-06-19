
#include <com/github/doevelopper/atlas/launcher/args/OptionMock.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;
using namespace com::github::doevelopper::atlas::launcher::args::test;

log4cxx::LoggerPtr OptionMock::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.OptionMock"));


OptionMock::OptionMock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

OptionMock::~OptionMock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}