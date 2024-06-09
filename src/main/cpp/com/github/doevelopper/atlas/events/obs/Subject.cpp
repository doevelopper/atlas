
#include <com/github/doevelopper/atlas/events/obs/Subject.hpp>

using namespace com::github::doevelopper::atlas::events::obs;

log4cxx::LoggerPtr Subject::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.events.obs.Subject"));

Subject::Subject() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Subject::~Subject() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}