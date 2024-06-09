
#include <com/github/doevelopper/atlas/events/pub/SubscriberTest.hpp>

using namespace com::github::doevelopper::atlas::events::pub;
using namespace com::github::doevelopper::atlas::events::pub::test;

log4cxx::LoggerPtr SubscriberTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.events.pub.test.SubscriberTest"));


SubscriberTest::SubscriberTest() noexcept
: m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

SubscriberTest::~SubscriberTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void SubscriberTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // m_targetUnderTest = new Version();
}

void SubscriberTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}
