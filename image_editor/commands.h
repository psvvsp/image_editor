#pragma once

#include "common.h"

class Executor;

class Command
{
public:
    virtual ~Command() {}
    virtual void execute(Executor& executor) = 0;
};

class LoadCommand : public Command
{
public:
    LoadCommand(const string& name,
                const string& filename)
        : m_name(name)
        , m_filename(filename)
    {}

    void execute(Executor& executor) override;

private:
    string m_name;
    string m_filename;
};

class StoreCommand : public Command
{
public:
    StoreCommand(const string& name,
                 const string& filename)
        : m_name(name)
        , m_filename(filename)
    {}

    void execute(Executor& executor) override;

private:
    string m_name;
    string m_filename;
};

class BlurCommand : public Command
{
public:
    BlurCommand(const string& fromName,
                const string& toName,
                int size)
        : m_fromName(fromName)
        , m_toName(toName)
        , m_size(size)
    {}

    void execute(Executor& executor) override;

private:
    string m_fromName;
    string m_toName;
    int m_size;
};

class ResizeCommand : public Command
{
public:
    ResizeCommand(const string& fromName,
                  const string& toName,
                  int newWidth,
                  int newHeight)
        : m_fromName(fromName)
        , m_toName(toName)
        , m_newWidth(newWidth)
        , m_newHeight(newHeight)
    {}

    void execute(Executor& executor) override;

private:
    string m_fromName;
    string m_toName;
    int m_newWidth;
    int m_newHeight;
};

class HelpCommand : public Command
{
public:
    void execute(Executor& executor) override;
};

class QuitCommand : public Command
{
public:
    void execute(Executor& executor) override;
};

