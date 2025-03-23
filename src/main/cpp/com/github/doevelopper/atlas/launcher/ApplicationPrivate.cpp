
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <thread>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <stdexcept>

#include <com/github/doevelopper/atlas/launcher/Application.hpp>
#include <com/github/doevelopper/atlas/launcher/ApplicationPrivate.hpp>

using namespace com::github::doevelopper::atlas::launcher;
// using namespace com::github::doevelopper::atlas::semver;


log4cxx::LoggerPtr ApplicationPrivate::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.ApplicationPrivate"));

ApplicationPrivate::ApplicationPrivate(Application* q) noexcept
    // : q_ptr(q)
    // , state(State::NotInitialized)
    // , argc(0)
    // , argv(nullptr)
    // , appVersion(std::make_unique<Version>())
    // , shutdownRequested(false)
{
    LOG4CXX_DEBUG(logger, "ApplicationPrivate constructor called");
}

ApplicationPrivate::ApplicationPrivate(Application* q, int argc, char** argv) noexcept
    // : q_ptr(q)
    // , state(State::NotInitialized)
    // , argc(argc)
    // , argv(argv)
    // , appVersion(std::make_unique<Version>())
    // , shutdownRequested(false)
{
    LOG4CXX_DEBUG(logger, "ApplicationPrivate constructor with arguments called");
    //processArguments(argc, argv);
}

