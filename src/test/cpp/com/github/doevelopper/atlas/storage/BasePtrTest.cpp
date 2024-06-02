
#include <memory>
#include <com/github/doevelopper/atlas/storage/BasePtrTest.hpp>

using namespace com::github::doevelopper::atlas::storage;
using namespace com::github::doevelopper::atlas::storage::test;

log4cxx::LoggerPtr BasePtrTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.storage.test.BasePtrTest"));


BasePtrTest::BasePtrTest()
    // : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

BasePtrTest::~BasePtrTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void BasePtrTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    m_targetUnderTest1 = Ptr(std::make_unique<int>(42));
    m_targetUnderTest2 = Ptr(std::make_unique<int>(43));
}

void BasePtrTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    m_targetUnderTest1.reset();
    m_targetUnderTest2.reset();
    // delete m_targetUnderTest;
}

TEST_F(BasePtrTest, DefaultConstructor)
{
    BasePtr<int, MockCopyPolicy, std::unique_ptr<int>> ptr;
    EXPECT_EQ(ptr.get(), nullptr);
}

TEST_F(BasePtrTest, NullptrConstructor)
{
    BasePtr<int, MockCopyPolicy, std::unique_ptr<int>> ptr(nullptr);
    EXPECT_EQ(ptr.get(), nullptr);
}

TEST_F(BasePtrTest, MoveConstructor)
{
    int* raw = new int(42);
    std::unique_ptr<int> source(raw);
    BasePtr<int, MockCopyPolicy, std::unique_ptr<int>> ptr(std::move(source));
    EXPECT_EQ(ptr.get(), raw);
    EXPECT_EQ(source.get(), nullptr);  // Ensure source was moved
}

TEST_F(BasePtrTest, Get)
{
    EXPECT_EQ(*m_targetUnderTest1.get(), 42);
    EXPECT_EQ(*m_targetUnderTest2.get(), 43);
}

TEST_F(BasePtrTest, Release)
{
    int* rawPtr1 = m_targetUnderTest1.release();
    int* rawPtr2 = m_targetUnderTest2.release();

    EXPECT_EQ(*rawPtr1, 42);
    EXPECT_EQ(*rawPtr2, 43);

    delete rawPtr1;
    delete rawPtr2;
}

TEST_F(BasePtrTest, Reset)
{
    m_targetUnderTest1.reset(new int(44));
    m_targetUnderTest2.reset(new int(45));

    EXPECT_EQ(*m_targetUnderTest1.get(), 44);
    EXPECT_EQ(*m_targetUnderTest2.get(), 45);
}

TEST_F(BasePtrTest, Swap)
{
    m_targetUnderTest1.swap(m_targetUnderTest2);

    EXPECT_EQ(*m_targetUnderTest1.get(), 43);
    EXPECT_EQ(*m_targetUnderTest2.get(), 42);
}

TEST_F(BasePtrTest, GetDeleter)
{
    // std::default_delete<int>* deleter1 = m_targetUnderTest1.get_deleter();
    // std::default_delete<int>* deleter2 = m_targetUnderTest2.get_deleter();0
    //
    // EXPECT_EQ(deleter1, std::default_delete<int>{});
    // EXPECT_EQ(deleter2, std::default_delete<int>{});
}

TEST_F(BasePtrTest, OperatorBool)
{
    EXPECT_TRUE(m_targetUnderTest1);
    EXPECT_TRUE(m_targetUnderTest2);

    m_targetUnderTest1.reset();
    m_targetUnderTest2.reset();

    EXPECT_FALSE(m_targetUnderTest1);
    EXPECT_FALSE(m_targetUnderTest2);
}

TEST_F(BasePtrTest, OperatorArraySubscript)
{
    // EXPECT_EQ(m_targetUnderTest1[0], 42);
    // EXPECT_EQ(m_targetUnderTest2[0], 43);
}


TEST_F(BasePtrTest, OperatorEqual)
{
    Ptr ptr3(std::make_unique<int>(42));

    EXPECT_TRUE(m_targetUnderTest1 == ptr3);
    EXPECT_TRUE(ptr3 == m_targetUnderTest1);

    EXPECT_FALSE(m_targetUnderTest1 == m_targetUnderTest2);
    EXPECT_FALSE(m_targetUnderTest2 == m_targetUnderTest1);

    EXPECT_TRUE(m_targetUnderTest1 == m_targetUnderTest1);
    EXPECT_TRUE(m_targetUnderTest2 == m_targetUnderTest2);

    EXPECT_TRUE(m_targetUnderTest1 != m_targetUnderTest2);
    EXPECT_TRUE(m_targetUnderTest2 != m_targetUnderTest1);

    EXPECT_FALSE(m_targetUnderTest1 != m_targetUnderTest1);
    EXPECT_FALSE(m_targetUnderTest2 != m_targetUnderTest2);
}

TEST_F(BasePtrTest, OperatorEqualNullptr)
{
    Ptr ptr3(std::make_unique<int>(42));

    EXPECT_FALSE(m_targetUnderTest1 == nullptr);
    EXPECT_FALSE(nullptr == m_targetUnderTest1);

    EXPECT_TRUE(ptr3 == nullptr);
    EXPECT_TRUE(nullptr == ptr3);

    EXPECT_TRUE(m_targetUnderTest1 != nullptr);
    EXPECT_TRUE(nullptr != m_targetUnderTest1);

    EXPECT_FALSE(ptr3 != nullptr);
    EXPECT_FALSE(nullptr != ptr3);
}


