
#include <com/github/doevelopper/atlas/ipc/IReadMappableRange.hpp>

using namespace com::github::doevelopper::atlas::ipc;

log4cxx::LoggerPtr IReadMappableRange::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.ipc.ReadMappableRange"));

IReadMappableRange::IReadMappableRange() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IReadMappableRange::~IReadMappableRange() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
