/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     17/06/24 W 20:23
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_BARRIERS_RECURSIVEREADWRITEMUTEX_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_BARRIERS_RECURSIVEREADWRITEMUTEX_HPP

#include <condition_variable>
#include <thread>
#include <vector>

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::barriers
{
    /*!
     * @brief a recursive read-write mutex.
    * Note that a write lock can be acquired if no other threads have a read lock.
    */
    class RecursiveReadWriteMutex
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        struct ThreadLockCount
        {
            ThreadLockCount() : id(), count(0) {}
            ThreadLockCount(std::thread::id id, unsigned int count) : id(id), count(count) {}
            std::thread::id id;
            unsigned int count;
        };
    public:
        RecursiveReadWriteMutex() noexcept;
        RecursiveReadWriteMutex(const RecursiveReadWriteMutex&) = default;
        RecursiveReadWriteMutex(RecursiveReadWriteMutex&&) = default;
        RecursiveReadWriteMutex& operator=(const RecursiveReadWriteMutex&) = default;
        RecursiveReadWriteMutex& operator=(RecursiveReadWriteMutex&&) = default;
        virtual ~RecursiveReadWriteMutex() noexcept;

        void read_lock();
        void read_unlock();
        void write_lock();
        void write_unlock();

    protected:
    private:
        std::mutex m_mutex;
        std::condition_variable m_cv;
         std::vector<ThreadLockCount> read_locking_threads;
        ThreadLockCount write_locking_thread;
    };
}

#endif
