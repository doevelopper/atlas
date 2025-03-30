/*******************************************************************
* @file
 * @version  v0.0.
 * @date     18/06/24 W 20:55
 * @brief
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
 ********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_COMMANDLINEPARSER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_COMMANDLINEPARSER_HPP

#include <com/github/doevelopper/atlas/launcher/args/NamedOption.hpp>
#include <com/github/doevelopper/atlas/launcher/args/PositionalOption.hpp>

namespace com::github::doevelopper::atlas::launcher::args
{
    class CommandLineParser
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DISABLE_COPY_MOVE(CommandLineParser)

    public:
        CommandLineParser() noexcept;
        ~CommandLineParser() noexcept;
        // CommandLineParser(const CommandLineParser&) = default;
        // CommandLineParser(CommandLineParser&&) = default;
        // CommandLineParser& operator=(const CommandLineParser&) = default;
        // CommandLineParser& operator=(CommandLineParser&&) = default;
        void parse(int argc, /*const*/ char* argv[]);
        std::vector<std::string> getPositionalArguments() const;
        boost::program_options::variables_map getVariablesMap() const;
    protected:

    private:
        boost::program_options::options_description desc;
        boost::program_options::positional_options_description positionalDesc;
        boost::program_options::variables_map vm;
    };
}

#endif