ApplicationPrivate::~ApplicationPrivate() noexcept
{
    // try {
    //     if (state.load() == State::Running) {
    //         LOG4CXX_WARN(logger, "Application is still running during destruction, forcing shutdown");
    //         shutdown("Destructor called");
    //     }
    //
    //     if (appThread && appThread->joinable()) {
    //         appThread->join();
    //     }
    //
    //     LOG4CXX_DEBUG(logger, "ApplicationPrivate destroyed");
    // } catch (const std::exception& e) {
    //     // Don't let exceptions escape the destructor
    //     LOG4CXX_ERROR(logger, "Exception in destructor: " << e.what());
    // } catch (...) {
    //     LOG4CXX_ERROR(logger, "Unknown exception in destructor");
    // }
}
/*
bool ApplicationPrivate::initialize()
{
    LOG4CXX_INFO(logger, "Initializing application");

    // State transition check
    {
        std::lock_guard<std::mutex> lock(stateMutex);
        if (state.load() != State::NotInitialized) {
            LOG4CXX_WARN(logger, "Application already initialized or initializing");
            return false;
        }
        state.store(State::Initializing);
    }

    try {
        // Initialize logging first to ensure proper error reporting
        if (!initializeLogging()) {
            LOG4CXX_ERROR(logger, "Failed to initialize logging");
            state.store(State::NotInitialized);
            return false;
        }

        // Setup configuration
        if (!setupConfiguration()) {
            LOG4CXX_ERROR(logger, "Failed to setup configuration");
            state.store(State::NotInitialized);
            return false;
        }

        // Additional initialization steps can be added here

        // Transition to initialized state
        {
            std::lock_guard<std::mutex> lock(stateMutex);
            state.store(State::Initialized);
            stateCondition.notify_all();
        }

        LOG4CXX_INFO(logger, "Application initialized successfully");
        return true;
    } catch (const std::exception& e) {
        LOG4CXX_ERROR(logger, "Initialization failed with exception: " << e.what());
        state.store(State::NotInitialized);
        throw std::runtime_error(std::string("Initialization failed: ") + e.what());
    } catch (...) {
        LOG4CXX_ERROR(logger, "Initialization failed with unknown exception");
        state.store(State::NotInitialized);
        throw std::runtime_error("Initialization failed with unknown error");
    }
}

std::future<void> ApplicationPrivate::run()
{
    LOG4CXX_INFO(logger, "Starting application");

    // Reset the start promise
    startPromise = std::promise<void>();

    // Check if we need to initialize first
    if (state.load() == State::NotInitialized) {
        try {
            if (!initialize()) {
                LOG4CXX_ERROR(logger, "Failed to initialize application");
                startPromise.set_exception(std::make_exception_ptr(
                    std::runtime_error("Failed to initialize application")));
                return startPromise.get_future();
            }
        } catch (const std::exception& e) {
            LOG4CXX_ERROR(logger, "Initialization failed: " << e.what());
            startPromise.set_exception(std::make_exception_ptr(e));
            return startPromise.get_future();
        }
    }

    // Check if we're already running
    if (state.load() == State::Running) {
        LOG4CXX_WARN(logger, "Application already running");
        startPromise.set_value();
        return startPromise.get_future();
    }

    // Wait for initialized state if we're still initializing
    {
        std::unique_lock<std::mutex> lock(stateMutex);
        if (state.load() == State::Initializing) {
            LOG4CXX_DEBUG(logger, "Waiting for initialization to complete");
            stateCondition.wait(lock, [this] {
                return state.load() != State::Initializing;
            });
        }

        // Check if initialization was successful
        if (state.load() != State::Initialized) {
            LOG4CXX_ERROR(logger, "Cannot run: application not in initialized state");
            startPromise.set_exception(std::make_exception_ptr(
                std::runtime_error("Cannot run: application not in initialized state")));
            return startPromise.get_future();
        }

        // Transition to running state
        state.store(State::Running);
        shutdownRequested.store(false);
        stateCondition.notify_all();
    }

    // Start the application thread
    appThread = std::make_unique<std::thread>(&ApplicationPrivate::applicationLoop, this);

    LOG4CXX_INFO(logger, "Application started");

    // Return the future that will be resolved when the application has started
    return startPromise.get_future();
}

std::future<void> ApplicationPrivate::shutdown(const std::string& reason)
{
    LOG4CXX_INFO(logger, "Shutting down application: " << reason);

    // Reset the shutdown promise
    shutdownPromise = std::promise<void>();

    // Check if we're already shutting down or shutdown
    if (state.load() == State::ShuttingDown || state.load() == State::Shutdown) {
        LOG4CXX_WARN(logger, "Application already shutting down or shutdown");
        return shutdownPromise.get_future();
    }

    // If not running, we can skip the application loop shutdown
    if (state.load() != State::Running) {
        LOG4CXX_WARN(logger, "Application not running, setting state directly to Shutdown");
        state.store(State::Shutdown);
        shutdownPromise.set_value();
        return shutdownPromise.get_future();
    }

    // Signal the application thread to shutdown
    shutdownRequested.store(true);
    shutdownReason = reason;

    // Transition to shutting down state
    {
        std::lock_guard<std::mutex> lock(stateMutex);
        state.store(State::ShuttingDown);
        stateCondition.notify_all();
    }

    // If this is not the application thread, wait for it to complete
    if (appThread && appThread->joinable() &&
        appThread->get_id() != std::this_thread::get_id()) {
        LOG4CXX_DEBUG(logger, "Waiting for application thread to join");
        appThread->join();
        appThread.reset();
    }

    return shutdownPromise.get_future();
}

bool ApplicationPrivate::processArguments(int argc, char** argv)
{
    LOG4CXX_DEBUG(logger, "Processing command-line arguments");

    // Simple argument processing example
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        if (arg == "--config" && i + 1 < argc) {
            configPath = argv[++i];
            LOG4CXX_DEBUG(logger, "Config path set to: " << configPath);
        } else if (arg.find("--config=") == 0) {
            configPath = arg.substr(9);
            LOG4CXX_DEBUG(logger, "Config path set to: " << configPath);
        } else if (arg == "--help" || arg == "-h") {
            std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "  --config <path>  Path to the configuration file" << std::endl;
            std::cout << "  --help, -h       Show this help message" << std::endl;
            // This is not an error, but we indicate that the application should exit
            throw std::runtime_error("Help requested, exiting");
        }
        // Add more argument processing as needed
    }

    return true;
}

bool ApplicationPrivate::setupConfiguration()
{
    LOG4CXX_DEBUG(logger, "Setting up application configuration");

    // Set default application properties
    appName = "DefaultApp";
    appDescription = "Default Application Description";

    // If config path is provided, load configuration from file
    if (!configPath.empty()) {
        try {
            if (std::filesystem::exists(configPath)) {
                LOG4CXX_INFO(logger, "Loading configuration from: " << configPath);

                // Here you would implement your configuration loading logic
                // For example, using a config file parser, JSON, XML, etc.

                // For demonstration, we'll just check if the file exists
                std::ifstream configFile(configPath);
                if (!configFile.is_open()) {
                    LOG4CXX_WARN(logger, "Could not open configuration file: " << configPath);
                    return false;
                }

                // Parse configuration
                // ...

                configFile.close();
            } else {
                LOG4CXX_WARN(logger, "Configuration file not found: " << configPath);
                return false;
            }
        } catch (const std::exception& e) {
            LOG4CXX_ERROR(logger, "Error loading configuration: " << e.what());
            throw; // Re-throw to let the caller handle it
        }
    } else {
        LOG4CXX_INFO(logger, "No configuration file specified, using defaults");
    }

    return true;
}

bool ApplicationPrivate::initializeLogging()
{
    try {
        // If log configuration file is available, use it
        if (!configPath.empty()) {
            std::string logConfigPath = configPath + ".log4cxx";
            if (std::filesystem::exists(logConfigPath)) {
                LOG4CXX_INFO(logger, "Loading logging configuration from: " << logConfigPath);
                log4cxx::PropertyConfigurator::configure(logConfigPath);
                return true;
            }
        }

        // Otherwise, use basic configuration
        LOG4CXX_INFO(logger, "Using basic logging configuration");
        log4cxx::BasicConfigurator::configure();
        return true;
    } catch (const log4cxx::helpers::Exception& e) {
        std::cerr << "Failed to initialize logging: " << e.what() << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cerr << "Failed to initialize logging: " << e.what() << std::endl;
        return false;
    } catch (...) {
        std::cerr << "Failed to initialize logging due to unknown error" << std::endl;
        return false;
    }
}

void ApplicationPrivate::applicationLoop()
{
    LOG4CXX_DEBUG(logger, "Entering application main loop");

    try {
        // Signal that the application has started
        startPromise.set_value();

        // Main application loop
        while (!shutdownRequested.load()) {
            // Application logic goes here

            // For demonstration, we'll just sleep
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            // Check for shutdown condition
            if (shutdownRequested.load()) {
                LOG4CXX_DEBUG(logger, "Shutdown requested in application loop");
                break;
            }
        }

        // Perform shutdown operations
        performShutdown(shutdownReason);

        // Signal that shutdown is complete
        shutdownPromise.set_value();
    } catch (const std::exception& e) {
        LOG4CXX_ERROR(logger, "Exception in application loop: " << e.what());

        // If we haven't resolved the start promise yet, set the exception
        try {
            startPromise.set_exception(std::current_exception());
        } catch (const std::future_error& fe) {
            // Promise might already be satisfied
            LOG4CXX_WARN(logger, "Could not set start promise exception: " << fe.what());
        }

        // Set the shutdown promise exception
        try {
            shutdownPromise.set_exception(std::current_exception());
        } catch (const std::future_error& fe) {
            // Promise might already be satisfied
            LOG4CXX_WARN(logger, "Could not set shutdown promise exception: " << fe.what());
        }

        // Ensure state is set to Shutdown
        state.store(State::Shutdown);
    } catch (...) {
        LOG4CXX_ERROR(logger, "Unknown exception in application loop");

        // Similar error handling as above
        try {
            startPromise.set_exception(std::current_exception());
        } catch (const std::future_error&) {
            // Ignore
        }

        try {
            shutdownPromise.set_exception(std::current_exception());
        } catch (const std::future_error&) {
            // Ignore
        }

        state.store(State::Shutdown);
    }

    LOG4CXX_DEBUG(logger, "Exited application main loop");
}

void ApplicationPrivate::performShutdown(const std::string& reason)
{
    LOG4CXX_INFO(logger, "Performing application shutdown: " << reason);

    // Transition to shutting down state if not already
    {
        std::lock_guard<std::mutex> lock(stateMutex);
        if (state.load() != State::ShuttingDown) {
            state.store(State::ShuttingDown);
            stateCondition.notify_all();
        }
    }

    // Perform cleanup operations
    // ...

    // Transition to shutdown state
    {
        std::lock_guard<std::mutex> lock(stateMutex);
        state.store(State::Shutdown);
        stateCondition.notify_all();
    }

    LOG4CXX_INFO(logger, "Application shutdown complete");
}
*/
// log4cxx::LoggerPtr ApplicationPrivate::logger =
//     log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.ApplicationPrivate"));
//
//
// ApplicationPrivate::ApplicationPrivate() noexcept
//     // : d_ptr(std::make_unique<ApplicationPrivate>()) //: Application(0, nullptr) {}
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     // Q_D(Application);
// }
//
// ApplicationPrivate::~ApplicationPrivate() noexcept
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     // Q_D ( Application );
// }