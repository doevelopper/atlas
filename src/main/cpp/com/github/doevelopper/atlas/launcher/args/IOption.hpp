/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     17/06/24 W 21:17
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_IOPTION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_IOPTION_HPP

#include <boost/any.hpp>

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::launcher::args
{
    class IOption
    {
        Q_DISABLE_COPY_MOVE(IOption)
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        IOption() noexcept;
        // IOption(const IOption&) = default;
        // IOption(IOption&&) = default;
        // IOption& operator=(const IOption&) = default;
        // IOption& operator=(IOption&&) = default;
        virtual ~IOption() noexcept;

        virtual bool is_set(char const* name) const = 0;

        virtual bool get(char const* name, bool default_) const = 0;
        virtual std::string get(char const* name, char const* default_) const = 0;
        virtual int get(char const* name, int default_) const = 0;
        virtual boost::any const& get(char const* name) const = 0;

        // template<typename Type>
        // Type get(char const* name) const;
    protected:
    private:
    };
}

#endif
