
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <log4cxx/xml/domconfigurator.h>


#include <com/github/doevelopper/atlas/logging/EnvironmentBasedInitializationStrategy.hpp>

using namespace com::github::doevelopper::atlas::logging;

EnvironmentBasedInitializationStrategy::EnvironmentBasedInitializationStrategy() noexcept
{

}

EnvironmentBasedInitializationStrategy::~EnvironmentBasedInitializationStrategy() noexcept
{

}

EnvironmentBasedInitializationStrategy::EnvironmentBasedInitializationStrategy(const std::string& envVarName, bool fallbackToBasic)
: m_envVarName(envVarName)
, m_fallbackToBasic(fallbackToBasic)
{

}

void EnvironmentBasedInitializationStrategy::initialize() const
{
    try
    {
        const char* configPath = std::getenv(m_envVarName.c_str());
        if (configPath != nullptr)
        {
            std::string path(configPath);

            if (path.ends_with(".xml"))
            {
                log4cxx::xml::DOMConfigurator::configure(path);
            }
            else if (path.ends_with(".properties"))
            {
                log4cxx::PropertyConfigurator::configure(path);
            }
            else
            {
                if (m_fallbackToBasic)
                {
                    log4cxx::BasicConfigurator::configure();
                    log4cxx::Logger::getRootLogger()->setLevel(log4cxx::Level::getWarn());
                }
                else
                {
                    // return false;
                }
            }
            // return true;
        }
        else if (m_fallbackToBasic)
        {
            log4cxx::BasicConfigurator::configure();
            log4cxx::Logger::getRootLogger()->setLevel(log4cxx::Level::getWarn());
            // return true;
        }
        else
        {
            // return false;
        }
    }
    catch (const log4cxx::helpers::Exception& e)
        {
        // return false;
    }
}

void EnvironmentBasedInitializationStrategy::appendenv(const char* varname, const char* append)
{
    char buf[2048] = "";
    const char* value = append;
    const char* old = getenv(varname);
    if (old != NULL)
    {
        snprintf(buf, sizeof(buf)-1, "%s:%s", old, append);
        buf[sizeof(buf)-1] = '\0';
        value = buf;
    }
    setenv(varname, value, 1);
}
