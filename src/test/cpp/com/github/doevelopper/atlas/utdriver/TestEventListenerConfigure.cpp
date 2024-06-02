#include <com/github/doevelopper/atlas/utdriver/TestEventListenerConfigure.hpp>

using namespace com::github::doevelopper::atlas::logging;
using namespace com::github::doevelopper::atlas::utdriver::test;

log4cxx::LoggerPtr TestEventListenerConfigure::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.utdriver.test.TestEventListenerConfigure"));

log4cxx::LoggerPtr TestEventListenerConfigure::Delegate::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.utdriver.test.TestEventListenerConfigure.Delegate"));

// TestEventListenerConfigure::TestEventListenerConfigure() noexcept
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

TestEventListenerConfigure::~TestEventListenerConfigure() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TestEventListenerConfigure::Delegate::Delegate(::testing::TestEventListener *eventListener)
        : delegateEventListener(eventListener)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        //        this->eventListener = eventListener;
}
TestEventListenerConfigure::Delegate::~Delegate()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TestEventListenerConfigure::Delegate TestEventListenerConfigure::Delegate::showProgramStartEnd()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        this->m_showProgramStartEnd = true;
        return (*this);
}

TestEventListenerConfigure::Delegate TestEventListenerConfigure::Delegate::showIterationsStartEnd()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        this->m_showIterationsStartEnd = true;
        return (*this);
}

TestEventListenerConfigure::Delegate TestEventListenerConfigure::Delegate::showTestCases()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        this->m_showTestCases = true;
        return (*this);
}

TestEventListenerConfigure::Delegate TestEventListenerConfigure::Delegate::showTestNames()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        this->m_showTestNames = true;
        return (*this);
}

TestEventListenerConfigure::Delegate TestEventListenerConfigure::Delegate::showTestSuite()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        this->m_showTestSuite = true;
        return (*this);
}

TestEventListenerConfigure::Delegate TestEventListenerConfigure::Delegate::showSuccesses()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        this->m_showSuccesses = true;
        return (*this);
}

TestEventListenerConfigure::Delegate TestEventListenerConfigure::Delegate::showFailures()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        this->m_showFailures = true;
        return (*this);
}

TestEventListenerConfigure::Delegate TestEventListenerConfigure::Delegate::showInlineFailures()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        this->m_showInlineFailures = true;
        return (*this);
}

TestEventListenerConfigure::Delegate TestEventListenerConfigure::Delegate::showEnvironment()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        this->m_showEnvironment = true;
        return (*this);
}

TestEventListenerConfigure::Delegate TestEventListenerConfigure::Delegate::showSkip()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        this->m_showSkip = true;
        return (*this);
}

TestEventListenerConfigure *TestEventListenerConfigure::Delegate::build()
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        return (new TestEventListenerConfigure(
                this->delegateEventListener, this->m_showProgramStartEnd, this->m_showIterationsStartEnd,
                this->m_showTestCases, this->m_showTestNames, this->m_showTestSuite, this->m_showSuccesses,
                this->m_showFailures, this->m_showInlineFailures, this->m_showEnvironment, this->m_showSkip));
}

//        std::unique_ptr<::testing::TestEventListener> eventListener, bool showProgramStartEnd,: m_eventListener(std::move(eventListener))
TestEventListenerConfigure::TestEventListenerConfigure(::testing::TestEventListener *eventListener,
                                                             bool showProgramStartEnd, bool showIterationsStartEnd,
                                                             bool showTestCases, bool showTestSuite, bool showTestNames,
                                                             bool showSuccesses, bool showFailures,
                                                             bool showInlineFailures, bool showEnvironment,
                                                             bool showSkip)
        : m_eventListener(eventListener), m_showProgramStartEnd(showProgramStartEnd),
          m_showIterationsStartEnd(showIterationsStartEnd), m_showTestCases(showTestCases),
          m_showTestNames(showTestNames), m_showTestSuite(showTestSuite), m_showSuccesses(showSuccesses),
          m_showFailures(showFailures), m_showInlineFailures(showInlineFailures), m_showEnvironment(showEnvironment),
          m_showSkip(showSkip)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TestEventListenerConfigure::OnTestProgramStart(const ::testing::UnitTest &unit_test)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showProgramStartEnd)
                this->m_eventListener->OnTestProgramStart(unit_test);
}

