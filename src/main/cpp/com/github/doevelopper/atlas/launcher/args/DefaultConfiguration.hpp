/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     18/06/24 W 20:58
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_DEFAULTCONFIGURATION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_DEFAULTCONFIGURATION_HPP

#include <boost/program_options/options_description.hpp>
#include <vector>

#include <com/github/doevelopper/atlas/launcher/args/AbstractConfiguration.hpp>
#include <com/github/doevelopper/atlas/launcher/args/ProgramOption.hpp>

namespace com::github::doevelopper::atlas::launcher::args
{
    class DefaultConfiguration : public  AbstractConfiguration
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:
        DefaultConfiguration() noexcept;
        // DefaultConfiguration(const DefaultConfiguration&) = default;
        // DefaultConfiguration(DefaultConfiguration&&) = default;
        // DefaultConfiguration& operator=(const DefaultConfiguration&) = default;
        // DefaultConfiguration& operator=(DefaultConfiguration&&) = default;
        ~DefaultConfiguration() noexcept override;

        DefaultConfiguration(int argc, char const* argv[]);
        DefaultConfiguration(int argc, char const* argv[], std::string const& config_file);
        DefaultConfiguration(
            int argc, char const* argv[],
            std::function <void(int argc, char const* const* argv)> const& handler);
        DefaultConfiguration(
            int argc, char const* argv[],
            std::function <void(int argc, char const* const* argv)> const& handler,
            std::string const& config_file);

        // add_options() allows users to add their own options. This MUST be called
        // before the first invocation of the_options() - typically during initialization.
        boost::program_options::options_description_easy_init addOptions();
    protected:
    private:

        [[nodiscard]] std::shared_ptr<AbstractOption> options() const override;

        void addPlatformOptions();

        virtual void parseArguments(
            boost::program_options::options_description desc,
            ProgramOption & options,
            int argc,
            char const* argv[]) const;

        virtual void parseEnvironment(
            boost::program_options::options_description& desc,
            ProgramOption& options) const;

        virtual void parseConfigFile(
            boost::program_options::options_description& desc,
            ProgramOption& options) const;


        std::string const m_configFile;
        int const m_argc{};
        char const** const m_argv{};
        std::function<void(int argc, char const* const* argv)> const m_unparsed_arguments_handler;
        std::shared_ptr<boost::program_options::options_description> const m_program_options;
        std::shared_ptr<AbstractOption> mutable m_options;
    };
}

#endif
