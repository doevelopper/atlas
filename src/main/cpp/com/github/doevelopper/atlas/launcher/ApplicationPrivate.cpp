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
using namespace com::github::doevelopper::atlas::semver;

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
    this->initializeLogging();
    LOG4CXX_DEBUG(logger, __LOG4CXX_FUNC__ << " Constructor called");
}

ApplicationPrivate::ApplicationPrivate(Application* q, int argc, char** argv) noexcept
    // : q_ptr(q)
    // , state(State::NotInitialized)
    // , argc(argc)
    // , argv(argv)
    // , appVersion(std::make_unique<Version>())
    // , shutdownRequested(false)
{
    //processArguments(argc, argv);
    this->initializeLogging();
    LOG4CXX_DEBUG(logger, __LOG4CXX_FUNC__ << " Constructor with arguments called");
}

ApplicationPrivate::~ApplicationPrivate() noexcept
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);

    if (log4cxx::LogManager::getLoggerRepository()->isConfigured())
    {
        //LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__ << " ---- END LOGGING -----");
        // LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__ << " ---- END LOGGING -----");
        LOG4CXX_INFO(logger, " --------------END LOGGING---------------");
    }
    log4cxx::LogManager::shutdown();

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

bool ApplicationPrivate::initialize()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // State transition check
    {
        std::lock_guard<std::mutex> lock(stateMutex);
        if (state.load() != State::NotInitialized)
        {
            LOG4CXX_WARN(logger, __LOG4CXX_FUNC__ << " Application already initialized or initializing");
            return false;
        }
        state.store(State::Initializing);
    }

    try
    {
        // // Initialize logging first to ensure proper error reporting
        // if (!initializeLogging()) {
        //     LOG4CXX_ERROR(logger, __LOG4CXX_FUNC__ <<  " Failed to initialize logging");
        //     state.store(State::NotInitialized);
        //     return false;
        // }

        // Setup configuration
        if (!setupConfiguration()) {
            LOG4CXX_ERROR(logger, __LOG4CXX_FUNC__ <<  " Failed to setup configuration");
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

        LOG4CXX_INFO(logger, __LOG4CXX_FUNC__ <<  " Application initialized successfully");
        return true;
    }
    catch (const std::exception& e)
    {
        LOG4CXX_ERROR(logger, __LOG4CXX_FUNC__ <<  " Initialization failed with exception: " << e.what());
        state.store(State::NotInitialized);
        throw std::runtime_error(std::string("Initialization failed: ") + e.what());
    }
    catch (...)
    {
        LOG4CXX_ERROR(logger, __LOG4CXX_FUNC__ <<  " Initialization failed with unknown exception");
        state.store(State::NotInitialized);
        throw std::runtime_error("Initialization failed with unknown error");
    }
}

bool ApplicationPrivate::initializeLogging()
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    
    try {
    //     // First check for environment-based configuration
    // auto envStrategy = std::make_unique<com::github::doevelopper::atlas::logging::EnvironmentBasedInitializationStrategy>("LOG4CXX_CONFIGURATION", true);
    // auto initializer = std::make_unique<com::github::doevelopper::atlas::logging::LoggingInitializer>(std::move(envStrategy));
    // initializer->initialize();

    auto envStrategy = std::make_unique<com::github::doevelopper::atlas::logging::ProgrammaticInitializationStrategy>();
    auto initializer = std::make_unique<com::github::doevelopper::atlas::logging::LoggingInitializer>(std::move(envStrategy));
    initializer->initialize();

        
    //     LOG4CXX_INFO(logger, "Logging system initialized successfully");
        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Failed to initialize logging: " << e.what() << std::endl;
        return false;
    } catch (...) {
        std::cerr << "Failed to initialize logging with unknown error" << std::endl;
        return false;
    }
}

bool ApplicationPrivate::setupConfiguration()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    
    // try {
    //     // Default configuration path if not set
    //     if (configPath.empty()) {
    //         configPath = "config/atlas.properties";
            
    //         // Check for environment variable
    //         if (const char* env_config = std::getenv("ATLAS_CONFIG_PATH")) {
    //             configPath = env_config;
    //         }
    //     }
        
    //     // Check if the configuration file exists
    //     if (!std::filesystem::exists(configPath)) {
    //         LOG4CXX_WARN(logger, "Configuration file not found at: " << configPath);
    //         LOG4CXX_INFO(logger, "Using default configuration settings");
    //         // Fall back to default settings
    //         return true;
    //     }
        
    //     LOG4CXX_INFO(logger, "Loading configuration from: " << configPath);
    //     // Here you would load the configuration file
    //     // For now, we'll just return success
        
    //     return true;
    // } catch (const std::exception& e) {
    //     LOG4CXX_ERROR(logger, "Failed to setup configuration: " << e.what());
    //     return false;
    // } catch (...) {
    //     LOG4CXX_ERROR(logger, "Failed to setup configuration with unknown error");
    //     return false;
    // }
    return false; // fir debugging
}

