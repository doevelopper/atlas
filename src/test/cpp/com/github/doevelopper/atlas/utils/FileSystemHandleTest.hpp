/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     02/06/24 W 17:52
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_FILESYSTEMHANDLETEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_FILESYSTEMHANDLETEST_HPP

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/utils/FileSystemHandle.hpp>

namespace com::github::doevelopper::atlas::utils::test
{
    class FileSystemHandleTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
        Q_DISABLE_COPY_MOVE(FileSystemHandleTest)
    public:
        FileSystemHandleTest();
        ~FileSystemHandleTest() override;

        void SetUp() override;
        void TearDown() override;
    protected:
        com::github::doevelopper::atlas::utils::FileSystemHandle * m_targetUnderTest;
        std::string testDirPath = "./testdir";
        std::string testFilePath = testDirPath + "/testfile.txt";
    private:
    };
}

#endif
