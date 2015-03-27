#ifndef TURTLEGRAPH_H
#define TURTLEGRAPH_H
//include files
#include "../../GL/glew.h"
#include "../../GLFW/glfw3.h"
#include "shar.h"
#include <cmath>

//typedefs
typedef vec2 point2;
enum pen_state {PEN_UP, PEN_DOWN};

//const values
// const float torad = M_PI/180.0; //convert degree to rad
const GLchar *vertexSource =
"#version 430 core \n"
"layout (location = 0) in vec4 vpos;" //vpos is at 0
"out vec4 fcolor;"
"void main() { gl_Position = vpos; fcolor = vec4((1+vpos.xyz)/2, 1.0); }";

const GLchar *fragmentSource =
"#version 430 core \n"
"in vec4 fcolor;"
"out vec4 color;"
"void main() { color = fcolor; }";


//global variables
const int turtle_points = 363;
point2 turtle[turtle_points];//10 points for the shape, 1 for the direction pointer
point2 points[10000]; //amount of points allowed to be drawn
GLuint vpos = 0; //vpos for the vertex shader

int pointsdraw = 0;  //points drawn so far
float turtle_angle = 0; //initial angle of the turtle
float r = 0.05; //radius of circle
float r2 = r+r; //radius of the point around the circle
int turtle_brush = turtle_points-1;
pen_state pstate = PEN_UP;

float speed = 1;

//opengl buffers & vao;
GLuint vao;
GLuint vbo;

//func prototype
void draw_point();
void initBuffers();
void turtleInit(float x, float y, float angle = turtle_angle);
void turtle_right(float angle);
inline void turtle_left(float angle);
void move_turtle(float distance);
void change_pen_state(pen_state state);
void render_turtle(GLenum drawwith);
void rotate_toface(float x, float y);
GLboolean move_topoint(float x, float y);
void draw_point();
void reset_angle_turtle();

#endif // TURTLEGRAPH_H
