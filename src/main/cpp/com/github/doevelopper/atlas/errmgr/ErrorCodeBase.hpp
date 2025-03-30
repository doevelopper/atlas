/*******************************************************************
 * @file
 * @version  v0.0.
 * @date     24/08/24 W 14:49
 * @brief    Common source of API return status codes and erros management.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * Copyright (C) 2024 ACME Technology Corp. All rights reserved.
********************************************************************/

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_ERRMGR_ERRORCODEBASE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_ERRMGR_ERRORCODEBASE_HPP

#include <iostream>
#include <unordered_map>
#include <mutex>
#include <string>
#include <stdexcept>

#include <com/github/doevelopper/atlas/logging/LoggingInitializer.hpp>

namespace com::github::doevelopper::atlas::errmgr
{
    static constexpr std::uint32_t OS_START_ERROR = static_cast<std::uint32_t>(20000LL);
    static constexpr std::uint32_t OS_ERRSPACE_SIZE = static_cast<std::uint32_t>(50000LL);
    static constexpr std::uint32_t UTIL_ERRSPACE_SIZE = static_cast<std::uint32_t>(20000LL);
    static constexpr std::uint32_t OS_START_STATUS = (OS_START_ERROR + OS_ERRSPACE_SIZE);
    static constexpr std::uint32_t UTIL_START_STATUS = (OS_START_STATUS + (OS_ERRSPACE_SIZE - UTIL_ERRSPACE_SIZE));
    static constexpr std::uint32_t OS_START_USERERR = (OS_START_STATUS + OS_ERRSPACE_SIZE);
    static constexpr std::uint32_t OS_START_CANONERR = (OS_START_USERERR + (OS_ERRSPACE_SIZE * 10));
    static constexpr std::uint32_t OS_START_EAIERR = (OS_START_CANONERR + OS_ERRSPACE_SIZE);
    static constexpr std::uint32_t OS_START_SYSERR = (OS_START_EAIERR + OS_ERRSPACE_SIZE);

    using HRESULT = std::uint32_t;
    using status_t = std::uint32_t;
    using cfs_status_t = std::int8_t;
    static constexpr HRESULT CFE_SUCCESS = static_cast<std::uint32_t>(0ULL);
    static constexpr HRESULT CFE_ERROR = (!CFE_SUCCESS);
    static constexpr HRESULT CFE_INVALIDE_ERROR = (0XFFFFFFFF);

/*!
 * @defgroup CFS_Severity_Status CFS Error severity.
 * Severity  Meaning
 *   00 Informational: This level is used to convey information to the user. No error has
 *          occurred. Informational messages are listed only when the FLAG (00) option is specified.
 *   10 Warning: This level indicates that an error was detected but is not serious enough to interfere
 *          with the running of the program.
 *   20 Error: This level indicates that an error was made, but the compiler is taking a recovery that might yield
 *        the desired code.
 *   30 Severe Error: This level indicates that a serious error was detected. Compilation is completed, but the
 *       module object is not created and running of the program cannot be attempted.
 *   40 Unrecoverable: This level usually indicates a user error that forces termination of processing.
 *   50 Unrecoverable: This level usually indicates a compiler error that forces termination of processing.
 *   99 Action: Some manual action is required, such as entering a reply, changing settigs, or replacing sensors...
 * @{
 */

    enum class edacSeverity : std::uint32_t
    {
        CFE_SEVERITY_BITMASK = (0xC0000000L),
        CFE_SEVERITY_SUCCESS = (0x00000000L),
        CFE_SEVERITY_NOTICE = 5, /*!< An unusual event has occured, though not an error condition. This
                                    should be investigated for the root cause.*/
        CFE_SEVERITY_DEBUG = 7, /*!< Useful non-operational messages that can assist in debugging. These
                                   should not occur during normal operation.*/
        CFE_SEVERITY_INFO = (0x40000000L), /*!< Normal operational messages. Useful for logging. No action
                                              is required for these messages.*/
        CFE_SEVERITY_WARNING = 4, /*!< Indicates about a possible future error if this is not resolved
                                     within a given timeframe. Example would be a low battery warning.*/
        CFE_SEVERITY_ERROR = (0xc0000000L), /*!< Indicates an error in secondary/redundant systems.*/
        CFE_SEVERITY_ALERT = 1, /*!< Action should be taken immediately. Indicates error in non-critical
                                   systems.*/
        CFE_SEVERITY_CRITICAL = 2, /*!< Action must be taken immediately. Indicates failure in a primary
                                      system.*/
        CFS_SEVERITY_EMERGENCY = 0, /*!< System is unusable. This is a "panic" condition.*/
        CFE_SEVERITY_NONE,    /*!< No logging will occur*/
        CFE_SEVERITY_ENUM_END = 8
    };
/*!
 * @}
 */

