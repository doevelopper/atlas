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
    class AbstractOptionMock : AbstractOption
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        AbstractOptionMock() noexcept;
        AbstractOptionMock(const AbstractOptionMock&) = default;
        AbstractOptionMock(AbstractOptionMock&&) = default;
        AbstractOptionMock& operator=(const AbstractOptionMock&) = default;
        AbstractOptionMock& operator=(AbstractOptionMock&&) = default;
        ~AbstractOptionMock() noexcept override;
    protected:
    private:
    };
}

#endif
