//
// Created by Chillstep on 2022/12/27.
//

#ifndef RAYTRACER_HITTABLELIST_H
#define RAYTRACER_HITTABLELIST_H

#include "Hittable.h"
#include <memory>
#include <vector>
using std::shared_ptr;
using std::make_shared;

class HittableList: public Hittable {
public:
    HittableList() = default;
    explicit HittableList(const shared_ptr<Hittable>&Object)
    {

    }

    void Clear()
    {
        Objects.clear();
        decltype(Objects)().swap(Objects);
    }
    void Add(const shared_ptr<Hittable>&object) { Objects.push_back(object); }
    virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;
public:
    std::vector<shared_ptr<Hittable>>Objects;
};


#endif //RAYTRACER_HITTABLELIST_H
