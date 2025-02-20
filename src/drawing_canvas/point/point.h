#pragma once

#include <stddef.h>
#include <raylib.h>

typedef struct {

    Vector2 coords;
    Color color;

    size_t stroke_size;  // radius of circle
    const size_t min_stroke_size; // what will shrink to

} Point;

// NOTE: when creating point, add offset so it looks bigger (like a stroke with brush)
// then get it smaller to min as the paint is settling, write everything to shader to add effects
