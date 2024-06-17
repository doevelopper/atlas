
#include <com/github/doevelopper/atlas/time/Alarm.hpp>

using namespace com::github::doevelopper::atlas::time;

log4cxx::LoggerPtr Alarm::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.time.Alarm"));

Alarm::Alarm() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Alarm::~Alarm() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
