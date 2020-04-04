#include <iomanip>
#include "Image.h"
#include <math.h>
#include "brightness.h"
#define WINDOWS_LEAN_AND_MEAN 1
int main()
{
    ColorImage input;
    input.Load("images/4.2.07.png");
    int brightness = 100;
    float gammabrighness = 0.7;
    change_using_brightness(&input, brightness);
    change_using_gamma(&input, gammabrighness);
}