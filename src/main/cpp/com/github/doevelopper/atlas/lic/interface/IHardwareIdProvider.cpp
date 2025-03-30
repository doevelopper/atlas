
#include <com/github/doevelopper/atlas/lic/interface/IHardwareIdProvider.hpp>
using namespace com::github::doevelopper::atlas::lic::interface;

log4cxx::LoggerPtr IHardwareIdProvider::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.lic.interface.IHardwareIdProvider"));

IHardwareIdProvider::IHardwareIdProvider() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IHardwareIdProvider::~IHardwareIdProvider()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
