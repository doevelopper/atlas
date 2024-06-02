
#include <com/github/doevelopper/atlas/semver/VersionTest.hpp>

using namespace com::github::doevelopper::atlas::semver;
using namespace com::github::doevelopper::atlas::semver::test;

log4cxx::LoggerPtr VersionTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.semver.test.VersionTest"));


VersionTest::VersionTest()
: m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

VersionTest::~VersionTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void VersionTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_targetUnderTest = new Version();
}

void VersionTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(VersionTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

// class MockISemverObject : public ISemverObject {
// public:
//     MOCK_CONST_METHOD0(GetMajor, std::string());
//     MOCK_CONST_METHOD0(GetMinor, std::string());
//     MOCK_CONST_METHOD0(GetPatch, std::string());
//     MOCK_CONST_METHOD0(GetPreRelease, std::string());
//     MOCK_CONST_METHOD0(GetBuildMetadata, std::string());
// };
//
// TEST_F(SemverObjectTest, DefaultConstructor) {
//     SemverObject obj;
//     EXPECT_EQ("0", obj.GetMajor());
//     EXPECT_EQ("0", obj.GetMinor());
//     EXPECT_EQ("0", obj.GetPatch());
//     EXPECT_EQ("", obj.GetPreRelease());
//     EXPECT_EQ("", obj.GetBuildMetadata());
// }
//
// TEST_F(SemverObjectTest, Constructor) {
//     MockISemverObject mock;
//     ON_CALL(mock, GetMajor).WillByDefault(::testing::Return("1"));
//     ON_CALL(mock, GetMinor).WillByDefault(::testing::Return("2"));
//     ON_CALL(mock, GetPatch).WillByDefault(::testing::Return("3"));
//     ON_CALL(mock, GetPreRelease).WillByDefault(::testing::Return("pre1"));
//     ON_CALL(mock, GetBuildMetadata).WillByDefault(::testing::Return("build1"));
//
//     SemverObject obj(mock);
//     EXPECT_EQ("1", obj.GetMajor());
//     EXPECT_EQ("2", obj.GetMinor());
//     EXPECT_EQ("3", obj.GetPatch());
//     EXPECT_EQ("pre1", obj.GetPreRelease());
//     EXPECT_EQ("build1", obj.GetBuildMetadata());
// }