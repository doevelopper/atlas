
#include <com/github/doevelopper/atlas/utils/AdelsonVelskyLandisNode.hpp>

using namespace com::github::doevelopper::atlas::utils;

template <typename Derived>
log4cxx::LoggerPtr AdelsonVelskyLandisNode<Derived>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.utils.AdelsonVelskyLandisNode"));

template <typename Derived>
AdelsonVelskyLandisNode<Derived>::AdelsonVelskyLandisNode() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename Derived>
AdelsonVelskyLandisNode<Derived>::~AdelsonVelskyLandisNode() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
