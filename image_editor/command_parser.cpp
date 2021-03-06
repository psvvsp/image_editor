#include "command_parser.h"
#include "commands.h"
#include "exception.h"

#include <sstream>

namespace
{
    string createHelpLine(const string& comm, const string& desc)
    {
        return "  " + comm + "\n    - " + desc + '\n';
    }
}

string LoadCommandParser::helpString() const
{
    return createHelpLine(
        "load|ld <name> <file_name>",
        "uploads file to memory");
}

string StoreCommandParser::helpString() const
{
    return createHelpLine(
        "store|s <name> <file_name>",
        "saves file to disk");
}

string BlurCommandParser::helpString() const
{
    return createHelpLine(
        "blur <from_name> <to_name> <size>",
        "blurs image with factor \"size\"");
}

string ResizeCommandParser::helpString() const
{
    return createHelpLine(
        "resize <from_name> <to_name> <new_width> <new_height>",
        "resizes image");
}

string HelpCommandParser::helpString() const
{
    return createHelpLine(
        "help",
        "prints this message");
}

string QuitCommandParser::helpString() const
{
    return createHelpLine(
        "quit|exit|q",
        "exits");
}

namespace
{
    bool stoi(const string& s, int& i)
    {
        size_t idx;
        try {
            i = std::stoi(s, &idx);
        }
        catch (...) {
            return false;
        }

        return idx == s.length();
    }
}

CommandPtr LoadCommandParser::process(const vector<string>& tokens)
{
    CommandPtr command;

    if (tokens.empty())
        return command;

    if (tokens.front() != "load" &&
        tokens.front() != "ld")
        return command;

    if (tokens.size() != 3) {
        string error = tokens.front() + ": wrong number of arguments";
        throw Exception(error.c_str());
    }

    command.reset(new LoadCommand(tokens[1], tokens[2]));

    return command;
}

CommandPtr StoreCommandParser::process(const vector<string>& tokens)
{
    CommandPtr command;

    if (tokens.empty())
        return command;

    if (tokens.front() != "store" &&
        tokens.front() != "s")
        return command;

    if (tokens.size() != 3) {
        string error = tokens.front() + ": wrong number of arguments";
        throw Exception(error.c_str());
    }

    command.reset(new StoreCommand(tokens[1], tokens[2]));

    return command;
}

CommandPtr BlurCommandParser::process(const vector<string>& tokens)
{
    CommandPtr command;

    if (tokens.empty())
        return command;

    if (tokens.front() != "blur")
        return command;

    if (tokens.size() != 4) {
        string error = tokens.front() + ": wrong number of arguments";
        throw Exception(error.c_str());
    }

    int size;

    if (!::stoi(tokens[3], size)) {
        string error = tokens.front() + ": invalid argument " + tokens[3];
        throw Exception(error.c_str());
    }

    command.reset(new BlurCommand(tokens[1], tokens[2], size));

    return command;
}

CommandPtr ResizeCommandParser::process(const vector<string>& tokens)
{
    CommandPtr command;

    if (tokens.empty())
        return command;

    if (tokens.front() != "resize")
        return command;

    if (tokens.size() != 5) {
        string error = tokens.front() + ": wrong number of arguments";
        throw Exception(error.c_str());
    }

    int newWidth;

    if (!::stoi(tokens[3], newWidth)) {
        string error = tokens.front() + ": invalid argument " + tokens[3];
        throw Exception(error.c_str());
    }

    int newHeight;

    if (!::stoi(tokens[4], newHeight)) {
        string error = tokens.front() + ": invalid argument " + tokens[4];
        throw Exception(error.c_str());
    }

    command.reset(new ResizeCommand(
        tokens[1], tokens[2], newWidth, newHeight));

    return command;
}

CommandPtr HelpCommandParser::process(const vector<string>& tokens)
{
    CommandPtr command;

    if (tokens.empty())
        return command;

    if (tokens.front() != "help")
        return command;

    if (tokens.size() != 1) {
        string error = tokens.front() + ": wrong number of arguments";
        throw Exception(error.c_str());
    }

    command.reset(new HelpCommand());

    return command;
}

CommandPtr QuitCommandParser::process(const vector<string>& tokens)
{
    CommandPtr command;

    if (tokens.empty())
        return command;

    if (tokens.front() != "quit" &&
        tokens.front() != "exit" &&
        tokens.front() != "q")
        return command;

    if (tokens.size() != 1) {
        string error = tokens.front() + ": wrong number of arguments";
        throw Exception(error.c_str());
    }

    command.reset(new QuitCommand());

    return command;
}
