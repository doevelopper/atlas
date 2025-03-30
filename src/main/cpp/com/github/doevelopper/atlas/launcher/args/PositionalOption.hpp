/*******************************************************************
* @file
 * @version  v0.0.
 * @date     18/06/24 W 20:55
 * @brief
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
 ********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_POSITIONALOPTION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_POSITIONALOPTION_HPP

#include <com/github/doevelopper/atlas/launcher/args/IOption.hpp>

namespace com::github::doevelopper::atlas::launcher::args
{
    class PositionalOption : public IOption
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        Q_DISABLE_COPY_MOVE(PositionalOption)

    public:
        PositionalOption() noexcept;
        ~PositionalOption() noexcept override;
        // PositionalOption(const PositionalOption&) = default;
        // PositionalOption(PositionalOption&&) = default;
        // PositionalOption& operator=(const PositionalOption&) = default;
        // PositionalOption& operator=(PositionalOption&&) = default;
        explicit PositionalOption(const std::vector<std::string>& args);

        void process() override;
    protected:

    private:
        std::vector<std::string> m_positionalArgs;

    };
}

#endif
