#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <iostream>

void RunOpenGLBoilerplate()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int main()
{
    glfwInit();
    RunOpenGLBoilerplate();

    // Create an OpenGL Window Object
    GLFWwindow *window = glfwCreateWindow(800, 600, "Window Test", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to Create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the newly created Window the current context.
    glfwMakeContextCurrent(window);

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set the window size
    glViewport(0, 0, 800, 600);

    // Register framebuffer_size_callback as a callback function when the window changes size.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // OpenGL Render Loop
    while (!glfwWindowShouldClose(window))
    {
        // Input
        processInput(window);

        // Render Stuff
        glClearColor(0.5f, 0.3f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Check and Call Events and Swap the buffers
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // Program is ready to end, clean up GLFW resources.
    glfwTerminate();
    return 0;
}