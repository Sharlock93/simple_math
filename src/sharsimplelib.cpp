#include "../headers/sharsimplelib.h"
#include "../../GL/glew.h"
#include "../../GLFW/glfw3.h"


void shWritePixel(GLfloat x, GLfloat y) {
    v_buff_x[V_BUFF_INDEX] = (2*x)/windoWidth - 1;
    v_buff_y[V_BUFF_INDEX] = -2*y/windowHeight + 1;
    ++V_BUFF_INDEX;

    glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat)*(V_BUFF_INDEX-1)*2, sizeof(GLfloat), &v_buff_x[V_BUFF_INDEX-1]);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat)+sizeof(GLfloat)*(V_BUFF_INDEX-1)*2, sizeof(GLfloat),
            &v_buff_y[V_BUFF_INDEX-1]);

    // cout << V_BUFF_INDEX << " " << (2*x)/windoWidth - 1 << " " << -2*y/windowHeight + 1 << endl;
    shSendData = GL_TRUE;
}

void shRender(shWindow *window) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ACCUM_BUFFER_BIT);

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    glDrawArrays(GL_POINTS, 0, V_BUFF_INDEX);
    glfwSwapBuffers(window);
    glfwPollEvents();
}


shWindow* shMakeWindow(int width, int height, char *title) {
    glfwInit();

    windowHeight = height;
    windoWidth = width;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    shWindow *window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    glewInit();

    return window;
}

void shInit() {
    const GLchar *vertexSource =
    "#version 430 core \n"
    "in vec4 vpos;"
    "void main() { gl_Position = vpos; }";

    const GLchar *fragmentSource =
    "#version 430 core \n"
    "out vec4 fcolor;"
    "void main() { fcolor = vec4(1.0, 1.0, 1.0, 1.0); }";

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v_buff_x) + sizeof(v_buff_y), nullptr, GL_STATIC_DRAW);

    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex, 1, &vertexSource, NULL);
    glShaderSource(fragment, 1, &fragmentSource, NULL);

    glCompileShader(vertex);
    glCompileShader(fragment);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);

    glLinkProgram(program);

    GLint vpos = glGetAttribLocation(program, "vpos");
    glVertexAttribPointer(vpos, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vpos);

    glUseProgram(program);
}


