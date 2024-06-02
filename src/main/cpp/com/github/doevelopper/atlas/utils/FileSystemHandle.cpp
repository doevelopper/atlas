
#include <filesystem>
#include <fstream>

#include <com/github/doevelopper/atlas/utils/FileSystemHandle.hpp>

using namespace com::github::doevelopper::atlas::utils;

log4cxx::LoggerPtr FileSystemHandle::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.utils.FileSystemHandle"));

FileSystemHandle::FileSystemHandle() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

FileSystemHandle::~FileSystemHandle() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

auto FileSystemHandle::createDirectory(std::string path) -> bool
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    try
    {
        if(path.back() == '/' || path.back() == '\\')
        {
            path.pop_back(); // else std::filesystem will return false because it cannot create an unnamed
            // subdirectory
        }

        auto fspath = std::filesystem::path{path};

        if(std::filesystem::exists(fspath))
        {
            if(std::filesystem::is_directory(fspath))
            {
                return true;
            }

            LOG4CXX_ERROR(logger, path << " exists but is not a directory.");
        }
        return std::filesystem::create_directories(fspath);
    }
    catch(const std::filesystem::filesystem_error& err)
    {
        LOG4CXX_ERROR(logger, path << " could not be created: " << err.what());
        return false;
    }

}

auto FileSystemHandle::createEmptyFile(const std::string & path) -> bool
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    try
    {
        auto fs_path = std::filesystem::path{path};
        if(std::filesystem::exists(fs_path))
        {
            if(std::filesystem::is_directory(fs_path))
            {
                LOG4CXX_ERROR(logger, path << " exists but is a directory.");
            }
            return true;
        }
        auto ofs = std::ofstream(path);
        return ofs.good();
    }
    catch(const std::filesystem::filesystem_error& err)
    {
        LOG4CXX_ERROR(logger, path << " could not be created: " << err.what());
        return false;
    }

}

auto FileSystemHandle::setFilePermissionsWriteAll(const std::string & path) -> bool
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    try
    {
        auto fs_path = std::filesystem::path{path};
        if(std::filesystem::exists(fs_path))
        {
            std::filesystem::permissions(fs_path,
                    std::filesystem::perms::owner_write | std::filesystem::perms::group_write
                            | std::filesystem::perms::others_write,
                    std::filesystem::perm_options::add);
            return true;
        }

        LOG4CXX_ERROR(logger, path << " does not exist.");
        return false;
    }
    catch(const std::filesystem::filesystem_error& err)
    {
        LOG4CXX_ERROR(logger, path << " could not be modified: " << err.what());
        return false;
    }

}

auto FileSystemHandle::setFilePermissionsAllAll(const std::string & path) -> bool
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    try
    {
        auto fs_path = std::filesystem::path{path};
        if(std::filesystem::exists(fs_path))
        {
            std::filesystem::permissions(
                    fs_path, std::filesystem::perms::all, std::filesystem::perm_options::add);
            return true;
        }

        LOG4CXX_ERROR(logger, path << " does not exist.");
        return false;
    }
    catch(const std::filesystem::filesystem_error& err)
    {
        LOG4CXX_ERROR(logger, path <<  " could not be modified: " << err.what());
        return false;
    }

}
