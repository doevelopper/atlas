#include <com/github/doevelopper/atlas/time/AlarmTest.hpp>
#include <com/github/doevelopper/atlas/time/Alarm.hpp>
using namespace com::github::doevelopper::atlas::time;
using namespace com::github::doevelopper::atlas::time::test;

log4cxx::LoggerPtr AlarmTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.time.AlarmTest"));

AlarmTest::AlarmTest() noexcept
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

AlarmTest::~AlarmTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void AlarmTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_targetUnderTest = new AlarmMock();
}

void AlarmTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(AlarmTest, CancelPendingAlarm)
{
    // AlarmMock alarm;
    // EXPECT_CALL(alarm, state()).WillRepeatedly(::testing::Return(Alarm::pending));
    // EXPECT_CALL(alarm, cancel()).WillOnce(::testing::Return(true));WillRepeatedly
    // EXPECT_TRUE(alarm.cancel());
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    EXPECT_CALL(*this->m_targetUnderTest, state()).WillRepeatedly(::testing::Return(Alarm::pending));
    EXPECT_CALL(*this->m_targetUnderTest, cancel()).WillOnce(::testing::Return(true));
    EXPECT_TRUE(this->m_targetUnderTest->cancel());
}

TEST_F(AlarmTest, CancelTriggeredAlarm)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    EXPECT_CALL(*this->m_targetUnderTest, state()).WillRepeatedly(::testing::Return(Alarm::triggered));
    EXPECT_CALL(*this->m_targetUnderTest, cancel()).WillOnce(::testing::Return(false));
    EXPECT_FALSE(this->m_targetUnderTest->cancel());
}

TEST_F(AlarmTest, ReschedulePendingAlarm)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    EXPECT_CALL(*this->m_targetUnderTest, state()).WillRepeatedly(::testing::Return(Alarm::pending));
    EXPECT_CALL(*this->m_targetUnderTest, reschedule_in(std::chrono::milliseconds(100))).WillOnce(::testing::Return(true));
    EXPECT_TRUE(this->m_targetUnderTest->reschedule_in(std::chrono::milliseconds(100)));
}

TEST_F(AlarmTest, RescheduleTriggeredAlarm)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    EXPECT_CALL(*this->m_targetUnderTest, state()).WillRepeatedly(::testing::Return(Alarm::triggered));
    EXPECT_CALL(*this->m_targetUnderTest, reschedule_in(std::chrono::milliseconds(100))).WillOnce(::testing::Return(false));
    EXPECT_FALSE(this->m_targetUnderTest->reschedule_in(std::chrono::milliseconds(100)));
}

TEST_F(AlarmTest, RescheduleForPendingAlarm)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    EXPECT_CALL(*this->m_targetUnderTest, state()).WillRepeatedly(::testing::Return(Alarm::pending));
    EXPECT_CALL(*this->m_targetUnderTest, reschedule_for(::Alarm::Timestamp())).WillOnce(::testing::Return(true));
    EXPECT_TRUE(this->m_targetUnderTest->reschedule_for(::Alarm::Timestamp()));
}

TEST_F(AlarmTest, RescheduleForTriggeredAlarm)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    EXPECT_CALL(*this->m_targetUnderTest, state()).WillRepeatedly(::testing::Return(Alarm::triggered));
    EXPECT_CALL(*this->m_targetUnderTest, reschedule_for(::Alarm::Timestamp())).WillOnce(::testing::Return(false));
    EXPECT_FALSE(this->m_targetUnderTest->reschedule_for(::Alarm::Timestamp()));
}