std::future<void> ApplicationPrivate::run()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    try
    {
        // Reset the promise before starting
        this->startPromise = std::promise<void>();

        // Check if already running
        if (state.load() == State::Running)
        {
            LOG4CXX_WARN(logger, __LOG4CXX_FUNC__ << " Application is already running");
            startPromise.set_value(); // Fulfill the promise immediately
            return startPromise.get_future();
        }

        // Check if initialized
        if (state.load() != State::Initialized)
        {
            // Try to initialize if not already done
            if (!this->initialize())
            {
                LOG4CXX_ERROR(logger, __LOG4CXX_FUNC__ << " Failed to initialize application");
                startPromise.set_exception(std::make_exception_ptr( std::runtime_error("Failed to initialize application")));
                return startPromise.get_future();
            }
        }

        // Update state and create thread
        {
            std::lock_guard<std::mutex> lock(stateMutex);
            state.store(State::Running);
            stateCondition.notify_all();
    //
    //         // Create a thread for the application loop
    //         appThread = std::make_unique<std::thread>([this]()
    //         {
    //             try
    //             {
    //                 LOG4CXX_INFO(logger, __LOG4CXX_FUNC__ << " Application thread started");
    //
    //                 // Signal that we've started
    //                 startPromise.set_value();
    //
    //                 // Run the application loop
    //                 applicationLoop();
    //
    //             }
    //             catch (const std::exception& e)
    //             {
    //                 LOG4CXX_ERROR(logger, __LOG4CXX_FUNC__ << " Exception in application thread: " << e.what());
    //
    //                 // If we haven't set the promise yet, set the exception
    //                 try
    //                 {
    //                     startPromise.set_exception(std::current_exception());
    //                 }
    //                 catch (const std::future_error&)
    //                 {
    //                     // Promise already satisfied, ignore
    //                 }
    //
    //                 // Initiate shutdown due to error
    //                 performShutdown("Exception in application thread: " + std::string(e.what()));
    //             }
    //             catch (...)
    //             {
    //                 LOG4CXX_ERROR(logger, __LOG4CXX_FUNC__ << " Unknown exception in application thread");
    //
    //                 // If we haven't set the promise yet, set the exception
    //                 try
    //                 {
    //                     startPromise.set_exception(std::current_exception());
    //                 }
    //                 catch (const std::future_error&)
    //                 {
    //                     // Promise already satisfied, ignore
    //                 }
    //
    //                 // Initiate shutdown due to error
    //                 performShutdown("Unknown exception in application thread");
    //             }
    //         });
        }

        LOG4CXX_INFO(logger, __LOG4CXX_FUNC__ << " Application starting asynchronously");
        return startPromise.get_future();

    }
    catch (const std::exception& e)
    {
        LOG4CXX_ERROR(logger, __LOG4CXX_FUNC__ << " Failed to start application: " << e.what());

        // Set the exception to propagate it to the caller
        startPromise.set_exception(std::current_exception());
        return startPromise.get_future();
    }
    catch (...)
    {
        LOG4CXX_ERROR(logger, __LOG4CXX_FUNC__ << " Failed to start application with unknown error");

        // Set the exception to propagate it to the caller
        startPromise.set_exception(std::make_exception_ptr(std::runtime_error("Failed to start application with unknown error")));
        return startPromise.get_future();
    }
}

void ApplicationPrivate::applicationLoop()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    
    LOG4CXX_INFO(logger, "Application main loop started");
    
    // Main application loop
    while (!shutdownRequested.load()) {
        // Process events, update application state, etc.
        
        // For now, just sleep to avoid high CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    LOG4CXX_INFO(logger, "Application main loop ended");
    
    // Update state to indicate shutdown
    {
        std::lock_guard<std::mutex> lock(stateMutex);
        state.store(State::Shutdown);
        stateCondition.notify_all();
    }
}

void ApplicationPrivate::performShutdown(const std::string& reason)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    
    LOG4CXX_INFO(logger, "Shutting down application: " << reason);
    
    // Set the shutdown flag to stop the main loop
    shutdownRequested.store(true);
    shutdownReason = reason;
    
    // Update state
    {
        std::lock_guard<std::mutex> lock(stateMutex);
        state.store(State::ShuttingDown);
        stateCondition.notify_all();
    }
}

std::future<void> ApplicationPrivate::shutdown(const std::string& reason)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    
    // Reset the promise
    shutdownPromise = std::promise<void>();
    
    try {
        // If not running, return immediately
        if (state.load() != State::Running) {
            LOG4CXX_WARN(logger, "Application is not running, cannot shut down");
            shutdownPromise.set_value();
            return shutdownPromise.get_future();
        }
        
        // Initiate shutdown
        performShutdown(reason);
        
        // Create a thread to wait for the application to shut down
        std::thread shutdownThread([this]() {
            try {
                // Wait for application thread to finish
                if (appThread && appThread->joinable()) {
                    appThread->join();
                }
                
                LOG4CXX_INFO(logger, "Application shutdown complete");
                shutdownPromise.set_value();
            } catch (const std::exception& e) {
                LOG4CXX_ERROR(logger, "Exception during shutdown: " << e.what());
                shutdownPromise.set_exception(std::current_exception());
            } catch (...) {
                LOG4CXX_ERROR(logger, "Unknown exception during shutdown");
                shutdownPromise.set_exception(std::make_exception_ptr(
                    std::runtime_error("Unknown exception during shutdown")));
            }
        });
        
        // Detach the thread as we'll track completion via the promise
        shutdownThread.detach();
        
        return shutdownPromise.get_future();
    } catch (const std::exception& e) {
        LOG4CXX_ERROR(logger, "Failed to initiate shutdown: " << e.what());
        shutdownPromise.set_exception(std::current_exception());
        return shutdownPromise.get_future();
    } catch (...) {
        LOG4CXX_ERROR(logger, "Failed to initiate shutdown with unknown error");
        shutdownPromise.set_exception(std::make_exception_ptr(
            std::runtime_error("Failed to initiate shutdown with unknown error")));
        return shutdownPromise.get_future();
    }
}