void TestEventListenerConfigure::OnTestIterationStart(const ::testing::UnitTest &unit_test, int iteration)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showIterationsStartEnd)
                this->m_eventListener->OnTestIterationStart(unit_test, iteration);
}

void TestEventListenerConfigure::OnEnvironmentsSetUpStart(const ::testing::UnitTest &unit_test)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showEnvironment)
                this->m_eventListener->OnEnvironmentsSetUpStart(unit_test);
}
void TestEventListenerConfigure::OnEnvironmentsSetUpEnd(const ::testing::UnitTest &unit_test)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showEnvironment)
                this->m_eventListener->OnEnvironmentsSetUpEnd(unit_test);
}
void TestEventListenerConfigure::OnTestSuiteStart(const ::testing::TestSuite &test_suite)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showTestSuite)
                this->m_eventListener->OnTestSuiteStart(test_suite);
}

void TestEventListenerConfigure::OnTestCaseStart(const ::testing::TestCase &test_case)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showTestCases)
                this->m_eventListener->OnTestCaseStart(test_case);
}

void TestEventListenerConfigure::OnTestStart(const ::testing::TestInfo &test_info)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showTestNames)
                this->m_eventListener->OnTestStart(test_info);
}

void TestEventListenerConfigure::OnTestDisabled(const ::testing::TestInfo &test_info)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showTestNames)
                this->m_eventListener->OnTestStart(test_info);
}
void TestEventListenerConfigure::OnTestPartResult(const ::testing::TestPartResult &test_part_result)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showSuccesses && test_part_result.passed())
                this->m_eventListener->OnTestPartResult(test_part_result);

        if (this->m_showFailures && test_part_result.failed())
                this->m_eventListener->OnTestPartResult(test_part_result);
}

void TestEventListenerConfigure::OnTestEnd(const ::testing::TestInfo &test_info)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if ((this->m_showInlineFailures && test_info.result()->Failed()) ||
            (this->m_showSuccesses && test_info.result()->Passed()) ||
            (this->m_showSkip && test_info.result()->Skipped()))
                this->m_eventListener->OnTestEnd(test_info);
}
void TestEventListenerConfigure::OnTestSuiteEnd(const ::testing::TestSuite &test_suite)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showTestSuite)
                this->m_eventListener->OnTestSuiteEnd(test_suite);
}

void TestEventListenerConfigure::OnTestCaseEnd(const ::testing::TestCase &test_case)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showTestCases)
                this->m_eventListener->OnTestCaseEnd(test_case);
}

void TestEventListenerConfigure::OnEnvironmentsTearDownStart(const ::testing::UnitTest &unit_test)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showEnvironment)
                this->m_eventListener->OnEnvironmentsTearDownStart(unit_test);
}

void TestEventListenerConfigure::OnEnvironmentsTearDownEnd(const ::testing::UnitTest &unit_test)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showEnvironment)
                this->m_eventListener->OnEnvironmentsTearDownEnd(unit_test);
}
void TestEventListenerConfigure::OnTestIterationEnd(const ::testing::UnitTest &unit_test, int iteration)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showIterationsStartEnd)
                this->m_eventListener->OnTestIterationEnd(unit_test, iteration);
}

void TestEventListenerConfigure::OnTestProgramEnd(const ::testing::UnitTest &unit_test)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        if (this->m_showProgramStartEnd)
                this->m_eventListener->OnTestProgramEnd(unit_test);
}
