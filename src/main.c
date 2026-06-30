#include <termbox2.h>

typedef struct {
    float x;
    float y;
    float z;
} vertex, ndCoords;

typedef struct {
    vertex vertices[3];
} triangle;

typedef struct {
    float x;
    float y;
    float z;
    float w;
} clipCoords;

typedef struct {
    float x, y; // X Y -> window coordinates
    float z;    // z -> depth
} windowCoords, fragment;

clipCoords ClipSpaceTransform(vertex vx) {
    // Multiply vertex coordinates by perspective matrix -> return clip coordinates
}

ndCoords NormalizeDeviceCoordinates(clipCoords cc) {
    // Divide cc's x, y and z components by w -> return normalized device coordinates
}

windowCoords WindowTransformation(ndCoords nc) {
    // Convert normalized device coordinates to window coordinates -> return window coordinates
}

fragment *ScanConversion(windowCoords wc[3]) {
    // scan convert a trinangle (3 window coordinates -> 1 triangle) -> return a pointer to a list of fragments
    // CALL FREE() AFTER USING FRAGMENTS
}

void FragmentWriting(fragment *fg) {
    // write each fragment to the screen with termbox
}

int main(void) {
    if (tb_init() != TB_OK) { return 1; } // initialize termbox2
    tb_set_output_mode(2); // allow termbox2 to use more colors

    struct tb_event ev;
    int running = 1;

    // main loop
    while (running == 1) {
        tb_clear();
        // --- rasterisation stuff ---
        tb_present();

        tb_poll_event(&ev);

        if (ev.key == TB_KEY_CTRL_C) {
            running = 0;
        }
    }

    tb_shutdown();

    return 0;
}