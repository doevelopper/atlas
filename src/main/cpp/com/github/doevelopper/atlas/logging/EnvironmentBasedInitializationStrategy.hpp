#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_ENVIRONMENTBASEDINITIALIZATIONSTRATEGY_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_ENVIRONMENTBASEDINITIALIZATIONSTRATEGY_HPP

#include <fstream>
#include <string>

#include <com/github/doevelopper/atlas/logging/ILoggingInitializationStrategy.hpp>

namespace com::github::doevelopper::atlas::logging
{
    /**
     * @class EnvironmentBasedInitializationStrategy
     * @brief A class to initialize the Log4CXX logging library in various ways.
     * @brief Environment variable initialization strategy for Log4CXX
     *
     * Configures Log4CXX based on environment variables.
     */
    class EnvironmentBasedInitializationStrategy : public ILoggingInitializationStrategy
    {
    public:

        EnvironmentBasedInitializationStrategy() noexcept;
        /**
         * @brief Constructor with environment variable name
         * @param envVarName Name of the environment variable containing the config file path
         * @param fallbackToBasic Whether to fall back to basic configuration if env var isn't set
         */
        explicit EnvironmentBasedInitializationStrategy(const std::string& envVarName = "LOG4CXX_CONFIG", bool fallbackToBasic = true);
        EnvironmentBasedInitializationStrategy(const EnvironmentBasedInitializationStrategy&) = delete;
        EnvironmentBasedInitializationStrategy(EnvironmentBasedInitializationStrategy&&) = default;
        EnvironmentBasedInitializationStrategy& operator=(const EnvironmentBasedInitializationStrategy&) = delete;
        EnvironmentBasedInitializationStrategy& operator=(EnvironmentBasedInitializationStrategy&&) = default;
        virtual ~EnvironmentBasedInitializationStrategy() noexcept;
        /**
          * @brief Initialize Log4CXX based on environment variable
          * @return bool True if initialization was successful
          */
        void initialize() const override;
        void appendenv(const char* varname, const char* append);
        // Private method to check if file exists
        bool fileExists(const std::string& filename)
        {
            std::ifstream file(filename);
            return file.good();
        }
    protected:
    private:
        std::string m_envVarName;
        bool m_fallbackToBasic;
    };

}

#endif
