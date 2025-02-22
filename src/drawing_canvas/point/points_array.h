#pragma once

#include "point.h"
#include "../conf/conf.h"

#include <stddef.h>
#include <raylib.h>

typedef struct {
    Point* points;
    size_t n_points;
    size_t available_spaces;

} PointsArray;

PointsArray points_array_create(size_t preallocated_size);
void points_array_destroy(PointsArray* pa);

void points_array_add(PointsArray* pa, Conf* conf);
void points_array_update(PointsArray* pa); // fix sizes
void points_array_render(PointsArray* pa);
