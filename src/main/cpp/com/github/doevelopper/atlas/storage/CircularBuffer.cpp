

#include <com/github/doevelopper/atlas/storage/CircularBuffer.hpp>

using namespace com::github::doevelopper::atlas::storage;

template <class Object>
log4cxx::LoggerPtr CircularBuffer<Object>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.storage.CircularBuffer"));

template <class Object>
CircularBuffer<Object>::CircularBuffer() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <class Object>
CircularBuffer<Object>::~CircularBuffer() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <class Object>
CircularBuffer<Object>::CircularBuffer(std::size_t size)
    : m_size{size}
    , m_count{0u}
    , m_index{0u}
    , m_buffer{std::vector<Object>(size)}
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <class Object>
template <class Item>
void CircularBuffer<Object>::push_back(Item&& item)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if(m_count < m_size)
        m_count = m_index + 1u;
    // making Image go out of scope(otherwise performance drop if buffer filled)
    auto release = std::move(m_buffer[m_index]);
    m_buffer[m_index] = std::move(item);
    m_index = (m_index + 1) % m_size;
}

template <class Object>
Object CircularBuffer<Object>::at(std::size_t index)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto ret = std::move(m_buffer[index]);
    return ret;
}

template <class Object>
std::size_t CircularBuffer<Object>::count()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return m_count;
}

template <class Object>
bool CircularBuffer<Object>::full()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return m_count >= m_size;
}

template <class Object>
void CircularBuffer<Object>::clear()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_count = 0u;
    m_index = 0u;
}
