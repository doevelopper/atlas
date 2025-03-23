//
// Created by hroland on 26/05/24.
//

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_APPLICATIONPRIVATE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_APPLICATIONPRIVATE_HPP

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/algorithm/string.hpp>

#include <string>
#include <future>
#include <memory>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <typeindex>

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::launcher
{

    // Forward declarations
    class Application;

    /**
     * @brief Private implementation of the Application class
     *
     * This class implements the PIMPL (Pointer to Implementation) pattern for the Application class.
     * It encapsulates the implementation details of the Application class to reduce compilation
     * dependencies and provide better ABI stability.
     */
    class ApplicationPrivate
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DECLARE_PUBLIC(Application)
    public:
        /**
         * @brief Constructor
         *
         * @param q Pointer to the public interface
         */
        explicit ApplicationPrivate(Application* q) noexcept;
        // explicit ApplicationPrivate() noexcept;
        /**
         * @brief Constructor with command-line arguments
         *
         * @param q Pointer to the public interface
         * @param argc Argument count
         * @param argv Argument values
         */
        ApplicationPrivate(Application* q, int argc, char** argv) noexcept;
        // ApplicationPrivate(int argc, char** argv) noexcept;

        /**
         * @brief Destructor
         */
        ~ApplicationPrivate() noexcept;

        // /**
        //  * @brief Initialize the application
        //  *
        //  * @return true if initialization succeeded, false otherwise
        //  * @throws std::runtime_error if critical initialization fails
        //  */
        // bool initialize();
        //
        // /**
        //  * @brief Run the application
        //  *
        //  * @return Future that resolves when the application has started
        //  */
        // std::future<void> run();
        //
        // /**
        //  * @brief Shutdown the application
        //  *
        //  * @param reason Reason for shutdown
        //  * @return Future that resolves when shutdown is complete
        //  */
        // std::future<void> shutdown(const std::string& reason);
        Application * q_ptr;
    private:
        // /**
        //  * @brief Process command-line arguments
        //  *
        //  * @param argc Argument count
        //  * @param argv Argument values
        //  * @return true if arguments are valid, false otherwise
        //  */
        // bool processArguments(int argc, char** argv);
        //
        // /**
        //  * @brief Set up application configuration
        //  *
        //  * @return true if configuration succeeded, false otherwise
        //  * @throws std::runtime_error if critical configuration fails
        //  */
        // bool setupConfiguration();
        //
        // /**
        //  * @brief Initialize logging
        //  *
        //  * @return true if logging initialization succeeded, false otherwise
        //  */
        // bool initializeLogging();
        //
        // /**
        //  * @brief The main application loop
        //  */
        // void applicationLoop();
        //
        // /**
        //  * @brief Perform shutdown operations
        //  *
        //  * @param reason Reason for shutdown
        //  */
        // void performShutdown(const std::string& reason);
        //
        // // Pointer to the public interface
        // Application* q_ptr;
        //
        // // Application state
        // enum class State
        // {
        //     NotInitialized,
        //     Initializing,
        //     Initialized,
        //     Running,
        //     ShuttingDown,
        //     Shutdown
        // };
        // std::atomic<State> state;
        //
        // // Command-line arguments
        // int argc;
        // char** argv;
        //
        // // Application version
        // std::unique_ptr<Version> appVersion;
        //
        // // Application configuration
        // std::string configPath;
        // std::string appName;
        // std::string appDescription;
        //
        // // Thread synchronization
        // std::mutex stateMutex;
        // std::condition_variable stateCondition;
        //
        // // Shutdown signal
        // std::atomic<bool> shutdownRequested;
        // std::string shutdownReason;
        //
        // // Thread for application loop
        // std::unique_ptr<std::thread> appThread;
        //
        // // Promise for signaling application start completion
        // std::promise<void> startPromise;
        //
        // // Promise for signaling application shutdown completion
        // std::promise<void> shutdownPromise;
    };

    // /**
    //  * @brief Private implementation of the Application class
    //  *
    //  * This class implements the PIMPL (Pointer to Implementation) pattern for the Application class.
    //  * It encapsulates the implementation details of the Application class to reduce compilation
    //  * dependencies and provide better ABI stability.
    //  */
    // class ApplicationPrivate
    // {
    //     LOG4CXX_DECLARE_STATIC_LOGGER
    // public:
    //
    //     ApplicationPrivate() noexcept;
    //     ApplicationPrivate(const ApplicationPrivate &) noexcept             = default;
    //     ApplicationPrivate(ApplicationPrivate &&) noexcept                  = default;
    //     ApplicationPrivate & operator=(const ApplicationPrivate &) noexcept = default;
    //     ApplicationPrivate & operator=(ApplicationPrivate &&) noexcept      = default;
    //     virtual ~ApplicationPrivate() noexcept;
    //
    //     ApplicationPrivate([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) noexcept;
    //     boost::filesystem::path data{"data"};
    //     boost::filesystem::path config{"config"};
    //     boost::filesystem::path loggerConfigurator{"log4cxx.xml"};
    //     boost::filesystem::path staticFileConfigurator;
    //
    //     std::uint64_t version;
    //     std::string versionString;
    //
    //     std::atomic_bool isQuitting{false};
    //
    //     using anyTypeCompareMap = std::unordered_map<std::type_index, std::function<bool(const std::any& a, const std::any& b)>>;
    //     anyTypeCompareMap anyCompare;
    //
    // protected:
    // private:
    //     std::string getFileExtension ( const std::string & s );
    //     void loggerConfigure ( std::string const & filename );
    // };
}

#endif
