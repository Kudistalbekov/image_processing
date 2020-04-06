#include <iomanip>
#include "Image.h"
#include <math.h>
#include "brightness.h"
#define WINDOWS_LEAN_AND_MEAN 1
int main()
{
    brightness(-100, "images/4.2.07.png");
    contrast(2, "brightnew.png");
    //brightness(100, "images/4.2.07.png");
    //gamma(0.7, "images/4.2.07.png");
    // inverse("images/4.2.07.png");
}
