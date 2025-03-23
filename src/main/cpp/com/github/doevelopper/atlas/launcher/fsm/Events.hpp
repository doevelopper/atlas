#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_FSM_EVENTS_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_FSM_EVENTS_HPP

#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <functional>
#include <vector>
#include <map>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/statechart/event.hpp>
#include <boost/statechart/custom_reaction.hpp>

// Forward declarations
namespace sc = boost::statechart;

// Events
struct EvInitialize : sc::event<EvInitialize> {};
struct EvConfigLoaded : sc::event<EvConfigLoaded> {};
struct EvResourcesInitialized : sc::event<EvResourcesInitialized> {};
struct EvStartupComplete : sc::event<EvStartupComplete> {};
struct EvShutdownRequested : sc::event<EvShutdownRequested> {};
struct EvResourcesReleased : sc::event<EvResourcesReleased> {};

struct EvError : sc::event<EvError>
{
    std::string message;
    int code;
    EvError(const std::string& msg, int errorCode) : message(msg), code(errorCode) {}
};

#endif //EVENTS_HPP
