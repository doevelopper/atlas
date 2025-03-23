
#include <com/github/doevelopper/atlas/ipc/IReadWritePool.hpp>

using namespace com::github::doevelopper::atlas::ipc;

log4cxx::LoggerPtr IReadWritePool::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.ipc.ReadWritePool"));

IReadWritePool::IReadWritePool() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IReadWritePool::~IReadWritePool() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
