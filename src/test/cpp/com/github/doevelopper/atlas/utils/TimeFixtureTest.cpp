#include <com/github/doevelopper/atlas/utils/TimeFixtureTest.hpp>

using namespace com::github::doevelopper::atlas::utils;
using namespace com::github::doevelopper::atlas::utils::test;

log4cxx::LoggerPtr TimeFixtureTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.storage.test.TimeFixtureTest"));

TimeFixtureTest::TimeFixtureTest() noexcept
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TimeFixtureTest::~TimeFixtureTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void TimeFixtureTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_targetUnderTest = new TimeFixture("Test Fixture", 10);
}

void TimeFixtureTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(TimeFixtureTest, DefaultConstructor)
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // TimeFixture fixture;
    EXPECT_TRUE(true); // Add your assertions here
}

TEST_F(TimeFixtureTest, Constructor)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    TimeFixture fixture("Test Fixture", 10);
    // EXPECT_EQ(this->m_targetUnderTest->m_name, "Test Fixture");
    // EXPECT_EQ(this->m_targetUnderTest->m_number, 0);
    // EXPECT_EQ(this->m_targetUnderTest->m_unit, 10);
}

TEST_F(TimeFixtureTest, NowPoint)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    TimeFixture fixture("Test Fixture NowPoint", 10);
    // TimeFixture fixture;
    // this->m_targetUnderTest.
    auto now = this->m_targetUnderTest->nowPoint();
    // Add your assertions here
}

TEST_F(TimeFixtureTest, StartPoint)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // // TimeFixture fixture;
    auto start = this->m_targetUnderTest->startPoint();
    // Add your assertions here
}

TEST_F(TimeFixtureTest, Seconds)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // TimeFixture fixture;
    auto duration = this->m_targetUnderTest->nowPoint() - this->m_targetUnderTest->startPoint();
    EXPECT_DOUBLE_EQ(std::chrono::duration_cast<std::chrono::duration<double>>(duration).count(), 0.0);
}

TEST_F(TimeFixtureTest, MilliSeconds)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // TimeFixture fixture;
    auto duration = this->m_targetUnderTest->nowPoint() - this->m_targetUnderTest->startPoint();
    EXPECT_DOUBLE_EQ(std::chrono::duration_cast<std::chrono::duration<double>>(duration).count(), 0.0);
}

TEST_F(TimeFixtureTest, MicroSeconds)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // TimeFixture fixture;
    auto duration = this->m_targetUnderTest->nowPoint() - this->m_targetUnderTest->startPoint();
    EXPECT_DOUBLE_EQ(std::chrono::duration_cast<std::chrono::duration<double>>(duration).count(), 0.0);
}

TEST_F(TimeFixtureTest, NanoSeconds)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // TimeFixture fixture;
    auto duration = this->m_targetUnderTest->nowPoint() - this->m_targetUnderTest->startPoint();
    EXPECT_DOUBLE_EQ(std::chrono::duration_cast<std::chrono::duration<double>>(duration).count(), 0.0);
}

TEST_F(TimeFixtureTest, SecondsWithEndPoint)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // TimeFixture fixture;
    auto start = this->m_targetUnderTest->startPoint();
    auto end = this->m_targetUnderTest->nowPoint();
    auto duration = end - start;
    EXPECT_DOUBLE_EQ(std::chrono::duration_cast<std::chrono::duration<double>>(duration).count(), 0.0);
}

TEST_F(TimeFixtureTest, MilliSecondsWithEndPoint)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // TimeFixture fixture;
    auto start = this->m_targetUnderTest->startPoint();
    auto end = this->m_targetUnderTest->nowPoint();
    auto duration = end - start;
    EXPECT_DOUBLE_EQ(std::chrono::duration_cast<std::chrono::duration<double>>(duration).count(), 0.0);
}

TEST_F(TimeFixtureTest, MicroSecondsWithEndPoint)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // TimeFixture fixture;
    auto start = this->m_targetUnderTest->startPoint();
    auto end = this->m_targetUnderTest->nowPoint();
    auto duration = end - start;
    EXPECT_DOUBLE_EQ(std::chrono::duration_cast<std::chrono::duration<double>>(duration).count(), 0.0);
}

TEST_F(TimeFixtureTest, NanoSecondsWithEndPoint)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // TimeFixture fixture;
    auto start = this->m_targetUnderTest->startPoint();
    auto end = this->m_targetUnderTest->nowPoint();
    auto duration = end - start;
    EXPECT_DOUBLE_EQ(std::chrono::duration_cast<std::chrono::duration<double>>(duration).count(), 0.0);
}

TEST_F(TimeFixtureTest, Error)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // TimeFixture fixture;
    // EXPECT_THROW(this->m_targetUnderTest->nowPoint(), std::runtime_error);
}
