#pragma once

#include "common.h"

class CommandParser
{
public:
    virtual ~CommandParser() {}
    virtual string helpString() const = 0;
    virtual CommandPtr process(const vector<string>& tokens) = 0;
};

class LoadCommandParser : public CommandParser
{
    string helpString() const override;
    CommandPtr process(const vector<string>& tokens) override;
};

class StoreCommandParser : public CommandParser
{
    string helpString() const override;
    CommandPtr process(const vector<string>& tokens) override;
};

class BlurCommandParser : public CommandParser
{
    string helpString() const override;
    CommandPtr process(const vector<string>& tokens) override;
};

class ResizeCommandParser : public CommandParser
{
    string helpString() const override;
    CommandPtr process(const vector<string>& tokens) override;
};

class HelpCommandParser : public CommandParser
{
    string helpString() const override;
    CommandPtr process(const vector<string>& tokens) override;
};

class QuitCommandParser : public CommandParser
{
    string helpString() const override;
    CommandPtr process(const vector<string>& tokens) override;
};




