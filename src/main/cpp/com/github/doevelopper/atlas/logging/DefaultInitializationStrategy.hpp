#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_DEFAULTINITIALIZATIONSTRATEGY_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_DEFAULTINITIALIZATIONSTRATEGY_HPP

#include <com/github/doevelopper/atlas/logging/ILoggingInitializationStrategy.hpp>

namespace com::github::doevelopper::atlas::logging
{
    /**
     * @class DefaultInitializationStrategy
     * @brief Use this as a fallback when no specific configuration is required..
     */
    class DefaultInitializationStrategy : public ILoggingInitializationStrategy
    {
    public:

        DefaultInitializationStrategy() noexcept;
        DefaultInitializationStrategy(const DefaultInitializationStrategy&) = delete;
        DefaultInitializationStrategy(DefaultInitializationStrategy&&) = default;
        DefaultInitializationStrategy& operator=(const DefaultInitializationStrategy&) = delete;
        DefaultInitializationStrategy& operator=(DefaultInitializationStrategy&&) = default;
        virtual ~DefaultInitializationStrategy() noexcept;
        /**
         * Initialize with BasicConfigurator (simple console output)
         * @throws std::runtime_error if already initialized or configuration fails
         */
        void initialize() const override;
    protected:
    private:
    };

}

#endif
