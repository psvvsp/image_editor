#include "lexer.h"
#include "exception.h"

namespace
{
    void split(const string& input, char delimiter, vector<string>& output)
    {
        output.clear();

        string substr;
        for (char c : input) {
            if (c == delimiter) {
                output.push_back(substr);
                substr.clear();
                continue;
            }
            substr.append(1, c);
        }

        output.push_back(substr);
    }

}

void Lexer::process(const string& input, vector<string>& output)
{
    output.clear();

    vector<string> tmp;
    split(input, '"', tmp);
    
    if (tmp.size() % 2 == 0)
        throw Exception("Wrong usage of quotation marks");

    for (size_t i = 0; i < tmp.size(); i++) {
        
        const string& str = tmp[i];
        if (str.empty()) continue;
        
        if (i % 2)
            output.push_back(str);
        else {
            vector<string> splitted;
            split(str, ' ', splitted);
            for (const string& s : splitted)
                if (!s.empty()) 
                    output.push_back(s);
        }
    }
}
