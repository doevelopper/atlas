/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     19/03/25 W 21:55
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2025 ACME Technology Corp. All rights reserved.
********************************************************************/


#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_FSM_APPLICATIONSTATEMACHINE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_FSM_APPLICATIONSTATEMACHINE_HPP

#include <com/github/doevelopper/atlas/launcher/fsm/Events.hpp>
#include <com/github/doevelopper/atlas/launcher/fsm/Idle.hpp>

namespace com::github::doevelopper::atlas::launcher::fsm
{
    // Forward declarations for states
    // struct Idle;
    // struct LoadingConfig;
    // struct InitializingResources;
    // struct Running;
    // struct ShuttingDown;
    // struct Error;

    class ApplicationStateMachine : boost::statechart::state_machine<ApplicationStateMachine,Idle>
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        ApplicationStateMachine() noexcept;
        ApplicationStateMachine(const ApplicationStateMachine&) = default;
        ApplicationStateMachine(ApplicationStateMachine&&) = default;
        ApplicationStateMachine& operator=(const ApplicationStateMachine&) = default;
        ApplicationStateMachine& operator=(ApplicationStateMachine&&) = default;
        ~ApplicationStateMachine() noexcept override;
    protected:
    private:
    };
}


#endif
