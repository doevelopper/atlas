/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     19/03/25 W 22:09
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2025 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_FSM_IDLE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_FSM_IDLE_HPP

#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/statechart/event.hpp>
#include <boost/statechart/custom_reaction.hpp>

#include <com/github/doevelopper/atlas/launcher/fsm/LoadingConfig.hpp>
#include <com/github/doevelopper/atlas/launcher/fsm/Events.hpp>

namespace com::github::doevelopper::atlas::launcher::fsm
{
    class ApplicationStateMachine;
    class Idle : public boost::statechart::simple_state<Idle,ApplicationStateMachine>
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        using reactions = boost::statechart::transition<EvInitialize,LoadingConfig>;
        Idle() noexcept;
        Idle(const Idle&) = default;
        Idle(Idle&&) = default;
        Idle& operator=(const Idle&) = default;
        Idle& operator=(Idle&&) = default;
        ~Idle() noexcept override;
    protected:
    private:
        void on
    };
}

#endif //IDLE_HPP
