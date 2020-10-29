#pragma once

#include "common.h"

class Executor
{
public:
    void load(const string& name, const string& filename);
    void store(const string& name, const string& filename);
    void blur(const string& fromName, const string& toName, int size);
    void resize(const string& fromName, const string& toName,
        int newWidth, int newHeight);
    void help();
    void quit();

    void setCommandParsers(const vector<CommandParserPtr>& commandParsers);

private:
    vector<CommandParserPtr> m_commandParsers;
};