
#include <com/github/doevelopper/atlas/ptp/IPtpClock.hpp>
using namespace com::github::doevelopper::atlas::ptp;

log4cxx::LoggerPtr IPtpClock::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.ptp.IPtpClock"));

IPtpClock::IPtpClock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IPtpClock::~IPtpClock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
