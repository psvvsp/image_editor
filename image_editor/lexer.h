#pragma once

#include <string>
#include <vector>

class Lexer
{
public:
    template<typename T>
    using vector = std::vector<T>;

    typedef std::string string;

    bool process(const string &input, vector<string> &output);
    const string &getLastError() const { return m_lastError; }

private:
    string m_lastError;

};
