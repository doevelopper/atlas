
#include <com/github/doevelopper/atlas/barriers/SynchronisedTest.hpp>

using namespace com::github::doevelopper::atlas::barriers;
using namespace com::github::doevelopper::atlas::barriers::test;

template<typename T>
log4cxx::LoggerPtr SynchronisedTest<T>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.barriers.test.SynchronisedTest"));

template<typename T>
SynchronisedTest<T>::SynchronisedTest() noexcept
// : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template<typename T>
SynchronisedTest<T>::~SynchronisedTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template<typename T>
void SynchronisedTest<T>::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // m_targetUnderTest = new RecursiveReadLock();
}

template<typename T>
void SynchronisedTest<T>::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}

/*
TYPED_TEST(SynchronisedTest, MoveConstructorPreservesValue)
{
    TypeParam initialValue = TypeParam(42);
    Synchronised<TypeParam> sync(initialValue);
    Synchronised<TypeParam> movedSync(std::move(sync));

    ASSERT_EQ(initialValue, *movedSync.lock());
}

TYPED_TEST(SynchronisedTest, MoveAssignmentPreservesValue)
{
    TypeParam initialValue = TypeParam(42);
    Synchronised<TypeParam> sync(initialValue);
    Synchronised<TypeParam> movedSync;
    movedSync = std::move(sync);

    ASSERT_EQ(initialValue, *movedSync.lock());
}

TYPED_TEST(SynchronisedTest, LockReturnsCorrectValue)
{
    TypeParam initialValue = TypeParam(42);
    Synchronised<TypeParam> sync(initialValue);
    auto locked = sync.lock();

    ASSERT_EQ(initialValue, *locked);
}

TYPED_TEST(SynchronisedTest, LockIsExclusive)
{
    TypeParam initialValue = TypeParam(42);
    Synchronised<TypeParam> sync(initialValue);
    std::thread t1([&]() {
        auto locked = sync.lock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    });

    std::thread t2([&]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ASSERT_THROW((void)sync.lock(), std::exception);
    });

    t1.join();
    t2.join();
}

TYPED_TEST(SynchronisedTest, DropReleasesLock)
{
    TypeParam initialValue = TypeParam(42);
    Synchronised<TypeParam> sync(initialValue);
    auto locked = sync.lock();

    locked.drop();

    // This should not throw
    (void)sync.lock();
}

TYPED_TEST(SynchronisedTest, WaitUnlocksAndReacquiresLock)
{
    TypeParam initialValue = TypeParam(42);
    Synchronised<TypeParam> sync(initialValue);
    std::condition_variable cv;
    std::mutex m;
    bool stopWaiting = false;

    std::thread t1([&]() {
        auto locked = sync.lock();
        cv.wait(m, [&] { return stopWaiting; });
    });

    std::thread t2([&]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        stopWaiting = true;
        cv.notify_all();
    });

    t1.join();
    t2.join();

    // This should not throw
    (void)sync.lock();
}
*/