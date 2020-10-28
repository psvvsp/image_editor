#pragma once

#include <string>
#include <vector>

class Command
{
public:
    template<typename T>
    using vector = std::vector<T>;

    typedef std::string string;

    enum class ReturnCode
    {
        MATCH,
        MISMATCH,
        ERROR
    };

    virtual ~Command() {}

    virtual ReturnCode parse(const vector<string>& tokens) = 0;
    
    const string &getLastError() const { return m_lastError; }

protected:
    string m_lastError;
};

class LoadCommand : public Command
{
public:
    ReturnCode parse(const vector<string>& tokens) override;

    const string& getName() const { return m_name; }
    const string& getFilename() const { return m_filename; }

private:
    string m_name;
    string m_filename;
};

class StoreCommand : public Command
{
public:
    ReturnCode parse(const vector<string>& tokens) override;

    const string& getName() const { return m_name; }
    const string& getFilename() const { return m_filename; }

private:
    string m_name;
    string m_filename;
};

class BlurCommand : public Command
{
public:
    ReturnCode parse(const vector<string>& tokens) override;

    const string& getFromName() const { return m_fromName; }
    const string& getToName() const { return m_toName; }
    int getSize() const { return m_size; }

private:
    string m_fromName;
    string m_toName;
    int m_size;
};

class ResizeCommand : public Command
{
public:
    ReturnCode parse(const vector<string>& tokens) override;

    const string& getFromName() const { return m_fromName; }
    const string& getToName() const { return m_toName; }
    int getNewWidth() const { return m_newWidth; }
    int getNewHeight() const { return m_newHeight; }

private:
    string m_fromName;
    string m_toName;
    int m_newWidth;
    int m_newHeight;
};

class HelpCommand : public Command
{
public:
    ReturnCode parse(const vector<string>& tokens) override;
};

class QuitCommand : public Command
{
public:
    ReturnCode parse(const vector<string>& tokens) override;
};

