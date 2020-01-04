#include <iostream>
#include <string>
#include "Fractal.h"
#include "FractalDrawer.h"
#include <boost/filesystem.hpp>
#include <boost/tokenizer.hpp>

namespace fs = boost::filesystem;
typedef boost::tokenizer< boost::escaped_list_separator<char> > Tokenizer;

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


void Parser::parseError() const
{
    std::cerr << INVALID_INPUT_MSG << std::endl;
    exit(EXIT_FAILURE);
}

void Parser::dimValidity(int dim) const
{
    if(LOWER_BOUND >= dim ||  dim > UPPER_BOUND)
    {
        parseError();
    }
}

void Parser::typeValidity(int type) const
{
    if(type != CARPET && type != TRIANGLE && type != VICSEK)
    {
        parseError();
    }
}

void Parser::checkIfInt(std::string& c) const
{
    std::string::const_iterator it = c.begin();
    while (it != c.end() && std::isdigit(*it)) ++it;
    if(!(!c.empty() && it == c.end()))
    {
        parseError();
    }
}

void Parser::inputValidity(int argc, char*argv[]) const
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
        std::cerr<<USAGE<<std::endl;
        exit(EXIT_FAILURE);
    }
}

void Parser::lineValidity(std::vector<std::string>& input) const
{
    checkIfInt((input[0]));
    checkIfInt(input[1]);
    typeValidity(std::stoi(input[0]));
    dimValidity(std::stoi(input[1]));
}

void Parser::doesFileExist(const std::string& fPath) const
{
    fs::path fp(fPath);
    if(!exists(fp))
    {
        parseError();
    }
}

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
    }
}

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
       Tokenizer tok(line);
       input.assign(tok.begin(),tok.end());
       if (input.size() != 2)
       {
           parseError();
       }
       lineValidity(input);
       f.push_back(factory(std::stoi(input[0]), std::stoi(input[1])));
       lines++;
   }
   if (lines == 0)
   {
       parseError();
   }
   return f;
}


int main(int argc, char*argv[])
{
    Parser p = Parser();
    p.inputValidity(argc, argv);
    p.doesFileExist(argv[1]);
    std::vector<Fractal*> fractal;
    std::string path = argv[1];
    fractal = p.parseFile(path, fractal);
    for (int i = (int) fractal.size()-1 ; i >= 0; --i)
    {
        fractal[i]->printFractal();
        delete fractal[i];
    }
    fractal.clear();
}

