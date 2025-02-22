#pragma once

#include "../../constants.h"

#include <stddef.h>
#include <raylib.h>

typedef struct {

    Vector2 mouse_pos;
    Vector2 prev_mouse_pos;

    Color color;
    size_t stroke_size;

} Conf;


Conf conf_create(void);