    enum class edacServiceId : std::uint32_t
    {
        CFE_SERVICE_BITMASK = (0x0e000000L),
        CFE_EVENTS_SERVICE = (0x02000000L),
        CFE_EXECUTIVE_SERVICE = (0x04000000L),
        CFE_FILE_SERVICE = (0x06000000L),
        CFE_OSAPI_SERVICE = (0x08000000L),
        CFE_SOFTWARE_BUS_SERVICE = (0x0a000000L),
        CFE_TABLE_SERVICE = (0x0c000000L),
        CFE_TIME_SERVICE = (0x0e000000L)
    };

/*!
 * @brief Error Code type enum class used to throw a exception with std::make_error_code in case of
 * generic user error .
 *
 */
    enum class CfeUserError : std::uint32_t
    {
        STATUS_ERR_NULL_POINTER, ///<  Indicates that a null pointer is detected.
        STATUS_ERR_BAD_PARAMETER, ///<  Indicates that a wrong parameter has been used in a function call.
        STATUS_ERR_INVALID_INDEX, ///<  Indicates that an invalid index is detected.
        STATUS_ERR_MEM_ALLOC_FAILED, ///<  Indicates that a memory allocation failed.
        STATUS_ERR_INVALID_HANDLE, ///<  Indicates that an invalid handle is detected.
        STATUS_ERR_INVALID_THREAD, ///<  Indicates that an invalid thread is detected.
        STATUS_ERR_INVALID_SEM, ///<  Indicates that an invalid semaphore is detected.
        STATUS_ERR_INVALID_MSGQ, ///<  Indicates that an invalid message queue is detected.
        STATUS_ERR_UNKNOWN,    ///<  Indicates that an unknown error is detected.
    };

    enum
    class CfeBoardDiagStatus : std::uint32_t
    {
        STATUS_NOT_DETECTED, ///<  The board is not detected.
        STATUS_BAD_CONF,  ///<  There is an error in the configuration.
        STATUS_NOT_CONFIGURED, ///<  The board is not configured.
        STATUS_BAD_VOLTAGE, ///<  Voltage issue on the board.
        STATUS_FAILURE_DETECTED ///<  General error on the board.
    };

    enum
    class edacAppErrc : std::uint32_t
    {
        CFG_ERROR_UPG,
        VOL_LOW_ERROR,
        SERIAL_N_ERROR,
        IMU_ERROR,
        COMPASS_ERROR,
        GPS_NOT_CALIBRATED_ERROR,
        CALIBRATION_ERROR,
        IMU_INITIALIZATION_ERROR
    };

    // clang-format off
    // struct
    // {
    //     static constexpr std::uint32_t value;
    //     static constexpr char* errorDescription;
    // } errorMap[] =
    // {
    //     {ERR_OK, "OK"},
    //     {ERR_OUT_OF_MEMORY, "ERR_OUT_OF_MEMORY"},
    //     {0, 0}
    // };

    // clang-format on

    class ErrorCodeBase
    {
        Q_DISABLE_COPY_MOVE(ErrorCodeBase)
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        // Singleton instance accessor (thread-safe Meyers' singleton)
        static ErrorCodeBase& Instance()
        {
            static ErrorCodeBase instance;
            return instance;
        }

        ErrorCodeBase() noexcept;
        virtual ~ErrorCodeBase() noexcept;
        std::string readErrorFileContents(const char* filename);

        // Add a new error code (prevents duplicates)
        void registerCode(int code, const std::string& description)
        {
            std::lock_guard<std::mutex> lock(this->m_mutex);
            if (this->m_codes.find(code) != this->m_codes.end())
            {
                throw std::invalid_argument("Error code " + std::to_string(code) + " already exists");
            }
            this->m_codes[code] = description;
        }

        // Retrieve error description (thread-safe)
        std::string what(int code) const
        {
            std::lock_guard<std::mutex> lock(this->m_mutex);
            auto it = this->m_codes.find(code);
            return it != this->m_codes.end() ? it->second : "Unknown error";
        }

    protected:
    private:
        const char* err2msg(std::uint32_t code);
        // Thread-safe container for error codes
        mutable std::mutex m_mutex;
        std::unordered_map<int, std::string> m_codes;
    };
}
/*
int main() {
    try {
        // Register error codes
        ErrorCode::Instance().registerCode(100, "File not found");
        ErrorCode::Instance().registerCode(200, "Permission denied");

        // Attempting duplicate registration would throw exception
        // ErrorCode::Instance().registerCode(100, "Duplicate entry");

        // Query descriptions
        std::cout << "Error 100: " << ErrorCode::Instance().what(100) << std::endl;
        std::cout << "Error 200: " << ErrorCode::Instance().what(200) << std::endl;
        std::cout << "Error 300: " << ErrorCode::Instance().what(300) << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
 */
#endif
