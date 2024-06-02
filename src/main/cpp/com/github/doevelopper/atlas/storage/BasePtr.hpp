
/***********************************************************************************************************************
* @file
 * @version  v0.0.
 * @date     2024/04/18 W 09:55:59
 * @brief
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2023 ACME Technology Corp. All rights reserved.
***********************************************************************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_STORAGE_BASEPTR_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_STORAGE_BASEPTR_HPP

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>


namespace com::github::doevelopper::atlas::storage
{
    template <class T, class CopyPolicy, class Ptr>
    class BasePtr
    {

    public:
        using pointer = typename Ptr::pointer;
        using element_type = typename Ptr::element_type;
        using deleter_type = typename Ptr::deleter_type;
        using underlying_type = Ptr;

    public:
        constexpr BasePtr() noexcept : m_ptr{} {}

        constexpr BasePtr(std::nullptr_t p) noexcept : m_ptr{p} {}

        BasePtr(Ptr ptr) noexcept : m_ptr{std::move(ptr)} {}

        BasePtr(BasePtr&& other) noexcept : m_ptr{std::move(other.m_ptr)} {}

        ~BasePtr() = default;

        inline auto operator=(BasePtr&& r) noexcept -> BasePtr&
        {
            m_ptr = std::move(r.m_ptr);
            return *this;
        }

        inline auto release() noexcept -> pointer { return m_ptr.release(); }
        inline auto reset(pointer ptr = pointer()) noexcept -> void { m_ptr.reset(ptr); }
        template <class U>
        auto reset(U) noexcept -> void = delete;
        inline auto reset(std::nullptr_t p) noexcept -> void { m_ptr.reset(p); }
        inline auto swap(BasePtr& other) noexcept -> void { m_ptr.swap(other.m_ptr); }
        inline auto get() const noexcept -> pointer { return m_ptr.get(); }
        inline auto get_deleter() noexcept -> deleter_type { return m_ptr.get_deleter(); }
        inline auto get_deleter() const noexcept -> const deleter_type { return m_ptr.get_deleter(); }
        explicit inline operator bool() const noexcept { return m_ptr.operator bool(); }
        inline auto operator[](std::size_t i) const -> element_type& { return m_ptr[i]; }

        // this is nasty but currently I see no other way to access the m_ptr of different instances
        inline const Ptr& get_underlying() const noexcept { return m_ptr; }

        // it is a good practice to provide an operator* overload for the BasePtr class, so that it can be used like a regular pointer.
        // inline auto operator*() const noexcept -> element_type& { return *m_ptr; } //ADRIAN
    protected:
        template <class Dest, class Src, class... Args>
        inline auto copy(Dest& dest, const Src& src, Args... args) -> void
        {
            CopyPolicy::copy(dest, src, args...);
        }

    private:
        BasePtr(const BasePtr&) = delete;
        auto operator=(const BasePtr&) -> BasePtr& = delete;

    protected:
        Ptr m_ptr;

    };

    template <class T1, class C1, class Ptr1, class T2, class C2, class Ptr2>
    inline auto operator==(const BasePtr<T1, C1, Ptr1>& x, const BasePtr<T2, C2, Ptr2>& y) noexcept -> bool
    {
        return x.get() == y.get();
    }

    template <class T1, class C1, class Ptr1, class T2, class C2, class Ptr2>
    inline auto operator!=(const BasePtr<T1, C1, Ptr1>& x, const BasePtr<T2, C2, Ptr2>& y) noexcept -> bool
    {
        return x.get() != y.get();
    }

    template <class T, class C, class Ptr>
    inline auto operator==(const BasePtr<T, C, Ptr>& x, std::nullptr_t) noexcept -> bool
    {
        return !x;
    }

    template <class T, class C, class Ptr>
    inline auto operator==(std::nullptr_t, const BasePtr<T, C, Ptr>& x) noexcept -> bool
    {
        return !x;
    }

    template <class T, class C, class Ptr>
    inline auto operator!=(const BasePtr<T, C, Ptr>& x, std::nullptr_t) noexcept -> bool
    {
        return static_cast<bool>(x);
    }

    template <class T, class C, class Ptr>
    inline auto operator!=(std::nullptr_t, const BasePtr<T, C, Ptr>& x) noexcept -> bool
    {
        return static_cast<bool>(x);
    }

}

#endif
