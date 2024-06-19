/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     18/06/24 W 20:28
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/


#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_ABSTRACTOPTION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_ARGS_ABSTRACTOPTION_HPP

#include <com/github/doevelopper/atlas/launcher/args/IOption.hpp>

namespace com::github::doevelopper::atlas::launcher::args
{
    class AbstractOption : public IOption
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:
        AbstractOption() noexcept;
        AbstractOption(const AbstractOption&) = default;
        AbstractOption(AbstractOption&&) = default;
        AbstractOption& operator=(const AbstractOption&) = default;
        AbstractOption& operator=(AbstractOption&&) = default;
        ~AbstractOption() noexcept override;

        bool is_set(const char * name) const override;
        bool get(const char * name, bool default_) const override;
        std::string get(const char * name, const char * default_) const override;
        int get(const char * name, int default_) const override;
        const boost::any & get(const char * name) const override;

        template<typename Type>
        Type get(char const* name) const;

    protected:
    private:
    };
}


#endif
