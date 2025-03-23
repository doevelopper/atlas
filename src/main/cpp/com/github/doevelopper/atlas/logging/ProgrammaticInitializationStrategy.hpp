#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_PROGRAMMATICINITIALIZATIONSTRATEGY_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_PROGRAMMATICINITIALIZATIONSTRATEGY_HPP

#include <com/github/doevelopper/atlas/logging/ILoggingInitializationStrategy.hpp>

namespace com::github::doevelopper::atlas::logging
{
    /**
     * @class ProgrammaticInitializationStrategy
     * @brief Use this when you want to configure appenders, layouts, and log levels directly in code.
     */
    class ProgrammaticInitializationStrategy : public ILoggingInitializationStrategy
    {
    public:

        ProgrammaticInitializationStrategy() noexcept;
        ProgrammaticInitializationStrategy(const ProgrammaticInitializationStrategy&) = delete;
        ProgrammaticInitializationStrategy(ProgrammaticInitializationStrategy&&) = default;
        ProgrammaticInitializationStrategy& operator=(const ProgrammaticInitializationStrategy&) = delete;
        ProgrammaticInitializationStrategy& operator=(ProgrammaticInitializationStrategy&&) = default;
        virtual ~ProgrammaticInitializationStrategy() noexcept;
        /**
         * Programmatic initialization with custom configuration
         * Creates a console appender with pattern layout and INFO level
         * @throws std::runtime_error if already initialized or configuration fails
         */
        void initialize() const override;
    protected:
    private:
    };

}

#endif
