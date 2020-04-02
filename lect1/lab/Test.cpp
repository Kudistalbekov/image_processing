#include "Image.h"
#define WINDOWS_LEAN_AND_MEAN 1
//! in order to execute it's in linux
//*g++ Test.cpp -o Test
//*we need png library
//*g++ Test.cpp -o Test -lpng : (-lpng is for execute with png library)
//!if -libpng not found
//*try to find where is located(path) or download (it can locate in usr/include)
//*try this command
//*g++ -L/path Test.cpp -o Test -lpng (path is in my case=usr/include)
//*g++ -L/usr/include Test.cpp -o Test -lpng
/*
void nearneigthinter(GrayscaleImage *img, std::string path, std::string imgname, int w, int h)
{
	GrayscaleImage newimg(w, h);
	(*img).Load(path + imgname);
	float sx = (float)(*img).GetWidth() / newimg.GetWidth();
	float sy = (float)(*img).GetHeight() / newimg.GetHeight();
	for (int x = 0; x < newimg.GetHeight(); x++)
	{
		for (int y = 0; y < newimg.GetWidth(); y++)
		{
			newimg(x, y) = (*img)(x * sx, y * sy);
		}
	}
	newimg.Save(path + "new" + imgname);
}
void blininter(GrayscaleImage *img, std::string path, std::string imgname, int w, int h)
{
	GrayscaleImage newimg(w, h);
	(*img).Load(path + imgname);

	for (int x = 0; x < newimg.GetHeight(); x++)
	{
		for (int y = 0; y < newimg.GetWidth(); y++)
		{
		}
	}

	newimg.Save(path + "new" + imgname);
}
void histogram(GrayscaleImage img)
{
}

int main()
{
	std::string path = "/home/kudi/Programming/cpp/src/digitalimage/tutorial/lect1/lab/images/";
	GrayscaleImage img;
	histogram(img);

	return 0;
}
*/
#include "Image.h"
#include <cmath>
#include <map>
#include <algorithm>

#define WINDOWS_LEAN_AND_MEAN 1

void get(GrayscaleImage img, int *max, int *min)
{
	for (int y = 0; y < img.GetHeight(); y++)
	{
		for (int x = 0; x < img.GetWidth(); x++)
		{
			if (x == 0 && y == 0)
			{
				*max = img(x, y);
				*min = img(x, y);
			}
			if (img(x, y) > *max)
			{
				*max = img(x, y);
			}
			else
			{
				*min = img(x, y);
			}
		}
	}
}

std::map<int, int> count(GrayscaleImage img, int max, int min)
{
	std::map<int, int> m;
	for (int i = min; i <= max; i++)
	{
	}
}

void prepare(GrayscaleImage img)
{
	std::map<int, int> m;
	std::map<int, int>::iterator itr;
	for (int y = 0; y < img.GetHeight(); y++)
	{
		for (int x = 0; x < img.GetWidth(); x++)
		{
			if (m.find(img(y, x)) != m.end())
			{
				m[img(y, x)]++;
			}
			else
			{
				m[img(y, x)] = 0;
			}
		}
	}
	for (itr = m.begin(); itr != m.end(); ++itr)
	{
		std::cout << itr->first << " " << itr->second << std::endl;
	}
}

int main()
{
	GrayscaleImage img, newimg;
	img.Load("/home/kudi/Programming/cpp/src/digitalimage/tutorial/lect1/lab/images/read.png");
	int max, min;
	newimg(img.GetHeight(), img.GetWidth());
	get(img, &max, &min);
	//std::map<int, int> imghist;
	//prepare(img);
	//imghist = count(img, max, min);

	int maxtype = (2 ^ max - 1) / (max - min);
	for (int x = 0; x < img.GetHeight(); x++)
	{
		for (int y = 0; y < img.GetWidth(); y++)
		{
			newimg(x, y) = (img(x, y) - min) * maxtype;
		}
	}
	newimg.Save("/home/kudi/Programming/cpp/src/digitalimage/tutorial/lect1/lab/images/newread.png");
}