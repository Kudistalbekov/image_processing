#pragma once
#include "Image.h"
#include "math.h"
void brightness(int bright, std::string path)
{
    int threshold;
    ColorImage img;
    img.Load(path);
    ColorImage newimg(img.GetWidth(), img.GetHeight());
    for (int y = 0; y < newimg.GetHeight(); y++)
        for (int x = 0; x < newimg.GetWidth(); x++)
            if (bright >= 0)
            {
                threshold = 255 - bright;
                newimg(y, x).r = (img(y, x).r <= threshold) ? (img(y, x).r + bright) : (255);
                newimg(y, x).g = (img(y, x).g <= threshold) ? (img(y, x).g + bright) : (255);
                newimg(y, x).b = (img(y, x).b <= threshold) ? (img(y, x).b + bright) : (255);
            }
            else
            {
                threshold = 0 - bright;
                newimg(y, x).r = (img(y, x).r >= threshold) ? (img(y, x).r + bright) : (0);
                newimg(y, x).g = (img(y, x).g >= threshold) ? (img(y, x).g + bright) : (0);
                newimg(y, x).b = (img(y, x).b >= threshold) ? (img(y, x).b + bright) : (0);
            }

    newimg.Save("brightnew.png");
}

void gamma(float bright, std::string path)
{
    ColorImage img;
    img.Load(path);
    ColorImage newimg(img.GetWidth(), img.GetHeight());
    for (int y = 0; y < newimg.GetHeight(); y++)
    {
        for (int x = 0; x < newimg.GetWidth(); x++)
        {
            newimg(y, x).r = 255 * pow((img(y, x).r / 255), bright);
            newimg(y, x).g = 255 * pow((img(y, x).g / 255), bright);
            newimg(y, x).b = 255 * pow((img(y, x).b / 255), bright);
        }
    }
    newimg.Save("gammanew.png");
}

void inverse(std::string path)
{
    ColorImage img;
    img.Load(path);
    ColorImage newimg((img).GetWidth(), (img).GetHeight());
    for (int y = 0; y < newimg.GetHeight(); y++)
        for (int x = 0; x < newimg.GetWidth(); x++)
        {
            newimg(y, x).r = 255 - (img)(y, x).r;
            newimg(y, x).g = 255 - (img)(y, x).g;
            newimg(y, x).b = 255 - (img)(y, x).b;
        }
    newimg.Save("inverse.png");
}
float check(float val)
{
    return (val > 255) ? 255 : (val < 0) ? 0 : val;
}
void contrast(float contr, std::string path)
{
    ColorImage img;
    img.Load(path);
    ColorImage newimg(img.GetWidth(), img.GetHeight());
    for (int y = 0; y < newimg.GetHeight(); y++)
    {
        for (int x = 0; x < newimg.GetWidth(); x++)
        {
            newimg(y, x).r = check(contr * (img(y, x).r - (2 ^ (8 - 1))) + (2 ^ (8 - 1)));
            newimg(y, x).g = check(contr * (img(y, x).g - (2 ^ (8 - 1))) + (2 ^ (8 - 1)));
            newimg(y, x).b = check(contr * (img(y, x).b - (2 ^ (8 - 1))) + (2 ^ (8 - 1)));
        }
    }
    newimg.Save("contrast.png");
}