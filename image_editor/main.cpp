//#include "opencv2/highgui.hpp"
//#include "opencv2/core.hpp"
//#include "opencv2/imgproc.hpp"
#include "command_parser.h"
#include "commands.h"
#include "exception.h"
#include "executor.h"
#include "lexer.h"
#include "parser.h"

#include <iostream>

//using namespace cv;
using namespace std;

int main(int /*argc*/, char** /*argv*/)
{
    Lexer lexer;

    Parser parser;
    parser.addCommandParser(make_shared<LoadCommandParser>());
    parser.addCommandParser(make_shared<StoreCommandParser>());
    parser.addCommandParser(make_shared<BlurCommandParser>());
    parser.addCommandParser(make_shared<ResizeCommandParser>());
    parser.addCommandParser(make_shared<HelpCommandParser>());
    parser.addCommandParser(make_shared<QuitCommandParser>());

    Executor executor;
    executor.setCommandParsers(parser.getCommandParsers());

    while (true) {
        
        cout << ">";
        
        string input;
        getline(cin, input);

        try {
            std::vector<string> tokens;
            lexer.process(input, tokens);

            if (CommandPtr command = parser.process(tokens))
                command->execute(executor);
        }
        catch (const Exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
	}

    return 0;
}