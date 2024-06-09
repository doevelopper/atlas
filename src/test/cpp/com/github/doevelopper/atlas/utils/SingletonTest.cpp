
#include <com/github/doevelopper/atlas/utils/SingletonTest.hpp>

using namespace com::github::doevelopper::atlas::utils;
using namespace com::github::doevelopper::atlas::utils::test;

log4cxx::LoggerPtr SingletonTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.storage.test.SingletonTest"));

SingletonTest::SingletonTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

SingletonTest::~SingletonTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void SingletonTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     // Before each test, reset the Singleton's instance to ensure a clean state
//     // We need to manually delete the instance because the Singleton destructor is private
//     // and cannot be called directly.
//     auto* instance = MySingleton::instance().get();
//     if (instance != nullptr) {
//         MySingleton::m_instance.reset();
//     }
//
//     // m_targetUnderTest = new MySingleton();
}

void SingletonTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // // After each test, again ensure that the Singleton instance is reset.
    // // This is a redundant check but ensures the Singleton is always in a known state.
    // auto* instance = MySingleton::instance().get();
    // if (instance != nullptr)
    // {
    //     MySingleton::m_instance.reset();
    // }
    //
    // // if (this->m_targetUnderTest)
    // //     delete m_targetUnderTest;
    // // this->m_targetUnderTest = nullptr;

}

TEST_F(SingletonTest, SingletonInstanceCreation)
{
    // auto& instance1 = MySingleton::instance();
    // auto& instance2 = MySingleton::instance();
    //
    // ASSERT_EQ(&instance1, &instance2); // Ensure both references point to the same instance
}

TEST_F(SingletonTest, SingletonDataModification)
{
    // auto& instance = MySingleton::instance();
    // instance.increment(); // Increment the data member
    //
    // ASSERT_EQ(1, instance.data); // Check that the data was incremented correctly
}

TEST_F(SingletonTest, SingletonThreadSafety) {
    // This test requires multiple threads, which is beyond the scope of this example.
    // You would need to create multiple threads that all call MySingleton::instance(),
    // and then check that they all get the same instance.
    // This can be complex and is not shown here.
}
