#include "dc.h"
#include "point/points_array.h"
#include "../constants.h"
#include "conf/conf.h"

#include <raylib.h>
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>


static Rectangle _bounds = { 0 };
static Conf _conf = { 0 };
static bool _window_should_close = false;
static pthread_t _update_id;

static PointsArray _points;

void canvas_setup(Rectangle bounds) {
    _bounds = bounds;
    _points = points_array_create(16);
    _conf = conf_create();
}


#define BORDER_ROUNDNESS 0.1f
#define BORDER_SEGMENTS 16
void canvas_render(void) {
    DrawRectangleRoundedLinesEx(_bounds, BORDER_ROUNDNESS, BORDER_SEGMENTS, 3, CANVAS_BORDER_COL);
    DrawRectangleRounded(_bounds, BORDER_ROUNDNESS, BORDER_SEGMENTS, CANVAS_BG_COL);

    points_array_render(&_points);
}

void canvas_close(void) {
    _window_should_close = true;
    pthread_join(_update_id, NULL);
    points_array_destroy(&_points);
}

// process brush strokes in in separate thread
// https://stackoverflow.com/questions/72018673/how-to-make-a-loop-run-x-frames-per-second
static struct timeval start, end;
#define FPS_UPDATE_US 1000000 / 30
void* canvas_update(void* _) {
    while (!_window_should_close) {
        gettimeofday(&start, NULL);

        ///////// process
        _conf.prev_mouse_pos = _conf.mouse_pos;
        _conf.mouse_pos = GetMousePosition();

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointRec(_conf.mouse_pos, _bounds)) {
                printf("hello\n");
                points_array_add(&_points, &_conf);
            }
        }

        ///////// fix framerate
        gettimeofday(&end, NULL);
        int delta_us = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
        if (delta_us < FPS_UPDATE_US) { // check if process took less than FPS
            usleep(FPS_UPDATE_US - delta_us); // sleep to reach that fps threshold
        }

    }

    return NULL;

}

// start canvas_update thread
void canvas_update_start(void) {
    pthread_create(&_update_id, NULL, canvas_update, NULL);


}
