
#include <memory>
#include <com/github/doevelopper/atlas/storage/CircularBufferTest.hpp>

using namespace com::github::doevelopper::atlas::storage;
using namespace com::github::doevelopper::atlas::storage::test;

template <typename T>
log4cxx::LoggerPtr CircularBufferTest<T>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.storage.test.CircularBufferTest"));


template <typename T>
CircularBufferTest<T>::CircularBufferTest() noexcept
    // : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

template <typename T>
CircularBufferTest<T>::~CircularBufferTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

template <typename T>
void CircularBufferTest<T>::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    m_targetUnderTest = std::make_unique<CircularBuffer<T>>(5);
}

template <typename T>
void CircularBufferTest<T>::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    m_targetUnderTest.reset();
    // delete m_targetUnderTest;
}

// TYPED_TEST(CircularBufferTest, PushBack)
// {
//     // TypeParam item = TypeParam();
//     // m_targetUnderTest.push_back(std::move(item));
//     // EXPECT_EQ(m_targetUnderTest.count(), 1u);
// }
//
// TYPED_TEST(CircularBufferTest, At)
// {
//     // TypeParam item = TypeParam();
//     // m_targetUnderTest.push_back(std::move(item));
//     // EXPECT_EQ(m_targetUnderTest.at(0), item);
// }
//
// TYPED_TEST(CircularBufferTest, Full)
// {
//     // for (size_t i = 0; i < m_targetUnderTest.size(); i++)
//     // {
//     //     m_targetUnderTest.push_back(TypeParam());
//     // }
//     // EXPECT_TRUE(m_targetUnderTest.full());
// }
//
// TYPED_TEST(CircularBufferTest, Clear)
// {
//     // for (size_t i = 0; i < m_targetUnderTest.size(); i++)
//     // {
//     //     m_targetUnderTest.push_back(TypeParam());
//     // }
//     // m_targetUnderTest.clear();
//     // EXPECT_EQ(m_targetUnderTest.count(), 0u);
// }

// TEST_F(CircularBufferTest, WrapAround)
// {
//     CircularBuffer<int> buffer{3};
//     std::vector<int> items{1, 2, 3, 4, 5};
//     FillBuffer(buffer, items);
//     EXPECT_EQ(3u, buffer.count());
//     EXPECT_EQ(2, buffer.at(0));
//     EXPECT_EQ(3, buffer.at(1));
//     EXPECT_EQ(4, buffer.at(2));
//     EXPECT_TRUE(buffer.full());
// }