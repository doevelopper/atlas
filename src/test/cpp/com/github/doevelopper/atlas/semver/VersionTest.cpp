
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
/*
For 0x0102030405060708:
Major: Bits 63-56 → 0x01 → 1
Minor: Bits 55-48 → 0x02 → 2
Patch: Bits 47-40 → 0x03 → 3
Pre-release: Bits 39-32 → 0x04 → 4
Pre-release Count: Bits 31-24 → 0x05 → 5
Build Metadata: Bits 23-16 → 0x06 → 6
Build Count: Bits 15-8 → 0x07 → 7
Additional Flags: Bits 7-0 → 0x08 → 8
*/
TEST_F(VersionTest, DefaultConstructor)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    EXPECT_EQ(this->m_targetUnderTest->rawVersion(), 0x0000000000000000);
    EXPECT_EQ(this->m_targetUnderTest->major(), 0);
    EXPECT_EQ(this->m_targetUnderTest->minor(), 0);
    EXPECT_EQ(this->m_targetUnderTest->patch(), 0);
    EXPECT_STREQ(this->m_targetUnderTest->toString().c_str(),"0.0.0-0.0+0.0[0]");
    EXPECT_NE(this->m_targetUnderTest->toString().c_str(),"");
    EXPECT_NE(this->m_targetUnderTest->toString().c_str(),"1.2.3-4.5+6.7[8]");
}

TEST_F(VersionTest, ParameterConstructor)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_targetUnderTest->rawVersion(0x0102030405060708);
    EXPECT_EQ(this->m_targetUnderTest->rawVersion(), 0x0102030405060708);
    EXPECT_EQ(this->m_targetUnderTest->major(), 0x01);
    EXPECT_EQ(this->m_targetUnderTest->minor(), 0x02);
    EXPECT_EQ(this->m_targetUnderTest->patch(), 0x03);
    EXPECT_NE(this->m_targetUnderTest->toString().c_str(),"0.0.0-0.0+0.0[0]");
    EXPECT_NE(this->m_targetUnderTest->toString().c_str(),"");
    EXPECT_NE(this->m_targetUnderTest->toString().c_str(),"1.2.3-4.5+6.7[8]");//!FIXME this should be right
    EXPECT_STREQ(this->m_targetUnderTest->toString().c_str(),"1.2.3-4.5+6.7[8]");
}

TEST_F(VersionTest, MultiParametersConstructor)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Version v(1, 2, 3, 4, 5, 6, 7, 8);
    // this->m_targetUnderTest->rawVersion(0x0102030405060708);
    // EXPECT_EQ(this->m_targetUnderTest->rawVersion(), 0x0102030405060708);
    // EXPECT_EQ(this->m_targetUnderTest->major(), 0x01);
    // EXPECT_EQ(this->m_targetUnderTest->minor(), 0x02);
    // EXPECT_EQ(this->m_targetUnderTest->patch(), 0x03);
    // EXPECT_NE(this->m_targetUnderTest->toString().c_str(),"0.0.0-0.0+0.0[0]");
    // EXPECT_NE(this->m_targetUnderTest->toString().c_str(),"");
    // EXPECT_NE(this->m_targetUnderTest->toString().c_str(),"1.2.3-4.5+6.7[8]");//!FIXME this should be right
    // EXPECT_STREQ(this->m_targetUnderTest->toString().c_str(),"1.1.3-4.5+6.7[8]");
}

