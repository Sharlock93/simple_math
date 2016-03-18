#include "..\headers\shar.h"
#include <cmath>
#include <iomanip>
#include <ostream>
#ifndef M_PI
#define M_PI 3.14159265359
#endif
//=================================================
//vector types

//vector 2
vec2::vec2(float xin, float yin) {
    x = xin;
    y = yin;
}

float& vec2::operator[] (const unsigned int num) {
    switch (num) {
    case 0: return x;
    case 1: return y;
    }
}//end vec2 op []


//vector 3
vec3::vec3(float xin, float yin, float zin) {
    x = xin;
    y = yin;
    z = zin;
}

float& vec3::operator[] (const unsigned int num) {
    switch (num) {
    case 0: return x;
    case 1: return y;
    case 2: return z;
    }
}//end vec3 op []



//vector 4
vec4::vec4(float xin, float yin, float zin, float win) {
    x = xin;
    y = yin;
    z = zin;
    w = win;
}

float& vec4::operator[] (const unsigned int num) {
    switch (num) {
    case 0: return x;
    case 1: return y;
    case 2: return z;
    case 3: return w;
    }
}//end vec4 op []
//=======================================================================

//=======================================================================
//vec2 operators

//addition
vec2 operator+(vec2 left, vec2 right) {
    return vec2(left.x + right.x, left.y + right.y);
}// +

vec2 operator+(vec2 left, float num) {
    return vec2(left.x + num, left.y + num);
}// +

vec2 operator+(float num, vec2 left) {
    return operator+(left, num);
}// +

vec2 operator-(vec2 vector) {
  return vec2(-vector.x, -vector.y);
}

vec2 operator-(vec2 left, vec2 right) {
    return vec2(left.x - right.x, left.y - right.y);
}


//division
vec2 operator/(vec2 left, vec2 right) {
    return vec2(left.x / right.x, left.y / right.y);
}// /

vec2 operator/(vec2 left, float num) {
    return vec2(left.x / num, left.y / num);
}// /

vec2 operator/(float num, vec2 left) {
    return vec2(num / left.x, num / left.y);
}// /
//======================================================================

//======================================================================
//vec3 op
vec3 operator+(vec3 left, vec3 right) {
    return vec3(left.x + right.x, left.y + right.y, left.z + right.z);
}//+

vec3 operator+(vec3 left, float num) {
    return vec3(left.x + num, left.y + num, left.z + num);
}//+

vec3 operator+(float num, vec3 left) {
    return vec3(left.x + num, left.y + num, left.z + num);
}//+

vec3 operator*(double scalar, vec3 v) {
    return vec3(scalar * v.x, scalar * v.y, scalar * v.z);
}//*

vec3 operator*(vec3 v, double scalar) {
    return vec3(scalar * v.x, scalar * v.y, scalar * v.z);
}//*

vec3 operator-(vec3 a, vec3 b) {
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}//-

//div
vec3 operator/(vec3 left, vec3 right) {
    return vec3(left.x / right.x, left.y / right.y, left.z / right.z);
}// /

vec3 operator/(float num, vec3 left) {
    return vec3(num / left.x, num / left.y, num / left.z);
}// /

vec3 operator/(vec3 left, float num) {
    return vec3(left.x / num, left.y / num, left.z / num);
}// /

vec3 operator/=(vec3 left, float num) {
    return vec3(left.x / num, left.y / num, left.z / num);
}// /


bool operator < (vec3 left, vec3 right) {
    float dleft = sqrt(left.x * left.x + left.y * left.y + left.z * left.z);
    float dright = sqrt(right.x * right.x + right.y * right.y + right.z * right.z);

    return dleft < dright;
}

bool operator==(vec3 left, vec3 right) {
    return left.x == right.x && left.y == right.y && left.z == right.z;
}

double length(vec3 in) {
    return sqrt(in.x * in.x + in.y * in.y + in.z * in.z);
}

vec3 normalize(vec3 vin) {
    double len = length(vin);
    return vec3(vin.x / len, vin.y / len, vin.z / len);
}

vec3 cross(vec3 vin, vec3 vin2) {
    return vec3( vin.y * vin2.z - vin.z * vin2.y, //x
                 -vin.x * vin2.z + vin.z * vin2.x, //y
                 vin.x * vin2.y - vin.y * vin2.x) //z
           ;
}

double dot(vec3 vin, vec3 vin2) {
    return (vin.x * vin2.x + vin.y * vin2.y + vin.z * vin2.z);
}

