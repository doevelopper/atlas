/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     22/12/24 W 21:01
 * @brief    
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/


#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_ADELSONVELSKYLANDISNODETEST_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_UTILS_ADELSONVELSKYLANDISNODETEST_HPP

#include <gtest/gtest.h>
#include <com/github/doevelopper/atlas/utils/AdelsonVelskyLandisNode.hpp>

namespace com::github::doevelopper::atlas::utils::test
{
/*
    class My : public AdelsonVelskyLandisNode<My>
    {
    public:
        using Self = AdelsonVelskyLandisNode<My>;
        My() = default;
        explicit My(const std::uint16_t v)
        : m_value(v)
        {

        }

        SDLC_REQUIRED_RESULT auto getValue() const -> std::uint16_t
        {
            return m_value;
        }
    protected:
    private:
        std::uint16_t m_value = 0;
    };
//*/
    // A simple derived class representing a key-value pair
    class KeyValueNode : public AdelsonVelskyLandisNode<KeyValueNode> {
    public:
        int key;
        std::string value;

        KeyValueNode(int k, std::string v) : key(k), value(std::move(v))
        {

        }

        // Comparator for searching
        static int compare(const KeyValueNode& node, int search_key)
        {
            return (search_key > node.key) ? 1 : (search_key < node.key) ? -1 : 0;
        }
    };

    class AdelsonVelskyLandisNodeTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
        Q_DISABLE_COPY_MOVE(AdelsonVelskyLandisNodeTest)
    public:
        AdelsonVelskyLandisNodeTest() noexcept;
        ~AdelsonVelskyLandisNodeTest() noexcept override;

        void SetUp() override;
        void TearDown() override;
        // Helper function to clear the tree
        void clearTree(KeyValueNode* node);
    protected:
        //com::github::doevelopper::atlas::utils::AdelsonVelskyLandisNode * m_targetUnderTest;
        KeyValueNode * m_targetUnderTest;
    private:
    };
}

#endif
