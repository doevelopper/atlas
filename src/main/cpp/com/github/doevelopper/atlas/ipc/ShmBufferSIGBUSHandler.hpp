#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_IPC_SHMBUFFERSIGBUSHANDLER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_IPC_SHMBUFFERSIGBUSHANDLER_HPP


#include <com/github/doevelopper/atlas/ipc/IWriteMappableRange.hpp>
#include <com/github/doevelopper/atlas/ipc/IReadMappableRange.hpp>

namespace com::github::doevelopper::atlas::ipc
{
    class ShmBufferSIGBUSHandler
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        ShmBufferSIGBUSHandler() noexcept;
        ShmBufferSIGBUSHandler(const ShmBufferSIGBUSHandler&) = default;
        ShmBufferSIGBUSHandler(ShmBufferSIGBUSHandler&&) = default;
        ShmBufferSIGBUSHandler& operator=(const ShmBufferSIGBUSHandler&) = default;
        ShmBufferSIGBUSHandler& operator=(ShmBufferSIGBUSHandler&&) = default;
        virtual ~ShmBufferSIGBUSHandler() noexcept;

    protected:
    private:
    };
    //static mir::Synchronised<std::vector<std::weak_ptr<AccessProtector>>> current_access;
    // static std::atomic<struct sigaction*> previous_handler;
    // static std::weak_ptr<ShmBufferSIGBUSHandler> installed_handler;
}
#endif
