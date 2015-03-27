##ifndef SHARFUN_H
#define SHARFUN_H

#include "shar.h"

mat4 sharotatez(const float angle); //rotate around z
mat4 sharotatey(const float angle); //rotate around y
mat4 sharotatex(const float angle); //rotate around x
mat4 sharotateav(float a, vec4 axis); // rotate around a given axis

mat4 shatranslate(float x, float y, float z); // translate 
mat4 shatranslate(vec3 v);
mat4 shatranslate(vec4 v);

mat4 shascale(float x, float y, float z); //scale

//camera function 
mat4 shalookat(vec4 eye, vec4 at, vec4 up);

//projections
mat4 shaortho(float left, float right, float top, float bottom, float pnear, float pfar);
mat4 shaoblique(float theta, float phi);

mat4 shafrustum(float lleft, float lright, float top, float bottom, float near, float far);
mat4 shaperspective(float fov, float aspect, float near, float far);


void shatriangle(point2 *buffer, int &current_index, point2 a, point2 b, point2 c);
void shatriangle(point3 *buffer, int &current_index, point3 a, point3 b, point3 c);
void shatriangle(point4 *buffer, int &current_index, point4 a, point4 b, point4 c);

void shatrianglediv(point2 *buffer, int &current_index,
                    point2 a, point2 b, point2 c,
                    int numdiv, bool random = false);

void shatertradiv(point3 *buffer, point3 *color_buffer, point3 base_color[4],
                  int &cur_index, int &color_index, point3 a, point3 b,
                  point3 c, point3 d, int num, bool rdm = false);

void shatertradiv(point4 *buffer, point4 *color_buffer, point4 base_color[4],
                  int &cur_index, int &color_index,
                  point4 a, point4 b, point4 c, point4 d,
                  int num, bool rdm = false);

#endif // SHARFUN_H
