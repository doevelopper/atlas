#include <com/github/doevelopper/atlas/events/pub/Publisher.hpp>

using namespace com::github::doevelopper::atlas::events::pub;

log4cxx::LoggerPtr Publisher::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.events.pub.Publisher"));

Publisher::Publisher() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Publisher::~Publisher() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
