#pragma once

#include "common.h"

class Parser
{
public:
    void addCommandParser(CommandParserPtr commandParser);    
    const vector<CommandParserPtr>& getCommandParsers() const;

    CommandPtr process(const vector<string>& tokens);

private:
    vector<CommandParserPtr> m_commandParsers;
};
