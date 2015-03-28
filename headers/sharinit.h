#ifndef _SHA_DER_
#define _SHA_DER_

#include "../../GL/glew.h"
#include "../../GLFW/glfw3.h"

char* shareadfile(const char *filename);
GLuint shamkshader(GLenum type, const char *filename);
GLuint shamkprogram(GLuint vertexShader, GLuint fragmentShader);
GLFWwindow* shainitwindow(int height, int width, char *title);

#endif
