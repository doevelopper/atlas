
#include <com/github/doevelopper/atlas/logging/LoggingInitializer.hpp>

#include <log4cxx/logmanager.h>

using namespace com::github::doevelopper::atlas::logging;

LoggingInitializer::LoggingInitializer() noexcept
{

}

LoggingInitializer::~LoggingInitializer() noexcept
{

}

LoggingInitializer::LoggingInitializer(std::unique_ptr<ILoggingInitializationStrategy> initStrategy)
    : m_strategy(std::move(initStrategy))
{

}

void LoggingInitializer::initialize() const
{
    if (!this->m_strategy)
    {
        throw std::runtime_error("No initialization strategy provided.");
    }
    this->m_strategy->initialize();
}

bool LoggingInitializer::isInitialized()
{
    auto repository = log4cxx::LogManager::getLoggerRepository();
    return repository && repository->isConfigured();
}

/*
// Example usage
int main() {
    try {
        // Option 1: Initialize with a configuration file
        auto fileStrategy = LogInitializationFactory::createStrategy("log4cxx.properties");
        LogInitializer fileInitializer(std::move(fileStrategy));
        fileInitializer.initialize();

        // Option 2: Initialize programmatically
        auto programmaticStrategy = LogInitializationFactory::createStrategy("programmatic");
        LogInitializer programmaticInitializer(std::move(programmaticStrategy));
        programmaticInitializer.initialize();

        // Option 3: Default initialization
        auto defaultStrategy = LogInitializationFactory::createStrategy();
        LogInitializer defaultInitializer(std::move(defaultStrategy));
        defaultInitializer.initialize();

        // Example log message
        auto logger = log4cxx::Logger::getLogger("MainLogger");
        LOG4CXX_INFO(logger, "Log4CXX has been successfully initialized!");

    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
 */