
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_IPC_READMAPPABLERANGE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_IPC_READMAPPABLERANGE_HPP


#include <com/github/doevelopper/atlas/ipc/IMapping.hpp>

namespace com::github::doevelopper::atlas::ipc
{
    class IReadMappableRange
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        IReadMappableRange() noexcept;
        IReadMappableRange(const IReadMappableRange&) = default;
        IReadMappableRange(IReadMappableRange&&) = default;
        IReadMappableRange& operator=(const IReadMappableRange&) = default;
        IReadMappableRange& operator=(IReadMappableRange&&) = default;
        virtual ~IReadMappableRange() noexcept;

        virtual auto map_ro() -> std::unique_ptr<IMapping<std::byte const>> = 0;
    protected:
    private:
    };
}
#endif
