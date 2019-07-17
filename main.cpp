#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> availableTokens = {"print"};
std::vector<std::string> tokens = {};

std::vector<std::string> readQueueFile(std::string fileName)
{
    std::vector<std::string> fileContent;
    std::string line;
    std::ifstream myfile(fileName);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            fileContent.push_back(line);
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
    return fileContent;
}

void lexer(std::vector<std::string> fileContent)
{
    std::string token = "";
    int stringStarted = 0;
    int functionParametersStarted = 0;
    std::string stringValue = "";
    int statementEnded = 0;

    for (int i = 0; i < fileContent.size(); i++)
    {
        std::cout << "this is the line "
                  << i
                  << " content"
                  << "\n"
                  << fileContent.at(i)
                  << "\n";
        for (char &c : fileContent.at(i))
        {
            token += c;
            if (token == " ")
            {
                if (stringStarted == 1)
                {
                    token = " ";
                }
                else
                {
                    token = "";
                }
            }
            else if (token == "\n")
            {
                token = "";
            }
            else if (token == "print")
            {
                tokens.push_back("PRINT");
                token = "";
            }
            else if (token == "(")
            {
                functionParametersStarted = 1;
                token = "";
            }
            else if (token == ")")
            {
                functionParametersStarted = 0;
                token = "";
            }
            else if (token == "\"")
            {
                if (stringStarted == 1)
                {
                    tokens.push_back("STRING:" + stringValue + "\"");
                    stringStarted = 0;
                    token = "";
                }
                else
                {
                    stringStarted = 1;
                }
            }
            else if (stringStarted == 1)
            {
                stringValue += token;
                token = "";
            }
            else if (token == ";")
            {
                statementEnded = 1;
                token = "";
            }
        }
    }

    std::cout << "{";
    for (int i = 0; i < tokens.size(); i++)
    {
        std::cout << tokens.at(i) << ",";
    }
    std::cout << "}"
              << "\n";
}

void parser()
{
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens.at(i) + " " + tokens.at((i + 1)).substr(0, 4) == "PRINT STRING")
        {
            std::cout << "found print";
        }
        else
        {
            
        }
    }
}

int main()
{
    std::string fileName = "test.di";

    std::vector<std::string> fileContent = readQueueFile(fileName);

    lexer(fileContent);

    parser();

    return 0;
}
