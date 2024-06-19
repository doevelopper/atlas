#include <com/github/doevelopper/atlas/launcher/args/AbstractOption.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;

log4cxx::LoggerPtr AbstractOption::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.AbstractOption"));


AbstractOption::AbstractOption() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

AbstractOption::~AbstractOption() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool AbstractOption::is_set(const char * name) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool AbstractOption::get(const char * name, bool default_) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

std::string AbstractOption::get(const char * name, const char * default_) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

int AbstractOption::get(const char * name, int default_) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

const boost::any & AbstractOption::get(const char * name) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template<typename Type>
Type AbstractOption::get(char const* name) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return boost::any_cast<Type>(this->get(name));
}