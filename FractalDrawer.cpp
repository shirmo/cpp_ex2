#include <iostream>
#include <string>
#include "Fractal.h"
#include <boost/filesystem.hpp>
#include <boost/tokenizer.hpp>

namespace fs = boost::filesystem;
typedef boost::tokenizer< boost::char_separator<char> > Tokenizer;

#define FILE_AMOUNT 2
#define FILE_POSITION 1
#define DOT '.'
#define VALID_EXTENSION "csv"
#define USAGE "Usage: FractalDrawer <file path>"
#define INVALID_INPUT_MSG "Invalid input"

#define LOWER_BOUND 0
#define UPPER_BOUND 6
#define CARPET 1
#define TRIANGLE 2
#define VICSEK 3
#define EMPTY 0

/**
 * c'tor
 * @param argc amount of arguments
 * @param argv arguments array
 * @param fractal a list to be populated
 */
Parser::Parser(int argc, char *argv[], std::vector<Fractal *> &fractal) : fractal(fractal)
{
    argsValidity(argc, argv);
    doesFileExist(argv[1]);
    std::string path = argv[1];
    fractal = parseFile(path, fractal);
    for (int i = (int) fractal.size()-1 ; i >= 0; --i)
    {
        fractal[i]->printFractal();
        delete fractal[i];
    }
    fractal.clear();
}

/**
 * Prints an error message and exits the program
 */
void Parser::parseError() const
{
    std::cerr << INVALID_INPUT_MSG << std::endl;
    exit(EXIT_FAILURE);
}

/**
 * Validates dim's boundaries - Greater than 0 and leq to 6
 * @param dim fractal required dimensions
 */
void Parser::dimValidity(int dim) const
{
    if(LOWER_BOUND >= dim ||  dim > UPPER_BOUND)
    {
        parseError();
    }
}

/**
 * Validates type's boundaries - f belongs to  {1,2,3}
 * @param type int representing a fractal type 1 = SC; 2 = ST; 3 = VF;
 */
void Parser::typeValidity(int type) const
{
    if(type != CARPET && type != TRIANGLE && type != VICSEK)
    {
        parseError();
    }
}

/**
 * Validates if the input in a specific cell in the given file is an int
 * @param fileCell a content of a specific cell in the given csv
 */
void Parser::checkIfInt(std::string& fileCell) const
{
    int digitFlag = 0, times = 0;
    for (auto c : fileCell)
    {
        if(!isdigit(c))
        {
            if(isspace(c) && digitFlag && !times)
            {
                times++;
                continue;
            }
            parseError();
        }
        digitFlag++;
        if(digitFlag > 1 || times > 1)
        {
            parseError();
        }
    }

//    std::string::const_iterator it = fileCell.begin();
//    while (it != fileCell.end() && std::isdigit(*it))
//    {
//        ++it;
//    }
//    if(!(!fileCell.empty() && it == fileCell.end()))
//    {
//        parseError();
//    }
}

/**
 * Validates amount of arguments and makes sure file type is csv
 * @param argc amount of arguments
 * @param argv arguments array
 */
void Parser::argsValidity(int argc, char **argv) const
{
    if(argc == FILE_AMOUNT)
    {
        std::string fileName = argv[FILE_POSITION];
        if(fileName.substr(fileName.find_last_of(DOT) + 1) == VALID_EXTENSION)
        {
            return;
        }
        else
        {
            parseError();
        }
    }
    else
    {
        std::cerr << USAGE << std::endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * Receives an input of a specific line in the file and checks if the values are valid
 * @param input vector containing two strings representing type and dimension of a wanted fractal
 */
void Parser::lineValidity(std::vector<std::string>& input) const
{
    checkIfInt((input[0]));
    checkIfInt(input[1]);
    typeValidity(std::stoi(input[0]));
    dimValidity(std::stoi(input[1]));
}

/**
 * Check if the input path is an actual file
 * @param fPath input path
 */
void Parser::doesFileExist(const std::string& fPath) const
{
    fs::path fp(fPath);
    if(!exists(fp))
    {
        parseError();
    }
}

/**
 * Creates a fractal according to a given type and dimension
 * @param type an int between 1-3
 * @param dim an int between 1-6
 * @return a pointer to a fractal object
 */
Fractal* Parser::factory(int type, int dim) const
{
    switch (type)
    {
        case CARPET:
            return new SC(dim);
        case TRIANGLE:
            return new ST(dim);
        case VICSEK :
            return new VF(dim);
        default:
            parseError();
            return nullptr;
    }
}

/**
 * Parses each individual line in the given file, validates it's input and creates the valid fractals
 * @param path a file path
 * @param f fractal vector
 * @return A fractal vector
 */
std::vector<Fractal*>& Parser::parseFile(std::string& path, std::vector<Fractal *>& f) const
{
   int lines = 0;
   std::vector<std::string> input;
   std::string line;
   std::ifstream is(path);
   if (!is.is_open())
   {
       parseError();
   }
   while(std::getline(is, line))
   {
       if(lines > EMPTY)
       {
           parseError();
       }
       if(!(line.compare("") || line.compare(",")))
       {
           ++lines;
           continue;
       }
       boost::char_separator<char> sep{","};
//       Tokenizer tok(line);
       Tokenizer tok{line, sep};
       input.assign(tok.begin(), tok.end());
       if (input.size() != 2)
       {
           parseError();
       }
       lineValidity(input);
       f.push_back(factory(std::stoi(input[0]), std::stoi(input[1])));
   }
   return f;
}

/**
 * A getter to the fractal vector
 * @return a fractal vector
 */
std::vector<Fractal*>& Parser::getFractalVec() const
{
    return this->fractal;
}

/**
 * Main function that operates the system
 * @param argc amount of argument given
 * @param argv the arguments
 * @return EXIT_SUCCESS
 */
int main(int argc, char*argv[])
{
    std::vector<Fractal*> fractal;
    Parser p = Parser(argc, argv, fractal);
    fractal = p.getFractalVec();
    for (int i = (int) fractal.size()-1 ; i >= 0; --i)
    {
        fractal[i]->printFractal();
        delete fractal[i];
    }
    fractal.clear();
    return EXIT_SUCCESS;
}

