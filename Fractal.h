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
    Fractal(int dim)
    std::vector<std::string> fractelize() const;

private:
    int grid_size;
    int dim;

};


#endif //CPP_EX2_FRACTAL_H

#ifndef CPP_EX2_FRACTAL_H
#define CPP_EX2_FRACTAL_H



class Fractal
{
public:
    Fractal(int dim)
    virtual std::vector<std::string> fractelize() const;

private:
    int grid_size;
    int dim;
    char* pattern;

};

#endif //CPP_EX2_FRACTAL_H


#ifndef CPP_EX2_FRACTAL_H
#define CPP_EX2_FRACTAL_H



class SC: public Fractal
{
public:
    std::vector<std::string> fractelize() const;

private:
    int grid_size;
    int dim;

};

#endif //CPP_EX2_FRACTAL_H