#include <sh_line.h>

sh_line::sh_line() {
    point[0] = vec2(0, 0);
    point[1] = vec2(0, 0);
    _color = vec4(1, 1, 1, 1);

    glGenBuffers(1, &vbo); 
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vec2)*2, point, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

sh_line::sh_line(vec2 a, vec2 b, vec4 color) {
    point[0] = a;
    point[1] = b;

    _color = color;
    glGenBuffers(1, &vbo); 
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vec2)*2, point, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void sh_line::update(vec2 a, vec2 b) {
    point[0] = a; 
    point[1] = b; 
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec2)*2, point, GL_DYNAMIC_DRAW);
}

void sh_line::render(int vpos, int color, int model) {
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glEnableVertexAttribArray(vpos);
    glVertexAttribPointer(vpos, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glUniform4fv(color, 1, &_color[0]);
    mat4 mat(1);
    glUniformMatrix4fv(model, 1, GL_TRUE, mat); 
    glDrawArrays(GL_LINES, 0, 2);
}
