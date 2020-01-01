//
// Created by shirmo on 31/12/2019.
//
#include <string>
#include <vector>

#ifndef CPP_EX2_FRACTAL_H
#define CPP_EX2_FRACTAL_H



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
    int grid_size;
    int dim;
    bool** pattern;
    bool** shape;
};


class SC: public Fractal
{
    SC(const int& dim);
};

class ST: public Fractal
{
    ST(const int& dim);
};

class VF: public Fractal
{
    VF(const int& dim);
};

#endif //CPP_EX2_FRACTAL_H