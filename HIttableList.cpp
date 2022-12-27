//
// Created by Chillstep on 2022/12/27.
//

#include "HIttableList.h"

bool HittableList::hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    hit_record TempRecord;
    bool bHitAnything = false;
    double Closest = t_max;

    for(const auto& obj: Objects)
    {
        if(obj->hit(r, t_min, Closest, TempRecord))
        {
            bHitAnything = true;
            Closest = TempRecord.t;
            rec = TempRecord;
        }
    }
    return bHitAnything;
}
