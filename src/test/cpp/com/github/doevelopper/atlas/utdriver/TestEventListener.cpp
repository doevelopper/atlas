#include <com/github/doevelopper/atlas/utdriver/TestEventListener.hpp>

#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <regex>

using namespace com::github::doevelopper::atlas::logging;
using namespace com::github::doevelopper::atlas::utdriver::test;

log4cxx::LoggerPtr TestEventListener::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.utdriver.test.TestEventListener"));

TestEventListener::TestEventListener() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TestEventListener::~TestEventListener() noexcept
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // gtest takes ownership of the TestEnvironment ptr - we don't delete it.
}


void TestEventListener::OnTestProgramStart(const ::testing::UnitTest &unit_test)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        LOG4CXX_INFO(logger,
                     "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
        LOG4CXX_INFO(logger, "Total Test Suite: " << ::testing::UnitTest::GetInstance()->total_test_suite_count()
                                                  << " Test cases with at least one test: "
                                                  << ::testing::UnitTest::GetInstance()->test_suite_to_run_count());
        LOG4CXX_INFO(logger,
                     "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
}

void TestEventListener::OnTestIterationStart(const ::testing::UnitTest &unit_test, int iteration)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TestEventListener::OnEnvironmentsSetUpStart(const ::testing::UnitTest &unit_test)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TestEventListener::OnEnvironmentsSetUpEnd(const ::testing::UnitTest &unit_test)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TestEventListener::OnTestSuiteStart(const ::testing::TestSuite &test_suite)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        LOG4CXX_DEBUG(logger, "RUN: " << test_suite.name());
}

void TestEventListener::OnTestCaseStart(const ::testing::TestCase &test_case)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        LOG4CXX_DEBUG(logger, ">--------------->>--------------->>--------------->>--------------->>--------------->");
        LOG4CXX_DEBUG(logger, "    " << ::testing::UnitTest::GetInstance()->current_test_case()->name() << "    "
                                     << test_case.test_to_run_count() << "/" << test_case.total_test_count());
        LOG4CXX_DEBUG(logger, ">--------------->>--------------->>--------------->>--------------->>--------------->");
}

void TestEventListener::OnTestStart(const ::testing::TestInfo &test_info)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        LOG4CXX_DEBUG(logger, test_info.test_suite_name() << "." << test_info.name());
        std::stringstream formatedTestInfo;
        formatedTestInfo << "Test : [" << test_info.name() << "]";
        formatedTestInfo << " Test suite: [" << test_info.test_suite_name() << "]";
        formatedTestInfo << " of test case [" << test_info.test_case_name() << "]";
        formatedTestInfo << " (" << ::testing::UnitTest::GetInstance()->test_case_to_run_count() << ")";

        if (test_info.value_param() != nullptr) {
                formatedTestInfo << " with value param [" << test_info.value_param() << "]";
        }

        if (test_info.type_param() != nullptr) {
                formatedTestInfo << " and with type param [" << test_info.type_param() << "]";
        }

        LOG4CXX_DEBUG(logger, "!!! " << formatedTestInfo.str() << " !!!");
}

void TestEventListener::OnTestDisabled(const ::testing::TestInfo &test_info)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TestEventListener::OnTestPartResult(const ::testing::TestPartResult &test_part_result)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        std::string status = test_part_result.failed() ? "*** Failure***" : "Success !!!";
        if (test_part_result.failed()) {
                std::string message = test_part_result.message();
                std::string summary = test_part_result.summary();
                std::stringstream msg;

                if (test_part_result.file_name())
                        msg << test_part_result.file_name() << std::string(":");

                if (test_part_result.line_number() != -1)
                        msg << test_part_result.line_number() << std::string(":");

                LOG4CXX_ERROR(logger, "Reason: " << msg.str());
                if (!summary.empty()) {
                        // if (msg) {
                        //         msg << std::string("\n");
                        // }
                        // msg << summary;
                    // summary.erase( std::remove( summary.begin(), summary.end(), '\n'), summary.end());
                    // boost::replace_all(summary, "\r\n", " ");
                    summary = std::regex_replace( summary, std::regex("\n")," ");
                    // std::erase_if( summary,
                    //                [](auto ch)
                    //                {
                    //                     return (ch == '\n' ||
                    //                         ch == '\t' ||
                    //                             ch == '\r');
                    //                });
                    LOG4CXX_ERROR(logger, summary.c_str());
                }
                // if (!summary.empty() && summary != message) {
                //         // if (msg) {
                //         //         msg << std::string("\n");
                //         // }
                //     // boost::trim(message); // removes all leading and trailing white spaces
                //     // boost::trim_if(message, boost::is_any_of("\n")); // removes only tabs
                //     //     msg << message;
                //     message.erase( std::remove( message.begin(), message.end(), '\n'), message.end());
                //     LOG4CXX_ERROR(logger, message.c_str());
                // }
                // LOG4CXX_ERROR(logger, "Reason " << test_part_result.summary() << msg.str()
                //                                 << test_part_result.fatally_failed());
        }
}

