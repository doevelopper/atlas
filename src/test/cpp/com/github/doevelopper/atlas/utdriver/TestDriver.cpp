

#include <com/github/doevelopper/atlas/utdriver/TestDriver.hpp>
#include <com/github/doevelopper/atlas/utdriver/TestEventListener.hpp>
#include <com/github/doevelopper/atlas/utdriver/TestEventListenerConfigure.hpp>
#include <com/github/doevelopper/atlas/utdriver/CustomTestEnvironment.hpp>

#include <gmock/gmock.h>

using namespace com::github::doevelopper::atlas::logging;
using namespace com::github::doevelopper::atlas::utdriver::test;

log4cxx::LoggerPtr TestDriver::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.extensions.test.TestDriver"));

TestDriver::TestDriver() noexcept
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TestDriver::TestDriver(std::string &suite, unsigned int iteration) noexcept
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TestDriver::~TestDriver() noexcept
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool TestDriver::setup(int argc, char *argv[])
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        this->moduleUnderTest(argv);
        ::testing::InitGoogleMock(&argc, argv);
        ::testing::TestEventListeners &listeners = testing::UnitTest::GetInstance()->listeners();
        auto default_printer = listeners.Release(listeners.default_result_printer());
        delete listeners.Release(listeners.default_result_printer());

        TestEventListenerConfigure::Delegate(default_printer).build();
        listeners.Append(new TestEventListener);
        ::testing::AddGlobalTestEnvironment(new CustomTestEnvironment);
        return true;
}

int TestDriver::run(int argc, char *argv[])
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        return (RUN_ALL_TESTS());
}

bool TestDriver::teardown()
{
        return true;
}

void TestDriver::moduleUnderTest(char *argv[])
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

        auto sp = std::span<char>(argv[0], strlen(argv[0]));
        std::transform(sp.begin(), sp.end(), sp.begin(), [](char c) { return std::toupper(c); });
        const std::string runnerProcessName = std::string(sp.begin(), sp.end());
        std::string::size_type i = runnerProcessName.find("CPP");
        m_moduleUnderTest = runnerProcessName;
        m_moduleUnderTest.remove_prefix(m_moduleUnderTest.find_last_of('/') + 1);

        LOG4CXX_INFO(logger, "###################################################################");
        LOG4CXX_INFO(logger, "Module Under UnitTest:  " << m_moduleUnderTest);
        LOG4CXX_INFO(logger, "###################################################################");
}

void TestDriver::notYetImplemented()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        GTEST_NONFATAL_FAILURE_("Not YET implemented!!!!!!");
}