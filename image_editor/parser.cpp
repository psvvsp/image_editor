#include "parser.h"
#include "command_parser.h"
#include "exception.h"

void Parser::addCommandParser(CommandParserPtr commandParser)
{
    m_commandParsers.push_back(commandParser);
}

const vector<CommandParserPtr>& Parser::getCommandParsers() const
{
    return m_commandParsers;
}

CommandPtr Parser::process(const vector<string>& tokens)
{
    if (tokens.empty())
        return CommandPtr();

    for (CommandParserPtr commandParser : m_commandParsers) {
        if (CommandPtr command = commandParser->process(tokens))
            return command;
    }

    throw Exception(("Unknown command: " + tokens[0]).c_str());
}
