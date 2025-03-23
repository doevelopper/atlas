
#include <com/github/doevelopper/atlas/logging/DefaultInitializationStrategy.hpp>

using namespace com::github::doevelopper::atlas::logging;

DefaultInitializationStrategy::DefaultInitializationStrategy() noexcept
{

}

DefaultInitializationStrategy::~DefaultInitializationStrategy() noexcept
{

}

void DefaultInitializationStrategy::initialize() const
{
    try
    {
        log4cxx::BasicConfigurator::configure();
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "Log4CXX initialized with default configuration.");
    }
    catch (const log4cxx::helpers::Exception& ex)
    {
        throw std::runtime_error("Failed to initialize Log4CXX with default configuration: " + std::string(ex.what()));
    }
}