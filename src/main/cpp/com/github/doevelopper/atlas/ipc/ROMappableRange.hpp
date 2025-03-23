
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_IPC_WRITEMAPPABLERANGE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_IPC_WRITEMAPPABLERANGE_HPP


#include <com/github/doevelopper/atlas/ipc/IMapping.hpp>

namespace com::github::doevelopper::atlas::ipc
{
    class IWriteMappableRange
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        IWriteMappableRange() noexcept;
        IWriteMappableRange(const IWriteMappableRange&) = default;
        IWriteMappableRange(IWriteMappableRange&&) = default;
        IWriteMappableRange& operator=(const IWriteMappableRange&) = default;
        IWriteMappableRange& operator=(IWriteMappableRange&&) = default;
        virtual ~IWriteMappableRange() noexcept;

        virtual auto map_wo() -> std::unique_ptr<IMapping<std::byte>> = 0;
    protected:
    private:
    };
}
#endif
