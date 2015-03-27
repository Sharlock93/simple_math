#include "../headers/shaturtlegraph.h"
#include "../headers/sharinit.h"
#include "../../GL/glew.h"
#include "../../GLFW/glfw3.h"

void initBuffers() {
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(turtle) + sizeof(points), NULL, GL_STATIC_DRAW);

    GLint vertex = glCreateShader(GL_VERTEX_SHADER);
    GLint fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex, 1, &vertexSource, NULL);
    glShaderSource(fragment, 1, &fragmentSource, NULL);

    glCompileShader(vertex);
    glCompileShader(fragment);

    GLuint program = shamkprogram(vertex, fragment);

    glEnableVertexAttribArray(vpos);
    glVertexAttribPointer(vpos, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glLinkProgram(program);
    glUseProgram(program);
}

//initiate the turtle with the center at (x, y), orientation of turtle_angle
void turtleInit(float x, float y, float angle) {
    float temp = 0; //angle
    for(int i = 0; i < turtle_points-3; ++i) {
        turtle[i].x = r*cos(temp*torad)+x;
        turtle[i].y = r*sin(temp*torad)+y;
        temp += 30;
    }

    turtle[turtle_points-3].x = r*cos(angle*torad)+x;
    turtle[turtle_points-3].y = r*sin(angle*torad)+y;

    turtle[turtle_points-2] = point2(r2*cos(angle*torad)+x, r2*sin(angle*torad)+y);
    turtle_angle = angle;

    turtle[turtle_brush] = point2(x, y);

    initBuffers();
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(turtle), turtle);
}

void turtle_right(float angle) {
    if(angle != 0) {
        turtle_angle -= angle;
        float nx = cos(turtle_angle*torad)*r2;
        float ny = sin(turtle_angle*torad)*r2;

        turtle[turtle_points-2].x = nx+turtle[turtle_brush].x;
        turtle[turtle_points-2].y = ny+turtle[turtle_brush].y;

        float nx1 = cos(turtle_angle*torad)*r;
        float ny1 = sin(turtle_angle*torad)*r;

        turtle[turtle_points-3].x = nx1+turtle[turtle_brush].x;
        turtle[turtle_points-3].y = ny1+turtle[turtle_brush].y;

        glBufferSubData(GL_ARRAY_BUFFER, (turtle_points-3)*sizeof(point2), sizeof(point2)+sizeof(point2), &turtle[turtle_points-3]);
    }
}

inline void turtle_left(float angle) {
    turtle_right(-angle);
}

void move_turtle(float distance) {
    for(auto &p : turtle) {
        p.x += cos(turtle_angle*torad)*distance;
        p.y += sin(turtle_angle*torad)*distance;
    }

    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(turtle), turtle);
}

void change_pen_state(pen_state state) {
    pstate = state;
}

void render_turtle(GLenum drawwith) {
    glDrawArrays(GL_LINE_STRIP, 0, turtle_points-3);
    glDrawArrays(GL_LINES, turtle_points-3, 2);
    if(pstate == PEN_DOWN)
        glDrawArrays(GL_POINTS, turtle_points-1, 1);
    if(pointsdraw > 0)
        glDrawArrays(drawwith, turtle_points, pointsdraw);
}

void rotate_toface(float x, float y) {
    float angle = atan2(-y, x)/torad;
    turtle_right((angle + turtle_angle)/speed);
}


GLboolean move_topoint(float x, float y) {
    float dist_x = x - turtle[turtle_brush].x;
    float dist_y = y - turtle[turtle_brush].y;
    float dist = sqrt(dist_x*dist_x + dist_y*dist_y);
    float angle = atan2(-dist_y, dist_x)/torad;

    // if(round(abs(turtle_angle)) != round(abs(angle))) {
        turtle_right((angle + turtle_angle)/speed);
    //     return GL_FALSE;
    // }

       // cout << ++i << " " << dist << endl;
    // if(round(abs(turtle_angle)) == round(abs(angle)) && !(dist < 0.01)) {
        move_turtle(dist);
        // return GL_FALSE;

    // }

    return GL_TRUE;
}

void draw_point() {
    if(pstate == PEN_DOWN) {
        points[pointsdraw++] = turtle[turtle_brush];
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(turtle)+sizeof(point2)*(pointsdraw-1), sizeof(point2),
         &points[pointsdraw-1]);

        // cout << pointsdraw << endl;
    }
}

void reset_angle_turtle() {
    turtle_angle = 0;
}
