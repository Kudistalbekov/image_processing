#include "Image.h"
#include <cmath>
#include "math.h"
#define WINDOWS_LEAN_AND_MEAN 1

void get(GrayscaleImage img, float *max, float *min)
{
    *max = img(0, 0);
    *min = img(0, 0);
    for (int y = 0; y < img.GetHeight(); y++)
    {
        for (int x = 0; x < img.GetWidth(); x++)
        {
            if (img(x, y) > *max)
            {
                *max = img(x, y);
            }
            if (img(x, y) < *min)
            {
                *min = img(x, y);
            }
        }
    }
    std::cout << *max << "  " << *min;
}

int check(int n)
{
    if (n < 0)
        return 0;
    if (n > 255)
        return 255;
    return n;
}

void contraststretching(std::string path, std::string name)
{
    GrayscaleImage img;
    img.Load(path + name);
    GrayscaleImage newimg(img.GetWidth(), img.GetHeight());
    float max, min;
    get(img, &max, &min);
    float maxtype = (256 - 1) / (max - min);
    for (int x = 0; x < img.GetHeight(); x++)
    {
        for (int y = 0; y < img.GetWidth(); y++)
        {
            newimg(x, y) = check((img(x, y) - min) * maxtype);
        }
    }
    newimg.Save(path + "new" + name);
}

int main()
{
    std::string path = "/home/kudi/Programming/cpp/src/digitalimage/tutorial/lect1/lab/images/";
    contraststretching(path, "index.png");
}