//return cos(theta) between the two vectors
double getcosa(vec3 vin, vec3 vin2) {
    return dot(vin, vin2) / (length(vin) * length(vin2));
}

double getangle(vec3 vin, vec3 vin2) {
    return 180.0 / M_PI * acos(dot(vin, vin2) / (length(vin) * length(vin2)));
}


//project a into b
double sproj(vec3 a, vec3 b) {
    return dot(a, b) / length(b);
}

//project a into b in vector form
vec3 vproj(vec3 a, vec3 b) {
    return (dot(a, b) / dot(b, b)) * b;
}

vec3 vrejc(vec3 a, vec3 b) {
    return a - vproj(a, b);
}

//======================================================================

//======================================================================
//vec4 op
vec4 operator+(vec4 left, vec4 right) {
    return vec4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
}// +

vec4 operator+(vec4 left, float num) {
    return vec4(left.x + num, left.y + num, left.z + num, left.w + num);
}// +

vec4 operator+(float num, vec4 left) {
    return vec4(left.x + num, left.y + num, left.z + num, left.w + num);
}// +

vec4 operator-(vec4 left, vec4 right) {
    return vec4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
}// -

vec4 operator-(vec4 left) {
    return vec4(-left.x, -left.y, -left.z, left.w);
}// -


vec4 operator-(vec4 left, float num) {
    return vec4(left.x - num, left.y - num, left.z - num, left.w);
}// -

vec4 operator-(float num, vec4 left) {
    return vec4(left.x - num, left.y - num, left.z - num, left.w);
}// +

vec4 operator*(double scalar, vec4 v) {
    return vec4(scalar * v.x, scalar * v.y, scalar * v.z, v.w);
}//*

vec4 operator*(vec4 v, double scalar) {
    return vec4(scalar * v.x, scalar * v.y, scalar * v.z, v.w);
}//*

vec4 operator/(vec4 left, float num) {
    return vec4(left.x / num, left.y / num, left.z / num, left.w / num);
}// /

vec4 operator/(float num, vec4 left) {
    return vec4(num / left.x, num / left.y, num / left.z, num / left.w);
}// /

vec4 operator/(vec4 left, vec4 right) {
    return vec4(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w);
}// /

double length(vec4 in) {
    return sqrt(in.x * in.x + in.y * in.y + in.z * in.z);
}

vec4 normalize(vec4 vin) {
    double len = length(vin);
    return vec4(vin.x / len, vin.y / len, vin.z / len, 1.0);
}

vec4 cross(vec4 vin, vec4 vin2) {
    return vec4( vin.y * vin2.z - vin.z * vin2.y, //x
                 -vin.x * vin2.z + vin.z * vin2.x, //y
                 vin.x * vin2.y - vin.y * vin2.x, //z
                 1 );                         //w
}

double dot(vec4 vin, vec4 vin2) {
    return (vin.x * vin2.x + vin.y * vin2.y + vin.z * vin2.z);
}

//return cos(theta) between the two vectors
double getcosa(vec4 vin, vec4 vin2) {
    return dot(vin, vin2) / (length(vin) * length(vin2));
}

double getangle(vec4 vin, vec4 vin2) {
    return 180.0 / M_PI * acos(dot(vin, vin2) / (length(vin) * length(vin2)));
}


//project a into b
double sproj(vec4 a, vec4 b) {
    return dot(a, b) / length(b);
}

//project a into b in vector form
vec4 vproj(vec4 a, vec4 b) {
    return (dot(a, b) / dot(b, b)) * b;
}


vec4 vrejc(vec4 a, vec4 b) {
    return a - vproj(a, b);
}

//======================================================================


//======================================================================
//matrix types Implementation
/* the fields are vectors, that is why they have .x .y .z .w
       x    y    z    w
    x[x.x][x.y][x.z][x.w]
    y[y.x][y.y][y.z][y.w]
    z[z.x][z.y][z.z][z.w]
    w[w.x][w.y][w.z][w.w]
*/

// 2x2 Matrix
//row major 2x2

mat2x2::mat2x2(float x1, float x2, float y1, float y2): x(x1, x2), y(y1, y2) {};
mat2x2::mat2x2(float diagonal) : x(diagonal, 0.0), y(0.0, diagonal) {};
mat2x2::mat2x2(float x1, float x2, vec2 yin) : x(x1, x2), y (yin) {};
mat2x2::mat2x2(vec2 xin, float y1, float y2) : x(xin), y (y1, y2) {};
mat2x2::mat2x2(vec2 xin, vec2 yin) : x(xin), y (yin) {};

