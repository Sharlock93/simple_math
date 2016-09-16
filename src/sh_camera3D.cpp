#include <sharfunc.h>
#include <sh_camera3D.h>

#include <iostream>

sh_camera3D::sh_camera3D () : _cam(1.0) {
    std::cout << "hello world" << std::endl;
}

sh_camera3D::sh_camera3D(vec4 eye, vec4 at, vec4 up): _cam(1.0) {
    _yaw = 0;
    _pitch = 0;
    _pos = eye;

    _cam = shalookat(eye, at, up); 
}

mat4 sh_camera3D::get_matrix() {
    return _cam;
}

void sh_camera3D::move_forward(float x) {
    _pos = _pos*shatranslate(-_cam.z*x);
    _cam = _cam*shatranslate(_cam.z*x);
    // std::cout << "hello" << std::endl;
} 

void sh_camera3D::move(vec4 v) {

}


void sh_camera3D::move_up(float x) {

}

void sh_camera3D::move_left(float x) {
    _pos = _pos*shatranslate(-_cam.x*x);
    _cam = _cam*shatranslate(_cam.x*x);
}

//Thanks to Christopher Haag, now I know that matrix order matters very dearly
//the model matrix should always come last i.e: mat4 model, rot
// it should be rot*model.

//Note(Sharo): Update on the above thing, its true that it should be rot*model, but
//for this camera class we want to rotate around the UP in the world, not the local UP

void sh_camera3D::increase_yaw(float add_yaw) {
    float diff = add_yaw -  _yaw;
    _cam = _cam*shatranslate(_pos)*sharotatey(diff)*shatranslate(-_pos);

    _yaw = add_yaw;
}

void sh_camera3D::increase_pitch(float add_pitch) {
    float diff = add_pitch - _pitch;
    _cam = sharotatex(diff)*_cam;
    _pitch = add_pitch;
}


void sh_camera3D::set_position(vec4 pos) {

}

vec4 sh_camera3D::get_position() {
    return _pos;
}

sh_camera3D::~sh_camera3D () {

}
