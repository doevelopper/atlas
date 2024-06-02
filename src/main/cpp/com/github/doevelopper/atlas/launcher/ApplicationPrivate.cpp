
#include <com/github/doevelopper/atlas/launcher/ApplicationPrivate.hpp>

#include <com/github/doevelopper/atlas/launcher/Application.hpp>

using namespace com::github::doevelopper::atlas::launcher;
using namespace com::github::doevelopper::atlas::semver;

log4cxx::LoggerPtr ApplicationPrivate::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.ApplicationPrivate"));


ApplicationPrivate::ApplicationPrivate() noexcept
    // : d_ptr(std::make_unique<ApplicationPrivate>()) //: Application(0, nullptr) {}
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // Q_D(Application);
}

ApplicationPrivate::~ApplicationPrivate() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // Q_D ( Application );
}