#include "..\headers\shar.h"
#include "..\headers\sharfun.h"
#include "..\headers\sh_camera3D.h"

#include <iostream>

sh_camera3D::sh_camera3D () : _cam(1.0) {
    std::cout << "hello world" << std::endl;
}

sh_camera3D::sh_camera3D(vec4 eye, vec4 at, vec4 up): _cam(1.0) {
    _yaw = 0;
    _pitch = 0;
    _pos = -eye;

    _cam = shalookat(eye, at, up);
}

mat4 sh_camera3D::get_matrix() {
    return _cam;
}

void sh_camera3D::move_forward(float x) {
    _pos = _pos*shatranslate(_cam.z*x);
    _cam = _cam*shatranslate(_cam.z*x);
    std::cout << _pos << std::endl;
} 

void sh_camera3D::move(vec4 v) {
    _pos = _pos + v;
}


void sh_camera3D::move_up(float x) {

}


//Thanks to Christopher Haag, now I know that matrix order matters very dearly
//the model matrix should always come last i.e: mat4 model, rot
// it should be rot*model.

//Note(Sharo): Update on the above thing, its true that it should be rot*model, but
//for this camera class we want to rotate around the UP in the world, not the local UP

void sh_camera3D::increase_yaw(float add_yaw) {
    float diff = add_yaw - _yaw;
    mat4 rots = shatranslate(-_pos);
    rots = rots*sharotatey(diff);
    rots = rots*shatranslate(_pos);

    _cam = _cam*rots;
    _yaw += diff;
}

void sh_camera3D::increase_pitch(float add_pitch) {
    float diff  = add_pitch - _pitch;
    
    if((_pitch > 85 && diff > 0) || (_pitch < -85 && diff < 0))
        diff = 0;
    
    _cam = sharotatex(diff)*_cam;
    _pitch += diff;
}


void sh_camera3D::set_position(vec4 pos) {

}

vec4 sh_camera3D::get_position() {
    return _pos;
}

sh_camera3D::~sh_camera3D () {
    std::cout << "bye world" << std::endl;
}
