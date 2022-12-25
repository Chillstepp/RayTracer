#include <iostream>
#include "Vec.h"
#include "ColorUtilityFunction.h"
#include "Image.h"
#include "Ray.h"

int main() {
    //Image
    constexpr double AspectRatio = 16.0/9.0;
    constexpr int ImageWidth = 400;
    constexpr int ImageHeight = static_cast<int>(ImageWidth/AspectRatio);
    Image img{ImageWidth, ImageHeight};

    //Camera
    constexpr double ViewportHeight = 2.0;
    constexpr double ViewportWidth = AspectRatio*ViewportHeight;
    constexpr double FocalLength = 1.0;
    point3 Origin{0,0,0};
    vec3 Horizontal{ViewportWidth,0,0};
    vec3 Vertical{0, ViewportHeight, 0};
    point3 LowerLeftCorner = Origin - Horizontal/2 - Vertical/2 - vec3{0,0,FocalLength};

    //Render
    std::cout << "P3\n" << ImageWidth << ' ' <<ImageHeight << "\n255\n";

    for(int j = ImageHeight - 1; j >= 0; --j)
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for(int i=0; i < ImageWidth; ++i)
        {
            double u = double(i) / (ImageWidth-1);
            double v = double(j) / (ImageHeight-1);
            Ray r{Origin, LowerLeftCorner + u*Horizontal + v*Vertical - Origin};

            color ColorPixel = ColorUtilityFunction::ray_color(r);
            ColorUtilityFunction::write_color(std::cout, ColorPixel);
        }
    }
    std::cerr << "\nDone.\n";
}
