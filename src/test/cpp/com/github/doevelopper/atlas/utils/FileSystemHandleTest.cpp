
#include <filesystem>

#include <com/github/doevelopper/atlas/utils/FileSystemHandleTest.hpp>

using namespace com::github::doevelopper::atlas::utils;
using namespace com::github::doevelopper::atlas::utils::test;

log4cxx::LoggerPtr FileSystemHandleTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.storage.test.FileSystemHandleTest"));

FileSystemHandleTest::FileSystemHandleTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

FileSystemHandleTest::~FileSystemHandleTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void FileSystemHandleTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Cleanup any leftovers from previous runs.");
    // Cleanup any leftovers from previous runs
    if (std::filesystem::exists(testDirPath))
    {
        std::filesystem::remove_all(testDirPath);
    }

    m_targetUnderTest = new FileSystemHandle();
}

void FileSystemHandleTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Cleanup after tests.");
    // Cleanup after tests
    if (std::filesystem::exists(testDirPath))
    {
        std::filesystem::remove_all(testDirPath);
    }

    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(FileSystemHandleTest, CreateEmptyFile)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    EXPECT_TRUE(this->m_targetUnderTest->createDirectory(testDirPath)); // Ensure directory exists
    EXPECT_TRUE(this->m_targetUnderTest->createEmptyFile(testFilePath));
    EXPECT_TRUE(std::filesystem::exists(testFilePath));
}

TEST_F(FileSystemHandleTest, SetFilePermissionsWriteAll)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    EXPECT_TRUE(this->m_targetUnderTest->createEmptyFile(testFilePath));
    EXPECT_TRUE(this->m_targetUnderTest->setFilePermissionsWriteAll(testFilePath));
    // Note: Actual permission checks are OS-dependent and might require platform-specific tests.
}

TEST_F(FileSystemHandleTest, SetFilePermissionsAllAll)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    EXPECT_TRUE(this->m_targetUnderTest->createEmptyFile(testFilePath));
    EXPECT_TRUE(this->m_targetUnderTest->setFilePermissionsAllAll(testFilePath));
    // Similar to above, actual permission checks depend on the OS.
}

TEST_F(FileSystemHandleTest, CreateDirectoryAlreadyExists)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    EXPECT_TRUE(this->m_targetUnderTest->createDirectory(testDirPath));
    EXPECT_FALSE(this->m_targetUnderTest->createDirectory(testDirPath)); // Should return false if already exists
}

TEST_F(FileSystemHandleTest, CreateEmptyFileNonExistentDir)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    std::string nestedPath = testDirPath + "/subdir/testfile.txt";
    EXPECT_FALSE(this->m_targetUnderTest->createEmptyFile(nestedPath)); // Directory does not exist
}

TEST_F(FileSystemHandleTest, SetPermissionsOnNonExistentFile)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    std::string nonExistentPath = testDirPath + "/nonexistent.txt";
    EXPECT_FALSE(this->m_targetUnderTest->setFilePermissionsWriteAll(nonExistentPath)); // File does not exist
    EXPECT_FALSE(this->m_targetUnderTest->setFilePermissionsAllAll(nonExistentPath)); // Ditto
}

TEST_F(FileSystemHandleTest, CreateDirectoryWithTrailingSlash)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    std::string pathWithSlash = testDirPath + "/";
    EXPECT_TRUE(this->m_targetUnderTest->createDirectory(pathWithSlash)); // Should handle trailing slash properly
}

TEST_F(FileSystemHandleTest, CreateDirectoryWithInvalidPath)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    std::string invalidPath = "./this/should/never/exist/or/be/allowed/";
    EXPECT_FALSE(this->m_targetUnderTest->createDirectory(invalidPath)); // Assuming invalid based on access rights
}

TEST_F(FileSystemHandleTest, HandleExceptionInCreateOperations) {
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    // Mock a situation that would cause an exception, e.g., insufficient permissions
    // This is tricky without controlling the filesystem state in test, but conceptually:
    // EXPECT_THROW(fileSystem.createDirectory("/path/cant/create"), std::filesystem::filesystem_error);
    // Real implementation would depend on how you can simulate such a scenario safely.
}