void TestEventListener::OnTestEnd(const ::testing::TestInfo &test_info)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

        std::stringstream formatedTestInfo;
        formatedTestInfo << " [Test suite: " << test_info.test_suite_name() << "] finished: ";
        formatedTestInfo << " Test : " << test_info.name();

        if (test_info.result()) {
                if (test_info.result()->Passed()) {
                        formatedTestInfo << " -> PASSED";
                }

                if (test_info.result()->Failed()) {
                        // if (GTEST_FLAG(list_tests))
                        // {
                        formatedTestInfo << " file [" << test_info.file() << "]";
                        formatedTestInfo << " line [" << test_info.line() << "]";
                        // }
                        formatedTestInfo << " -> FAILED";
                }
        }

        formatedTestInfo << " ";
        formatedTestInfo << (test_info.result())->elapsed_time() << " ms";

        LOG4CXX_INFO(logger, "Summary: " << formatedTestInfo.str());
}

void TestEventListener::OnTestSuiteEnd(const ::testing::TestSuite &test_suite)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        LOG4CXX_DEBUG(logger, "END RUN: " << test_suite.name());
}

void TestEventListener::OnTestCaseEnd(const ::testing::TestCase &test_case)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        LOG4CXX_DEBUG(logger, "<---------------<<---------------<<---------------<<---------------<<---------------");
        LOG4CXX_DEBUG(logger, "    " << ::testing::UnitTest::GetInstance()->current_test_case()->name() << "   "
                                     << test_case.elapsed_time() << " ms");
        LOG4CXX_DEBUG(logger, " Passed(" << test_case.successful_test_count() << ")"
                                         << " Failed(" << test_case.failed_test_count() << ")"
                                         << " Skipped(" << test_case.skipped_test_count() << ")"
                                         << " Disabled(" << test_case.disabled_test_count() << ")");
        LOG4CXX_DEBUG(logger, "<---------------<<---------------<<---------------<<---------------<<---------------");
}

void TestEventListener::OnEnvironmentsTearDownStart(const ::testing::UnitTest &unit_test)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TestEventListener::OnEnvironmentsTearDownEnd(const ::testing::UnitTest &unit_test)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TestEventListener::OnTestIterationEnd(const ::testing::UnitTest &unit_test, int iteration)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        LOG4CXX_DEBUG(logger, "Test Iteration  " << unit_test.Passed() << " Elapsed time " << unit_test.elapsed_time()
                                                 << " ms");
}

void TestEventListener::OnTestProgramEnd(const ::testing::UnitTest &unit_test)
{
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
        LOG4CXX_INFO(logger,
                     "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
        LOG4CXX_INFO(logger, unit_test.reportable_test_count()
                                     << " tests Executed: Passed(" << unit_test.successful_test_count() << "), Failed("
                                     << unit_test.failed_test_count() << ")"
                                     << ", Skipped(" << unit_test.skipped_test_count() << ")"
                                     << ", Disabled(" << unit_test.reportable_disabled_test_count() << ")"
                                     << " Duration: (" << unit_test.elapsed_time() << " ms)");
        LOG4CXX_INFO(logger,
                     "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
}