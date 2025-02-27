#include <raylib.h>

#include "constants.h"

#include "drawing_canvas/dc.h"

int main(void) {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "tracer");
    SetTargetFPS(FPS);

    const Vector2 canvas_offset = {100, 50};
    canvas_setup((Rectangle){
        canvas_offset.x,
        canvas_offset.y,
        SCREEN_WIDTH - 2 * canvas_offset.x,
        SCREEN_HEIGHT - 2 * canvas_offset.y
    });

    canvas_update_start();

    while (!WindowShouldClose()) {
        float delta = GetFrameTime();

        BeginDrawing();
            ClearBackground(BG_COL);

            canvas_render();

            // FPS screen
            DrawFPS(SCREEN_WIDTH - 100, 20);


        EndDrawing();

    }

    canvas_close();
    CloseWindow();

    return 0;
}
