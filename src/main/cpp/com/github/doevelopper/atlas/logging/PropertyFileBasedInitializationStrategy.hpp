/*******************************************************************
* @file
 * @version  v0.0.
 * @date     02/11/24 W 13:39
 * @brief
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_PROPERTYFILEBASEDINITIALIZATIONSTRATEGY_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_PROPERTYFILEBASEDINITIALIZATIONSTRATEGY_HPP

#include <com/github/doevelopper/atlas/logging/ILoggingInitializationStrategy.hpp>

namespace com::github::doevelopper::atlas::logging
{
    /**
     * @class PropertyFileBasedInitializationStrategy
     * @brief Pass the path to a log4cxx.properties file to configure logging via a configuration file.
     */
    class PropertyFileBasedInitializationStrategy : public ILoggingInitializationStrategy
    {
    public:

        PropertyFileBasedInitializationStrategy() noexcept;
        PropertyFileBasedInitializationStrategy(const PropertyFileBasedInitializationStrategy&) = delete;
        PropertyFileBasedInitializationStrategy(PropertyFileBasedInitializationStrategy&&) = default;
        PropertyFileBasedInitializationStrategy& operator=(const PropertyFileBasedInitializationStrategy&) = delete;
        PropertyFileBasedInitializationStrategy& operator=(PropertyFileBasedInitializationStrategy&&) = default;
        virtual ~PropertyFileBasedInitializationStrategy() noexcept;

        explicit PropertyFileBasedInitializationStrategy(const std::string& filePath);
        /**
         * Initialize from a properties file via URL
         * @param urlString URL pointing to .properties file
         * @throws std::runtime_error if already initialized or configuration fails
         */
        /**
         * Initialize from a properties file
         * @param filePath Path to .properties file
         * @throws std::runtime_error if already initialized or configuration fails
         */
        void initialize() const override;
    protected:
    private:
        std::string m_configFilePath;
    };

}

#endif
