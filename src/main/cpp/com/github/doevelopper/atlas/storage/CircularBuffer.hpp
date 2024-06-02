/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     02/06/24 W 16:21
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_STORAGE_CIRCULARBUFFER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_STORAGE_CIRCULARBUFFER_HPP

#include <cstddef>
#include <vector>

#include <com/github/doevelopper/atlas/storage/BasePtr.hpp>

namespace com::github::doevelopper::atlas::storage
{
    template <class Object>
    class CircularBuffer
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        CircularBuffer() noexcept;
        CircularBuffer(const CircularBuffer&) = default;
        CircularBuffer(CircularBuffer&&) = default;
        CircularBuffer& operator=(const CircularBuffer&) = default;
        CircularBuffer& operator=(CircularBuffer&&) = default;
        virtual ~CircularBuffer()noexcept;

        CircularBuffer(std::size_t size);
        template <class Item>
        void push_back(Item&& item);
        Object at(std::size_t index);
        std::size_t count();
        bool full();
        void clear();
    protected:
    private:
        const std::size_t m_size{};
        std::size_t m_count{};
        std::size_t m_index{};
        std::vector<Object> m_buffer;

    };
}


#endif //CIRCULARBUFFER_HPP
