#ifndef _SHAR_SIMP_LIB_
#define _SHAR_SIMP_LIB_

#include "../../GL/glew.h"
#include "../../GLFW/glfw3.h"


const GLint SIZE_OF_VIRTUAL_BUFF = 1000; // 512 for x and 512 for y
GLfloat v_buff_x[SIZE_OF_VIRTUAL_BUFF];
GLfloat v_buff_y[SIZE_OF_VIRTUAL_BUFF];
GLint   V_BUFF_INDEX = 0;
GLboolean shSendData = GL_TRUE;
GLint windoWidth = 0;
GLint windowHeight = 0;

typedef GLFWwindow shWindow;


void shWritePixel(GLfloat x, GLfloat y);
void shRender(shWindow *window);
shWindow* shMakeWindow(int width, int height, char *title);
void shInit();

#endif
