
#include <com/github/doevelopper/atlas/lic/interface/ILicense.hpp>
using namespace com::github::doevelopper::atlas::lic::interface;

log4cxx::LoggerPtr ILicense::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.lic.interface.ILicense"));

ILicense::ILicense() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ILicense::~ILicense()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
