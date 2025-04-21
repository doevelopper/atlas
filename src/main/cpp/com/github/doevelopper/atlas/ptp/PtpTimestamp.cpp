
#include <com/github/doevelopper/atlas/ptp/IPtpClock.hpp>
using namespace com::github::doevelopper::atlas::ptp;

log4cxx::LoggerPtr IPtpClock::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.ptp.IPtpClock"));

IPtpClock::IPtpClock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

IPtpClock::~IPtpClock() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void PtpTimestamp::normalize()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (m_nanoseconds >= 1'000'000'000) {
        m_seconds += m_nanoseconds / 1'000'000'000;
        m_nanoseconds %= 1'000'000'000;
    } else if (m_nanoseconds < 0) {
        m_seconds -= (std::abs(m_nanoseconds) / 1'000'000'000) + 1;
        m_nanoseconds = 1'000'000'000 - (std::abs(m_nanoseconds) % 1'000'000'000);
    }
    // Enforce 48-bit limit for seconds as per IEEE 1588
    m_seconds &= 0xFFFFFFFFFFFF;  // 48-bit mask    
}

std::vector<std::byte> PtpTimestamp::serialize() const 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::vector<std::byte> result(10); // 6 bytes for seconds + 4 bytes for nanoseconds
    
    // Convert seconds (48 bits) to network byte order
    for (int i = 5; i >= 0; --i) 
    {
        result[i] = static_cast<std::byte>((m_seconds >> ((5-i) * 8)) & 0xFF);
    }
    
    // Convert nanoseconds (32 bits) to network byte order
    for (int i = 9; i >= 6; --i) {
        result[i] = static_cast<std::byte>((m_nanoseconds >> ((9-i) * 8)) & 0xFF);
    }
    
    return result;
}

PtpTimestamp PtpTimestamp::operator+(const TimeInterval& interval) const 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    PtpTimestamp result = *this;
    result.m_seconds += interval.getSeconds();
    result.m_nanoseconds += interval.getNanoseconds();
    result.normalize();
    return result;
}

TimeInterval PtpTimestamp::operator-(const PtpTimestamp& other) const 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // Calculate the time difference between two timestamps
    std::int64_t diffSeconds = static_cast<std::int64_t>(m_seconds) - static_cast<std::int64_t>(other.m_seconds);
    std::int32_t diffNanos = static_cast<std::int32_t>(m_nanoseconds) - static_cast<std::int32_t>(other.m_nanoseconds);
    
    // Handle negative nanoseconds
    if (diffNanos < 0) 
    {
        diffSeconds--;
        diffNanos += 1'000'000'000;
    }
    
    return TimeInterval(diffSeconds, diffNanos);
}

std::chrono::system_clock::time_point PtpTimestamp::toSystemTime() const 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    using namespace std::chrono;
    
    // Convert seconds to duration since epoch
    seconds secs(m_seconds);
    
    // Add nanoseconds
    nanoseconds nanos(m_nanoseconds);
    
    // Combine to form time point
    return system_clock::time_point(duration_cast<system_clock::duration>(secs + nanos));
}

PtpTimestamp PtpTimestamp::fromSystemTime(const std::chrono::system_clock::time_point& timePoint) 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    using namespace std::chrono;
    
    // Get duration since epoch
    auto sinceEpoch = timePoint.time_since_epoch();
    
    // Extract seconds and nanoseconds
    auto secs = duration_cast<seconds>(sinceEpoch);
    auto nanos = duration_cast<nanoseconds>(sinceEpoch - secs);
    
    return PtpTimestamp(static_cast<std::uint64_t>(secs.count()), 
                       static_cast<std::uint32_t>(nanos.count()));
}

/*
// Using structured bindings with the timestamp
    auto [secs, nanos] = std::tuple{timestamp.getSeconds(), timestamp.getNanoseconds()};
*/

/*
void PtpTimestamp::serialize()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_serializedData.resize(sizeof(m_seconds) + sizeof(m_nanoseconds));
    std::memcpy(m_serializedData.data(), &m_seconds, sizeof(m_seconds));
    std::memcpy(m_serializedData.data() + sizeof(m_seconds), &m_nanoseconds, sizeof(m_nanoseconds));
}
*/
