#include <com/github/doevelopper/atlas/utils/NaturallyAligned.hpp>

using namespace com::github::doevelopper::atlas::utils;

template <typename T>
log4cxx::LoggerPtr NaturallyAligned<T>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.utils.NaturallyAligned"));

template <typename T>
NaturallyAligned<T>::NaturallyAligned() noexcept
    : T()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename T>
NaturallyAligned<T>::~NaturallyAligned() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename T>
NaturallyAligned<T>::NaturallyAligned(const NaturallyAligned& t) noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename T>
template <class U>
NaturallyAligned<T>::NaturallyAligned(const U& u) noexcept
    : T(u)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}