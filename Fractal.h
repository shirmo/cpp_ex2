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
    Fractal(const int& dimension);
    Fractal(const Fractal& f);
   // ~Fractal();
   // Fractal& operator=(const Fractal& f);
   // Fractal operator=(const Fractal& f) const;
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
    SC(const int& dimension);
    SC(const Fractal& f);
    //~SC();
};

class ST: public Fractal
{
public:
    ST(const int& dimension);
    ST(const Fractal& f);
    //~ST();
};

class VF: public Fractal
{
public:
    VF(const int& dim);
    VF(const Fractal& f);
    //~VF();
};

#endif //CPP_EX2_FRACTAL_H