// TEST_F(BasePtrTest, MoveAssignment) {
//     int* raw = new int(42);
//     BasePtr<int, MockCopyPolicy, std::unique_ptr<int>> ptr1;
//     // BasePtr<int, MockCopyPolicy, std::unique_ptr<int>> ptr2(raw);
//     BasePtr<int, MockCopyPolicy, std::unique_ptr<int, CustomDeleter<int>>> ptr2(raw);
//     ptr1 = std::move(ptr2);
//     EXPECT_EQ(ptr1.get(), raw);
//     EXPECT_EQ(ptr2.get(), nullptr);  // Ensure ptr2 was moved
// }
//
// TEST_F(BasePtrTest, Release) {
//     int* raw = new int(42);
//     BasePtr<int, MockCopyPolicy, std::unique_ptr<int>> ptr(raw);
//     EXPECT_EQ(ptr.release(), raw);
//     EXPECT_EQ(ptr.get(), nullptr);  // Ensure ptr was released
// }
//
// TEST_F(BasePtrTest, ResetNullptr)
// {
//     BasePtr<int, MockCopyPolicy, std::unique_ptr<int>> ptr;
//     ptr.reset();
//     EXPECT_EQ(ptr.get(), nullptr);
// }
//
// TEST_F(BasePtrTest, ResetNew)
// {
//     BasePtr<int, MockCopyPolicy, std::unique_ptr<int>> ptr;
//     ptr.reset(new int(42));
//     EXPECT_NE(ptr.get(), nullptr);
// }
//
// TEST_F(BasePtrTest, CustomDeleter)
// {
//     std::unique_ptr<int, CustomDeleter> deleter_ptr(new int(42));
//     BasePtr<int, MockCopyPolicy, std::unique_ptr<int, CustomDeleter>> ptr(std::move(deleter_ptr));
//     // EXPECT_EQ(ptr.get_deleter().count(), 1);  // Assuming CustomDeleter maintains a counter
// }
//
// TEST_F(BasePtrTest, EqualityOperators)
// {
//     int* raw1 = new int(42);
//     int* raw2 = new int(43);
//     BasePtr<int, MockCopyPolicy, std::unique_ptr<int>> ptr1(raw1);
//     BasePtr<int, MockCopyPolicy, std::unique_ptr<int>> ptr2(raw2);
//
//     EXPECT_TRUE(ptr1 == raw1);
//     EXPECT_FALSE(ptr1 == raw2);
//     EXPECT_FALSE(ptr1 == nullptr);
//
//     EXPECT_FALSE(ptr1 != raw1);
//     EXPECT_TRUE(ptr1 != raw2);
//     EXPECT_TRUE(ptr1 != nullptr);
// }

// TEST_F(BasePtrTest, test_Simple)
// {
//     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }
//
//
// // Test construction
// TEST_F(BasePtrTest, Construction) {
//     MyIntPtr ptr; // Default constructor
//     EXPECT_FALSE(ptr);
//
//     MyIntPtr nullPtr(nullptr);
//     EXPECT_FALSE(nullPtr);
//
//     int* rawPtr = new int(5);
//     MyIntPtr constructedPtr(unique_ptr<int>(rawPtr));
//     EXPECT_EQ(*constructedPtr, 5);
//     delete rawPtr; // Cleanup, though unique_ptr manages it
// }
//
// // Test move constructor
// TEST_F(BasePtrTest, MoveConstructor) {
//     MyIntPtr source(new int(10));
//     MyIntPtr movedPtr(std::move(source));
//     EXPECT_EQ(*movedPtr, 10);
//     EXPECT_FALSE(source); // Source should be empty
// }
//
// // Test assignment
// TEST_F(BasePtrTest, Assignment) {
//     MyIntPtr assignee;
//     assignee = MyIntPtr(new int(20));
//     EXPECT_EQ(*assignee, 20);
// }
//
// // Test release
// TEST_F(BasePtrTest, Release) {
//     MyIntPtr ptr(new int(30));
//     int* released = ptr.release();
//     EXPECT_FALSE(ptr);
//     EXPECT_EQ(*released, 30);
//     delete released; // Manual cleanup
// }
//
// // Test reset
// TEST_F(BasePtrTest, Reset) {
//     MyIntPtr ptr(new int(40));
//     ptr.reset(new int(50));
//     EXPECT_EQ(*ptr, 50);
//     ptr.reset(); // Should not leak
// }
//
// // Test swap
// TEST_F(BasePtrTest, Swap) {
//     MyIntPtr ptr1(new int(60));
//     MyIntPtr ptr2(new int(70));
//     ptr1.swap(ptr2);
//     EXPECT_EQ(*ptr1, 70);
//     EXPECT_EQ(*ptr2, 60);
// }
//
// // Test comparisons
// TEST_F(BasePtrTest, Comparisons) {
//     MyIntPtr ptr1(new int(80));
//     MyIntPtr ptr2(new int(80));
//     MyIntPtr nullPtr;
//
//     EXPECT_TRUE(ptr1 == ptr2);
//     EXPECT_FALSE(ptr1 != ptr2);
//     EXPECT_TRUE(ptr1 != nullPtr);
//     EXPECT_FALSE(ptr1 == nullPtr);
// }
