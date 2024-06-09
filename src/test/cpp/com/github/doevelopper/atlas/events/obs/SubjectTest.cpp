
#include <com/github/doevelopper/atlas/events/obs/SubjectTest.hpp>

using namespace com::github::doevelopper::atlas::events::obs;
using namespace com::github::doevelopper::atlas::events::obs::test;

log4cxx::LoggerPtr SubjectTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.events.obs.test.SubjectTest"));


SubjectTest::SubjectTest() noexcept
: m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

SubjectTest::~SubjectTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void SubjectTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // m_targetUnderTest = new Version();
}

void SubjectTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}
