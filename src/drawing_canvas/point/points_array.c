#include "points_array.h"
#include "point.h"

#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

PointsArray points_array_create(size_t preallocated_size) {
    Point* arr = malloc(preallocated_size * sizeof(*arr));

    return (PointsArray) {
        .points = arr,
        .n_points = 0,
        .available_spaces = preallocated_size,

    };
}
void points_array_destroy(PointsArray* pa) {
    free(pa->points);
}


void _array_allocate_more_space(PointsArray* pa) {
    // make array grow exponentially like vectors in c++
    pa->available_spaces *= 2;

    if (!(pa->points = realloc(pa->points, pa->available_spaces * sizeof(*pa->points)))) {
        perror("cannot reallocate buy more ram :(");
    }

}

void points_array_add(PointsArray* pa, Conf* conf) {
    // TODO: check if points are distant enough (1 radius, so effectively 2 radius distance from center)
    // printf("%f\n", Vector2Distance(conf->mouse_pos,pa->points[pa->n_points].pos));
    // printf("%f\n", pa->points[pa->n_points].pos.x);
    // if (Vector2Distance(conf->mouse_pos, pa->points[pa->n_points].pos) < conf->stroke_size * 2) {
    //     return;
    // }

    if (pa->available_spaces <= pa->n_points + 1) {
        _array_allocate_more_space(pa);
    }

    pa->points[pa->n_points] = (Point) {
        .pos = conf->mouse_pos,
        .color = conf->color,
        .stroke_size = conf->stroke_size  * 1.2f * 2,
        .min_stroke_size = conf->stroke_size, // it will diminish to wanted stroke size

    };
    pa->n_points++;

    // TODO: shrink other members
}


void points_array_render(PointsArray* pa) {
    for (int i = 0; i < pa->n_points; i++) {
        Point* point = pa->points + i;
        DrawCircleLinesV(point->pos, point->stroke_size, point->color);
        DrawCircleV(point->pos, point->stroke_size * 0.1f, point->color);
    }
}
