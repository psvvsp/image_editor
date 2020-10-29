#pragma once

#include <memory>
#include <string>
#include <vector>

template<typename T>
using vector = std::vector<T>;

typedef std::string string;

class Command;
typedef std::shared_ptr<Command> CommandPtr;

class CommandParser;
typedef std::shared_ptr<CommandParser> CommandParserPtr;