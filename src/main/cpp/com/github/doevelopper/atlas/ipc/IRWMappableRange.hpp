
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_IPC_RWMAPPABLERANGE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_IPC_RWMAPPABLERANGE_HPP


#include <com/github/doevelopper/atlas/ipc/IWriteMappableRange.hpp>
#include <com/github/doevelopper/atlas/ipc/IReadMappableRange.hpp>

namespace com::github::doevelopper::atlas::ipc
{
    class IRWMappableRange : public IReadMappableRange, public IWriteMappableRange
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        IRWMappableRange() noexcept;
        IRWMappableRange(const IRWMappableRange&) = default;
        IRWMappableRange(IRWMappableRange&&) = default;
        IRWMappableRange& operator=(const IRWMappableRange&) = default;
        IRWMappableRange& operator=(IRWMappableRange&&) = default;
        virtual ~IRWMappableRange() noexcept;

        virtual auto map_rw() -> std::unique_ptr<IMapping<std::byte>> = 0;
    protected:
    private:
    };
}
#endif
