
#include <com/github/doevelopper/atlas/ipc/IWriteOnlyPool.hpp>

using namespace com::github::doevelopper::atlas::ipc;

log4cxx::LoggerPtr IWriteOnlyPool::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.ipc.WriteOnlyPool"));

IWriteOnlyPool::IWriteOnlyPool() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IWriteOnlyPool::~IWriteOnlyPool() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
