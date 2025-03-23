#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_XMLFILEBASEDINITIALIZATIONSTRATEGY_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_XMLFILEBASEDINITIALIZATIONSTRATEGY_HPP

#include <log4cxx/logger.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <fstream>
#include <string>

#include <com/github/doevelopper/atlas/logging/ILoggingInitializationStrategy.hpp>

namespace com::github::doevelopper::atlas::logging
{
    /**
     * @class XMLFileBasedInitializationStrategy
     * @brief A class to initialize the Log4CXX logging library in various ways.
     */
    class XMLFileBasedInitializationStrategy : public ILoggingInitializationStrategy
    {
    public:

        XMLFileBasedInitializationStrategy() noexcept;
        XMLFileBasedInitializationStrategy(const XMLFileBasedInitializationStrategy&) = delete;
        XMLFileBasedInitializationStrategy(XMLFileBasedInitializationStrategy&&) = default;
        XMLFileBasedInitializationStrategy& operator=(const XMLFileBasedInitializationStrategy&) = delete;
        XMLFileBasedInitializationStrategy& operator=(XMLFileBasedInitializationStrategy&&) = default;
        virtual ~XMLFileBasedInitializationStrategy() noexcept;
        /**
         * Initialize from an XML configuration via URL
         * @param urlString URL pointing to XML configuration
         * @throws std::runtime_error if already initialized or configuration fails
         */
        /**
         * Initialize from an XML configuration file
         * @param filePath Path to XML configuration file
         * @throws std::runtime_error if already initialized or configuration fails
         */
        void initialize() const override;

        // Private method to check if file exists
        bool fileExists(const std::string& filename)
        {
            std::ifstream file(filename);
            return file.good();
        }
    protected:
    private:
    };

}

#endif
