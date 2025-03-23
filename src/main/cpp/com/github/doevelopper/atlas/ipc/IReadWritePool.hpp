
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_IPC_READWRITEPOOL_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_IPC_READWRITEPOOL_HPP


#include <com/github/doevelopper/atlas/ipc/IWriteOnlyPool.hpp>
#include <com/github/doevelopper/atlas/ipc/IReadOnlyPool.hpp>
#include <com/github/doevelopper/atlas/ipc/IRWMappableRange.hpp>

namespace com::github::doevelopper::atlas::ipc
{
    class IReadWritePool : public IReadOnlyPool, public IWriteOnlyPool
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        IReadWritePool() noexcept;
        IReadWritePool(const IReadWritePool&) = default;
        IReadWritePool(IReadWritePool&&) = default;
        IReadWritePool& operator=(const IReadWritePool&) = default;
        IReadWritePool& operator=(IReadWritePool&&) = default;
        virtual ~IReadWritePool() noexcept;

        virtual auto get_rw_range(size_t start, size_t len) -> std::unique_ptr<IRWMappableRange> = 0;
        void resize(size_t new_size) override = 0;
    protected:
    private:
    };
}
#endif