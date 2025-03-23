/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     24/12/24 W 22:20
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_ADELSONVELSKYLANDISTEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_ADELSONVELSKYLANDISTEST_HPP

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/utils/AdelsonVelskyLandis.hpp>

namespace com::github::doevelopper::atlas::utils::test
{

    class My : public cavl::Node<My>
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        My() = default;
        explicit My(const std::uint16_t v)
        : value(v)
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
        }
        using Self = cavl::Node<My>;
        using Self::isLinked;
        using Self::isRoot;
        using Self::getChildNode;
        using Self::getParentNode;
        using Self::getNextInOrderNode;
        using Self::getBalanceFactor;
        using Self::search;
        using Self::remove;
        using Self::traverseInOrder;
        using Self::traversePostOrder;
        using Self::min;
        using Self::max;

        SDLC_REQUIRED_RESULT auto getValue() const -> std::uint16_t
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            return value;
        }

    private:
        std::uint16_t value = 0;

        // These dummy fields are needed to ensure the node class does not make incorrect references to the fields
        // defined in the derived class. That would trigger compilation error in this case, but may be deadly in the field.
        using E = struct {};
        SDLC_MAYBE_UNUSED E up;
        SDLC_MAYBE_UNUSED E lr;
        SDLC_MAYBE_UNUSED E bf;
    };

    class AdelsonVelskyLandisTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
        Q_DISABLE_COPY_MOVE(AdelsonVelskyLandisTest)
    public:

        using MyTree = cavl::Tree<My>;
        static_assert(std::is_same<My::TreeType, MyTree>::value, "????");
        static_assert(std::is_same<cavl::Node<My>, MyTree::NodeType>::value, "????????");
        template <typename T>
        using N = typename cavl::Node<T>::DerivedType;
        static_assert(std::is_same<My, N<My>>::value, "????????????");

        AdelsonVelskyLandisTest() noexcept;
        ~AdelsonVelskyLandisTest() noexcept override;

        void SetUp() override;
        void TearDown() override;

        template <typename T>
        SDLC_REQUIRED_RESULT bool checkLinkage(const N<T>* const  self
                    , const N<T>* const           up,
                                    const std::array<N<T>*, 2>& lr,
                                    const std::int8_t           bf)
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            return (self->getParentNode() == up)
                && (self->getChildNode(false) == lr.at(0))
                && (self->getChildNode(true) == lr.at(1))
                && (self->getBalanceFactor() == bf)
                && ((up == nullptr)
                    || (up->getChildNode(false) == self)
                    || (up->getChildNode(true) == self))
                && ((lr.at(0) == nullptr)
                    || (lr.at(0)->getParentNode() == self))
                && ((lr.at(1) == nullptr)
                    || (lr.at(1)->getParentNode() == self));
        }

        template <typename T>
        SDLC_REQUIRED_RESULT auto getHeight(const N<T>* const n) -> std::int8_t  // NOLINT(misc-no-recursion)
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            return (n != nullptr) ?
                static_cast<std::int8_t>(1 + std::max(getHeight<T>(n->getChildNode(false)), getHeight<T>(n->getChildNode(true))))
                : 0;
        }

        /// Returns the size if the tree is ordered correctly, otherwise SIZE_MAX.
        template <typename T>
        SDLC_REQUIRED_RESULT std::size_t checkNormalOrdering(const N<T>* const root)
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            const N<T>* prev  = nullptr;
            bool        valid = true;
            std::size_t size  = 0;
            T::traverseInOrder(root, [&](const N<T>& nd) {
                if (prev != nullptr)
                {
                    valid = valid && (prev->getValue() < nd.getValue());
                }
                prev = &nd;
                size++;
            });

            return valid ? size : std::numeric_limits<std::size_t>::max();
        }

        template <typename T>
        std::size_t checkReverseOrdering(const N<T>* const root)
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            const N<T>* prev  = nullptr;
            bool        valid = true;
            std::size_t size  = 0;
            T::traverseInOrder(
                root,
                [&](const N<T>& nd) {
                    if (prev != nullptr)
                    {
                        valid = valid && (prev->getValue() > nd.getValue());
                    }
                    prev = &nd;
                    size++;

                    // Fake `return` to cover other `traverseInOrder` overload (the returning one).
                    return false;
                },
                true /* reverse */);

            return valid ? size : std::numeric_limits<std::size_t>::max();
        }

        template <typename T>
        SDLC_REQUIRED_RESULT std::size_t checkOrdering(const N<T>* const root)
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            const std::size_t ordered = checkNormalOrdering<T>(root);
            const std::size_t reverse = checkReverseOrdering<T>(root);
            return (ordered == reverse) ? ordered : std::numeric_limits<std::size_t>::max();
        }

        template <typename T>
        void checkPostOrdering(const N<T>* const root, const std::vector<std::uint16_t>& expected, const bool reverse = false)
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            std::vector<std::uint16_t> order;
            T::traversePostOrder(root, [&](const N<T>& nd) { order.push_back(nd.getValue()); }, reverse);
        //    TEST_ASSERT_EQUAL(expected.size(), order.size());
            if (!order.empty())
            {
         //       TEST_ASSERT_EQUAL_UINT16_ARRAY(expected.data(), order.data(), order.size());
            }
        }

        template <typename T>
        // NOLINTNEXTLINE(misc-no-recursion)
        SDLC_REQUIRED_RESULT const N<T>* findBrokenAncestry(const N<T>* const n, const N<T>* const parent = nullptr)
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if ((n != nullptr) && (n->getParentNode() == parent))
            {
                for (const bool v : {true, false})
                {
                    if (const N<T>* p = findBrokenAncestry<T>(n->getChildNode(v), n))
                    {
                        return p;
                    }
                }
                return nullptr;
            }
            return n;
        }

        template <typename T>
        SDLC_REQUIRED_RESULT const N<T>* findBrokenBalanceFactor(const N<T>* const n)  // NOLINT(misc-no-recursion)
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (n != nullptr)
            {
                if (std::abs(n->getBalanceFactor()) > 1)
                {
                    return n;
                }
                if (n->getBalanceFactor() != (getHeight<T>(n->getChildNode(true)) - getHeight<T>(n->getChildNode(false))))
                {
                    return n;
                }
                for (const bool v : {true, false})
                {
                    if (auto* const ch = n->getChildNode(v))
                    {
                        if (auto* const p = findBrokenBalanceFactor<T>(ch))
                        {
                            return p;
                        }
                    }
                }
            }
            return nullptr;
        }

        template <typename T>
        SDLC_REQUIRED_RESULT auto toGraphviz(const cavl::Tree<T>& tr) -> std::string
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            std::ostringstream ss;
            ss << "// Feed the following text to Graphviz, or use an online UI like https://edotor.net/\n"
               << "digraph {\n"
               << "node[style=filled,shape=circle,fontcolor=white,penwidth=0,fontname=\"monospace\",fixedsize=1,fontsize=18];\n"
               << "edge[arrowhead=none,penwidth=2];\n"
               << "nodesep=0.0;ranksep=0.3;splines=false;\n";
            tr.traverseInOrder([&](const typename cavl::Tree<T>::DerivedType& x) {
                const char* const fill_color =  // NOLINTNEXTLINE(*-avoid-nested-conditional-operator)
                    (x.getBalanceFactor() == 0) ? "black" : ((x.getBalanceFactor() > 0) ? "orange" : "blue");
                ss << x.getValue() << "[fillcolor=" << fill_color << "];";
            });
            ss << "\n";
            tr.traverseInOrder([&](const typename cavl::Tree<T>::DerivedType& x) {
                if (const auto* const ch = x.getChildNode(false))
                {
                    ss << x.getValue() << ":sw->" << ch->getValue() << ":n;";
                }
                if (const auto* const ch = x.getChildNode(true))
                {
                    ss << x.getValue() << ":se->" << ch->getValue() << ":n;";
                }
            });
            ss << "\n}";
            return ss.str();
        }

        auto getRandomByte()
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            return static_cast<std::uint8_t>((0xFFLL * std::rand()) / RAND_MAX);
        }
    protected:
        //com::github::doevelopper::atlas::utils::AdelsonVelskyLandisTree * m_targetUnderTest;
    private:
    };
}

#endif