vec2& mat2x2::operator[] (const int index) {
    switch (index) {
    case 0: return x;
    case 1: return y;
    }
}


// 3x3 Matrix

mat3x3::mat3x3(float x1, float x2, float x3,
               float y1, float y2, float y3,
               float z1, float z2, float z3)
    : x(x1, x2, x3),
      y(y1, y2, y3),
      z(z1, z2, z3) {};

mat3x3::mat3x3(float diagonal) :
    x(diagonal, 0.0, 0.0),
    y(0.0, diagonal, 0.0),
    z(0.0, 0.0, diagonal) {};

mat3x3::mat3x3(vec3 xin,
               float y1, float y2, float y3,
               float z1, float z2, float z3)
    : x(xin),
      y(y1, y2, y3),
      z(z1, z2, z3) {};

mat3x3::mat3x3(vec3 xin,
               vec3 yin,
               float z1, float z2, float z3)
    : x(xin),
      y(yin),
      z(z1, z2, z3) {};

mat3x3::mat3x3(vec3 xin,
               float y1, float y2, float y3,
               vec3 zin)
    : x(xin),
      y(y1, y2, y3),
      z(zin) {};

mat3x3::mat3x3(float x1, float x2, float x3,
               vec3 yin,
               float z1, float z2, float z3)
    : x(x1, x2, x3),
      y(yin),
      z(z1, z2, z3) {};

mat3x3::mat3x3(float x1, float x2, float x3,
               vec3 yin,
               vec3 zin)
    : x(x1, x2, x3),
      y(yin),
      z(zin) {};

mat3x3::mat3x3(float x1, float x2, float x3,
               float y1, float y2, float y3,
               vec3 zin)
    : x(x1, x2, x3),
      y(y1, y2, y3),
      z(zin) {};


mat3x3::mat3x3(vec3 xin,
               vec3 yin,
               vec3 zin)
    : x(xin),
      y(yin),
      z(zin) {};

//row major 3x3
vec3& mat3x3::operator[] (const int index) {
    switch (index) {
    case 0: return x;
    case 1: return y;
    case 2: return z;
    }
}


// 4x4 Matrix

mat4x4::mat4x4(float x1, float x2, float x3, float x4,
           float y1, float y2, float y3, float y4,
           float z1, float z2, float z3, float z4,
           float w1, float w2, float w3, float w4)
           :x(x1, x2, x3, x4),
            y(y1, y2, y3, y4),
            z(z1, z2, z3, z4),
            w(w1, w2, w3, w4) {};

mat4x4::mat4x4(float diagonal) :
      x(diagonal, 0.0, 0.0, 0.0),
      y(0.0, diagonal, 0.0, 0.0),
      z(0.0, 0.0, diagonal, 0.0),
      w(0.0, 0.0, 0.0, diagonal) {};

mat4x4::mat4x4(vec4 xin,
       float y1, float y2, float y3, float y4,
       float z1, float z2, float z3, float z4,
       float w1, float w2, float w3, float w4)
       :x(xin),
        y(y1, y2, y3, y4),
        z(z1, z2, z3, z4),
        w(w1, w2, w3, w4) {};

mat4x4::mat4x4(vec4 xin,
       vec4 yin,
       float z1, float z2, float z3, float z4,
       float w1, float w2, float w3, float w4)
       :x(xin),
        y(yin),
        z(z1, z2, z3, z4),
        w(w1, w2, w3, w4) {};

mat4x4::mat4x4(vec4 xin,
       vec4 yin,
       vec4 zin,
       float w1, float w2, float w3, float w4)
       :x(xin),
        y(yin),
        z(zin),
        w(w1, w2, w3, w4) {};

mat4x4::mat4x4(vec4 xin,
       vec4 yin,
       vec4 zin,
       vec4 win)
       :x(xin),
        y(yin),
        z(zin),
        w(win) {};

mat4x4::mat4x4(float x1, float x2, float x3, float x4,
       vec4 yin,
       vec4 zin,
       float w1, float w2, float w3, float w4)
       :x(x1, x2, x3, x4),
        y(yin),
        z(zin),
        w(w1, w2, w3, w4) {};

