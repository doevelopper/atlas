/*******************************************************************
* @file
 * @version  v0.0.
 * @date     18/06/24 W 20:55
 * @brief
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
 ********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_NAMEDOPTION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_NAMEDOPTION_HPP

#include <boost/program_options.hpp>

#include <com/github/doevelopper/atlas/launcher/args/IOption.hpp>

namespace com::github::doevelopper::atlas::launcher::args
{
    class NamedOption : public IOption
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DISABLE_COPY_MOVE(NamedOption)

    public:
        NamedOption() noexcept;
        ~NamedOption() noexcept override;
        // NamedOption(const NamedOption&) = default;
        // NamedOption(NamedOption&&) = default;
        // NamedOption& operator=(const NamedOption&) = default;
        // NamedOption& operator=(NamedOption&&) = default;
        explicit NamedOption(const boost::program_options::variables_map& variablesMap);

        void process() override;
    protected:

    private:
        boost::program_options::variables_map m_vm;
    };
}

#endif
