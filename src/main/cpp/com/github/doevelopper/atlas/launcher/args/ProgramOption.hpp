/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     18/06/24 W 20:40
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/


#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_PROGRAMOPTION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_PROGRAMOPTION_HPP

#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/options_description.hpp>

#include <com/github/doevelopper/atlas/launcher/args/AbstractOption.hpp>

namespace com::github::doevelopper::atlas::launcher::args
{
    class ProgramOption : public AbstractOption
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:
        ProgramOption() noexcept;
        ProgramOption(const ProgramOption&) = default;
        ProgramOption(ProgramOption&&) = default;
        ProgramOption& operator=(const ProgramOption&) = default;
        ProgramOption& operator=(ProgramOption&&) = default;
        ~ProgramOption() noexcept override;

        void parseArguments(
            boost::program_options::options_description const& description,
            int argc,
            char const* argv[]);

        void parseEnvironment(
            boost::program_options::options_description const& description,
            char const* prefix);

        void parseFile(
            boost::program_options::options_description const& description,
            std::string const& filename);

        bool is_set(const char * name) const override;
        bool get(const char * name, bool default_) const override;
        std::string get(const char * name, const char * default_) const override;
        int get(const char * name, int default_) const override;
        const boost::any & get(const char * name) const override;

    protected:
    private:
        boost::program_options::variables_map m_options;
        std::vector<std::string> m_unparsed_tokens;
    };
}

#endif
