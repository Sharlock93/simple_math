#ifndef SH_CIRCLE_H
#define SH_CIRCLE_H


#ifndef CIRCLE_SEGMENTS
#define CIRCLE_SEGMENTS 32
#endif // CIRCLE_SEGMENTS

#include <shar.h>
#include <sharfunc.h>
#include <GL\glew.h>

class SH_API sh_circle {
public:
    sh_circle();
    sh_circle(float x, float y, float r, vec2 direction = vec2(1,0), vec4 color = vec4(1, 1, 1, 1), vec2 center = vec2(0, 0));
    ~sh_circle();

    vec2 get_position();
    void set_position(float x, float y);
    void set_position(vec2 pos);


    void move_position(float x, float y);
    void move_position(vec2 vel);
    void move_position(float speed);

    vec4 get_color();
    void set_color(vec4 color);


    void set_size(float r);
    void change_size_by(float amount);
    float get_size();


    void rotate(float angle);

    vec2 get_center();
    void set_center(float x, float y);
    void set_center(vec2 center);

    void render(GLint vpos_attrib, GLint color_attrib, GLint model_trans);

    vec2 _direction;
    GLuint _vbo;
    vec2 _position;
    vec2 _center;
    vec4 _color;
    mat4 _transform;


    float _r;

    vec2 _data[CIRCLE_SEGMENTS]; // this can be dynamically allocated perhaps, 100 segments seem very close to nice.
};


#endif // SH_CIRCLE_H
