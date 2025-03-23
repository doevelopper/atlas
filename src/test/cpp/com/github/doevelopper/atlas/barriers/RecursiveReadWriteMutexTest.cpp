
#include <com/github/doevelopper/atlas/barriers/RecursiveReadWriteMutexTest.hpp>

using namespace com::github::doevelopper::atlas::barriers;
using namespace com::github::doevelopper::atlas::barriers::test;

log4cxx::LoggerPtr RecursiveReadWriteMutexTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.barriers.test.RecursiveReadWriteMutexTest"));


RecursiveReadWriteMutexTest::RecursiveReadWriteMutexTest() noexcept
: m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

RecursiveReadWriteMutexTest::~RecursiveReadWriteMutexTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void RecursiveReadWriteMutexTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_targetUnderTest = new RecursiveReadWriteMutex();
}

void RecursiveReadWriteMutexTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(RecursiveReadWriteMutexTest, Test_constructions)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // Check that a read lock can be acquired
    //this->m_targetUnderTest->
    //ASSERT_EQ(1U, mutex.read_locking_threads[0].count);
}