mat4x4::mat4x4(float x1, float x2, float x3, float x4,
       vec4 yin,
       float z1, float z2, float z3, float z4,
       vec4 win)
       :x(x1, x2, x3, x4),
        y(yin),
        z(z1, z2, z3, z4),
        w(win) {};


mat4x4::mat4x4(float x1, float x2, float x3, float x4,
       vec4 yin,
       vec4 zin,
       vec4 win)
       :x(x1, x2, x3, x4),
        y(yin),
        z(zin),
        w(win) {};

mat4x4::mat4x4(float x1, float x2, float x3, float x4,
       float y1, float y2, float y3, float y4,
       vec4 zin,
       vec4 win)
       :x(x1, x2, x3, x4),
        y(y1, y2, y3, y4),
        z(zin),
        w(win) {};

vec4& mat4x4::operator[] (const int index) {
    switch (index) {
    case 0: return x;
    case 1: return y;
    case 2: return z;
    case 3: return w;
    }
}

mat4x4::operator const float* () {
    return &this[0][0][0];
}


//=====================================================================
//matrix 2x2 operations
//operators for mat2x2

//div
mat2x2 operator/ (const mat2x2 matrix_in, float divisor) {
    return mat2x2(matrix_in.x / divisor, matrix_in.y / divisor);
}

mat2x2 transpose(mat2x2 matrix_in) {
    return mat2x2(
               matrix_in.x.x, matrix_in.y.x,
               matrix_in.x.y, matrix_in.y.y
           );
}

float determinate(mat2x2 matrix_in) {
    return (matrix_in.x.x * matrix_in.y.y - matrix_in.x.y * matrix_in.y.x);
}


mat2x2 inverse(mat2x2 m_in) {
    return mat2x2( m_in.y.y, -m_in.x.y,
                   -m_in.y.x,  m_in.x.x) / determinate(m_in);
}

vec2 operator * (const mat2x2 m, const vec2 vin) {
    return vec2(m.x.x * vin.x + m.x.y * vin.y, m.y.x * vin.x + m.y.y * vin.y);
}

vec2 operator * (const vec2 vin, const mat2x2 m) {
    return vec2(m.x.x * vin.x + m.x.y * vin.y, m.y.x * vin.x + m.y.y * vin.y);
}

mat2x2 operator * (const mat2x2 m, const mat2x2 m2) {
    return mat2x2(
               m.x.x * m2.x.x + m.x.y * m2.y.x,
               m.x.x * m2.x.y + m.x.y * m2.y.y,
               m.y.x * m2.x.x + m.y.y * m2.y.x,
               m.y.x * m2.x.y + m.y.y * m2.y.y
           );
}

//mat 3x3
mat3x3 operator/ (const mat3x3 mat, float divisor) {
    return mat3x3(mat.x / divisor, mat.y / divisor, mat.z / divisor);
}

mat3x3 transpose(mat3x3 mat) {
    return mat3x3(
               mat.x.x, mat.y.x, mat.z.x,
               mat.x.y, mat.y.y, mat.z.y,
               mat.x.z, mat.y.z, mat.z.z);
}

float determinate(mat3x3 mat) {
    return ( mat.x.x * mat.y.y * mat.z.z
             - mat.x.x * mat.y.z * mat.z.y

             - mat.x.y * mat.y.x * mat.z.z
             + mat.x.y * mat.y.z * mat.z.x

             + mat.x.z * mat.y.x * mat.z.y
             - mat.x.z * mat.y.y * mat.z.x);
}


mat3x3 inverse(mat3x3 mat) {
    return mat3x3( mat.y.y * mat.z.z - mat.y.z * mat.z.y, //xx
                   -mat.x.y * mat.z.z + mat.x.z * mat.z.y, //xy
                   mat.x.y * mat.y.z - mat.x.z * mat.y.y, //xz
                   -mat.y.x * mat.z.z + mat.y.z * mat.z.x, //yx
                   mat.x.x * mat.z.z - mat.x.z * mat.z.x, //yy
                   -mat.x.x * mat.y.z + mat.x.z * mat.y.x, //yz
                   mat.y.x * mat.z.y - mat.y.y * mat.z.x, //zx
                   -mat.x.x * mat.z.y + mat.x.y * mat.z.x, //zy
                   mat.x.x * mat.y.y - mat.x.y * mat.y.x //zz
                 ) / determinate(mat);
}


