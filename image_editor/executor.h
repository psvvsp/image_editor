#pragma once

#include "common.h"

#include <opencv2/core.hpp>

#include <memory>
#include <unordered_map>

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
    void throwIfImageInMemory(const string& name) const;
    void throwIfImageNotInMemory(const string& name) const;

    vector<CommandParserPtr> m_commandParsers;
    std::unordered_map<string, std::unique_ptr<cv::Mat>> m_images;
};