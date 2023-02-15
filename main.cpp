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
#include "Dielectric.h"

HittableList random_world()
{
    HittableList world;
    auto ground_material = make_shared<Lambertian>(color(0.5, 0.5, 0.5));
    world.Add(make_shared<Sphere>(point3(0,-1000,0), 1000, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

            if ((center - point3(4, 0.2, 0)).Length() > 0.9) {
                shared_ptr<Material> Sphere_material;

                if (choose_mat < 0.8) {
                    // diffuse
                    auto albedo = VecUtilityFunction::random() * VecUtilityFunction::random();
                    Sphere_material = make_shared<Lambertian>(albedo);
                    world.Add(make_shared<Sphere>(center, 0.2, Sphere_material));
                } else if (choose_mat < 0.95) {
                    // Metal
                    auto albedo = VecUtilityFunction::random(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    Sphere_material = make_shared<Metal>(albedo, fuzz);
                    world.Add(make_shared<Sphere>(center, 0.2, Sphere_material));
                } else {
                    // glass
                    Sphere_material = make_shared<Dielectric>(1.5);
                    world.Add(make_shared<Sphere>(center, 0.2, Sphere_material));
                }
            }
        }
    }

    auto material1 = make_shared<Dielectric>(1.5);
    world.Add(make_shared<Sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<Lambertian>(color(0.4, 0.2, 0.1));
    world.Add(make_shared<Sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<Metal>(color(0.7, 0.6, 0.5), 0.0);
    world.Add(make_shared<Sphere>(point3(4, 1, 0), 1.0, material3));

    return world;
}

int main() {
    //Image
    constexpr double AspectRatio = 3.0/2.0;
    constexpr int ImageWidth = 1200;
    constexpr int ImageHeight = static_cast<int>(ImageWidth/AspectRatio);
    constexpr int samples_per_pixel = 500;
    Image img{ImageWidth, ImageHeight};
    constexpr int max_depth = 50;

//	//Material
//	auto Material_Ground = make_shared<Lambertian>(color(0.75, 0.75, 0.75));
//	auto Material_Center = make_shared<Lambertian>(color(0.7, 0.3, 0.3));
//	auto Material_Left = make_shared<Metal>(color(0.8, 0.8, 0.8), 0.3);
//	//auto Material_Right = make_shared<Metal>(color(0.69, 0.878, 0.9), 1);
//	auto Material_Right = make_shared<Dielectric>(1.5);
//
//	//World
//    HittableList World;
//	World.Add(make_shared<Sphere>(point3( 0.0, -100.5, -1.0), 100.0, Material_Ground));
//	World.Add(make_shared<Sphere>(point3( 0.0, 0.0, -1.0),0.5, Material_Center));
//	World.Add(make_shared<Sphere>(point3( -1.0, 0.0, -1.0), 0.4, Material_Left));
//	World.Add(make_shared<Sphere>(point3( 1.0, 0.0, -1.0), 0.3, Material_Right));

    HittableList World = random_world();

    point3 lookfrom(13,2,3);
    point3 lookat(0,0,0);
    vec3 vup(0,1,0);
    auto dist_to_focus = 10.0;
    auto aperture = 0.1;
    //Camera
    Camera camera(lookfrom, lookat, vup, 20, AspectRatio, aperture, dist_to_focus);

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
