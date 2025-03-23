
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_IPC_Mapping_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_IPC_Mapping_HPP


#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::ipc
{
    /**
     * Interface for a directly-accessible mapped view of shared memory
     *
     * Mapping<T> provides a view much like `std::array<T>` onto some form of
     * shared memory backing.
     *
     * @tparam T    The type to interpret the underlying memory as
     */
    template<typename T>
    class IMapping
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        IMapping() noexcept;
        IMapping(const IMapping&) = delete;
        IMapping(IMapping&&) = default;
        IMapping& operator=(const IMapping&) = delete;
        IMapping& operator=(IMapping&&) = default;
        virtual ~IMapping() noexcept;

        // Mapping<T> interface
        virtual T* data() = 0;
        virtual T const* data() const = 0;
        virtual size_t len() const = 0;

        /**
         * Check if access to this mapping has failed
         *
         * The underlying storage for a `mmap` region may not exist (for example,
         * `ftruncate` can shrink an existing `mmap`ed file), in which case accesses
         * to the missing region will generate a fault.
         *
         * Implementations of Mapping<T> will ensure that such access faults are
         * not fatal (although faulting reads will return 0 and faulting writes
         * will not be visible in any other mapping).
         *
         * \ref access_fault() returns whether or not an access fault has occured
         * in the lifetime of this Mapping<T>.
         *
         * \returns    Whether an access fault has occured on this Mapping<T>
         */
        virtual auto access_fault() const -> bool = 0;

        // Convenience functions for accessing a Mapping<T>
        auto operator[](size_t idx) -> T&
        {
            return data()[idx];
        }
        auto operator[](size_t idx) const -> T const&
        {
            return data()[idx];
        }

        auto begin() -> T*
        {
            return data();
        }
        auto end() -> T*
        {
            return data() + len();
        }

        auto begin() const -> T const*
        {
            return data();
        }
        auto end() const -> T const*
        {
            return data() + len();
        }

        auto cbegin() const -> T const*
        {
            return data();
        }
        auto cend() const -> T const*
        {
            return data() + len();
        }
    protected:
    private:
    };
}
#endif
