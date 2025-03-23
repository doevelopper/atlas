
#include <com/github/doevelopper/atlas/ipc/IRWMappableRange.hpp>

using namespace com::github::doevelopper::atlas::ipc;

log4cxx::LoggerPtr IRWMappableRange::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.ipc.RWMappableRange"));

IRWMappableRange::IRWMappableRange() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IRWMappableRange::~IRWMappableRange() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
