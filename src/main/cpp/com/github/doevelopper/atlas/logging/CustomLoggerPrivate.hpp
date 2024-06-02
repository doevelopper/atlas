
/*******************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief    Main entry point of application
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_CUSTOMLOGGERPRIVATE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_CUSTOMLOGGERPRIVATE_HPP

#include <apr-1/apr.h>
#include <log4cxx/appender.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/fileappender.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/logger.h>
#include <log4cxx/logmanager.h>
#include <log4cxx/logstring.h> // has typedefed string type used in log4cxx
// #include <log4cxx/net/socketappender.h>
#include <stdexcept>
#include <string>
#include <log4cxx/nt/nteventlogappender.h>
#include <log4cxx/nt/outputdebugstringappender.h> // NT OUTPUTDEBUGSTRING Appender
#include <log4cxx/patternlayout.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/rolling/fixedwindowrollingpolicy.h>
#include <log4cxx/rolling/rollingfileappender.h>
#include <log4cxx/rolling/rollingpolicy.h>
#include <log4cxx/rolling/rollingpolicybase.h>
#include <log4cxx/rolling/sizebasedtriggeringpolicy.h>
#include <log4cxx/rolling/triggeringpolicy.h>
#include <log4cxx/simplelayout.h>
#include <log4cxx/xml/domconfigurator.h>

namespace com::github::doevelopper::atlas::logging
{
    class CustomLoggerPrivate
    {
    public:
        CustomLoggerPrivate() noexcept;
        CustomLoggerPrivate(const CustomLoggerPrivate&) noexcept = delete;
        CustomLoggerPrivate(CustomLoggerPrivate&&) noexcept =  delete;
        CustomLoggerPrivate& operator=(const CustomLoggerPrivate&) noexcept = delete;
        CustomLoggerPrivate& operator=(CustomLoggerPrivate&&) noexcept = delete;
        virtual ~CustomLoggerPrivate() noexcept;

        explicit CustomLoggerPrivate(std::uint32_t delay);
        bool initLogger();

    protected:
    private:
        bool checkLogManagerStatus();
        /*!
         *  @brief Value for periodical check if configFilename has been created
         * or modified!
         */
        std::uint32_t m_watchPeriod;
    };
}

#endif //CUSTOMLOGGERPRIVATE_HPP
