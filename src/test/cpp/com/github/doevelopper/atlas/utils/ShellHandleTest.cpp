/*******************************************************************
* @file
 * @version  v0.0.
 * @date     02/06/24 W 17:16
 * @brief
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#include <com/github/doevelopper/atlas/utils/ShellHandleTest.hpp>

using namespace com::github::doevelopper::atlas::utils;
using namespace com::github::doevelopper::atlas::utils::test;

log4cxx::LoggerPtr ShellHandleTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.storage.test.ShellHandleTest"));

ShellHandleTest::ShellHandleTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

ShellHandleTest::~ShellHandleTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void ShellHandleTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_targetUnderTest = new ShellHandle();
}

void ShellHandleTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(ShellHandleTest, ExecEcho)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__  << " Test a simple command that returns a string");
    std::string result = this->m_targetUnderTest->exec("echo 'Hello, world!'");
    EXPECT_EQ(result, "Hello, world!\n");
}

TEST_F(ShellHandleTest, ExecLs)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Test a simple command that returns a string");
    std::string result = this->m_targetUnderTest->exec("ls -l");
    EXPECT_TRUE(result.find("total") != std::string::npos);
}

TEST_F(ShellHandleTest, ExecCmdFailed)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Test a command that fails");
    std::string result = this->m_targetUnderTest->exec("this-command-does-not-exist");
    EXPECT_TRUE(result.find("popen() failed!") != std::string::npos);
}