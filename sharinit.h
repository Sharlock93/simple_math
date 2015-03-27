#ifndef _SHA_DER_
#define _SHA_DER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#ifndef __glew_h__
#include <GL\glew.h>
#endif

//====================================================================================
//read a file into a buffer and return it for making a shader

char* shareadfile(const char *filename) {
    FILE *tempfile = fopen(filename, "rb");
    if(tempfile == NULL) {
        printf("Error opening file %s : ", filename);
        perror("");
        exit(EXIT_FAILURE);
    } else {
        fseek(tempfile, 0, SEEK_END);
        long size_of_file = ftell(tempfile);
        cout << size_of_file << endl;
        char *ret = new char[size_of_file+1];
        rewind(tempfile);
        fread(ret, 1, size_of_file, tempfile);
        ret[size_of_file] = '\0';
        fclose(tempfile);

        return ret;
    }

    return NULL;
}
//====================================================================================

//====================================================================================
//return a shader with the source (filename) and type (type)

GLuint shamkshader(GLenum type, const char *filename) {
    const GLchar *shaderSource = shareadfile(filename);

    if(shaderSource == NULL) {
        exit(EXIT_FAILURE);
    }

    GLuint shader = glCreateShader(type);

    if(shader == 0) {
        printf("%s\n", "Error making shader");
        exit(EXIT_FAILURE);
    }

    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    GLint compiletest;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiletest);


    if( compiletest != GL_TRUE) {
        printf("Error compiling Shader file: %s\n", filename);

        GLint logsize;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logsize);//getting the size of log

        char *infolog = new char[logsize];
        glGetShaderInfoLog(shader, logsize, NULL, infolog);
        printf("%s", infolog);//print log

        delete[] infolog;//delete log
        delete[] shaderSource;
        exit(EXIT_FAILURE);
    }//if error occurred when compiling the shader

    return shader;
}
//====================================================================================

//====================================================================================
//make a program from the shaders given

GLuint shamkprogram(GLuint vertexShader, GLuint fragmentShader) {
    GLuint program = glCreateProgram();

    if(program == 0) {
        printf("Error creating program\n");
        exit(EXIT_FAILURE);
    }

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    GLint compiletest;
    glGetProgramiv(program, GL_LINK_STATUS, &compiletest);

    if(compiletest != GL_TRUE) {
        printf("Error Linking the program.\n");

        GLint log_size = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_size);

        GLchar *log_info = new GLchar[log_size];
        glGetProgramInfoLog(program, log_size, NULL, log_info);

        printf("%s", log_info);

        delete[] log_info;
    }

    return program;
}

//====================================================================

//====================================================================
//initiate a window from opengl and return it.

GLFWwindow* shainitwindow(int height, int width, char *title) {
    if(glfwInit() == 0) {
        cout << "glfwInit() error" << endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(height, width, title, nullptr, nullptr);

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK) {
        cout << "glewInit() error " << endl;
        exit(EXIT_FAILURE);
    }

    return window;
}

// int main() {
//     char *test = shareadfile("test.txt");
//     printf("%s", test);
//     return 0;
// }

#endif
