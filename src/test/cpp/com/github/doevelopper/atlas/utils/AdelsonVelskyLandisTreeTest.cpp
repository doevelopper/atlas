

#include <com/github/doevelopper/atlas/utils/AdelsonVelskyLandisTreeTest.hpp>

using namespace com::github::doevelopper::atlas::utils;
using namespace com::github::doevelopper::atlas::utils::test;

log4cxx::LoggerPtr AdelsonVelskyLandisTreeTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.utils.test.AdelsonVelskyLandisTreeTest"));

AdelsonVelskyLandisTreeTest::AdelsonVelskyLandisTreeTest() noexcept
    // : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

AdelsonVelskyLandisTreeTest::~AdelsonVelskyLandisTreeTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void AdelsonVelskyLandisTreeTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Cleanup any leftovers from previous runs.");
    // m_targetUnderTest = new AdelsonVelskyLandisNode();
}

void AdelsonVelskyLandisTreeTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Cleanup after tests.");
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}
