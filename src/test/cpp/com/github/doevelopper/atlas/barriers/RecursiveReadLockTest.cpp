
#include <com/github/doevelopper/atlas/barriers/RecursiveReadLockTest.hpp>

using namespace com::github::doevelopper::atlas::barriers;
using namespace com::github::doevelopper::atlas::barriers::test;

log4cxx::LoggerPtr RecursiveReadLockTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.barriers.test.RecursiveReadLockTest"));


RecursiveReadLockTest::RecursiveReadLockTest() noexcept
: m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

RecursiveReadLockTest::~RecursiveReadLockTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void RecursiveReadLockTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // m_targetUnderTest = new RecursiveReadLock();
}

void RecursiveReadLockTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(RecursiveReadLockTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
