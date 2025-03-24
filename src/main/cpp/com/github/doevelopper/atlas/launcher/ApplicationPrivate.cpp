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
    // LOG4CXX_INFO(logger, "Initializing application");

    // State transition check
    // {
    //     std::lock_guard<std::mutex> lock(stateMutex);
    //     if (state.load() != State::NotInitialized) 
    //     {
    //         LOG4CXX_WARN(logger, "Application already initialized or initializing");
    //         return false;
    //     }
    //     state.store(State::Initializing);
    // }

    // try 
    // {
    //     // Initialize logging first to ensure proper error reporting
    //     if (!initializeLogging()) {
    //         LOG4CXX_ERROR(logger, "Failed to initialize logging");
    //         state.store(State::NotInitialized);
    //         return false;
    //     }

    //     // Setup configuration
    //     if (!setupConfiguration()) {
    //         LOG4CXX_ERROR(logger, "Failed to setup configuration");
    //         state.store(State::NotInitialized);
    //         return false;
    //     }

    //     // Additional initialization steps can be added here

    //     // Transition to initialized state
    //     {
    //         std::lock_guard<std::mutex> lock(stateMutex);
    //         state.store(State::Initialized);
    //         stateCondition.notify_all();
    //     }

    //     LOG4CXX_INFO(logger, "Application initialized successfully");
    //     return true;
    // } catch (const std::exception& e) {
    //     LOG4CXX_ERROR(logger, "Initialization failed with exception: " << e.what());
    //     state.store(State::NotInitialized);
    //     throw std::runtime_error(std::string("Initialization failed: ") + e.what());
    // } catch (...) {
    //     LOG4CXX_ERROR(logger, "Initialization failed with unknown exception");
    //     state.store(State::NotInitialized);
    //     throw std::runtime_error("Initialization failed with unknown error");
    // }
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
}
