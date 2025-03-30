#include <com/github/doevelopper/atlas/launcher/args/CommandLineParser.hpp>

using namespace com::github::doevelopper::atlas::launcher::args;

log4cxx::LoggerPtr CommandLineParser::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.atlas.launcher.args.CommandLineParser"));

CommandLineParser::CommandLineParser() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // Define named arguments
    desc.add_options()
        ("help,h", "Show help message")
        ("file,f", boost::program_options::value<std::string>(), "Input file path")
        ("verbose,v", "Enable verbose mode")
        ("threads,t", boost::program_options::value<int>()->default_value(1), "Number of threads")
        ("include,i", boost::program_options::value<std::vector<std::string>>(), "Include paths");

    // Define positional arguments
    positionalDesc.add("file", 1); // "file" is a positional argument
}

CommandLineParser::~CommandLineParser() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void CommandLineParser::parse(int argc, /*const*/ char* argv[])
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    try
    {
        boost::program_options::store(boost::program_options::command_line_parser(argc, argv)
                      .options(desc)
                      .positional(positionalDesc)
                      .run(),
                  vm);
        boost::program_options::notify(vm);

        if (vm.count("help"))
        {
            LOG4CXX_INFO(logger, __LOG4CXX_FUNC__ << " " << desc  );
            return;
        }
    }
    catch (const std::exception& e)
    {
        LOG4CXX_ERROR(logger, __LOG4CXX_FUNC__ << " " << "Error: " << e.what()  << " " << desc );
    }
}

std::vector<std::string> CommandLineParser::getPositionalArguments() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::vector<std::string> positionalArgs;
    if (vm.count("file"))
    {
        positionalArgs.push_back(vm["file"].as<std::string>());
    }
    return positionalArgs;
}

boost::program_options::variables_map CommandLineParser::getVariablesMap() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return vm;
}