
#include <com/github/doevelopper/atlas/logging/ProgrammaticInitializationStrategy.hpp>

using namespace com::github::doevelopper::atlas::logging;

ProgrammaticInitializationStrategy::ProgrammaticInitializationStrategy() noexcept
{

}

ProgrammaticInitializationStrategy::~ProgrammaticInitializationStrategy() noexcept
{
    // if (log4cxx::LogManager::getLoggerRepository()->isConfigured())
    // {
    //     LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);
    // }
}

void ProgrammaticInitializationStrategy::initialize() const
{
    try
    {
        // log4cxx::PatternLayoutPtr layout(new log4cxx::PatternLayout(LOG4CXX_STR("%d{yyyy-MM-dd HH:mm:ss.SSS} %Y [%-6p] %y - [%15.15t] - %-35c{1.} -- %Y %m%y%n")));
        auto layout = std::make_shared<log4cxx::PatternLayout>(LOG4CXX_STR("%d{yyyy-MM-dd HH:mm:ss.SSS} %Y [%-6p] %y - [%15.15t] - %-35c{1.} -- %Y %m%y%n"));
        // auto layout = std::make_shared<log4cxx::PatternLayout>("%d [%t] %-5p %c - %m%n");
        auto appender = std::make_shared<log4cxx::ConsoleAppender>(layout);
        log4cxx::BasicConfigurator::configure(appender);

        auto loggingLogger = log4cxx::Logger::getLogger("com.github.doevelopper.atlas.logging.ProgrammaticInitializationStrategy");

        LOG4CXX_INFO(loggingLogger, " --------------START LOGGING---------------");
        // LOG4CXX_INFO(loggingLogger,  __LOG4CXX_FUNC__ << " ----START LOGGING-----");
        // LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "Log4CXX initialized programmatically.");
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