
#include <com/github/doevelopper/atlas/ipc/IReadOnlyPool.hpp>

using namespace com::github::doevelopper::atlas::ipc;

log4cxx::LoggerPtr IReadOnlyPool::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.ipc.ReadOnlyPool"));

IReadOnlyPool::IReadOnlyPool() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IReadOnlyPool::~IReadOnlyPool() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
