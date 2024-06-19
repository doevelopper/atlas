
#include <com/github/doevelopper/atlas/launcher/args/ProgramOptionTest.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;
using namespace com::github::doevelopper::atlas::launcher::args::test;

log4cxx::LoggerPtr ProgramOptionTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.ProgramOptionTest"));


ProgramOptionTest::ProgramOptionTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ProgramOptionTest::~ProgramOptionTest() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void ProgramOptionTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // m_targetUnderTest = new ProgramOption();
}

void ProgramOptionTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}