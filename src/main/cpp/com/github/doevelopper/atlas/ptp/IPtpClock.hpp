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
        /*!
         * @brief Start the PTP clock.
         *
         * @details This method starts the PTP clock.
         */
        virtual void start() = 0;
        /*!
         * @brief Stop the PTP clock.
         *
         * @details This method stops the PTP clock.
         */
        virtual void stop() = 0;
        /*!
         * @brief Reset the PTP clock.
         *
         * @details This method resets the PTP clock.
         */
        virtual void reset() = 0;
        /*!
         * @brief Set the PTP clock to a specific time.
         *
         * @details This method sets the PTP clock to a specific time.
         */
        virtual void setTime(const std::chrono::nanoseconds& time) = 0;
        /*!
         * @brief Get the current time of the PTP clock.
         *
         * @details This method retrieves the current time of the PTP clock.
         */
        virtual std::chrono::nanoseconds getTime() const = 0;
        /*!
         * @brief Get the current time of the PTP clock in nanoseconds.
         *
         * @details This method retrieves the current time of the PTP clock in nanoseconds.
         */
        virtual std::chrono::nanoseconds getTimeInNanoseconds() const = 0;
        /*!
         * @brief Get the current time of the PTP clock in microseconds.
         *
         * @details This method retrieves the current time of the PTP clock in microseconds.
         */
        virtual std::chrono::microseconds getTimeInMicroseconds() const = 0;
        /*!
         * @brief Get the current time of the PTP clock in milliseconds.
         *
         * @details This method retrieves the current time of the PTP clock in milliseconds.
         */
        virtual std::chrono::milliseconds getTimeInMilliseconds() const = 0;
        /*!
         * @brief Start the PTP clock.
         *
         * @details This method starts the PTP clock.
         */
        virtual void update(const std::chrono::nanoseconds& offset) = 0;
        /*!
         * @brief Stop the PTP clock.
         *
         * @details This method stops the PTP clock.
         */
        virtual std::chrono::nanoseconds getOffset() const = 0;


    protected:
         std::chrono::nanoseconds offset_ = std::chrono::nanoseconds(0);
            /*!
             * @brief Set the offset for the PTP clock.
             *
             * @details This method sets the offset for the PTP clock.
             */
            virtual  void setOffset(const std::chrono::nanoseconds& offset) = 0;
            /*!
             * @brief Get the offset for the PTP clock.
             *
             * @details This method retrieves the offset for the PTP clock.
             */
            void setOffset(const std::chrono::nanoseconds& offset) { offset_ = offset; }
            /*!
            * @brief Get the offset for the PTP clock.
            *
            * @details This method retrieves the offset for the PTP clock.
            */
            std::chrono::nanoseconds getOffset() const { return offset_; }
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
