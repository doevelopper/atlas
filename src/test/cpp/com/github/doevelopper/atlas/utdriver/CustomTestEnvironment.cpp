#include <com/github/doevelopper/atlas/utdriver/CustomTestEnvironment.hpp>

#include <random>

using namespace com::github::doevelopper::atlas::logging;
using namespace com::github::doevelopper::atlas::utdriver::test;

log4cxx::LoggerPtr CustomTestEnvironment::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.utdriver.test.CustomTestEnvironment"));

CustomTestEnvironment::CustomTestEnvironment() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

CustomTestEnvironment::~CustomTestEnvironment() noexcept
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // gtest takes ownership of the TestEnvironment ptr - we don't delete it.
}

void CustomTestEnvironment::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(1024, 65536);
    // const int port = (std::rand() % (65536 - 1024)) + 1024;
    const int port = distr (eng) + 1024;

    LOG4CXX_INFO(logger, "Environment TCP_PORT=" << port);
    // LOG4CXX_DEBUG_FMT(logger, "Raw CDI for node: {}", port);
    constexpr int overwrite = 1;
    setenv("MASTER_PORT_5984_TCP_ADDR", "127.0.0.1", overwrite);
    setenv("MASTER_PORT_5984_TCP_PORT", std::to_string(port).c_str(), overwrite);
    setenv("SPLOG_STDERR", "1", overwrite);
    // setenv("TERM", "xterm-256color", 0);
    setenv("LOG4CXX_CONFIGURATION_WATCH_SECONDS", "120", 0);
    setenv("LOG4CXX_CONFIGURATION", "/etc/configs/nightOwl.xml", 0);
}

void CustomTestEnvironment::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // setenv("TERM", "", 0);
    // setenv("LOG4CXX_CONFIGURATION_WATCH_SECONDS", "", 0);
    // setenv("LOG4CXX_CONFIGURATION", "", 0);
    // unsetenv("LOG4CXX_CONFIGURATION");
    // unsetenv("LOG4CXX_CONFIGURATION_WATCH_SECONDS");
}
