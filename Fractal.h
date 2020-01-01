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
    Fractal(const int& dim);
    Fractal(const Fractal& f);
    ~Fractal();
    Fractal& operator=(const Fractal& f);
    Fractal operator=(const Fractal& f) const;
    void createShape();


protected:
    int basicSize;
    int gridSize;
    int dim;
    fractalVec pattern;
    fractalVec shape;

    bool populateFractal(const int& row,const int& col, int n);
};


class SC: public Fractal
{
    SC(const int& dim);
    SC(const Fractal& f);
    ~SC();
};

class ST: public Fractal
{
    ST(const int& dim);
    ST(const Fractal& f);
    ~ST();
};

class VF: public Fractal
{
    VF(const int& dim);
    VF(const Fractal& f);
    ~VF();
};

#endif //CPP_EX2_FRACTAL_H