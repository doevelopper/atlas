
#include <com/github/doevelopper/atlas/logging/ProgrammaticInitializationStrategy.hpp>

using namespace com::github::doevelopper::atlas::logging;

ProgrammaticInitializationStrategy::ProgrammaticInitializationStrategy() noexcept
{

}

ProgrammaticInitializationStrategy::~ProgrammaticInitializationStrategy() noexcept
{

}

void ProgrammaticInitializationStrategy::initialize() const
{
    try
    {
        auto layout = std::make_shared<log4cxx::PatternLayout>("%d [%t] %-5p %c - %m%n");
        auto appender = std::make_shared<log4cxx::ConsoleAppender>(layout);
        log4cxx::BasicConfigurator::configure(appender);
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "Log4CXX initialized programmatically.");
    }
    catch (const log4cxx::helpers::Exception& ex)
    {
        throw std::runtime_error("Failed to initialize Log4CXX programmatically: " + std::string(ex.what()));
    }

    // checkInitialized();
    // try
    //     {
    //     auto layout = log4cxx::PatternLayout::newInstance("%d{ISO8601} [%t] %-5p %c - %m%n");
    //     auto appender = log4cxx::ConsoleAppender::newInstance(layout);
    //     auto rootLogger = log4cxx::Logger::getRootLogger();
    //
    //     rootLogger->addAppender(appender);
    //     rootLogger->setLevel(log4cxx::Level::getInfo());
    // }
    // catch (log4cxx::helpers::Exception& e)
    // {
    //     throw std::runtime_error("Programmatic init failed: " + std::string(e.what()));
    // }
}