/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     17/06/24 W 19:46
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_OBS_OBSERVERREGISTRAR_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_EVENTS_OBS_OBSERVERREGISTRAR_HPP

#include <memory>

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::events::obs
{
    template<class Observer>
    class ObserverRegistrar
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        ObserverRegistrar() noexcept;
        ObserverRegistrar(const ObserverRegistrar&) = default;
        ObserverRegistrar(ObserverRegistrar&&) = default;
        ObserverRegistrar& operator=(const ObserverRegistrar&) = default;
        ObserverRegistrar& operator=(ObserverRegistrar&&) = default;
        virtual ~ObserverRegistrar() noexcept;

        /*!
         * @brief Add an observer to the set notified of all observations
         *
         * @details The ObserverRegistrar does not take any ownership of \p observer, and will
         *      automatically remove it when \p observer expires.
         *
         * @param [in] observer The observer to register
         */
        virtual void register_interest(std::weak_ptr<Observer> const& observer) = 0;
    protected:
    private:
    };
}

#endif
