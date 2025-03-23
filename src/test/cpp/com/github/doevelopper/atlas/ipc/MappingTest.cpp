// Test case using the fixture with type 'int'
TEST_F(MockIMappingTestFixture<int>, Test_Data_ReturnsExpectedValue) {
    // Override expectations if needed for this specific test
    // Example: Override the default 'data()' behavior
    EXPECT_CALL(mock_, data())
        .WillOnce(testing::Return(reinterpret_cast<int*>(0x300)));

    // Use the mock in your test
    int* result = mock_.data();
    EXPECT_EQ(reinterpret_cast<int*>(0x300), result);
}

TEST_F(MockIMappingTestFixture<int>, Test_Len_ReturnsExpectedLength) {
    // Use the default 'len()' expectation set in SetUp
    size_t length = mock_.len();
    EXPECT_EQ(5, length);
}