
#include <cstdint>
#include <string>
#include <iostream>

#include <com/github/doevelopper/atlas/errmgr/ErrorCodeBase.hpp>

using namespace com::github::doevelopper::atlas::errmgr;

log4cxx::LoggerPtr ErrorCodeBase::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.errmgr.ErrorCodeBase"));

ErrorCodeBase::ErrorCodeBase() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ErrorCodeBase::~ErrorCodeBase() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

const char* ErrorCodeBase::err2msg(std::uint32_t code)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // for (int i = 0; errorMap[i].errorDescription; ++i)
    //     if (errorMap[i].value == code)
    //         return errorMap[i].errorDescription;
    return "unknown";
}

std::string ErrorCodeBase::readErrorFileContents(const char* filename)
{
    // std::ifstream in(filename, std::ios::in | std::ios::binary); // filename, std::ifstream::in |
    // // std::ifstream::binary | std::ifstream::ate);
    // if (in)
    //     0{
    //         //// unsafe: The null termination character is not guaranteed.
    //         // std::string str((std::istreambuf_iterator<char>(in)),std::istreambuf_iterator<char>());
    //         // std::string str;
    //         // std::copy(std::istreambuf_iterator<char>(in),std::istreambuf_iterator<char>(),std::back_inserter(str));
    //         // std::size_t nBoffLines
    //         // std::count(std::istreambuf_iterator<char>(in),std::istreambuf_iterator<char>(), '\n');
    //         // std::cout << "[" << str << "]" << std::endl;
    //         // return(std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>()));
    //         // warning file not closed // in.close(); required
    //
    //         std::string dataInFile =
    //             std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    //         in.close();
    //         return (dataInFile);
    //     }

    // LOG4CXX_ERROR(....)
    // throw(errno);
}