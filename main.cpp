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
#include "Metal.h"
#include "Lambertian.h"



int main() {
    //Image
    constexpr double AspectRatio = 16.0/9.0;
    constexpr int ImageWidth = 1000;
    constexpr int ImageHeight = static_cast<int>(ImageWidth/AspectRatio);
    constexpr int samples_per_pixel = 100;
    Image img{ImageWidth, ImageHeight};
    constexpr int max_depth = 50;

	//Material
	auto Material_Ground = make_shared<Lambertian>(color(0.96, 0.96, 0.96));
	auto Material_Center = make_shared<Lambertian>(color(0.941, 1, 1));
	auto Material_Left = make_shared<Metal>(color(0.8, 0.8, 0.8));
	auto Material_Right = make_shared<Metal>(color(0.69, 0.878, 0.9));


	//World
    HittableList World;
	World.Add(make_shared<Sphere>(point3( 0.0, -100.5, -1.0), 100.0, Material_Ground));
	World.Add(make_shared<Sphere>(point3( 0.0, 0.0, -1.0),0.5, Material_Center));
	World.Add(make_shared<Sphere>(point3( -1.5, 0.0, -1.0), 0.3, Material_Left));
	World.Add(make_shared<Sphere>(point3( 1.5, 0.0, -1.0), 0.2, Material_Right));


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