//
// TEST_F(VersionTest, ValidCoreOnly)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v("1.0.0");
//     EXPECT_EQ(v.get_m_major(), 1);
//     EXPECT_EQ(v.get_m_minor(), 0);
//     EXPECT_EQ(v.get_m_patch(), 0);
//     EXPECT_EQ(v.getPreRelease(), "");
//     EXPECT_EQ(v.getBuild(), "");
//     EXPECT_EQ(v.toString(), "1.0.0");
//     // EXPECT_EQ(v.toNumericalValue(), 0x01000000000000FFULL);
// }
//
// TEST_F(VersionTest, ValidWithPreRelease)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v("1.0.0-alpha");
//     EXPECT_EQ(v.get_m_major(), 1);
//     EXPECT_EQ(v.get_m_minor(), 0);
//     EXPECT_EQ(v.get_m_patch(), 0);
//     EXPECT_EQ(v.getPreRelease(), "alpha");
//     EXPECT_EQ(v.getBuild(), "");
//     EXPECT_EQ(v.toString(), "1.0.0-alpha");
//     // EXPECT_EQ(v.toNumericalValue(), 0x0100000000000001ULL);
// }
//
// TEST_F(VersionTest, ValidWithBuild)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v("1.0.0+build");
//     EXPECT_EQ(v.get_m_major(), 1);
//     EXPECT_EQ(v.get_m_minor(), 0);
//     EXPECT_EQ(v.get_m_patch(), 0);
//     EXPECT_EQ(v.getPreRelease(), "");
//     // EXPECT_EQ(v.getBuild(), "build");
//     // EXPECT_EQ(v.toString(), "1.0.0+build");
//     //EXPECT_EQ(v.toNumericalValue(), 0x01000000000000FFULL); // Build metadata doesn't affect numerical value
//
// }
//
// TEST_F(VersionTest, ValidWithPreReleaseAndBuild)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v("1.0.0-rc-1+build.2");
//     EXPECT_EQ(v.get_m_major(), 1);
//     EXPECT_EQ(v.get_m_minor(), 0);
//     EXPECT_EQ(v.get_m_patch(), 0);
//     EXPECT_EQ(v.getPreRelease(), "rc-1");
//     // EXPECT_EQ(v.getBuild(), "build.2");
//     // EXPECT_EQ(v.toString(), "1.0.0-rc-1+build.2");
// }
//
// TEST_F(VersionTest, ValidWithPreReleaseAndBuildExt) {
//     Version v("1.3.7+build.2.b8f12d7");
//     EXPECT_EQ(v.get_m_major(), 1);
//     EXPECT_EQ(v.get_m_minor(), 3);
//     EXPECT_EQ(v.get_m_patch(), 7);
//     EXPECT_EQ(v.getPreRelease(), "");
//     //EXPECT_EQ(v.getBuild(), "build.2.b8f12d7");
//     // EXPECT_EQ(v.toNumericalValue(), 0x0103000700000000ULL | (2ULL << 16) | (3ULL << 8));
// }
//
// TEST_F(VersionTest, EdgeCaseMinimumValues)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v("0.0.0");
//     EXPECT_EQ(v.get_m_major(), 0);
//     EXPECT_EQ(v.get_m_minor(), 0);
//     EXPECT_EQ(v.get_m_patch(), 0);
//     EXPECT_EQ(v.getPreRelease(), "");
//     EXPECT_EQ(v.getBuild(), "");
//     EXPECT_EQ(v.toString(), "0.0.0");
//     // EXPECT_EQ(v.toNumericalValue(), 0x00000000000000FFULL);
// }
//
// TEST_F(VersionTest, EdgeCaseLargeNumbers)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v("255.255.255");
//     EXPECT_EQ(v.get_m_major(), 255);
//     EXPECT_EQ(v.get_m_minor(), 255);
//     EXPECT_EQ(v.get_m_patch(), 255);
//     // EXPECT_EQ(v.toNumericalValue(), 0xFFFF0000000000FFULL);
// }
//
// TEST_F(VersionTest, EdgeCaseEmptyPreRelease)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     // EXPECT_THROW(Version("1.0.0-"), std::invalid_argument);
// }
//
// TEST_F(VersionTest, EdgeCaseEmptyBuild)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     // EXPECT_THROW(Version("1.0.0+"), std::invalid_argument);
// }
//
// TEST_F(VersionTest, ComparisonEqualVersions)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v1("1.0.0");
//     Version v2("1.0.0");
//     EXPECT_EQ(v1.compare(v2), 0);
// }
//
// TEST_F(VersionTest, ComparisonDifferentMajor)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v1("1.0.0");
//     Version v2("2.0.0");
//     EXPECT_LT(v1.compare(v2), 0);
//     EXPECT_GT(v2.compare(v1), 0);
// }
//
// TEST_F(VersionTest, ComparisonWithPreRelease)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v1("1.0.0-alpha");
//     Version v2("1.0.0");
//     EXPECT_LT(v1.compare(v2), 0);
//     EXPECT_GT(v2.compare(v1), 0);
// }
//
// TEST_F(VersionTest, ComparisonPreReleaseOrder)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v1("1.0.0-alpha");
//     Version v2("1.0.0-beta");
//     EXPECT_LT(v1.compare(v2), 0);
//     EXPECT_GT(v2.compare(v1), 0);
// }
//
// TEST_F(VersionTest, ComparisonComplexPreRelease)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v1("1.0.0-alpha.1");
//     Version v2("1.0.0-alpha.2");
//     EXPECT_LT(v1.compare(v2), 0);
//     EXPECT_GT(v2.compare(v1), 0);
// }
//
// TEST_F(VersionTest, ComparisonNumericVsAlphanumeric)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v1("1.0.0-1");
//     Version v2("1.0.0-alpha");
//     EXPECT_LT(v1.compare(v2), 0);
//     EXPECT_GT(v2.compare(v1), 0);
// }
//
// TEST_F(VersionTest, ComparisonDifferentLengths)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     Version v1("1.0.0-alpha");
//     Version v2("1.0.0-alpha.1");
//     EXPECT_LT(v1.compare(v2), 0);
//     EXPECT_GT(v2.compare(v1), 0);
// }
//
// TEST_F(VersionTest, InvalidLeadingZeroInMajor)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     //EXPECT_THROW(Semver("01.0.0"), std::invalid_argument);
// }
//
// TEST_F(VersionTest, InvalidLeadingZeroInPreRelease)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     //EXPECT_THROW(Semver("1.0.0-00"), std::invalid_argument);
// }
//
// TEST_F(VersionTest, InvalidStructure)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     //EXPECT_THROW(Semver("1.0.0-alpha..1"), std::invalid_argument);
//     //EXPECT_THROW(Semver("1.0.0+"), std::invalid_argument);
// }

// TEST_F(VersionTest, ValidVersionCore)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     //SemVer semver("1.2.3");
//     EXPECT_EQ(this->m_targetUnderTest->get_m_major(), 0);
//     EXPECT_EQ(this->m_targetUnderTest->get_m_minor(), 0);
//     EXPECT_EQ(this->m_targetUnderTest->get_m_patch(), 0);
//     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << "this->m_targetUnderTest->get_m_tweak()" << this->m_targetUnderTest->get_m_tweak());
//     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << "this->m_targetUnderTest->get_m_tweak()" << this->m_targetUnderTest->get_m_release_type());
//     // EXPECT_TRUE(this->m_targetUnderTest->get_m_tweak());
//     // EXPECT_TRUE(semver.build().empty());
// }

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