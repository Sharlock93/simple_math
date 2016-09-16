#include <shar.h>
#include <GL\glew.h>
#ifndef SH_LINE
#define SH_LINE

struct SH_API sh_line {
    sh_line();
    sh_line(vec2 a, vec2 b, vec4 color = vec4(1, 1, 1, 1));
    vec2 point[2];

    unsigned int vbo;
    vec4 _color;
    void update(vec2 a, vec2 b);
    void render(int vpos, int color, int model);
};

#endif

