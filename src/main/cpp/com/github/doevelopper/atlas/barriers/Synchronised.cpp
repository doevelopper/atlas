#include <com/github/doevelopper/atlas/barriers/Synchronised.hpp>

using namespace com::github::doevelopper::atlas::barriers;

template<typename T>
log4cxx::LoggerPtr Synchronised<T>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.barriers.Synchronised"));

template<typename T>
Synchronised<T>::Synchronised() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template<typename T>
Synchronised<T>::~Synchronised() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
