
#include <com/github/doevelopper/atlas/launcher/args/DefaultConfigurationTest.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;
using namespace com::github::doevelopper::atlas::launcher::args::test;

log4cxx::LoggerPtr DefaultConfigurationTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.DefaultConfigurationTest"));


DefaultConfigurationTest::DefaultConfigurationTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

DefaultConfigurationTest::~DefaultConfigurationTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void DefaultConfigurationTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // m_targetUnderTest = new ProgramOption();
}

void DefaultConfigurationTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}


