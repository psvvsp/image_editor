#include "executor.h"
#include "command_parser.h"
#include "exception.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

using namespace std;
using namespace cv;

void Executor::load(const string& name, const string& filename)
{
    cout << "load " << name << " " << filename << endl;

    throwIfImageInMemory(name);

    Mat image = imread(filename, IMREAD_UNCHANGED);

    if (image.empty()) {
        string error = "Failed to load image \"" + filename + "\"";
        throw ::Exception(error.c_str());
    }

    m_images[name] = make_unique<Mat>(image);
}

void Executor::store(const string& name, const string& filename)
{
    cout << "store " << name << " " << filename << endl;

    throwIfImageNotInMemory(name);

    bool success = imwrite(filename, *m_images[name]);
    if (!success) {
        string error = "Failed to store image to \"" + filename + "\"";
        throw ::Exception(error.c_str());
    }
}

void Executor::blur(const string& fromName, const string& toName, int size)
{
    cout << "blur " << fromName << " " << toName << " " << size << endl;

    throwIfImageNotInMemory(fromName);
    throwIfImageInMemory(toName);

    Mat dst = m_images[fromName]->clone();
    try {
        cv::blur(*m_images[fromName], dst, { size, size });
    }
    catch (...) {
        string error = "opencv failed to blur \"" + 
                       fromName +
                       "\" with given parameters";
        throw ::Exception(error.c_str());
    }
    m_images[toName] = make_unique<Mat>(dst);
}

void Executor::resize(const string& fromName, const string& toName,
    int newWidth, int newHeight)
{
    cout << "resize " << fromName << " " << toName << " "
        << newWidth << " " << newHeight << endl;

    throwIfImageNotInMemory(fromName);
    throwIfImageInMemory(toName);

    Mat dst;
    try {
        cv::resize(*m_images[fromName], dst, { newWidth, newHeight });
    }
    catch (...) {
        string error = "opencv failed to resize \"" +
            fromName +
            "\" with given parameters";
        throw ::Exception(error.c_str());
    }
    m_images[toName] = make_unique<Mat>(dst);
}

void Executor::help()
{
    cout << endl << "Supported commands:" << endl << endl;
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

void Executor::throwIfImageInMemory(const string& name) const
{
    if (m_images.count(name)) {
        string error = "Image \"" + name + "\" is already in memory";
        throw ::Exception(error.c_str());
    }
}

void Executor::throwIfImageNotInMemory(const string& name) const
{
    if (!m_images.count(name)) {
        string error = "Image \"" + name + "\" is not in memory";
        throw ::Exception(error.c_str());
    }
}
