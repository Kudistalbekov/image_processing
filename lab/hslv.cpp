#include "Image.h"
#include "math.h"
#include <cstdlib>
#define minimumrgb(x, y, z) (x < y ? (x < z ? x : z) : (y < z ? y : z))
#define maximumrgb(x, y, z) (x > y ? (x > z ? x : z) : (y > z ? y : z))

using namespace std;

int main()
{
    ColorImage img;
    img.Load("images/colors.png");

    ColorImage newImg(img.GetWidth(), img.GetHeight());
    float R, G, B;
    float Cmax, Cmin;
    float d, H, V, S, L, X, C, m, mv;

    for (int y = 0; y < img.GetHeight(); y++)
        for (int x = 0; x < img.GetWidth(); x++)
        {

            R = (float)img(x, y).r / 255.f;
            G = (float)img(x, y).g / 255.f;
            B = (float)img(x, y).b / 255.f;

            Cmax = maximumrgb(R, G, B);
            Cmin = minimumrgb(R, G, B);
            d = Cmax - Cmin;
            if (d == 0)
                H = 0;
            else if (Cmax == R)
                H = 60 * ((int)((G - B) / d) % 6);
            else if (Cmax == G)
                H = 60 * (((B - R) / d) + 2);
            else if (Cmax == B)
                H = 60 * (((R - G) / d) + 4);
            V = Cmax;
            V = V * 0.5;
            L = ((Cmax - Cmin) / 2);
            L = L * 0.5;
            S = (d == 0) ? 0 : d / (1 - abs(2 * L - 1));
            C = (1 - abs(2 * L - 1)) * S;
            m = L - (C / 2);
            X = C * (1 - abs(((int)(H / 60) % 2) - 1));
            mv = V - X;
            //!R
            if ((0 <= H && H < 60) || (300 <= H && H < 360))
                R = C;
            else if (120 <= H && H < 240)
                R = 0;
            else
                R = X;
            //!G
            if (60 <= H && H < 120)
                G = C;
            else if (240 <= H && H < 300)
                G = 0;
            else
                G = X;
            //!B
            if (0 <= H && H < 120)
                B = 0;
            else if (180 <= H && H < 300)
                B = C;
            else
                B = X;
            newImg(x, y).r = (R + m) * 255.f;
            newImg(x, y).g = (G + m) * 255.f;
            newImg(x, y).b = (B + m) * 255.f;

            newImg(x, y).r = (R + mv) * 255.f;
            newImg(x, y).g = (G + mv) * 255.f;
            newImg(x, y).b = (B + mv) * 255.f;
        }

    newImg.Save("images/hslv.png");
    return 0;
}