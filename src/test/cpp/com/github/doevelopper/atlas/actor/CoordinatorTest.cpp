
#include <com/github/doevelopper/atlas/actor/CoordinatorTest.hpp>

using namespace com::github::doevelopper::atlas::actor;
using namespace com::github::doevelopper::atlas::actor::test;

log4cxx::LoggerPtr CoordinatorTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.actor.test.CoordinatorTest"));


CoordinatorTest::CoordinatorTest() noexcept
: m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

CoordinatorTest::~CoordinatorTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void CoordinatorTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // m_targetUnderTest = new RecursiveReadLock();
}

void CoordinatorTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(CoordinatorTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
