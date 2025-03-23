
#include <com/github/doevelopper/atlas/ipc/IMapping.hpp>

using namespace com::github::doevelopper::atlas::ipc;
template<typename T>
log4cxx::LoggerPtr IMapping<T>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.ipc.IMapping"));

template<typename T>
IMapping<T>::IMapping() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

// template<typename T>
// Mappinge<T>::~Mapping() noexcept
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }
