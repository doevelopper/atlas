/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     18/03/25 W 22:38
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2025 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_SECURITY_CONFIGTOOL_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_SECURITY_CONFIGTOOL_HPP


#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::security
{
    /**
     * Command line tool for generating basic settings.
     */
    class ConfigTool
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        ConfigTool() = default;
        ConfigTool(const ConfigTool&) = default;
        ConfigTool(ConfigTool&&) = default;
        ConfigTool& operator=(const ConfigTool&) = default;
        ConfigTool& operator=(ConfigTool&&) = default;
        virtual ~ConfigTool() = default;

        /**
         * Interactively generates application settings.
         */
        void execute() noexcept;
    protected:
    private:
        static void generateKeyPair();
        static void manageHosts();
        static void generateVerifier();
        static void createDummyHostsFile(const char *path);
    };
}
#endif //CONFIGTOOL_HPP
