
#include <com/github/doevelopper/atlas/logging/XMLFileBasedInitializationStrategy.hpp>

using namespace com::github::doevelopper::atlas::logging;

XMLFileBasedInitializationStrategy::XMLFileBasedInitializationStrategy() noexcept
{

}

XMLFileBasedInitializationStrategy::~XMLFileBasedInitializationStrategy() noexcept
{

}

void XMLFileBasedInitializationStrategy::initialize() const
{
    // try
    // {
    //     if (this->m_configFilePath.empty())
    //     {
    //         throw std::invalid_argument("Configuration file path is empty.");
    //     }
    //
    //     log4cxx::PropertyConfigurator::configure(this->m_configFilePath);
    //     LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "Log4CXX initialized with configuration file.");
    //
    // }
    // catch (const log4cxx::helpers::Exception& ex)
    // {
    //     throw std::runtime_error("Failed to initialize Log4CXX with file: " + std::string(ex.what()));
    // }

    // checkInitialized();
    // try
    //     {
    //     log4cxx::helpers::URL url(urlString);
    //     log4cxx::xml::XMLConfigurator::configure(url);
    // } catch (log4cxx::helpers::Exception& e)
    //     {
    //     throw std::runtime_error("XML URL init failed: " + std::string(e.what()));
    // }

    // checkInitialized();
    // try {
    //     log4cxx::xml::XMLConfigurator::configure(filePath);
    // } catch (log4cxx::helpers::Exception& e) {
    //     throw std::runtime_error("XML file init failed: " + std::string(e.what()));
    // }

}