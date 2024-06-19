/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     19/06/24 W 20:05
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_OPTIONMOCK_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_OPTIONMOCK_HPP

#include <gmock/gmock.h>

#include <com/github/doevelopper/atlas/launcher/args/IOption.hpp>

namespace com::github::doevelopper::atlas::launcher::args::test
{
    class OptionMock : public IOption
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        OptionMock() noexcept;
        OptionMock(const OptionMock&) = default;
        OptionMock(OptionMock&&) = default;
        OptionMock& operator=(const OptionMock&) = default;
        OptionMock& operator=(OptionMock&&) = default;
        ~OptionMock() noexcept override;

        MOCK_CONST_METHOD(bool, is_set, (char const*));
        MOCK_CONST_METHOD(bool, get, (char const*, bool));
        MOCK_CONST_METHOD(std::string, get, (char const*, char const*));
        MOCK_CONST_METHOD(int, get, (char const*, int));
        MOCK_CONST_METHOD(boost::any const&, get, (char const*));
    protected:
    private:
    };
}

#endif
