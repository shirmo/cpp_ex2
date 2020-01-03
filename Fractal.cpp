//
// Created by shirmo on 31/12/2019.
//
#include <cmath>
#include <iostream>
#include "Fractal.h"
#define SC_SIZE 3
#define ST_SIZE 2
#define VF_SIZE 3
#define ASTRIX '#'
#define SPC ' '

Fractal::Fractal(const int& dimension)
{
    basicSize = 0;
    gridSize = 0;
    dim = dimension;
    std::vector<bool> inner1(dim, false);
    fractalVec fractalVec1(dim, inner1);
    shape = fractalVec1;

    std::vector<bool> inner2(1, false);
    fractalVec fractalVec2(1, inner2);

    pattern = fractalVec2;
}

//todo ask ilan if it's valid the iteration over the vector. maybe I should copy vec
Fractal::Fractal(const Fractal& f)
{
    basicSize = f.basicSize;
    gridSize = f.gridSize;
    dim = f.dim;
    for (int i = 0; i < basicSize; ++i)
    {
        for (int k = 0; k < basicSize; ++k)
        {
            pattern[i][k] = f.pattern[i][k];
        }
    }
    for (int i = 0; i < gridSize; ++i)
    {
        for (int k = 0; k < gridSize; ++k)
        {
            shape[i][k] = f.shape[i][k];
        }
    }
}

SC::SC(const int& dimension): Fractal(dimension)
{
    basicSize = SC_SIZE;
    gridSize = (int) pow(basicSize,dim);

    std::vector<bool> inner1(gridSize, false);
    fractalVec fractalVec1(gridSize, inner1);
    shape = fractalVec1;

    std::vector<bool> inner2(basicSize, false);
    fractalVec fractalVec2(basicSize, inner2);

    pattern = {{true, true, true}, {true, false, true}, {true, true, true}};

    createShape();
}

SC::SC(const Fractal& f):Fractal(f)
{
}

ST::ST(const int& dimension): Fractal(dimension)
{
    basicSize = ST_SIZE;
    gridSize = (int) pow(basicSize,dim);

    std::vector<bool> inner1(gridSize, false);
    fractalVec fractalVec1(gridSize, inner1);
    shape = fractalVec1;

    std::vector<bool> inner2(basicSize, false);
    fractalVec fractalVec2(basicSize, inner2);

    pattern = {{true, true}, {true, false}};

    createShape();
}

ST::ST(const Fractal& f): Fractal(f)
{
}

VF::VF(const int& dimension): Fractal(dimension)
{
    basicSize = VF_SIZE;
    gridSize = (int) pow(basicSize,dim);

    std::vector<bool> inner1(gridSize, false);
    fractalVec fractalVec1(gridSize, inner1);
    shape = fractalVec1;

    std::vector<bool> inner2(basicSize, false);
    fractalVec fractalVec2(basicSize, inner2);

    pattern = {{true, false, true}, {false, true, false}, {true, false, true}};

    createShape();
}

VF::VF(const Fractal& f):Fractal(f)
{
}


void Fractal::populateFractal(const int& row, const int& col, int n)
{
    int newRow = row;
    int newCol = col;
    if (n==0)
    {
        shape[newRow][newCol] = true;
        return;
    }
    int diff = (int) pow(basicSize, n-1);
    for (int i = 0; i < basicSize; ++i)
    {
        newCol = col;
        for (int k = 0; k < basicSize; ++k)
        {
            if (pattern[i][k])
            {
                populateFractal(newRow, newCol, n-1);
            }
            newCol += diff;
        }
        newRow += diff;
    }
        // newCol
//    if(n-1 == 0)
//    {
//        newRow = row/basicSize;
//        newCol = col/basicSize;
//        return pattern[newRow][newCol];
//    }
//    else
//    {
//        int divisor = (int) pow(basicSize,n-1);
//        newRow = row/divisor;
//        newCol = col/divisor;
//        if (pattern[newRow][newCol])
//        {
//            populateFractal(row, col, n-1);
//        }
//        else
//        {
//            return false;
//        }
//    }
}


void Fractal::createShape()
{
    populateFractal(0,0, dim);
}

void Fractal::printFractal()
{
    char printVal;
    for (int i = 0; i < gridSize; ++i)
    {
        for (int k = 0; k < gridSize; ++k)
        {
            printVal = (shape[i][k])? ASTRIX:SPC;
            std::cout<<printVal;
        }
        std::cout<<std::endl;
    }
}


