#include "conf.h"


Conf conf_create(void) {
    return (Conf) {
        .mouse_pos = {0},
        .prev_mouse_pos = {0},
        .color = DEFAULT_COLOR,
        .stroke_size = DEFAULT_STROKE_SIZE,

    };
}
