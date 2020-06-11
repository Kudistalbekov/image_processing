#pragma once
#include <iostream>
#include <iomanip>
#include "Image.h"
#include <map>
//!This kernel i'm using for EROSION AND DILATION
int kernel[3][3];
int object = 0;

//!first will be romved by second
std::map<int, int> conflict;
std::map<int, int>::iterator pntr;

//!first num of image and second is size
std::map<int, int> images;
//!function just to print my pixel image
void print_image(GrayscaleImage objimage)
{
    for (int y = 0; y < objimage.GetHeight(); y++)
    {
        for (int x = 0; x < objimage.GetWidth(); x++)
        {
            int val = objimage(x, y);
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void prepare_kernels()
{
    //*EROSION //DILATION
    kernel[0][1] = 1;
    kernel[1][0] = 1;
    kernel[1][1] = 1;
    kernel[1][2] = 1;
    kernel[2][1] = 1;
}
void print_kernel()
{
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            std::cout << "[" << kernel[y][x] << "]"
                      << " ";
        }
        std::cout << std::endl;
    }
}
