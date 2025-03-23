
#include <com/github/doevelopper/atlas/ipc/IWriteMappableRange.hpp>

using namespace com::github::doevelopper::atlas::ipc;

log4cxx::LoggerPtr IWriteMappableRange::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.ipc.WriteMappableRange"));

IWriteMappableRange::IWriteMappableRange() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IWriteMappableRange::~IWriteMappableRange() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
