
#include <com/github/doevelopper/atlas/events/obs/ObserverRegistrar.hpp>

using namespace com::github::doevelopper::atlas::events::obs;

template<class Observer>
log4cxx::LoggerPtr ObserverRegistrar<Observer>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.events.obs.ObserverRegistrar"));

template<class Observer>
ObserverRegistrar<Observer>::ObserverRegistrar() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template<class Observer>
ObserverRegistrar<Observer>::~ObserverRegistrar() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
