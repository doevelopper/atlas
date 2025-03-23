
#include <numeric>
#include <cstddef>//std::nullptr_t
#include <com/github/doevelopper/atlas/utils/AdelsonVelskyLandisTest.hpp>

using namespace com::github::doevelopper::atlas::utils;
using namespace com::github::doevelopper::atlas::utils::test;

log4cxx::LoggerPtr AdelsonVelskyLandisTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.utils.test.AdelsonVelskyLandisTest"));


log4cxx::LoggerPtr My::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.utils.My"));

AdelsonVelskyLandisTest::AdelsonVelskyLandisTest() noexcept
    // : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

AdelsonVelskyLandisTest::~AdelsonVelskyLandisTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void AdelsonVelskyLandisTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Cleanup any leftovers from previous runs.");
    // m_targetUnderTest = new AdelsonVelskyLandisNode();
}

void AdelsonVelskyLandisTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Cleanup after tests.");
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}

TEST_F(AdelsonVelskyLandisTest, testRandomized)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " Test the creation and basic properties of a node.");
    std::array<std::shared_ptr<My>, 256> t{};
    for (std::uint8_t i = 0U; i < 255U; i++)
    {
        t.at(i) = std::make_shared<My>(i);
    }

    std::array<bool, 256> mask{};
    std::size_t           size = 0;
    typename My::TreeType root;
    std::uint64_t         cnt_addition = 0;
    std::uint64_t         cnt_removal  = 0;

    const auto validate = [&] {
        ASSERT_EQ(size,
                          std::accumulate(mask.begin(), mask.end(), 0U, [](const std::size_t a, const std::size_t b) {
                              return a + b;
                          }));
        EXPECT_NE(nullptr, findBrokenBalanceFactor<My>(root));
        // TEST_ASSERT_NULL(findBrokenBalanceFactor<My>(root));
        EXPECT_NE(nullptr, findBrokenAncestry<My>(root));
        // TEST_ASSERT_NULL(findBrokenAncestry<My>(root));

        ASSERT_EQ(size, checkOrdering<My>(root));
        std::array<bool, 256> new_mask{};
        root.traverseInOrder([&](const My& node) { new_mask.at(node.getValue()) = true; });
        ASSERT_EQ(mask, new_mask);  // Otherwise, the contents of the tree does not match our expectations.
    };

    validate();

    const auto add = [&](const std::uint8_t x) {
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
        const auto predicate = [&](const My& v) { return x - v.getValue(); };
        if (My* const existing = root.search(predicate))
        {
            ASSERT_TRUE(mask.at(x));
            ASSERT_EQ(x, existing->getValue());
            auto result = root.search(predicate, []() -> My* {
                EXPECT_TRUE(false) <<"Attempted to create a new node when there is one already";
                return nullptr;
            });
            ASSERT_EQ(x, std::get<0>(result)->getValue());
            ASSERT_TRUE(std::get<1>(result));
        }
        else
        {
            ASSERT_FALSE(mask.at(x));
            bool factory_called = false;
            auto result         = root.search(predicate, [&]() -> My* {
                factory_called = true;
                return t.at(x).get();
            });
            ASSERT_EQ(x, std::get<0>(result)->getValue());
            ASSERT_FALSE(std::get<1>(result));
            //TEST_ASSERT(factory_called);
            size++;
            cnt_addition++;
            mask.at(x) = true;
        }
    };

    const auto drop = [&](const std::uint8_t x) {
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
        const auto predicate = [&](const My& v) { return x - v.getValue(); };
        if (My* const existing = root.search(predicate))
        {
            ASSERT_TRUE(mask.at(x));
            ASSERT_EQ(x, existing->getValue());
            root.remove(existing);
            size--;
            cnt_removal++;
            mask.at(x) = false;
            EXPECT_EQ(root.search(predicate),nullptr);
        }
        else
        {
            ASSERT_FALSE(mask.at(x));
        }
    };

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << "Running the randomized test...");
    // for (std::uint32_t iteration = 0U; iteration < 100'000U; iteration++)
    for (std::uint32_t iteration = 0U; iteration < 1'000U; iteration++)
    {
        if ((getRandomByte() % 2U) != 0)
        {
            add(getRandomByte());
        }
        else
        {
            drop(getRandomByte());
        }
        validate();
    }

    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ <<  "Final state:");
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << "size=" << size << ", cnt_addition=" << cnt_addition << ", cnt_removal=" << cnt_removal);
    if (root != nullptr)
    {
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << "min/max: " << root.min()->getValue() << "/" << root.max()->getValue());
    }
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__  << toGraphviz(root));
    validate();
}