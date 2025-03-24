#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_LOGGINGINITIALIZER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_LOGGINGINITIALIZER_HPP

#include <com/github/doevelopper/atlas/logging/ILoggingInitializationStrategy.hpp>

namespace com::github::doevelopper::atlas::logging
{
    enum class Level : std::uint32_t
    {
        /* user actions malfunctions ....*/
        EMERGENCY    = (1 << 0),    /* system is unusable. A panic condition was reported to all processes. */
        CRITICAL     = (1 << 1),
        FATAL        = (1 << 2),    /* critical conditions */
        ALERT        = (1 << 3),
        ERROR        = (1 << 4),    /* action must be taken immediately. A condition that should be corrected immediately.  */
        WARNING      = (1 << 5),    /* error conditions */
        INFO         = (1 << 6),    /* warning conditions */
        TRACE        = (1 << 7),    /* informational */
        DEBUG        = (1 << 8),    /* debug-level messages. A message useful for debugging programs.  */
        ADVISORY     = (1 << 9),
      /* software malfunctions */
        INHIBIT      = (1 << 10),   /* System should be restarted.  */
        HINDENBUG    = (1 << 11),   /* bug with catastrophic behavior.*/
        MANDELBUG    = (1 << 12),   /* Behavior appear chaotic or even non-deterministic.*/
        BOHRBUG      = (1 << 13),   /*They do not change their behavior and are relatively easily detected.*/
        HEISENBUG    = (1 << 14),   /* Disappear or alter its behavior when one attempts to study it.*/
        SCHRODINBUG  = (1 << 15),   /*Bug that manifests itself in running software after a programmer notices that the code should never have worked in the first place.*/
        HIGGS_BUGSON = (1 << 16)    /*bug that is predicted to exist based upon other observed conditions, but is difficult, if not impossible, to artificially reproduce in a development or test environment. */
    };

    // // RAII class to log function entry and exit
    // class LogFunctionEntryExit
    // {
    // public:
    //     // Constructor logs the entry of the function
    //     LogFunctionEntryExit(const char* funcName) : funcName_(funcName)
    //     {
    //         LOG4CXX_DEBUG(logger, "Entering function: " << funcName_);
    //     }
    //
    //     // Destructor logs the exit of the function
    //     ~LogFunctionEntryExit() {
    //         LOG4CXX_DEBUG(logger, "Exiting function: " << funcName_);
    //     }
    //
    // private:
    //     const char* funcName_;  // Stores the function name
    // };
    // // Macro to create an instance of LogFunctionEntryExit with the current function name
    // #define LOG_FUNCTION_ENTRY_EXIT LogFunctionEntryExit log(__func__)
    // void myFunction() {
    //     LOG_FUNCTION_ENTRY_EXIT;
    //     // Your function code here
    //     std::cout << "Doing something..." << std::endl;
    // }

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
