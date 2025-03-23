#include <gtest/gtest.h>
#include "MockIMapping.h"  // Ensure your mock is included here

template <typename T>
class MockIMappingTestFixture : public ::testing::Test {
protected:
    MockIMappingTestFixture() = default;
    ~MockIMappingTestFixture() override = default;

    void SetUp() override {
        // Initialize mock and set common expectations here
        // Example: Set default behavior for mock methods
        EXPECT_CALL(mock_, data())
            .WillRepeatedly(testing::Return(reinterpret_cast<T*>(0x100)));
        EXPECT_CALL(mock_, data())
            .WillRepeatedly(testing::Return(reinterpret_cast<const T*>(0x200)));
        EXPECT_CALL(mock_, len())
            .WillRepeatedly(testing::Return(5));
    }

    void TearDown() override {
        // Cleanup resources here if needed
        // (e.g., free memory, close files, etc.)
    }

    MockIMapping<T> mock_;
};