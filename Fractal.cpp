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

/**
 * c'tor
 * @param dimension int representing the wanted fractal size
 */
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

/**
 * Sierpinski Carpet fractal c'tor
 * @param dimension the required fractal dimension
 */
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

/**
 * Sierpinski Triangle fractal c'tor
 * @param dimension the required fractal dimension
 */
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

/**
 * Vicsek fractal c'tor
 * @param dimension the required fractal dimension
 */
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

/**
 * Recursively passes over the grids cells and check if they should be true or false
 * @param row a row index of a grid's cell
 * @param col a col index of a grid's cell
 * @param n dimension of a fractal
 */
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
}

/**
 * Calls the recursive function populateFractal with the right initialization params
 */
void Fractal::createShape()
{
    populateFractal(0,0, dim);
}

/**
 * prints a fractal object
 */
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
    std::cout<<std::endl;
}


