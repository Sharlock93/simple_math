#ifndef SH_CAMERA3D_H
#define SH_CAMERA3D_H

#include <shar.h>

class SH_API sh_camera3D {

public:
    sh_camera3D();
    sh_camera3D(vec4 eye, vec4 at, vec4 up);
    ~sh_camera3D();

    mat4 get_matrix();
    
    void move_forward(float x);
    void move_up(float x);
    void move_left(float x);

    void move(vec4 v);

    void set_position(vec4 vec4);
    vec4 get_position();

    void increase_yaw(float add_yaw);
    void increase_pitch(float add_yaw);
    mat4 _cam;
    vec4 _pos;

    float _yaw;
    float _pitch;

};

#endif // SH_CAMERA3D_H