vec3 operator * (const mat3x3 m, const vec3 vin) {
    return vec3(m.x.x * vin.x + m.x.y * vin.y + m.x.z * vin.z,
                m.y.x * vin.x + m.y.y * vin.y + m.y.z * vin.z,
                m.z.x * vin.x + m.z.y * vin.y + m.z.z * vin.z);
}

vec3 operator * (const vec3 vin, const mat3x3 m) {
    return vec3(m.x.x * vin.x + m.x.y * vin.y + m.x.z * vin.z,
                m.y.x * vin.x + m.y.y * vin.y + m.y.z * vin.z,
                m.z.x * vin.x + m.z.y * vin.y + m.z.z * vin.z);
}

mat3x3 operator * (const mat3x3 m, const mat3x3 m2) {
    return mat3x3(
               m.x.x * m2.x.x + m.x.y * m2.y.x + m.x.z * m2.z.x,
               m.x.x * m2.x.y + m.x.y * m2.y.y + m.x.z * m2.z.y,
               m.x.x * m2.x.z + m.x.y * m2.y.z + m.x.z * m2.z.z,

               m.y.x * m2.x.x + m.y.y * m2.y.x + m.y.z * m2.z.x,
               m.y.x * m2.x.y + m.y.y * m2.y.y + m.y.z * m2.z.y,
               m.y.x * m2.x.z + m.y.y * m2.y.z + m.y.z * m2.z.z,

               m.z.x * m2.x.x + m.z.y * m2.y.x + m.z.z * m2.z.x,
               m.z.x * m2.x.y + m.z.y * m2.y.y + m.z.z * m2.z.y,
               m.z.x * m2.x.z + m.z.y * m2.y.z + m.z.z * m2.z.z
           );
}


//mat4 op
mat4x4 transpose(mat4x4 mat) {
    return mat4x4(mat.x.x, mat.y.x, mat.z.x, mat.w.x,
                  mat.x.y, mat.y.y, mat.z.y, mat.w.y,
                  mat.x.z, mat.y.z, mat.z.z, mat.w.z,
                  mat.x.w, mat.y.w, mat.z.w, mat.w.w);
}

float determinate(mat4x4 mat) {
    return (+mat.x.x * mat.y.y * mat.z.z * mat.w.w + mat.x.x * mat.y.z * mat.z.w * mat.w.y + mat.x.x * mat.y.w * mat.z.y * mat.w.z
            + mat.x.y * mat.y.x * mat.z.w * mat.w.z + mat.x.y * mat.y.z * mat.z.x * mat.w.w + mat.x.y * mat.y.w * mat.z.z * mat.w.x
            + mat.x.z * mat.y.x * mat.z.y * mat.w.w + mat.x.z * mat.y.y * mat.z.w * mat.w.x + mat.x.z * mat.y.w * mat.z.x * mat.w.y
            + mat.x.w * mat.y.x * mat.z.z * mat.w.y + mat.x.w * mat.y.y * mat.z.x * mat.w.z + mat.x.w * mat.y.z * mat.z.y * mat.w.x
            - mat.x.x * mat.y.y * mat.z.w * mat.w.z - mat.x.x * mat.y.z * mat.z.y * mat.w.w - mat.x.x * mat.y.w * mat.z.z * mat.w.y
            - mat.x.y * mat.y.x * mat.z.z * mat.w.w - mat.x.y * mat.y.z * mat.z.w * mat.w.x - mat.x.y * mat.y.w * mat.z.x * mat.w.z
            - mat.x.z * mat.y.x * mat.z.w * mat.w.y - mat.x.z * mat.y.y * mat.z.x * mat.w.w - mat.x.z * mat.y.w * mat.z.y * mat.w.x
            - mat.x.w * mat.y.x * mat.z.y * mat.w.z - mat.x.w * mat.y.y * mat.z.z * mat.w.x - mat.x.w * mat.y.z * mat.z.x * mat.w.y);
}


