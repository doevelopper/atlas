
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_VERSIONTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_VERSIONTEST_HPP

#include <com/github/doevelopper/atlas/semver/Version.hpp>

#include <gtest/gtest.h>

namespace com::github::doevelopper::atlas::semver::test
{
    class VersionTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        VersionTest();
        VersionTest(const VersionTest &)             = delete;
        VersionTest(VersionTest &&)                  = delete;
        VersionTest & operator=(const VersionTest &) = delete;
        VersionTest & operator=(VersionTest &&)      = delete;
        ~VersionTest() override;

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::atlas::semver::Version * m_targetUnderTest;

    private:
    };
}
#endif