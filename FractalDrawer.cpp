#include <iostream>
#include <string>

#define FILE_AMOUNT 2
#define FILE_POSITION 1
#define DOT '.'
#define VALID_EXTENSION "csv"
#define USAGE "Usage: FractalDrawer <file path>"
#define INVALID_ARGS "Invalid input"
#define SC 1
#define ST 2
#define VF 3

void inputValidity(int argc, char*argv[])
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
            std::cerr<<INVALID_ARGS<<std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        std::cerr<<USAGE<<std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char*argv[])
{
    inputValidity(argc, argv);

}
