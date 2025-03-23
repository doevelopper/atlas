
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_IPC_RWMAPPABLERANGE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_IPC_RWMAPPABLERANGE_HPP


#include <com/github/doevelopper/atlas/ipc/IWriteMappableRange.hpp>
#include <com/github/doevelopper/atlas/ipc/IReadMappableRange.hpp>

namespace com::github::doevelopper::atlas::ipc
{
    class WOMappableRange
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        WOMappableRange() noexcept;
        WOMappableRange(const WOMappableRange&) = default;
        WOMappableRange(WOMappableRange&&) = default;
        WOMappableRange& operator=(const WOMappableRange&) = default;
        WOMappableRange& operator=(WOMappableRange&&) = default;
        virtual ~WOMappableRange() noexcept;

    protected:
    private:
    };
}
#endif
