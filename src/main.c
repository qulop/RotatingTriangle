#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>

#include <glad/glad.h>
// #define GLFW_INCLUDE_NONE
#include <glfw/include/GLFW/glfw3.h>

#define NEW_LINE                    printf("\n");

struct WindowProps
{
    int width;
    int height;
    char* name;

    uint8_t isResizable;
};


GLFWwindow* createWindow(struct WindowProps sizes)
{
    if (!glfwInit())
        fprintf_s(stderr, "Failed to init GLFW. Line: %d\n", __LINE__);

    GLFWwindow* window = glfwCreateWindow(sizes.width, sizes.height, sizes.name, NULL, NULL);
    if (!window)
        fprintf_s(stderr, "Failed to init window. Line: %d\n", __LINE__);

    glfwMakeContextCurrent(window);
  
    return window;
}




int main(int argc, char** argv)
{
    struct WindowProps sizes = { 600, 600, "RotatingTriangle", 0 };

    GLFWwindow* window = createWindow(sizes);

    if (!gladLoadGL())
        fprintf_s(stderr, "Failed to load OpenGL. Line: %d\n", __LINE__);

    printf_s("Ver: %d\n", GLVersion.major);


    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }
    
        
}