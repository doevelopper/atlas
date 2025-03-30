
#include <fstream>

#include <boost/program_options/parsers.hpp>

#include <com/github/doevelopper/atlas/launcher/args/ProgramOption.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;

log4cxx::LoggerPtr ProgramOption::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.ProgramOption"));

ProgramOption::ProgramOption() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ProgramOption::~ProgramOption() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

/*
void ProgramOption::parseArguments(
    boost::program_options::options_description const & description, int argc, char const * argv[])
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::vector<std::string> args {argv + 1, argv + std::max(argc, 1)};
    auto parsed_command_line =
        boost::program_options::command_line_parser(args).options(description).allow_unregistered().run();
    boost::program_options::store(parsed_command_line, this->m_options);
    boost::program_options::notify(this->m_options);
    this->m_unparsed_tokens = boost::program_options::collect_unrecognized(
        parsed_command_line.options, boost::program_options::include_positional);
}

void ProgramOption::parseEnvironment(
    boost::program_options::options_description const & description, char const * prefix)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto parsed_options =
        boost::program_options::parse_environment(description, [=](std::string const & from) -> std::string {
            auto const sizeof_prefix = strlen(prefix);

            if (from.length() < sizeof_prefix || 0 != from.find(prefix))
                return {}; // std::string();

            std::string result(from, sizeof_prefix);

            for (auto & ch : result)
            {
                if (ch == '_')
                    ch = '-';
                else
                    ch = std::tolower(ch, std::locale::classic()); // avoid current locale
            }

            return result;
        });

    boost::program_options::store(parsed_options, this->m_options);
}

void ProgramOption::parseFile(
    boost::program_options::options_description const & config_file_desc, std::string const & filename)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::string config_roots;

    if (auto config_home = getenv("XDG_CONFIG_HOME"))
        (config_roots = config_home) += ":";
    else if (auto home = getenv("HOME"))
        (config_roots = home) += "/.config:";

    if (auto config_dirs = getenv("XDG_CONFIG_DIRS"))
        config_roots += config_dirs;
    else
        config_roots += "/etc/xdg";

    LOG4CXX_DEBUG(logger, config_roots);

    std::istringstream config_stream(config_roots);

    // Read options from config files
    for (std::string config_root; getline(config_stream, config_root, ':');)
    {
        auto const & afile = config_root + "/" + filename;

        try
        {
            std::ifstream file(afile);
            boost::program_options::store(
                boost::program_options::parse_config_file(file, config_file_desc, true), this->m_options);
        }
        catch (const boost::program_options::error & error)
        {
            LOG4CXX_WARN(logger, __LOG4CXX_FUNC__ << "Error in " << filename.c_str() << " " << error.what());
        }
    }

    boost::program_options::notify(this->m_options);
}

bool ProgramOption::is_set(const char * name) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return AbstractOption::is_set(name);
    return this->m_options.count(parseName(name));
}

bool ProgramOption::get(const char * name, bool adefault) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return AbstractOption::get(name, default);
    auto const parsed_name = parseName(name);
    if (this->m_options.count(parsed_name))
    {
        return this->m_options[parsed_name].as<bool>();
    }

    return adefault;
}

std::string ProgramOption::get(const char * name, const char * adefault) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return AbstractOption::get(name, adefault);
    auto const parsed_name = parseName(name);
    if (this->m_options.count(parsed_name))
    {
        return this->m_options[parsed_name].as<std::string>();
    }

    return adefault;
}

int ProgramOption::get(const char * name, int adefault) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return AbstractOption::get(name, adefault);
    auto const parsed_name = parseName(name);
    if (this->m_options.count(parsed_name))
    {
        return this->m_options[parsed_name].as<int>();
    }

    return adefault;
}

const boost::any & ProgramOption::get(const char * name) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // return AbstractOption::get(name);
    auto const parsed_name = parseName(name);
    if (this->m_options.count(parsed_name))
    {
        return this->m_options[parsed_name].value();
    }
    static boost::any const adefault;
    return adefault;
}

const std::vector<std::string> & ProgramOption::unparsedTokens() const
{
    return this->m_unparsed_tokens;
}

void ProgramOption::unparsedTokens(const std::vector<std::string> & unparsed_tokens)
{
    this->m_unparsed_tokens = unparsed_tokens;
}
*/