//Im sorry, this was the only way,
mat4x4 inverse(mat4x4 mat) {
    float det = determinate(mat);

    return mat4x4(
               (mat.y.y * mat.z.z * mat.w.w + mat.y.z * mat.z.w * mat.w.y + mat.y.w * mat.z.y * mat.w.z
                - mat.y.y * mat.z.w * mat.w.z - mat.y.z * mat.z.y * mat.w.w - mat.y.w * mat.z.z * mat.w.y) / det,
               (mat.x.y * mat.z.w * mat.w.z + mat.x.z * mat.z.y * mat.w.w + mat.x.w * mat.z.z * mat.w.y
                - mat.x.y * mat.z.z * mat.w.w - mat.x.z * mat.z.w * mat.w.y - mat.x.w * mat.z.y * mat.w.z) / det,
               (mat.x.y * mat.y.z * mat.w.w + mat.x.z * mat.y.w * mat.w.y + mat.x.w * mat.y.y * mat.w.z
                - mat.x.y * mat.y.w * mat.w.z - mat.x.z * mat.y.y * mat.w.w - mat.x.w * mat.y.z * mat.w.y) / det,
               (mat.x.y * mat.y.w * mat.z.z + mat.x.z * mat.y.y * mat.z.w + mat.x.w * mat.y.z * mat.z.y
                - mat.x.y * mat.y.z * mat.z.w - mat.x.z * mat.y.w * mat.z.y - mat.x.w * mat.y.y * mat.z.z) / det,
               (mat.y.x * mat.z.w * mat.w.z + mat.y.z * mat.z.x * mat.w.w + mat.y.w * mat.z.z * mat.w.x
                - mat.y.x * mat.z.z * mat.w.w - mat.y.z * mat.z.w * mat.w.x - mat.y.w * mat.z.x * mat.w.z) / det,
               (mat.x.x * mat.z.z * mat.w.w + mat.x.z * mat.z.w * mat.w.x + mat.x.w * mat.z.x * mat.w.z
                - mat.x.x * mat.z.w * mat.w.z - mat.x.z * mat.z.x * mat.w.w - mat.x.w * mat.z.z * mat.w.x) / det,
               (mat.x.x * mat.y.w * mat.w.z + mat.x.z * mat.y.x * mat.w.w + mat.x.w * mat.y.z * mat.w.x
                - mat.x.x * mat.y.z * mat.w.w - mat.x.z * mat.y.w * mat.w.x - mat.x.w * mat.y.x * mat.w.z) / det,
               (mat.x.x * mat.y.z * mat.z.w + mat.x.z * mat.y.w * mat.z.x + mat.x.w * mat.y.x * mat.z.z
                - mat.x.x * mat.y.w * mat.z.z - mat.x.z * mat.y.x * mat.z.w - mat.x.w * mat.y.z * mat.z.x) / det,
               (mat.y.x * mat.z.y * mat.w.w + mat.y.y * mat.z.w * mat.w.x + mat.y.w * mat.z.x * mat.w.y
                - mat.y.x * mat.z.w * mat.w.y - mat.y.y * mat.z.x * mat.w.w - mat.y.w * mat.z.y * mat.w.x) / det,
               (mat.x.x * mat.z.w * mat.w.y + mat.x.y * mat.z.x * mat.w.w + mat.x.w * mat.z.y * mat.w.x
                - mat.x.x * mat.z.y * mat.w.w - mat.x.y * mat.z.w * mat.w.x - mat.x.w * mat.z.x * mat.w.y) / det,
               (mat.x.x * mat.y.y * mat.w.w + mat.x.y * mat.y.w * mat.w.x + mat.x.w * mat.y.x * mat.w.y
                - mat.x.x * mat.y.w * mat.w.y - mat.x.y * mat.y.x * mat.w.w - mat.x.w * mat.y.y * mat.w.x) / det,
               (mat.x.x * mat.y.w * mat.z.y + mat.x.y * mat.y.x * mat.z.w + mat.x.w * mat.y.y * mat.z.x
                - mat.x.x * mat.y.y * mat.z.w - mat.x.y * mat.y.w * mat.z.x - mat.x.w * mat.y.x * mat.z.y) / det,
               (mat.y.x * mat.z.z * mat.w.y + mat.y.y * mat.z.x * mat.w.z + mat.y.z * mat.z.y * mat.w.x
                - mat.y.x * mat.z.y * mat.w.z - mat.y.y * mat.z.z * mat.w.x - mat.y.z * mat.z.x * mat.w.y) / det,
               (mat.x.x * mat.z.y * mat.w.z + mat.x.y * mat.z.z * mat.w.x + mat.x.z * mat.z.x * mat.w.y
                - mat.x.x * mat.z.z * mat.w.y - mat.x.y * mat.z.x * mat.w.z - mat.x.z * mat.z.y * mat.w.x) / det,
               (mat.x.x * mat.y.z * mat.w.y + mat.x.y * mat.y.x * mat.w.z + mat.x.z * mat.y.y * mat.w.x
                - mat.x.x * mat.y.y * mat.w.z - mat.x.y * mat.y.z * mat.w.x - mat.x.z * mat.y.x * mat.w.y) / det,
               (mat.x.x * mat.y.y * mat.z.z + mat.x.y * mat.y.z * mat.z.x + mat.x.z * mat.y.x * mat.z.y
                - mat.x.x * mat.y.z * mat.z.y - mat.x.y * mat.y.x * mat.z.z - mat.x.z * mat.y.y * mat.z.x) / det);
}


