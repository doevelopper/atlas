#include <com/github/doevelopper/atlas/events/pub/IBroker.hpp>

using namespace com::github::doevelopper::atlas::events::pub;

log4cxx::LoggerPtr IBroker::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.events.pub.IBroker"));

IBroker::IBroker() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IBroker::~IBroker() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
