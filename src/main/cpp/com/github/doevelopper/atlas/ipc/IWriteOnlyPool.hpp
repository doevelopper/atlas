
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_IPC_WRITEONLYPOOL_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_IPC_WRITEONLYPOOL_HPP

#include <com/github/doevelopper/atlas/ipc/IWriteMappableRange.hpp>

namespace com::github::doevelopper::atlas::ipc
{
    class IWriteOnlyPool
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        IWriteOnlyPool() noexcept;
        IWriteOnlyPool(const IWriteOnlyPool&) = default;
        IWriteOnlyPool(IWriteOnlyPool&&) = default;
        IWriteOnlyPool& operator=(const IWriteOnlyPool&) = default;
        IWriteOnlyPool& operator=(IWriteOnlyPool&&) = default;
        virtual ~IWriteOnlyPool() noexcept;

        virtual auto get_wo_range(size_t start, size_t len) -> std::unique_ptr<IWriteMappableRange> = 0;
        virtual void resize(size_t new_size) = 0;
    protected:
    private:
    };
}
#endif