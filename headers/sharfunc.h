#ifndef SHARFUN_H
#define SHARFUN_H

#include "shar.h"

SH_API mat4 sharotatez(const float angle); //rotate around z
SH_API mat4 sharotatey(const float angle); //rotate around y
SH_API mat4 sharotatex(const float angle); //rotate around x
SH_API mat4 sharotateav(float a, vec4 axis); // rotate around a given axis
SH_API mat4 shatranslate(float x, float y, float z); // translate 
SH_API mat4 shatranslate(vec3 v);
SH_API mat4 shatranslate(vec4 v);
SH_API mat4 shascale(float x, float y, float z); //scale

//camera function 
SH_API mat4 shalookat(vec4 eye, vec4 at, vec4 up);

//projections
SH_API mat4 shaortho(float left, float right, float top, float bottom, float pnear, float pfar);
SH_API mat4 shaoblique(float theta, float phi);
SH_API mat4 shafrustum(float lleft, float lright, float top, float bottom, float near, float far);
SH_API mat4 shaperspective(float fov, float aspect, float near, float far);
#endif // SHARFUN_H
