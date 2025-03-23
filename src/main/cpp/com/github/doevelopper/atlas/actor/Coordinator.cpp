
#include <com/github/doevelopper/atlas/actor/Coordinator.hpp>
using namespace com::github::doevelopper::atlas::actor;

log4cxx::LoggerPtr Coordinator::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.actor.Coordinator"));

Coordinator::Coordinator() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Coordinator::~Coordinator() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
