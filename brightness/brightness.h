#pragma once
#include "Image.h"
#include "math.h"
int brightness_func(int pixvalue, int brightness)
{
    int threshold;
    switch (brightness >= 0)
    {
    case 1:
        threshold = 255 - brightness; //155 if lets say pix 165 we cant assign 265 limit is 255

        if (pixvalue <= threshold)
        {
            return pixvalue + brightness;
        }
        else
        {
            return 255;
        }
        break;
    case 0:
        threshold = 0 - brightness;
        if (pixvalue >= threshold)
        {
            return pixvalue + brightness;
        }
        else
        {
            return 0;
        }
        break;
    }
}
void change_using_brightness(ColorImage *img, int value)
{
    ColorImage output((*img).GetWidth(), (*img).GetHeight());
    for (int y = 0; y < output.GetHeight(); y++)
    {
        for (int x = 0; x < output.GetWidth(); x++)
        {
            output(y, x).r = brightness_func((*img)(y, x).r, value);
            output(y, x).g = brightness_func((*img)(y, x).g, value);
            output(y, x).b = brightness_func((*img)(y, x).b, value);
        }
    }
    output.Save("brighnessnewimg.png");
}
//!change_using_gamma
float gamma_func(int input, float brightness)
{
    return (2 ^ 8 - 1) * (pow((input / 2 ^ 8 - 1), brightness)); //8 bits
}
void change_using_gamma(ColorImage *img, float value)
{
    ColorImage output((*img).GetWidth(), (*img).GetHeight());
    for (int y = 0; y < output.GetHeight(); y++)
    {
        for (int x = 0; x < output.GetWidth(); x++)
        {
            output(y, x).r = gamma_func((*img)(y, x).r, value);
            output(y, x).g = gamma_func((*img)(y, x).g, value);
            output(y, x).b = gamma_func((*img)(y, x).b, value);
        }
    }
    output.Save("gammanewimg.png");
}