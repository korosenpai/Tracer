#include <raylib.h>

#include "constants.h"

#include "drawing_canvas/dc.h"

int main(void) {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "tracer");
    SetTargetFPS(FPS);

    const Vector2 canvas_offset = {100, 50};
    setup_canvas((Rectangle){
        canvas_offset.x,
        canvas_offset.y,
        SCREEN_WIDTH - 2 * canvas_offset.x,
        SCREEN_HEIGHT - 2 * canvas_offset.y
    });

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BG_COL);

            update_canvas();

            // FPS screen
            DrawFPS(SCREEN_WIDTH - 100, 20);


        EndDrawing();

    }

    CloseWindow();

    return 0;
}
