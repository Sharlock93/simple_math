#ifndef _SHAR_FUNC_
#define _SHAR_FUNC_

#include "../headers/sharfunc.h"
#include <math.h>

//rotate in z-plane about the origin.
mat4 sharotatez(const float angle) {
    float s = angle * 3.1459f/180.0f;
    return mat4(cos(s), -sin(s), 0, 0,
                sin(s),  cos(s), 0, 0,
                0,       0, 1, 0,
                0,       0, 0, 1);
}

//in y-plane about origin
mat4 sharotatey(const float angle) {
    float s = angle * 3.1459f/180.0f;
    return mat4( cos(s),  0, sin(s), 0,
                 0,  1,      0, 0,
                 -sin(s),  0, cos(s), 0,
                 0,  0,      0, 1);
}

//x plane rotation
mat4 sharotatex(const float angle) {

    if (angle == 0)
        return mat4(1);
    float s = angle * 3.1459f/180.0f;
    return mat4(1,      0,       0, 0,
                0, cos(s), -sin(s), 0,
                0, sin(s),  cos(s), 0,
                0,      0,       0, 1);
}

//translation
mat4 shatranslate(float x, float y, float z) {
    return mat4(1.0, 0.0, 0.0, x,
                0.0, 1.0, 0.0, y,
                0.0, 0.0, 1.0, z,
                0.0, 0.0, 0.0, 1.0
               );
}

mat4 shatranslate(vec3 v) {
    return mat4(1.0, 0.0, 0.0, v.x,
                0.0, 1.0, 0.0, v.y,
                0.0, 0.0, 1.0, v.z,
                0.0, 0.0, 0.0, 1.0
               );
}

mat4 shatranslate(vec4 v) {
    return mat4(1.0, 0.0, 0.0, v.x,
                0.0, 1.0, 0.0, v.y,
                0.0, 0.0, 1.0, v.z,
                0.0, 0.0, 0.0, 1.0
               );
}

//scale
mat4 shascale(float x, float y, float z) {
    return mat4(x, 0, 0, 0,
                0, y, 0, 0,
                0, 0, z, 0,
                0, 0, 0, 1
               );
}

//rotate around an axis
mat4 sharotateav(float a, vec4 axis) {
    mat4 I = mat4(1.0);
    axis = normalize(axis);
    mat4 aat = mat4(
                   axis.x * axis.x, axis.x * axis.y, axis.x * axis.z, 0,
                   axis.x * axis.y, axis.y * axis.y, axis.z * axis.y, 0,
                   axis.x * axis.z, axis.y * axis.z, axis.z * axis.z, 0,
                                 0,               0,               0, 1
               ); //hello

    float radians = 3.1459f/180.0f * a; //handling the degree -> rad convertion

    mat4 dual_axis = mat4 (
                             0.0,  axis.z, -axis.y, 0,
                         -axis.z,     0.0,  axis.x, 0,
                          axis.y, -axis.x,     0.0, 0,
                               0,       0,       0, 1
                     );//the dual matrix of the axis vector

    return (cos(radians) * I + (1 - cos(radians)) * aat + dual_axis * sin(radians));
}

mat4 shaortho(float left, float right, float top, float bottom, float pnear, float pfar) {
    return mat4(2 / (left - right),              0,              0, -(right + left) / (right - left),
                0, 2 / (top - bottom),               0, -(top  + bottom) / (top - bottom),
                0,              0, -2 / (pfar - pnear), -(pfar + pnear) / (pnear - pfar),
                0,              0,              0, 1 );
}


//oblique proj
mat4 shaoblique(float theta, float phi) {
    return mat4(1.0f, 0.0f,   1.0f / tan(theta * torad), 0.0f,
                0.0f, 1.0f,   1.0f / tan(phi * torad), 0.0f,
                0.0f, 0.0f,                     1.0f, 0.0f,
                0.0f, 0.0f,                     0.0f, 1.0);
}

mat4 shalookat(vec4 eye, vec4 at, vec4 up) {
    vec4 n = normalize(eye - at); //this is the positive z direction
    vec4 u = normalize(cross(up, n)); //positive x direction
    vec4 v = cross(n, u); //positive y direction
    n.w = v.w = u.w = 0;

    mat4 result(u, v, n, vec4(0, 0, 0, 1));

    // std::cout << result << std::endl;
    // std::cout <<  shatranslate(-eye) << std::endl;

    return  result*shatranslate(-eye) ;
}

mat4 shafrustum(float lleft, float lright, float top, float bottom, float near, float far) {
    return mat4(2 * near / (lright - lleft),                   0,  (lright + lleft) / (lright - lleft),                      0,
                0, 2 * near / (top - bottom),      (top + bottom) / (top - bottom),                      0,
                0,                   0,         -(far + near) / (far - near), -2 * far * near / (far - near),
                0,                   0,                             -1,                      0 );
}

mat4 shaperspective(float fov, float aspect, float near, float far) {

    float top = tan((fov / 2) * 3.1459f/180.0f) * near;
    float right = top * aspect;

    return mat4(near / right,          0,                             0,                              0,
                           0, near / top,                             0,                              0,
                           0,          0,  -(far + near) / (far - near), -2 * far * near / (far - near),
                           0,          0,                            -1,                              0 );
}

#endif
