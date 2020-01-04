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
    explicit Fractal(const int& dimension = 0);
    void printFractal();

protected:
    int basicSize;
    int gridSize;
    int dim;
    fractalVec pattern;
    fractalVec shape;

    void populateFractal(const int& row,const int& col, int n);
    void createShape();
};


class SC: public Fractal
{
public:
    explicit SC(const int& dimension);
};

class ST: public Fractal
{
public:
    explicit ST(const int& dimension);
};

class VF: public Fractal
{
public:
    explicit VF(const int& dim);
};

#endif //CPP_EX2_FRACTAL_H