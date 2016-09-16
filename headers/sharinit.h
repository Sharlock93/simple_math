// #define GLEW_STATIC
#ifndef _SHA_DER_
#define _SHA_DER_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

__declspec(dllexport) char* shareadfile(const char *filename);
__declspec(dllexport) GLuint shamkshader(GLenum type, const char *filename);
__declspec(dllexport) GLuint shamkprogram(GLuint vertexShader, GLuint fragmentShader);
__declspec(dllexport) GLFWwindow* shainitwindow(int height, int width, char *title);

#endif
