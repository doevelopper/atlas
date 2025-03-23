
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_IPC_READONLYPOOL_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_IPC_READONLYPOOL_HPP

#include <com/github/doevelopper/atlas/ipc/IReadMappableRange.hpp>

namespace com::github::doevelopper::atlas::ipc
{
    class IReadOnlyPool
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        IReadOnlyPool() noexcept;
        IReadOnlyPool(const IReadOnlyPool&) = default;
        IReadOnlyPool(IReadOnlyPool&&) = default;
        IReadOnlyPool& operator=(const IReadOnlyPool&) = default;
        IReadOnlyPool& operator=(IReadOnlyPool&&) = default;
        virtual ~IReadOnlyPool() noexcept;


        virtual auto get_ro_range(size_t start, size_t len) -> std::unique_ptr<IReadMappableRange> = 0;
        virtual void resize(size_t new_size) = 0;
    protected:
    private:
    };
}
#endif