#include <com/github/doevelopper/atlas/launcher/args/NamedOption.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;

log4cxx::LoggerPtr NamedOption::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.NamedOption"));

NamedOption::NamedOption() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
NamedOption::NamedOption(const boost::program_options::variables_map& variablesMap)
    : m_vm(variablesMap)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

NamedOption::~NamedOption() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void NamedOption::process()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_vm.count("file"))
    {
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " - File: " << this->m_vm["file"].as<std::string>() );
    }

    if (this->m_vm.count("verbose"))
    {
        LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ << " - Verbose Mode: Enabled");
    }
}