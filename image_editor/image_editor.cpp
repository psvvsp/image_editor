//#include "opencv2/highgui.hpp"
//#include "opencv2/core.hpp"
//#include "opencv2/imgproc.hpp"
#include "lexer.h"

#include <iostream>
#include <string>

//using namespace cv;
using namespace std;

int main(int /*argc*/, char** /*argv*/)
{
    Lexer lexer;

    while (true) {
        
        cout << ">";
        
        string input;
        getline(cin, input);
        
        //cout << input << endl;

        vector<string> tokens;
        if (!lexer.process(input, tokens)) {
            cerr << "Error: " << lexer.getLastError() << endl;
            continue;
        }

        //for (const string& token : tokens)
        //	cout << token << endl;





	}

    return 0;
}

//int main() { return 0; }