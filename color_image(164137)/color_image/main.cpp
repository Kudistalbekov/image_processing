#include "Image.h"
#include "math.h"
#include "algorithm"

#define WINDOWS_LEAN_AND_MEAN 1

using namespace std;

int sumfunc(int sum)
{
    if (sum > 255)
        return 255;
    if (sum < 0)
        return 0;
    return sum;
}

int multtoker(GrayscaleImage image, std::vector<std::vector<int>> array, int x, int y)
{
    return ((image(x - 1, y - 1) * array[0][0]) + (image(x, y - 1) * array[0][1]) + (image(x + 1, y - 1) * array[0][2]) + (image(x - 1, y) * array[1][0]) + (image(x, y) * array[1][1]) + (image(x + 1, y) * array[1][2]) + (image(x - 1, y + 1) * array[2][0]) + (image(x, y + 1) * array[2][1]) + (image(x + 1, y + 1) * array[2][2]));
}

void edgefunc(string pic)
{
    vector<vector<int>> array(3, vector<int>(3, -1));
    array[1][1] = 8;

    GrayscaleImage image;
    image.Load(pic);
    GrayscaleImage mynewImg(image.GetWidth(), image.GetHeight());

    int sum = 0;

    for (int y = 1; y < image.GetHeight() - 1; y++)
    {
        for (int x = 1; x < image.GetWidth() - 1; x++)
        {

            sum = multtoker(image, array, x, y);

            mynewImg(x, y) = sumfunc(sum);
        }
    }
    mynewImg.Save("color/edge2.png");
}

void smoothfunc(string pic)
{
    vector<vector<int>> array(3, vector<int>(3, 1));

    GrayscaleImage image;
    image.Load(pic);
    GrayscaleImage mynewImg(image.GetWidth(), image.GetHeight());

    int sum = 0;

    for (int y = 1; y < image.GetHeight() - 1; y++)
    {
        for (int x = 1; x < image.GetWidth() - 1; x++)
        {

            sum = multtoker(image, array, x, y);
            mynewImg(x, y) = sumfunc(sum) / 9;
        }
    }
    mynewImg.Save("color/smooth2.png");
}

void sharpfunc(string pic)
{
    vector<vector<int>> array(3, vector<int>(3, -1));
    array[1][1] = 9;

    GrayscaleImage image;
    image.Load(pic);
    GrayscaleImage mynewImg(image.GetWidth(), image.GetHeight());

    int sum = 0;

    for (int y = 1; y < image.GetHeight() - 1; y++)
    {
        for (int x = 1; x < image.GetWidth() - 1; x++)
        {
            sum = multtoker(image, array, x, y);
            mynewImg(x, y) = sumfunc(sum);
        }
    }
    mynewImg.Save("color/sharp2.png");
}

int main()
{
    string pic = "pic3.png";
    sharpfunc(pic);
    smoothfunc(pic);
    edgefunc(pic);
    return 0;
}
