#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_PUB_IPUBLISHER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_PUB_IPUBLISHER_HPP

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::events::pub
{
    class IPublisher
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        IPublisher() noexcept;
        IPublisher(const IPublisher&) = default;
        IPublisher(IPublisher&&) = default;
        IPublisher& operator=(const IPublisher&) = default;
        IPublisher& operator=(IPublisher&&) = default;
        virtual ~IPublisher() noexcept;
    protected:
    private:
    };
}

#endif
