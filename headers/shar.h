//Sharo Qadir (Sharo93@gmail.com)
//law of the Graphics universe...
//scale
//rotate
//translate
//translate*rotate*scale <<---quiet fucked up
//v' = P*V*M*v << first model matrix, then view, then projections

// FUCKING MATRIX ORDER MATTERS.... mat4 v1, v2
//v1*v2 =!= v2*v1, even in my own fucking code...
//i wrote this code...math still fucks with you.

#ifndef _SHAR_
#define _SHAR_

#define BUFFER_OFFSET(byte) ((void*) (byte))
#include <ostream>
#include <iomanip>
#include <cmath>
const double torad = 3.14159265359 / 180.0;

#ifdef HELLO
#define SH_API __declspec(dllexport)
#else
#define SH_API __declspec(dllimport)
#endif

//=================================================
//vector types

//vector 2
struct SH_API vec2 {
    float x;
    float y; 
    vec2(float xin = 0, float yin = 0);
    float& operator[] (const unsigned int num);
};//end vec2

SH_API vec2 operator+(vec2 left, vec2 right);
SH_API vec2 operator+(vec2 left, float num);
SH_API vec2 operator+(float num, vec2 left);
SH_API vec2 operator-(vec2 vector);
SH_API vec2 operator-(vec2 left, vec2 right);
SH_API vec2 operator/(vec2 left, vec2 right);
SH_API vec2 operator/(vec2 left, float num);
SH_API vec2 operator/(float num, vec2 left);
SH_API vec2 normalize(vec2);
SH_API vec2 vproj(vec2 a, vec2 b);
SH_API double dot(vec2 a, vec2 b);
SH_API double length(vec2);
SH_API double sproj(vec2 a, vec2 b);
SH_API std::ostream& operator << (std::ostream& os, const vec2 vin);


// vector 3
struct SH_API  vec3 {
    float x;
    float y;
    float z;
    vec3(float xin = 0, float yin = 0, float zin = 0);
    float& operator[] (const unsigned int num);
};//end vec3

SH_API vec3 operator+(vec3 left, vec3 right);
SH_API vec3 operator+(vec3 left, float num);
SH_API vec3 operator+(float num, vec3 left);
SH_API vec3 operator*(double scalar, vec3 v);
SH_API vec3 operator*(vec3 v, double scalar);
SH_API vec3 operator-(vec3 a, vec3 b);
SH_API vec3 operator/(vec3 left, vec3 right);
SH_API vec3 operator/(float num, vec3 left);
SH_API vec3 operator/(vec3 left, float num);
SH_API vec3 operator/=(vec3 left, float num);
SH_API bool operator < (vec3 left, vec3 right);
SH_API bool operator==(vec3 left, vec3 right);
SH_API double length(vec3 in);
SH_API vec3 normalize(vec3 vin);
SH_API vec3 cross(vec3 vin, vec3 vin2);
SH_API double dot(vec3 vin, vec3 vin2);
SH_API double getcosa(vec3 vin, vec3 vin2);
SH_API double getangle(vec3 vin, vec3 vin2);
SH_API double sproj(vec3 a, vec3 b);
SH_API vec3 vproj(vec3 a, vec3 b);
SH_API vec3 vrejc(vec3 a, vec3 b);
SH_API std::ostream& operator << (std::ostream& os, const vec3 vin);


//vector 4
struct SH_API vec4 {
    float x;
    float y;
    float z;
    float w;
    vec4(float xin = 0, float yin = 0, float zin = 0, float win = 0); 
    float& operator[] (const unsigned int num); 
};//end vec4

SH_API vec4 operator+(vec4 left, vec4 right);
SH_API vec4 operator+(vec4 left, float num);
SH_API vec4 operator+(float num, vec4 left);
SH_API vec4 operator-(vec4 left, vec4 right);
SH_API vec4 operator-(vec4 left);
SH_API vec4 operator-(vec4 left, float num);
SH_API vec4 operator-(float num, vec4 left);
SH_API vec4 operator*(double scalar, vec4 v);
SH_API vec4 operator*(vec4 v, double scalar);
SH_API vec4 operator/(vec4 left, float num);
SH_API vec4 operator/(float num, vec4 left);
SH_API vec4 operator/(vec4 left, vec4 right);
SH_API double length(vec4 in);
SH_API vec4 normalize(vec4 vin);
SH_API vec4 cross(vec4 vin, vec4 vin2);
SH_API double dot(vec4 vin, vec4 vin2);
SH_API double getcosa(vec4 vin, vec4 vin2);
SH_API double getangle(vec4 vin, vec4 vin2);
SH_API double sproj(vec4 a, vec4 b);
SH_API vec4 vproj(vec4 a, vec4 b);
SH_API vec4 vrejc(vec4 a, vec4 b);
SH_API std::ostream& operator << (std::ostream& os, const vec4 vin);

//======================================================================

//======================================================================
//matrix types
/* the fields are vectors, that is why they have .x .y .z .w
       x    y    z    w
    x[x.x][x.y][x.z][x.w]
    y[y.x][y.y][y.z][y.w]
    z[z.x][z.y][z.z][z.w]
    w[w.x][w.y][w.z][w.w]
*/

