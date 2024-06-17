/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     17/06/24 W 19:55
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_OBS_OBSERVERREGISTRARMOCK_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_OBS_OBSERVERREGISTRARMOCK_HPP

#include <gmock/gmock.h>

#include <com/github/doevelopper/atlas/events/obs/ObserverRegistrar.hpp>

namespace com::github::doevelopper::atlas::events::obs::test
{
    class ObserverRegistrarMock
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        ObserverRegistrarMock() noexcept;
        ObserverRegistrarMock(const ObserverRegistrarMock&) = default;
        ObserverRegistrarMock(ObserverRegistrarMock&&) = default;
        ObserverRegistrarMock& operator=(const ObserverRegistrarMock&) = default;
        ObserverRegistrarMock& operator=(ObserverRegistrarMock&&) = default;
        virtual ~ObserverRegistrarMock()  noexcept;
    protected:
    private:
    };
}


#endif
