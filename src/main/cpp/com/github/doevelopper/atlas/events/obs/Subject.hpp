/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     08/06/24 W 21:10
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_OBS_SUBJECT_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_OBS_SUBJECT_HPP

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::events::obs
{
    class Subject
    {
        Q_DISABLE_COPY_MOVE(Subject)
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        Subject() noexcept;
        ~Subject() noexcept;
    protected:
    private:
    };
}

#endif
