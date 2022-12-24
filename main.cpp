#include <iostream>
#include "Vec.h"
#include "ColorUtilityFunction.h"

int main() {
    constexpr int ImageWidth = 256;
    constexpr int ImageHeight = 256;

    std::cout << "P3\n" << ImageWidth << ' ' <<ImageHeight << "\n255\n";

    for(int j = ImageHeight - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for(int i=0; i < ImageWidth; ++i)
        {
            double r = double(i) / (ImageWidth-1);
            double g = double(j) / (ImageHeight-1);
            double b = 0.25;
            color ColorPixel(r, g, b);
            write_color(std::cout, ColorPixel);
        }
    }
    std::cerr << "\nDone.\n";
}
