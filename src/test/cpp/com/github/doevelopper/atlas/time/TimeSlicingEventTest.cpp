
#include <com/github/doevelopper/atlas/time/TimeSlicingEventTest.hpp>

using namespace com::github::doevelopper::atlas::time;
using namespace com::github::doevelopper::atlas::time::test;

log4cxx::LoggerPtr TimeSlicingEventTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.time.TimeSlicingEventTest"));

TimeSlicingEventTest::TimeSlicingEventTest() noexcept
    // : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimeSlicingEventTest::~TimeSlicingEventTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TimeSlicingEventTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // m_targetUnderTest = new AlarmMock();
}

void TimeSlicingEventTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}

