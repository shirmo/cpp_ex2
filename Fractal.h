//
// Created by shirmo on 31/12/2019.
//
#include <string>
#include <vector>

#ifndef CPP_EX2_FRACTAL_H
#define CPP_EX2_FRACTAL_H
typedef std::vector<std::vector<bool>> fractalVec;

/**
 *
 */
class Fractal
{
public:
    /**
     * c'tor
     * @param dimension int representing the wanted fractal size
     */
    explicit Fractal(const int& dimension = 0);
    /**
     * prints a fractal object
     */
    void printFractal();

protected:
    int basicSize;
    int gridSize;
    int dim;
    fractalVec pattern;
    fractalVec shape;

    /**
     * Recursively passes over the grids cells and check if they should be true or false
     * @param row a row index of a grid's cell
     * @param col a col index of a grid's cell
     * @param n dimension of a fractal
     */
    void populateFractal(const int& row, const int& col, int n);

    /**
     * Calls the recursive function populateFractal with the right initialization params
     */
    void createShape();
};

/**
 * Sierpinski Carpet fractal
 */
class SC: public Fractal
{
public:
    /**
     * Sierpinski Carpet fractal c'tor
     * @param dimension the required fractal dimension
     */
    explicit SC(const int& dimension);
};

/**
 * Sierpinski Triangle fractal
 */
class ST: public Fractal
{
public:
    /**
     * Sierpinski Triangle fractal c'tor
     * @param dimension the required fractal dimension
     */
    explicit ST(const int& dimension);
};

/**
 * Vicsek fractal
 */
class VF: public Fractal
{
public:
    /**
     * Vicsek fractal c'tor
     * @param dimension the required fractal dimension
     */
    explicit VF(const int& dimension);
};

/**
 * A parser class that parses a csv file, creates fractals vector and holds it.
 */
class Parser
{

private:
    std::vector<Fractal*>& fractal;

public:
    /**
     * c'tor
     * @param argc amount of arguments
     * @param argv arguments array
     * @param fractal a list to be populated
     */
    Parser(int argc, char *argv[], std::vector<Fractal *> &fractal);

    /**
     * A getter to the fractal vector
     * @return a fractal vector
     */
    std::vector<Fractal*>& getFractalVec() const;

    /**
     * Check if the input path is an actual file
     * @param fPath input path
     */
    void doesFileExist(const std::string &fPath) const;

    /**
     * Validates amount of arguments and makes sure file type is csv
     * @param argc amount of arguments
     * @param argv arguments array
     */
    void argsValidity(int argc, char **argv) const;

    /**
     * Parses each individual line in the given file, validates it's input and creates the valid fractals
     * @param path a file path
     * @param f fractal vector
     * @return A fractal vector
     */
    std::vector<Fractal *> &parseFile(std::string &path, std::vector<Fractal *> &f) const;

    /**
     * Prints an error message and exits the program
     */
    void parseError() const;

    /**
     * Validates dim's boundaries - Greater than 0 and leq to 6
     * @param dim fractal required dimensions
     */
    void dimValidity(int dim) const;

    /**
     * Validates type's boundaries - f belongs to  {1,2,3}
     * @param type int representing a fractal type 1 = SC; 2 = ST; 3 = VF;
     */
    void typeValidity(int type) const;

    /**
     * Validates if the input in a specific cell in the given file is an int
     * @param fileCell a content of a specific cell in the given csv
     */
    void checkIfInt(std::string &fileCell) const;

    /**
     * Receives an input of a specific line in the file and checks if the values are valid
     * @param input vector containing two strings representing type and dimension of a wanted fractal
     */
    void lineValidity(std::vector<std::string> &input) const;

    /**
     * Creates a fractal according to a given type and dimension
     * @param type an int between 1-3
     * @param dim an int between 1-6
     * @return a pointer to a fractal object
     */
    Fractal* factory(int type, int dim) const;

};

#endif //CPP_EX2_FRACTAL_H