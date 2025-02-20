#include "dc.h"
#include <raylib.h>

#include "../constants.h"
#include "conf/conf.h"

static Rectangle _bounds;
static Conf _conf;

void setup_canvas(Rectangle bounds) {
    _bounds = bounds;
}


void update_canvas(void) {
    DrawRectangleRoundedLinesEx(_bounds, 0.1, 16, 3, CANVAS_BORDER_COL);
}
