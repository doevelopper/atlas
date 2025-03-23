
#include <com/github/doevelopper/atlas/security/AlgorithmTest.hpp>

using namespace com::github::doevelopper::atlas::security;
using namespace com::github::doevelopper::atlas::security::test;

log4cxx::LoggerPtr AlgorithmTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.security.test.AlgorithmTest"));


AlgorithmTest::AlgorithmTest() noexcept
: m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

AlgorithmTest::~AlgorithmTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void AlgorithmTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // m_targetUnderTest = new RecursiveReadLock();
}

void AlgorithmTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(AlgorithmTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}


#include "AlgorithmTest.hpp"
