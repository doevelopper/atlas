
#include <com/github/doevelopper/atlas/lic/interface/IActivator.hpp>
using namespace com::github::doevelopper::atlas::lic::interface;

log4cxx::LoggerPtr IActivator::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.lic.interface.IActivator"));

IActivator::IActivator() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IActivator::~IActivator()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
