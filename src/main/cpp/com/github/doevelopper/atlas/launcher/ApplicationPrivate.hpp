//
// Created by hroland on 26/05/24.
//

#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_APPLICATIONPRIVATE_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LAUNCHER_APPLICATIONPRIVATE_HPP

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/algorithm/string.hpp>

#include <typeindex>

#include <com/github/doevelopper/atlas/logging/CustomLogger.hpp>

namespace com::github::doevelopper::atlas::launcher
{
    class ApplicationPrivate
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        ApplicationPrivate() noexcept;
        ApplicationPrivate(const ApplicationPrivate &) noexcept             = default;
        ApplicationPrivate(ApplicationPrivate &&) noexcept                  = default;
        ApplicationPrivate & operator=(const ApplicationPrivate &) noexcept = default;
        ApplicationPrivate & operator=(ApplicationPrivate &&) noexcept      = default;
        virtual ~ApplicationPrivate() noexcept;

        ApplicationPrivate([[maybe_unused]] int argc, [[maybe_unused]] char ** argv) noexcept;
        boost::filesystem::path data{"data"};
        boost::filesystem::path config{"config"};
        boost::filesystem::path loggerConfigurator{"log4cxx.xml"};
        boost::filesystem::path staticFileConfigurator;

        std::uint64_t version;
        std::string versionString;

        std::atomic_bool isQuitting{false};

        using anyTypeCompareMap = std::unordered_map<std::type_index, std::function<bool(const std::any& a, const std::any& b)>>;
        anyTypeCompareMap anyCompare;

    protected:
    private:
        std::string getFileExtension ( const std::string & s );
        void loggerConfigure ( std::string const & filename );
    };
}

#endif
