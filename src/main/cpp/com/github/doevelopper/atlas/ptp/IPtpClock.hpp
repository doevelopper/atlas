/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     02/11/24 W 13:37
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

//
// Created by hroland on 02/11/24.
//

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_PTP_IPTP_CLOCK_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_PTP_IPTP_CLOCK_HPP

#include <com/github/doevelopper/atlas/logging/ILoggingInitializationStrategy.hpp>

namespace com::github::doevelopper::atlas::ptp
{
    /*!
     * @brief Interface for PTP clock.
     *
     * @details This interface provides methods to manage and control a PTP clock.
     */
    class IPtpClock
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        IPtpClock() noexcept;
        IPtpClock(const IPtpClock&) = default;
        IPtpClock(IPtpClock&&) = default;
        IPtpClock& operator=(const IPtpClock&) = default;
        IPtpClock& operator=(IPtpClock&&) = default;
        virtual ~IPtpClock() noexcept;
    protected:
    private:
    };

    using IPtpClockPtr = std::shared_ptr<IPtpClock>;
    using IPtpClockConstPtr = std::shared_ptr<const IPtpClock>;
    using IPtpClockWeakPtr = std::weak_ptr<IPtpClock>;
    using IPtpClockWeakConstPtr = std::weak_ptr<const IPtpClock>;
    using IPtpClockUniquePtr = std::unique_ptr<IPtpClock>;
    using IPtpClockUniqueConstPtr = std::unique_ptr<const IPtpClock>;
    using IPtpClockSharedPtr = std::shared_ptr<IPtpClock>;
    using IPtpClockSharedConstPtr = std::shared_ptr<const IPtpClock>;

}
#endif
