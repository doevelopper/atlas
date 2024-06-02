

#include <com/github/doevelopper/atlas/utils/ShellHandle.hpp>

using namespace com::github::doevelopper::atlas::utils;

log4cxx::LoggerPtr ShellHandle::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.utils.Version"));

ShellHandle::ShellHandle() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ShellHandle::~ShellHandle() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

auto ShellHandle::exec(const char* cmd) -> std::string
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    constexpr const size_t bufferSize{128};
    std::array<char, bufferSize> buffer{};
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if(!pipe)
    {
        LOG4CXX_ERROR(logger, "popen() failed!");
    }
    while(fgets(buffer.data(), static_cast<int> (buffer.size()), pipe.get()) != nullptr)
    {
        result += buffer.data();
    }

    if(result.back() == '\n')
    {
        result.pop_back();
    }

    LOG4CXX_INFO(logger, "Command "<< cmd << " returned " << result);
    return result;
}

