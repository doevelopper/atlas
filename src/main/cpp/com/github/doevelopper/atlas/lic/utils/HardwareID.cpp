
#include <com/github/doevelopper/atlas/lic/utils/HardwareID.hpp>

using namespace com::github::doevelopper::atlas::lic::utils;

log4cxx::LoggerPtr HardwareID::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.lic.utils.HardwareID"));

HardwareID::HardwareID() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

HardwareID::~HardwareID() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

std::string HardwareID::getHardwareId()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

std::vector<std::string> HardwareID::getHardwareComponents()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool HardwareID::matchesHardwareId(const std::string& hardwareId)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

std::string HardwareID::getStableFingerprint()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
