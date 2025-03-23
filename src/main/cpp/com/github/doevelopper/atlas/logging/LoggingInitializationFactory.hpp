#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_LOGGINGINITIALIZATIONFACTORY_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_LOGGINGINITIALIZATIONFACTORY_HPP

#include <com/github/doevelopper/atlas/logging/ILoggingInitializationStrategy.hpp>
#include <com/github/doevelopper/atlas/logging/PropertyFileBasedInitializationStrategy.hpp>
#include <com/github/doevelopper/atlas/logging/ProgrammaticInitializationStrategy.hpp>
#include <com/github/doevelopper/atlas/logging/XMLFileBasedInitializationStrategy.hpp>
#include <com/github/doevelopper/atlas/logging/DefaultInitializationStrategy.hpp>

namespace com::github::doevelopper::atlas::logging
{
    /**
     * @class LoggingInitializationFactory
     * @brief A class to initialize the Log4CXX logging library in various ways.
     */
    class LoggingInitializationFactory : public ILoggingInitializationStrategy
    {
    public:

        LoggingInitializationFactory() noexcept;
        LoggingInitializationFactory(const LoggingInitializationFactory&) = delete;
        LoggingInitializationFactory(LoggingInitializationFactory&&) = default;
        LoggingInitializationFactory& operator=(const LoggingInitializationFactory&) = delete;
        LoggingInitializationFactory& operator=(LoggingInitializationFactory&&) = default;
        virtual ~LoggingInitializationFactory() noexcept;

        static std::unique_ptr<ILoggingInitializationStrategy> createStrategy(const std::string& configFilePath = "")
        {
            if (!configFilePath.empty())
            {
                return std::make_unique<PropertyFileBasedInitializationStrategy>(configFilePath);
            }
            else if (configFilePath == "programmatic")
            {
                return std::make_unique<ProgrammaticInitializationStrategy>();
            }
            else
            {
                return std::make_unique<DefaultInitializationStrategy>();
            }
        }
    protected:
    private:
    };

}

#endif
