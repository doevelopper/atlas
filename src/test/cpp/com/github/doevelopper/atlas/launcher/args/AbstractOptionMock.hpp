/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     19/06/24 W 20:28
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_ABSTRACTOPTIONMOCK_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_ABSTRACTOPTIONMOCK_HPP

#include <gmock/gmock.h>

#include <com/github/doevelopper/atlas/launcher/args/AbstractOption.hpp>

namespace com::github::doevelopper::atlas::launcher::args::test
{
    class AbstractOptionMock : public AbstractOption
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        AbstractOptionMock() noexcept;
        AbstractOptionMock(const AbstractOptionMock&) = default;
        AbstractOptionMock(AbstractOptionMock&&) = default;
        AbstractOptionMock& operator=(const AbstractOptionMock&) = default;
        AbstractOptionMock& operator=(AbstractOptionMock&&) = default;
        ~AbstractOptionMock() noexcept override;

        // Use MOCK_METHOD to mock virtual functions from the base class IOption
        MOCK_METHOD(bool, is_set, (const char* name), (const, override));
        MOCK_METHOD(bool, get, (const char* name, bool default_), (const, override));
        MOCK_METHOD(std::string, get, (const char* name, const char* default_), (const, override));
        MOCK_METHOD(int, get, (const char* name, int default_), (const, override));
        MOCK_METHOD(const boost::any&, get, (const char* name), (const, override));
    protected:
    private:
    };
}

#endif
