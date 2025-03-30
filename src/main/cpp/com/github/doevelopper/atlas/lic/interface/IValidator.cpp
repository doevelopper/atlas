

#include <com/github/doevelopper/atlas/lic/interface/IValidator.hpp>
using namespace com::github::doevelopper::atlas::lic::interface;

log4cxx::LoggerPtr IValidator::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.lic.interface.IValidator"));

IValidator::IValidator() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IValidator::~IValidator()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
