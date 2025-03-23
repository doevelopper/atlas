
#include <com/github/doevelopper/atlas/ipc/ShmBufferSIGBUSHandler.hpp>

using namespace com::github::doevelopper::atlas::ipc;

log4cxx::LoggerPtr ShmBufferSIGBUSHandler::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.ipc.WriteMappableRange"));

ShmBufferSIGBUSHandler::ShmBufferSIGBUSHandler() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ShmBufferSIGBUSHandler::~ShmBufferSIGBUSHandler() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