mat4x4 operator/ (const mat4x4 mat, float divisor) {
    return mat4x4(mat.x / divisor, mat.y / divisor, mat.z / divisor, mat.w / divisor);
}

mat4x4 operator * (const mat4x4 m, const float scalar) {
    return mat4x4(m.x.x * scalar, m.x.y * scalar, m.x.z * scalar, m.x.w * scalar,
                  m.y.x * scalar, m.y.y * scalar, m.y.z * scalar, m.y.w * scalar,
                  m.z.x * scalar, m.z.y * scalar, m.z.z * scalar, m.z.w * scalar,
                  m.w.x * scalar, m.w.y * scalar, m.w.z * scalar, m.w.w * scalar);
}

mat4x4 operator * (const float scalar, const mat4x4 m) {
    return mat4x4(m.x.x * scalar, m.x.y * scalar, m.x.z * scalar, m.x.w * scalar,
                  m.y.x * scalar, m.y.y * scalar, m.y.z * scalar, m.y.w * scalar,
                  m.z.x * scalar, m.z.y * scalar, m.z.z * scalar, m.z.w * scalar,
                  m.w.x * scalar, m.w.y * scalar, m.w.z * scalar, m.w.w * scalar);
}

vec4 operator * (const mat4x4 m, const vec4 vin) {
    return vec4(m.x.x * vin.x + m.x.y * vin.y + m.x.z * vin.z + m.x.w * vin.w,
                m.y.x * vin.x + m.y.y * vin.y + m.y.z * vin.z + m.y.w * vin.w,
                m.z.x * vin.x + m.z.y * vin.y + m.z.z * vin.z + m.z.w * vin.w,
                m.w.x * vin.x + m.w.y * vin.y + m.w.z * vin.z + m.w.w * vin.w);
}


//this is both ethically  & mathematically wrong...does the same as above
vec4 operator * (const vec4 vin, const mat4x4 m) {
    return vec4(m.x.x * vin.x + m.x.y * vin.y + m.x.z * vin.z + m.x.w * vin.w,
                m.y.x * vin.x + m.y.y * vin.y + m.y.z * vin.z + m.y.w * vin.w,
                m.z.x * vin.x + m.z.y * vin.y + m.z.z * vin.z + m.z.w * vin.w,
                m.w.x * vin.x + m.w.y * vin.y + m.w.z * vin.z + m.w.w * vin.w);
}

mat4x4 operator * (const mat4x4 m, const mat4x4 m2) {
    return mat4x4(m.x.x * m2.x.x + m.x.y * m2.y.x + m.x.z * m2.z.x + m.x.w * m2.w.x,
                  m.x.x * m2.x.y + m.x.y * m2.y.y + m.x.z * m2.z.y + m.x.w * m2.w.y,
                  m.x.x * m2.x.z + m.x.y * m2.y.z + m.x.z * m2.z.z + m.x.w * m2.w.z,
                  m.x.x * m2.x.w + m.x.y * m2.y.w + m.x.z * m2.z.w + m.x.w * m2.w.w,

                  m.y.x * m2.x.x + m.y.y * m2.y.x + m.y.z * m2.z.x + m.y.w * m2.w.x,
                  m.y.x * m2.x.y + m.y.y * m2.y.y + m.y.z * m2.z.y + m.y.w * m2.w.y,
                  m.y.x * m2.x.z + m.y.y * m2.y.z + m.y.z * m2.z.z + m.y.w * m2.w.z,
                  m.y.x * m2.x.w + m.y.y * m2.y.w + m.y.z * m2.z.w + m.y.w * m2.w.w,

                  m.z.x * m2.x.x + m.z.y * m2.y.x + m.z.z * m2.z.x + m.z.w * m2.w.x,
                  m.z.x * m2.x.y + m.z.y * m2.y.y + m.z.z * m2.z.y + m.z.w * m2.w.y,
                  m.z.x * m2.x.z + m.z.y * m2.y.z + m.z.z * m2.z.z + m.z.w * m2.w.z,
                  m.z.x * m2.x.w + m.z.y * m2.y.w + m.z.z * m2.z.w + m.z.w * m2.w.w,

                  m.w.x * m2.x.x + m.w.y * m2.y.x + m.w.z * m2.z.x + m.w.w * m2.w.x,
                  m.w.x * m2.x.y + m.w.y * m2.y.y + m.w.z * m2.z.y + m.w.w * m2.w.y,
                  m.w.x * m2.x.z + m.w.y * m2.y.z + m.w.z * m2.z.z + m.w.w * m2.w.z,
                  m.w.x * m2.x.w + m.w.y * m2.y.w + m.w.z * m2.z.w + m.w.w * m2.w.w);
}


