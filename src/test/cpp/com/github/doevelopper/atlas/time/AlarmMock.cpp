#include <com/github/doevelopper/atlas/time/AlarmMock.hpp>

using namespace com::github::doevelopper::atlas::time;
using namespace com::github::doevelopper::atlas::time::test;

log4cxx::LoggerPtr AlarmMock::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.time.AlarmMock"));

AlarmMock::AlarmMock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

AlarmMock::~AlarmMock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
