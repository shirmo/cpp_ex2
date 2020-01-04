//
// Created by shirmo on 31/12/2019.
//
#include <string>
#include <vector>

#ifndef CPP_EX2_FRACTAL_H
#define CPP_EX2_FRACTAL_H
typedef std::vector<std::vector<bool>> fractalVec;


class Fractal
{
public:
    /**
     *
     * @param dimension
     */
    explicit Fractal(const int& dimension = 0);
    /**
     *
     */
    void printFractal();

protected:
    int basicSize;
    int gridSize;
    int dim;
    fractalVec pattern;
    fractalVec shape;

    /**
     *
     * @param row
     * @param col
     * @param n
     */
    void populateFractal(const int& row,const int& col, int n);
    /**
     *
     */
    void createShape();
};


class SC: public Fractal
{
public:
    /**
     *
     * @param dimension
     */
    explicit SC(const int& dimension);
};

class ST: public Fractal
{
public:
    /**
     *
     * @param dimension
     */
    explicit ST(const int& dimension);
};

class VF: public Fractal
{
public:
    /**
     *
     * @param dim
     */
    explicit VF(const int& dim);
};

#endif //CPP_EX2_FRACTAL_H