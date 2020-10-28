#include "commands.h"

Command::ReturnCode LoadCommand::parse(const vector<string>& tokens)
{
    m_lastError.clear();

    if (tokens.empty())
        return ReturnCode::MISMATCH;

    if (tokens.front() != "load" &&
        tokens.front() != "ld")
        return ReturnCode::MISMATCH;

    if (tokens.size() != 3) {
        m_lastError = "LoadCommand: wrong number of arguments";
        return ReturnCode::ERROR;
    }

    m_name = tokens[1];
    m_filename = tokens[2];

    return ReturnCode::MATCH;
}

Command::ReturnCode StoreCommand::parse(const vector<string>& tokens)
{
    m_lastError.clear();

    if (tokens.empty())
        return ReturnCode::MISMATCH;

    if (tokens.front() != "store" &&
        tokens.front() != "s")
        return ReturnCode::MISMATCH;

    if (tokens.size() != 3) {
        m_lastError = "StoreCommand: wrong number of arguments";
        return ReturnCode::ERROR;
    }

    m_name = tokens[1];
    m_filename = tokens[2];

    return ReturnCode::MATCH;
}

Command::ReturnCode BlurCommand::parse(const vector<string>& tokens)
{
    m_lastError.clear();

    if (tokens.empty())
        return ReturnCode::MISMATCH;

    if (tokens.front() != "blur")
        return ReturnCode::MISMATCH;

    if (tokens.size() != 4) {
        m_lastError = "BlurCommand: wrong number of arguments";
        return ReturnCode::ERROR;
    }

    m_fromName = tokens[1];
    m_toName = tokens[2];

    size_t idx = 0;
    m_size = stoi(tokens[3], &idx);

    if (idx != tokens[3].size()) {
        m_lastError = "BlurCommand: invalid argument " + tokens[3];
        return ReturnCode::ERROR;
    }

    return ReturnCode::MATCH;
}

Command::ReturnCode ResizeCommand::parse(const vector<string>& tokens)
{
    m_lastError.clear();

    if (tokens.empty())
        return ReturnCode::MISMATCH;

    if (tokens.front() != "resize")
        return ReturnCode::MISMATCH;

    if (tokens.size() != 5) {
        m_lastError = "ResizeCommand: wrong number of arguments";
        return ReturnCode::ERROR;
    }

    m_fromName = tokens[1];
    m_toName = tokens[2];

    size_t idx = 0;
    m_newWidth = stoi(tokens[3], &idx);

    if (idx != tokens[3].size()) {
        m_lastError = "ResizeCommand: invalid argument " + tokens[3];
        return ReturnCode::ERROR;
    }

    m_newHeight = stoi(tokens[4], &idx);

    if (idx != tokens[4].size()) {
        m_lastError = "ResizeCommand: invalid argument " + tokens[4];
        return ReturnCode::ERROR;
    }

    return ReturnCode::MATCH;
}

Command::ReturnCode HelpCommand::parse(const vector<string>& tokens)
{
    m_lastError.clear();

    if (tokens.empty())
        return ReturnCode::MISMATCH;

    if (tokens.front() != "help")
        return ReturnCode::MISMATCH;

    if (tokens.size() != 1) {
        m_lastError = "HelpCommand: wrong number of arguments";
        return ReturnCode::ERROR;
    }

    return ReturnCode::MATCH;
}

Command::ReturnCode QuitCommand::parse(const vector<string>& tokens)
{
    m_lastError.clear();

    if (tokens.empty())
        return ReturnCode::MISMATCH;

    if (tokens.front() != "quit" &&
        tokens.front() != "exit" &&
        tokens.front() != "q")
        return ReturnCode::MISMATCH;

    if (tokens.size() != 1) {
        m_lastError = "QuitCommand: wrong number of arguments";
        return ReturnCode::ERROR;
    }

    return ReturnCode::MATCH;
}
