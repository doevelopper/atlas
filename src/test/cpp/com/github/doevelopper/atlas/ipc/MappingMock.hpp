
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_IPC_TEST_MAPPINGMOCK_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_IPC_TEST_MAPPINGMOCK_HPP

#include <com/github/doevelopper/atlas/ipc/IMapping.hpp>

#include <gmock/gmock.h>

namespace com::github::doevelopper::atlas::ipc::test
{
    template <typename T>
    class MappingMock : public IMapping<T>, public ::testing::Mock
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        MappingMock() noexcept;
        MappingMock(const MappingMock&) = default;
        MappingMock(MappingMock&&) = default;
        MappingMock& operator=(const MappingMock&) = default;
        MappingMock& operator=(MappingMock&&) = default;
        ~MappingMock() noexcept override;

        // Mock declarations for the pure virtual functions
        MOCK_METHOD(T*, data, (), (override));
        MOCK_METHOD(T const*, data, (), (const, override));
        MOCK_METHOD(size_t, len, (), (const, override));
    protected:
    private:
    };
}

#endif

// TEST(IMappingTest, ExampleTest) {
//     MockIMapping<int> mock;
//     EXPECT_CALL(mock, data())
//         .WillOnce(testing::Return(reinterpret_cast<int*>(0x1234)));
//     EXPECT_CALL(mock, data())
//         .WillOnce(testing::Return(reinterpret_cast<const int*>(0x5678)));
//     EXPECT_CALL(mock, len())
//         .WillOnce(testing::Return(10));
//
//     // Use mock in your test...
// }
