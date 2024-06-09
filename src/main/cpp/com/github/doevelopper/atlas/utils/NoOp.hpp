/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     08/06/24 W 13:17
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_NOOP_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_NOOP_HPP

#include <com/github/doevelopper/atlas/storage/BasePtr.hpp>

namespace com::github::doevelopper::atlas::utils
{
    class NoOp
    {
        Q_DISABLE_COPY_MOVE(NoOp)
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        NoOp() noexcept;
        ~NoOp() noexcept;

        template < class... Args >
        constexpr void operator( ) ( Args &&... args ) const
        {
        }

        constexpr explicit operator bool ( ) const
        {
            return ( false );
        }

        constexpr bool operator! ( ) const
        {
            return ( true );
        }

        /** No-op performed on a lock() operation. */
        void lock ( )
        {
            // clang-format off

            /* *INDENT-OFF* */
            [] () { } ();
            //              |  |   |  |
            //              |  |   |  The lambda is invoked.
            //              |  |   The lambda does not do anything.
            //              |  The lambda does not take any arguments.
            //              The lambda does not capture anything.
            /* *INDENT-ON* */

            // clang-format on
        }
        // clang-format off
        /** No-op performed on an unlock() operatior. */
        /* *INDENT-OFF* */
        void unlock()
        {
            [] () { } ();
        }

        /* *INDENT-ON* */

        // clang-format on

    protected:
    private:
    };
}

#endif
