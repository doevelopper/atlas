
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_PTP_PTP_TIMESTAMP_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_PTP_PTP_TIMESTAMP_HPP

#include <com/github/doevelopper/atlas/logging/ILoggingInitializationStrategy.hpp>

namespace com::github::doevelopper::atlas::ptp
{
    class PtpTimestamp
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        /*!
         * @brief Default constructor.
         *      Initializes to epoch or current time.
         * @details This constructor initializes the PtpTimestamp object.
         */
        PtpTimestamp() noexcept;
        PtpTimestamp(const PtpTimestamp&) = default;
        PtpTimestamp(PtpTimestamp&&) = default;
        PtpTimestamp& operator=(const PtpTimestamp&) = default;
        PtpTimestamp& operator=(PtpTimestamp&&) = default;
        virtual ~PtpTimestamp() noexcept;

        /*!
         * @brief Constructs a PtpTimestamp from a system clock time point.
         * @param timePoint The system clock time point to convert.
         * @details This constructor initializes the PtpTimestamp object with the specified time point.
         */
        explicit PtpTimestamp(const std::chrono::system_clock::time_point& timePoint);

        /*
         * @brief Constructs a PtpTimestamp with specified seconds and nanoseconds.
         * @param seconds The number of seconds since epoch.
         * @param nanoseconds The number of nanoseconds since the last second.
         */
        PtpTimestamp(std::uint64_t seconds, std::uint32_t nanoseconds);


        /*
         * @brief Gets the number of seconds since epoch.
         */
        std::uint64_t getSeconds() const;
        /*
         * @brief Gets the number of nanoseconds since the last second.
         */
        std::uint32_t getNanoseconds() const;
        
        /*
         * @brief Sets the number of seconds since epoch.
         * @param seconds The number of seconds to set.
         */
        void setSeconds(std::uint48_t seconds);
        /*
         * @brief Sets the number of nanoseconds since the last second.
         * @param nanoseconds The number of nanoseconds to set.
         */
        void setNanoseconds(std::uint32_t nanoseconds);
        
        /*
         * @brief Converts the PtpTimestamp to a system clock time point.
         * @return The system clock time point representing the PtpTimestamp.
         */
        std::chrono::system_clock::time_point toSystemTime() const;
        /*
         * @brief Converts a system clock time point to a PtpTimestamp.
         * @param timePoint The system clock time point to convert.
         * @return The PtpTimestamp representing the system clock time point.
         */
        static PtpTimestamp fromSystemTime(const std::chrono::system_clock::time_point& timePoint);
        
        /*
         * @brief Serializes the PtpTimestamp to a byte vector for transmission.
         * @return A vector of bytes representing the serialized PtpTimestamp.
         */
        std::vector<std::byte> serialize() const;

        /*
         * @brief Deserializes a byte vector into a PtpTimestamp.
         * @param data The byte vector to deserialize.
         * @return The PtpTimestamp represented by the byte vector.
         */
        static PtpTimestamp deserialize(const std::vector<std::byte>& data);


        // Time arithmetic operations
        PtpTimestamp operator+(const TimeInterval& interval) const;
        PtpTimestamp operator-(const TimeInterval& interval) const;
        TimeInterval operator-(const PtpTimestamp& other) const; // Time difference
        
        // Comparison operators
        bool operator==(const PtpTimestamp& other) const;
        bool operator!=(const PtpTimestamp& other) const;
        bool operator<(const PtpTimestamp& other) const;
        bool operator<=(const PtpTimestamp& other) const;
        bool operator>(const PtpTimestamp& other) const;
        bool operator>=(const PtpTimestamp& other) const;
        
        // String representation for debugging and logging
        std::string toString() const;
        
    protected:
    private:
        /*
         * @brief Normalizes the timestamp.
         * @details Ensures nanoseconds are < 1 billion and adjusts seconds accordingly.
         */
        void normalize();

        // According to IEEE 1588, PTP timestamps consist of:
        // - secondsField: 48 bits for seconds since the PTP epoch (usually Jan 1, 1970)
        // - nanosecondsField: 32 bits for nanoseconds within the current second
    
        // In C++, we can use standard types with appropriate bit widths    
        std::uint64_t m_seconds;      // Number of seconds since epoch
        std::uint32_t m_nanoseconds;  // Number of nanoseconds since the last second
        std::chrono::system_clock::time_point m_timePoint; // System clock time point
        std::vector<std::byte> m_serializedData; // Serialized data for transmission
        std::string m_stringRepresentation; // String representation for debugging
        std::mutex m_mutex; // Mutex for thread safety
        std::condition_variable m_cv; // Condition variable for synchronization
        std::atomic<bool> m_isReady; // Flag to indicate if the object is ready
        std::atomic<bool> m_isValid; // Flag to indicate if the object is valid
        std::atomic<bool> m_isDeserialized; // Flag to indicate if the object is deserialized
        std::atomic<bool> m_isSerialized; // Flag to indicate if the object is serialized
    };
    using PtpTimestampPtr = std::shared_ptr<PtpTimestamp>;
    using PtpTimestampConstPtr = std::shared_ptr<const PtpTimestamp>;
}
#endif