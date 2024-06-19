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


#include <com/github/doevelopper/atlas/launcher/args/IOption.hpp>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace com::github::doevelopper::atlas::launcher::args::test
{
    class OptionMock : public ::testing::NaggyMock<IOption>
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        OptionMock() noexcept;
        OptionMock(const OptionMock&) = default;
        OptionMock(OptionMock&&) = default;
        OptionMock& operator=(const OptionMock&) = default;
        OptionMock& operator=(OptionMock&&) = default;
        ~OptionMock() noexcept override;

        MOCK_METHOD(bool, is_set, (char const* name), (const, override));
        MOCK_METHOD(bool, get, (char const* name, bool default_), (const, override));
        MOCK_METHOD(std::string, get, (char const* name, char const* default_), (const, override));
        MOCK_METHOD(int, get, (char const* name, int default_), (const, override));
        MOCK_METHOD(boost::any const&, get, (char const* name), (const, override));
    protected:
    private:
    };
}

#endif