//row major 2x2
struct SH_API  mat2x2 {
    vec2 x; // x axis
    vec2 y; // y axis

    //ctors for various ways to init the mat2
    mat2x2(float x1, float x2, float y1, float y2);
    mat2x2(float diagonal);
    mat2x2(float x1, float x2, vec2 yin);
    mat2x2(vec2 xin, float y1, float y2);
    mat2x2(vec2 xin, vec2 yin);

    vec2& operator[](const int index);
}; //struct for 2x2

SH_API vec2 operator * (const mat2x2 m, const vec2 vin);
SH_API vec2 operator * (const vec2 vin, const mat2x2 m);
SH_API mat2x2 operator * (const mat2x2 m, const mat2x2 m2);
SH_API mat2x2 operator/ (const mat2x2 matrix_in, float divisor);
SH_API mat2x2 transpose(mat2x2 matrix_in);
SH_API float determinate(mat2x2 matrix_in);
SH_API mat2x2 inverse(mat2x2 m_in);
SH_API std::ostream& operator << (std::ostream& os, const mat2x2 m);

//row major 3x3
struct SH_API  mat3x3 {
    vec3 x;
    vec3 y;
    vec3 z;

    //ctors for various ways to init the mat3
    mat3x3(float x1, float x2, float x3,
           float y1, float y2, float y3,
           float z1, float z2, float z3);

    mat3x3(float diagonal = 1.0);

    mat3x3(vec3 xin,
           float y1, float y2, float y3,
           float z1, float z2, float z3);

    mat3x3(vec3 xin,
           vec3 yin,
           float z1, float z2, float z3);

    mat3x3(vec3 xin,
           float y1, float y2, float y3,
           vec3 zin);

    mat3x3(float x1, float x2, float x3,
           vec3 yin,
           float z1, float z2, float z3);

    mat3x3(float x1, float x2, float x3,
           vec3 yin,
           vec3 zin);

    mat3x3(float x1, float x2, float x3,
           float y1, float y2, float y3,
           vec3 zin);

    mat3x3(vec3 xin,
           vec3 yin,
           vec3 zin);

    vec3& operator[](const int index);
}; //struct for 3x3

SH_API vec3 operator * (const vec3 vin, const mat3x3 m);
SH_API vec3 operator * (const mat3x3 m, const vec3 vin);
SH_API mat3x3 operator/ (const mat3x3 mat, float divisor);
SH_API mat3x3 transpose(mat3x3 mat);
SH_API mat3x3 inverse(mat3x3 mat);
SH_API mat3x3 operator * (const mat3x3 m, const mat3x3 m2);
SH_API float determinate(mat3x3 mat);
SH_API std::ostream& operator << (std::ostream& os, const mat3x3 m);

//mat 4x4
struct SH_API mat4x4 {
    vec4 x;
    vec4 y;
    vec4 z;
    vec4 w;

    mat4x4(float x1, float x2, float x3, float x4,
           float y1, float y2, float y3, float y4,
           float z1, float z2, float z3, float z4,
           float w1, float w2, float w3, float w4);

    mat4x4(float diagonal = 1);

    mat4x4(vec4 xin,
           float y1, float y2, float y3, float y4,
           float z1, float z2, float z3, float z4,
           float w1, float w2, float w3, float w4);

    mat4x4(vec4 xin,
           vec4 yin,
           float z1, float z2, float z3, float z4,
           float w1, float w2, float w3, float w4);

    mat4x4(vec4 xin,
           vec4 yin,
           vec4 zin,
           float w1, float w2, float w3, float w4);

    mat4x4(vec4 xin,
           vec4 yin,
           vec4 zin,
           vec4 win);

    mat4x4(float x1, float x2, float x3, float x4,
           vec4 yin,
           vec4 zin,
           float w1, float w2, float w3, float w4);

    mat4x4(float x1, float x2, float x3, float x4,
           vec4 yin,
           float z1, float z2, float z3, float z4,
           vec4 win);


    mat4x4(float x1, float x2, float x3, float x4,
           vec4 yin,
           vec4 zin,
           vec4 win);

    mat4x4(float x1, float x2, float x3, float x4,
           float y1, float y2, float y3, float y4,
           vec4 zin,
           vec4 win);

    vec4& operator[] (const int index);
    operator const float*();
};//mat4x4



SH_API std::ostream& operator << (std::ostream& os, const mat4x4 m);
SH_API vec4 operator * (const mat4x4 m, const vec4 vin);
SH_API vec4 operator * (const vec4 vin, const mat4x4 m);
SH_API mat4x4 operator / (const mat4x4 mat   , float divisor);
SH_API mat4x4 operator * (const float  scalar, const mat4x4 m);
SH_API mat4x4 operator * (const mat4x4 m     , const float scalar);
SH_API mat4x4 operator * (const mat4x4 m     , const mat4x4 m2);
SH_API mat4x4 operator + (const mat4x4 m     , const mat4x4 m2);
SH_API mat4x4 transpose(mat4x4 mat);
SH_API float determinate(mat4x4 mat);
SH_API mat4x4 inverse(mat4x4 mat);

typedef vec2   point2;
typedef vec3   point3;
typedef vec4   point4;
typedef mat4x4 mat4;

#endif
