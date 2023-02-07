#include <iostream>
#include "Vec.h"
#include "ColorUtilityFunction.h"
#include "VecUtilityFunction.h"
#include "Image.h"
#include "Ray.h"
#include "RayUtilityFunction.h"
#include "HIttableList.h"
#include "Sphere.h"
#include "Camera.h"



int main() {
    //Image
    constexpr double AspectRatio = 16.0/9.0;
    constexpr int ImageWidth = 1000;
    constexpr int ImageHeight = static_cast<int>(ImageWidth/AspectRatio);
    constexpr int samples_per_pixel = 100;
    Image img{ImageWidth, ImageHeight};
    constexpr int max_depth = 50;

    //World
    HittableList World;
    World.Add(make_shared<Sphere>(point3(0,0,-1), 0.5));
    World.Add(make_shared<Sphere>(point3(0,-100.5,-1), 100));


    //Camera
    Camera camera;

    //Render
    std::cout << "P3\n" << ImageWidth << ' ' <<ImageHeight << "\n255\n";

    for(int j = ImageHeight - 1; j >= 0; --j)
    {
        std::cerr << "\r Progress: " << 100.0- (j*100.0/ImageHeight) << '%' << std::flush;
        for(int i = 0; i < ImageWidth; ++i)
        {
            color pixel_color(0, 0, 0);
            for(int s = 0; s < samples_per_pixel; ++s)
            {
                double u = (i + random_double()) / (ImageWidth-1);
                double v = (j + random_double()) / (ImageHeight-1);
                Ray r = camera.get_ray(u,v);
                pixel_color += RayUtilityFunction::ray_color(r, World, max_depth);
            }
            ColorUtilityFunction::write_color(std::cout, pixel_color ,samples_per_pixel);
        }
    }
    std::cerr << "\nDone.\n";
}
