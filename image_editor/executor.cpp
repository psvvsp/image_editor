#include "executor.h"
#include "command_parser.h"
#include <iostream>
using namespace std;

void Executor::load(const string& name, const string& filename)
{
    cout << "load " << name << " " << filename << endl;

}

void Executor::store(const string& name, const string& filename)
{
    cout << "store " << name << " " << filename << endl;
}

void Executor::blur(const string& fromName, const string& toName, int size)
{
    cout << "blur " << fromName << " " << toName << " " << size << endl;

}

void Executor::resize(const string& fromName, const string& toName,
    int newWidth, int newHeight)
{
    cout << "resize " << fromName << " " << toName << " "
        << newWidth << newHeight << endl;

}

void Executor::help()
{
    cout << "Supported commands:" << endl;
    for (CommandParserPtr commandParser : m_commandParsers)
        cout << commandParser->helpString() << endl;
}

void Executor::quit()
{
    cout << "quit" << endl;
    exit(0);
}

void Executor::setCommandParsers(const std::vector<CommandParserPtr>& commandParsers)
{
    m_commandParsers.assign(commandParsers.begin(), commandParsers.end());
}
