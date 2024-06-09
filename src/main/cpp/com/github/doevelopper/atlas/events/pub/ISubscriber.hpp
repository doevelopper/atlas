#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_PUB_ISUBSCRIBER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_PUB_ISUBSCRIBER_HPP

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::events::pub
{
    class ISubscriber
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        ISubscriber() noexcept;
        ISubscriber(const ISubscriber&) = default;
        ISubscriber(ISubscriber&&) = default;
        ISubscriber& operator=(const ISubscriber&) = default;
        ISubscriber& operator=(ISubscriber&&) = default;
        virtual ~ISubscriber() noexcept;
    protected:
    private:
    };
}

#endif
