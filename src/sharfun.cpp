#ifndef _SHAR_FUNC_
#define _SHAR_FUNC_

#include "../headers/sharfun.h"
// #include "../headers/shar.h"
#include <random>
#include <math.h>
#include <iostream>

//introduce some randomness
std::random_device randev;
std::mt19937 rantwist(randev());
std::uniform_real_distribution<float> uniformdist(0, 10);

void shatriangle(point2 *buffer, int &current_index,
                 point2 a, point2 b, point2 c) {
    buffer[current_index] = a;
    ++current_index;
    buffer[current_index] = b;
    ++current_index;
    buffer[current_index] = c;
    ++current_index;
}

void shatriangle(point3 *buffer, int &current_index,
                 point3 a, point3 b, point3 c) {
    buffer[current_index] = a;
    ++current_index;
    buffer[current_index] = b;
    ++current_index;
    buffer[current_index] = c;
    ++current_index;
}

void shatriangle(point4 *buffer, int &current_index,
                 point4 a, point4 b, point4 c) {
    buffer[current_index] = a;
    ++current_index;
    buffer[current_index] = b;
    ++current_index;
    buffer[current_index] = c;
    ++current_index;
}


void shatrianglediv(point2 *buffer, int &current_index,
                    point2 a, point2 b, point2 c,
                    int numdiv, bool random) {

    if (numdiv > 0) {
        point2 ab = (a + b) / 2.0;
        point2 ac = (a + c) / 2.0;
        point2 bc = (b + c) / 2.0;

        if (random == true) {
            ab = ab + uniformdist(rantwist);
            ac = ac + uniformdist(rantwist);
            bc = bc + uniformdist(rantwist);
        }

        shatrianglediv(buffer, current_index, a, ab, ac, numdiv - 1, random);
        shatrianglediv(buffer, current_index, ab, b, bc, numdiv - 1, random);
        shatrianglediv(buffer, current_index, ac, bc, c, numdiv - 1, random);
    } else {
        shatriangle(buffer, current_index, a, b, c);
    }
}

void shatertradiv(point3 *buffer, point3 *color_buffer, point3 base_color[4],
                  int &cur_index, int &color_index, point3 a, point3 b,
                  point3 c, point3 d, int num, bool rdm) {

    if (num > 0) {
        point3 ab, ac, ad, bc, bd, cd;
        ab = (a + b) / 2;
        ac = (a + c) / 2;
        ad = (a + d) / 2;
        bc = (b + c) / 2;
        bd = (b + d) / 2;
        cd = (c + d) / 2;

        if (rdm == true) {
            ab = ab + uniformdist(rantwist);
            ac = ac + uniformdist(rantwist);
            ad = ad + uniformdist(rantwist);
            bc = bc + uniformdist(rantwist);
            bd = bd + uniformdist(rantwist);
            cd = cd + uniformdist(rantwist);
        }

        shatertradiv(buffer, color_buffer, base_color, cur_index, color_index, a, ab, ac, ad, num - 1, rdm);
        shatertradiv(buffer, color_buffer, base_color, cur_index, color_index, ab, b, bc, bd, num - 1, rdm);
        shatertradiv(buffer, color_buffer, base_color, cur_index, color_index, ac, bc, c, cd, num - 1, rdm);
        shatertradiv(buffer, color_buffer, base_color, cur_index, color_index, ad, cd, bd, d, num - 1, rdm);
    } else {
        shatriangle(buffer, cur_index, a, b, c);
        shatriangle(color_buffer, color_index, base_color[0], base_color[0], base_color[0]);

        shatriangle(buffer, cur_index, a, c, d);
        shatriangle(color_buffer, color_index, base_color[1], base_color[1], base_color[1]);

        shatriangle(buffer, cur_index, a, b, d);
        shatriangle(color_buffer, color_index, base_color[2], base_color[2], base_color[2]);

        shatriangle(buffer, cur_index, b, c, d);
        shatriangle(color_buffer, color_index, base_color[3], base_color[3], base_color[3]);
    }
}


//homocoordinates
void shatertradiv(point4 *buffer, point4 *color_buffer, point4 base_color[4],
                  int &cur_index, int &color_index,
                  point4 a, point4 b, point4 c, point4 d,
                  int num, bool rdm) {
    if (num > 0) {
        point4 ab, ac, ad, bc, bd, cd;
        ab = (a + b) / 2;
        ac = (a + c) / 2;
        ad = (a + d) / 2;
        bc = (b + c) / 2;
        bd = (b + d) / 2;
        cd = (c + d) / 2;

        if (rdm == true) {
            ab = ab + uniformdist(rantwist);
            ac = ac + uniformdist(rantwist);
            ad = ad + uniformdist(rantwist);
            bc = bc + uniformdist(rantwist);
            bd = bd + uniformdist(rantwist);
            cd = cd + uniformdist(rantwist);
        }

        shatertradiv(buffer, color_buffer, base_color, cur_index, color_index, a, ab, ac, ad, num - 1, rdm);
        shatertradiv(buffer, color_buffer, base_color, cur_index, color_index, ab, b, bc, bd, num - 1, rdm);
        shatertradiv(buffer, color_buffer, base_color, cur_index, color_index, ac, bc, c, cd, num - 1, rdm);
        shatertradiv(buffer, color_buffer, base_color, cur_index, color_index, ad, cd, bd, d, num - 1, rdm);
    } else {
        shatriangle(buffer, cur_index, a, b, c);
        shatriangle(color_buffer, color_index, base_color[0], base_color[0], base_color[0]);

        shatriangle(buffer, cur_index, a, c, d);
        shatriangle(color_buffer, color_index, base_color[1], base_color[1], base_color[1]);

        shatriangle(buffer, cur_index, a, b, d);
        shatriangle(color_buffer, color_index, base_color[2], base_color[2], base_color[2]);

        shatriangle(buffer, cur_index, b, c, d);
        shatriangle(color_buffer, color_index, base_color[3], base_color[3], base_color[3]);
    }
}





//rotate in z-plane about the origin.
mat4 sharotatez(const float angle) {
    float s = angle * torad;
    return mat4(cos(s), -sin(s), 0, 0,
                sin(s),  cos(s), 0, 0,
                0,       0, 1, 0,
                0,       0, 0, 1);
}

//in y-plane about origin
mat4 sharotatey(const float angle) {
    float s = angle * torad;
    return mat4( cos(s),  0, sin(s), 0,
                 0,  1,      0, 0,
                 -sin(s),  0, cos(s), 0,
                 0,  0,      0, 1);
}

//x plane rotation
mat4 sharotatex(const float angle) {

    if (angle == 0)
        return mat4(1);
    float s = angle * torad;
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
                   0,             0,             0, 1
               ); //hello

    double radians = torad * a; //handling the degree -> rad convertion

    mat4 dual_axis = mat4 (
                         0.0,  axis.z, -axis.y, 0,
                         -axis.z,     0.0,  axis.x, 0,
                         axis.y, -axis.x,  0.0   , 0,
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
    return mat4(1, 0, 1 / tan(theta * torad), 0,
                0, 1, 1 / tan(phi * torad), 0,
                0, 0,                  1, 0,
                0, 0,                  0, 1);
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

    float top = tan((fov / 2) * torad) * near;
    float right = top * aspect;

    return mat4(near / right,        0,  0, 0,
                0, near / top,  0, 0,
                0,        0,  -(far + near) / (far - near), -2 * far * near / (far - near),
                0,        0, -1, 0 );
}

#endif
