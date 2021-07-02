#include <GLFW/glfw3.h>
#include <GL/glu.h>

#include <iostream>
#include <sstream>

extern void draw(int, int);

std::stringstream move;

static void error(int code, const char *description)
{
    std::cerr << "\e[3;31;1mError: \e[0m" << description << std::endl;
    glfwTerminate();
    exit(code);
}

static void key(GLFWwindow *window, int key, int scancode, int action, int modes)
{
    // TODO
    std::cout << move.str().size() << ", " << move.str() << std::endl;
    if (move.str().size() < 4 /* && action == GLFW_RELEASE */) {
        if (key == GLFW_KEY_A) move << 'a';
        else if (key == GLFW_KEY_B) move << 'b';
        else if (key == GLFW_KEY_C) move << 'c';
        else if (key == GLFW_KEY_D) move << 'd';
        else if (key == GLFW_KEY_E) move << 'e';
        else if (key == GLFW_KEY_F) move << 'f';
        else if (key == GLFW_KEY_G) move << 'g';
        else if (key == GLFW_KEY_H) move << 'h';
        else if (key == GLFW_KEY_1) move << '1';
        else if (key == GLFW_KEY_2) move << '2';
        else if (key == GLFW_KEY_3) move << '3';
        else if (key == GLFW_KEY_4) move << '4';
        else if (key == GLFW_KEY_5) move << '5';
        else if (key == GLFW_KEY_6) move << '6';
        else if (key == GLFW_KEY_7) move << '7';
        else if (key == GLFW_KEY_8) move << '8';
    } else {
        move.clear();
        /* TODO */
    }
}

static void warning(const char *description)
{
    std::cout << "\e[3;33;Warning: \e[0m" << description << std::endl;
}

int main(int argc, char const *argv[])
{
    if (!glfwInit()) error(1, "Failed to initialise GLFW (glfwInit())");
    GLFWwindow *window = glfwCreateWindow(1000, 1000, "Chess", nullptr, nullptr);

    glfwSetErrorCallback(error);
    glfwSetKeyCallback(window, key);
    glfwMakeContextCurrent(window);

    gluOrtho2D(0, 80, 80, 0);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    while (!glfwWindowShouldClose(window)) {
        glfwGetWindowSize(window, &width, &height);
        glViewport(0, 0, width, height);

        draw(width, height);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    

    return 0;
}

