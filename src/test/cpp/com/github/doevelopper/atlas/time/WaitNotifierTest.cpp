
#include <com/github/doevelopper/atlas/time/WaitNotifierTest.hpp>

using namespace com::github::doevelopper::atlas::time;
using namespace com::github::doevelopper::atlas::time::test;

log4cxx::LoggerPtr WaitNotifierTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.time.WaitNotifierTest"));

WaitNotifierTest::WaitNotifierTest() noexcept
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

WaitNotifierTest::~WaitNotifierTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void WaitNotifierTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // m_targetUnderTest = new WaitNotifier();
    m_targetUnderTest = std::make_unique<WaitNotifier>();
}

void WaitNotifierTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_targetUnderTest.reset();
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}

// Test that wait() blocks until notify() is called
TEST_F(WaitNotifierTest, WaitBlocksUntilNotify)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    bool notified = false;

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Start a thread that waits.");

    std::thread waiter([&]()
    {
        this->m_targetUnderTest->wait();
        notified = true;
    });

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Ensure the waiter thread is waiting.");

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Notify the waiter thread.");

    this->m_targetUnderTest->notify();

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Join the thread and verify it was notified.");

    waiter.join();
    EXPECT_TRUE(notified);
}

// Test that wait_until() returns when the timeout expires
TEST_F(WaitNotifierTest, WaitUntilReturnsOnTimeout)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto future_time = std::chrono::system_clock::now() + std::chrono::milliseconds(100);
    bool notified = false;

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Start a thread that waits until the timeout.");
    std::thread waiter([&]()
    {
        this->m_targetUnderTest->wait_until(future_time);
        notified = true;
    });

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Join the thread and verify it was notified due to timeout.");
    waiter.join();
    EXPECT_TRUE(notified);
}

// Test that wait_until() returns early if notify() is called
TEST_F(WaitNotifierTest, WaitUntilReturnsEarlyOnNotify)
{
    auto future_time = std::chrono::system_clock::now() + std::chrono::seconds(5); // Long timeout
    bool notified = false;

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Start a thread that waits until the timeout.");
    std::thread waiter([&]()
    {
        this->m_targetUnderTest->wait_until(future_time);
        notified = true;
    });

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Ensure the waiter thread is waiting.");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Notify the waiter thread.");
    this->m_targetUnderTest->notify();

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Join the thread and verify it was notified early.");
    waiter.join();
    EXPECT_TRUE(notified);
}

// Test that wait_for() returns when the duration expires
TEST_F(WaitNotifierTest, WaitForReturnsOnTimeout)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    bool notified = false;

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Start a thread that waits for a short duration.");
    std::thread waiter([&]()
    {
        this->m_targetUnderTest->wait_for(std::chrono::milliseconds(100));
        notified = true;
    });

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Join the thread and verify it was notified due to timeout.");
    waiter.join();
    EXPECT_TRUE(notified);
}

// Test that wait_for() returns early if notify() is called
TEST_F(WaitNotifierTest, WaitForReturnsEarlyOnNotify)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    bool notified = false;

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Start a thread that waits for a long duration.");
    std::thread waiter([&]()
    {
        this->m_targetUnderTest->wait_for(std::chrono::seconds(5)); // Long duration
        notified = true;
    });

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Ensure the waiter thread is waiting.");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Notify the waiter thread.");
    this->m_targetUnderTest->notify();

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Join the thread and verify it was notified early.");
    waiter.join();
    EXPECT_TRUE(notified);
}

// Test that multiple threads can wait and be notified
TEST_F(WaitNotifierTest, MultipleThreadsCanWaitAndBeNotified)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    const int num_threads = 5;
    std::vector<std::thread> threads;
    std::vector<bool> notified(num_threads, false);

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Start multiple threads that wait.");
    for (int i = 0; i < num_threads; ++i)
    {
        threads.emplace_back([&, i]()
        {
            this->m_targetUnderTest->wait();
            notified[i] = true;
        });
    }

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Ensure all threads are waiting.");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Notify all threads.");
    for (int i = 0; i < num_threads; ++i)
    {
        this->m_targetUnderTest->notify();
    }

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Join all threads and verify they were notified.");
    for (auto& thread : threads)
    {
        thread.join();
    }

    for (bool n : notified)
    {
        EXPECT_TRUE(n);
    }
}

TEST_F(WaitNotifierTest, NotifyBeforeWait)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_targetUnderTest->notify();
    std::atomic<bool> waited{false};
    std::thread t([&]()
    {
        this->m_targetUnderTest->wait();
        waited = true;
    });
    t.join();
    EXPECT_TRUE(waited); // Thread should proceed immediately
}

TEST_F(WaitNotifierTest, WaitUntilTimeout)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto start = std::chrono::system_clock::now();
    auto timeout = start + std::chrono::milliseconds(200);
    this->m_targetUnderTest->wait_until(timeout);
    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    EXPECT_GE(duration.count(), 190); // Allow some tolerance
    EXPECT_LE(duration.count(), 210);
}

TEST_F(WaitNotifierTest, WaitUntilEarlyNotification)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto start = std::chrono::system_clock::now();
    auto timeout = start + std::chrono::milliseconds(500);
    std::atomic<bool> waited{false};
    std::thread t([&]() {
        this->m_targetUnderTest->wait_until(timeout);
        waited = true;
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    this->m_targetUnderTest->notify();
    t.join();
    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    EXPECT_TRUE(waited);
    EXPECT_LE(duration.count(), 200); // Should be much less than 500ms
}

TEST_F(WaitNotifierTest, WaitForTimeout)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto start = std::chrono::system_clock::now();
    this->m_targetUnderTest->wait_for(std::chrono::milliseconds(200));
    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    EXPECT_GE(duration.count(), 190);
    EXPECT_LE(duration.count(), 210);
}

TEST_F(WaitNotifierTest, WaitForEarlyNotification)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto start = std::chrono::system_clock::now();
    std::thread t([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        this->m_targetUnderTest->notify();
    });
    this->m_targetUnderTest->wait_for(std::chrono::milliseconds(500));
    t.join();
    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    EXPECT_LE(duration.count(), 200); // Should be around 100ms
}

TEST_F(WaitNotifierTest, MultipleWaits)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::atomic<bool> waited1{false};
    std::atomic<bool> waited2{false};
    std::thread t1([&]() {
        this->m_targetUnderTest->wait();
        waited1 = true;
    });
    std::thread t2([&]() {
        this->m_targetUnderTest->wait();
        waited2 = true;
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    EXPECT_FALSE(waited1);
    EXPECT_FALSE(waited2); // Both should be waiting

    this->m_targetUnderTest->notify();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    EXPECT_TRUE(waited1 != waited2); // Exactly one should have proceeded

    this->m_targetUnderTest->notify();
    t1.join();
    t2.join();
    EXPECT_TRUE(waited1);
    EXPECT_TRUE(waited2); // Both should have proceeded
}