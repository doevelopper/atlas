
#include <com/github/doevelopper/atlas/barriers/RecursiveWriteLockTest.hpp>

using namespace com::github::doevelopper::atlas::barriers;
using namespace com::github::doevelopper::atlas::barriers::test;

log4cxx::LoggerPtr RecursiveWriteLockTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.barriers.test.RecursiveWriteLockTest"));


RecursiveWriteLockTest::RecursiveWriteLockTest() noexcept
: m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

RecursiveWriteLockTest::~RecursiveWriteLockTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void RecursiveWriteLockTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_targetUnderTest = new RecursiveWriteLock();
}

void RecursiveWriteLockTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(RecursiveWriteLockTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