mat4x4 operator + (const mat4x4 m, const mat4x4 m2) {
    return mat4x4(m.x + m2.x, m.y + m2.y, m.z + m2.z, vec4(0, 0, 0, 1));
}

//outputs
std::ostream& operator << (std::ostream& os, const mat2x2 m) {
    os << std::right  << std::setw(3) << m.x.x << " ";
    os << std::right << std::setw(3) << m.x.y << std::endl;

    os << std::right  << std::setw(3) << m.y.x << " ";
    os << std::right << std::setw(3) << m.y.y;
    return os;
}

std::ostream& operator << (std::ostream& os, const mat3x3 m) {
    os << std::right  << std::setw(3) << m.x.x << " ";
    os << std::right << std::setw(3) << m.x.y << " ";
    os << std::right << std::setw(3) << m.x.z << std::endl;

    os << std::right  << std::setw(3) << m.y.x << " ";
    os << std::right << std::setw(3) << m.y.y << " ";
    os << std::right << std::setw(3) << m.y.z << std::endl;

    os << std::right  << std::setw(3) << m.z.x << " ";
    os << std::right << std::setw(3) << m.z.y << " ";
    os << std::right << std::setw(3) << m.z.z << std::endl;
    return os;
}


std::ostream& operator << (std::ostream& os, const mat4x4 m) {
    os << std::right << std::setfill('0') << std::setprecision(2)  << std::setw(3) << m.x.x << " ";
    os << std::right << std::setfill('0') << std::setprecision(2)  << std::setw(3) << m.x.y << " ";
    os << std::right << std::setfill('0') << std::setprecision(2)  << std::setw(3) << m.x.z << " ";
    os << std::right << std::setfill('0') << std::setprecision(2)  << std::setw(3) << m.x.w << std::endl;
    os << std::right << std::setfill('0') << std::setprecision(2)  << std::setw(3) << m.y.x << " ";
    os << std::right << std::setfill('0') << std::setprecision(2) << std::setw(3) << m.y.y << " ";
    os << std::right << std::setfill('0') << std::setprecision(2) << std::setw(3) << m.y.z << " ";
    os << std::right << std::setfill('0') << std::setprecision(2) << std::setw(3) << m.y.w << std::endl;
    os << std::right << std::setfill('0') << std::setprecision(2)  << std::setw(3) << m.z.x << " ";
    os << std::right << std::setfill('0') << std::setprecision(2) << std::setw(3) << m.z.y << " ";
    os << std::right << std::setfill('0') << std::setprecision(2) << std::setw(3) << m.z.z << " ";
    os << std::right << std::setfill('0') << std::setprecision(2) << std::setw(3) << m.z.w << std::endl;
    os << std::right << std::setfill('0') << std::setprecision(2)  << std::setw(3) << m.w.x << " ";
    os << std::right << std::setfill('0') << std::setprecision(2) << std::setw(3) << m.w.y << " ";
    os << std::right << std::setfill('0') << std::setprecision(2) << std::setw(3) << m.w.z << " ";
    os << std::right << std::setfill('0') << std::setprecision(2) << std::setw(3) << m.w.w;

    return os;
}

std::ostream& operator << (std::ostream& os, const vec2 vin) {
    os << "(" << vin.x << "|" << vin.y << ")";
    return os;
}

std::ostream& operator << (std::ostream& os, const vec3 vin) {
    os << "(" << vin.x << "|" << vin.y << "|" << vin.z << ")";
    return os;
}

std::ostream& operator << (std::ostream& os, const vec4 vin) {
    os << "(" << vin.x << "|" << vin.y << "|" <<  vin.z << "|" << vin.w << ")";
    return os;
}
