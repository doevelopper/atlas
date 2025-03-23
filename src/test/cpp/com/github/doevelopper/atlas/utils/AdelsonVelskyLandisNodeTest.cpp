

#include <com/github/doevelopper/atlas/utils/AdelsonVelskyLandisNodeTest.hpp>

using namespace com::github::doevelopper::atlas::utils;
using namespace com::github::doevelopper::atlas::utils::test;

log4cxx::LoggerPtr AdelsonVelskyLandisNodeTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.utils.test.AdelsonVelskyLandisNodeTest"));

AdelsonVelskyLandisNodeTest::AdelsonVelskyLandisNodeTest() noexcept
     // : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

AdelsonVelskyLandisNodeTest::~AdelsonVelskyLandisNodeTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void AdelsonVelskyLandisNodeTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Cleanup any leftovers from previous runs.");
    m_targetUnderTest = nullptr;
}

void AdelsonVelskyLandisNodeTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Cleanup after tests.");
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
    clearTree(this->m_targetUnderTest);
}

void AdelsonVelskyLandisNodeTest::clearTree(KeyValueNode* node)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Cleanup after tests.");
    if (node == nullptr) return;
    clearTree(node->getChildNode(false));
    clearTree(node->getChildNode(true));
    delete node;
}

// TEST_F(AdelsonVelskyLandisNodeTest, NodeCreation)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Test the creation and basic properties of a node.");
//     KeyValueNode node(1, "one");
//     EXPECT_EQ(node.key, 1);
//     EXPECT_EQ(node.value, "one");
//     EXPECT_FALSE(node.isLinked());
// }