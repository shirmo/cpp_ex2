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
    void populateFractal(const int& row,const int& col, int n);

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

#endif //CPP_EX2_FRACTAL_H