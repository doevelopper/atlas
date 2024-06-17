
#include <com/github/doevelopper/atlas/barriers/RecursiveReadWriteMutex.hpp>

using namespace com::github::doevelopper::atlas::barriers;

log4cxx::LoggerPtr RecursiveReadWriteMutex::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.barriers.RecursiveReadWriteMutex"));

RecursiveReadWriteMutex::RecursiveReadWriteMutex() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

RecursiveReadWriteMutex::~RecursiveReadWriteMutex() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

