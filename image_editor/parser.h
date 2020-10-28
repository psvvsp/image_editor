#pragma once

#include <memory>
#include <string>
#include <vector>

class Command;

class Parser
{
public:
    template<typename T>
    using vector = std::vector<T>;

    typedef std::string string;

    bool process(const vector<string>& tokens);
    string getLastError() const { return m_lastError; }

private:
    string m_lastError;
    vector<std::unique_ptr<Command>> m_commands;
};
