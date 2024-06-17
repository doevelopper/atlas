
#include <com/github/doevelopper/atlas/events/obs/ObserverRegistrarMock.hpp>

using namespace com::github::doevelopper::atlas::events::obs;
using namespace com::github::doevelopper::atlas::events::obs::test;

log4cxx::LoggerPtr ObserverRegistrarMock::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.events.obs.test.ObserverRegistrarMock"));


ObserverRegistrarMock::ObserverRegistrarMock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ObserverRegistrarMock::~ObserverRegistrarMock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

