#pragma once

#include <raylib.h>


void canvas_setup(Rectangle bounds);

// call every frame, pass mouse
void canvas_render(void);
void canvas_close(void);

void canvas_update_start(void); // do in a thread thats runs like _physics_process
