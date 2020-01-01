//
// Created by shirmo on 31/12/2019.
//
#include <cmath>
#include "Fractal.h"


bool Fractal::populateFractal(const int& row, const int& col, int n)
{
    int newRow;
    int newCol;
    if(n-1 == 0)
    {
        return pattern[row][col];
    }
    else
    {
        int divisor = (int) pow(basicSize,n-1);
        newRow = row/divisor;
        newCol = col/divisor;
        if (pattern[newRow][newCol])
        {
            populateFractal(row, col, n-1);
        }
        else
        {
            return false;
        }
    }
}


void Fractal::createShape()
{
    for (int m = 0; m < gridSize; ++m)
    {
        for (int k = 0; k < gridSize; ++k)
        {
            shape[m][k] = populateFractal(m,k,dim);
        }
    }
}




