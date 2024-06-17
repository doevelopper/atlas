

#include <com/github/doevelopper/atlas/events/pub/PublisherTest.hpp>

using namespace com::github::doevelopper::atlas::events::pub;
using namespace com::github::doevelopper::atlas::events::pub::test;


log4cxx::LoggerPtr PublisherTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.events.pub.test.PublisherTest"));


PublisherTest::PublisherTest() noexcept
: m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

PublisherTest::~PublisherTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void PublisherTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // m_targetUnderTest = new Version();
}

void PublisherTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(PublisherTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
