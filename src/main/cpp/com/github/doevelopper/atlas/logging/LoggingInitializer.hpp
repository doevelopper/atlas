#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_LOGGINGINITIALIZER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_LOGGINGINITIALIZER_HPP

#include <com/github/doevelopper/atlas/logging/ILoggingInitializationStrategy.hpp>

namespace com::github::doevelopper::atlas::logging
{
    /**
     * @class LoggingInitializer
    * @brief Main Log4CXX initializer class
     *
     * Responsible for initializing the Log4CXX logging library using various strategies.
     * This class follows the SOLID principles:
     * - Single Responsibility: Focuses only on initializing Log4CXX
     * - Open/Closed: Can be extended with new initialization strategies without modification
     * - Liskov Substitution: All strategy implementations are interchangeable
     * - Interface Segregation: Uses minimal interfaces
     * - Dependency Inversion: Depends on abstractions, not concrete implementations
     */
    class LoggingInitializer
    {
    public:

        LoggingInitializer() noexcept;
        LoggingInitializer(const LoggingInitializer&) = delete;
        LoggingInitializer(LoggingInitializer&&) = default;
        LoggingInitializer& operator=(const LoggingInitializer&) = delete;
        LoggingInitializer& operator=(LoggingInitializer&&) = default;
        virtual ~LoggingInitializer() noexcept;

        explicit LoggingInitializer(std::unique_ptr<ILoggingInitializationStrategy> initStrategy);
        void initialize() const;
        bool isInitialized();
    protected:
    private:
        std::unique_ptr<ILoggingInitializationStrategy> m_strategy;
    };

}

#endif
