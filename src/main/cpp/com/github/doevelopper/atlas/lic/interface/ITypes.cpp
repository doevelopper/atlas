
#include <com/github/doevelopper/atlas/lic/interface/ITypes.hpp>
using namespace com::github::doevelopper::atlas::lic::interface;

log4cxx::LoggerPtr ITypes::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.lic.interface.ITypes"));

ITypes::ITypes() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ITypes::~ITypes()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
