#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <iostream>

#define WIDTH 800
#define HEIGHT 800

// vertex data of the rectangle
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f,
    0.5f, 0.5f, 0.0f};

float indices[] = {
    0, 1, 2,
    2, 3, 0};

int main()
{
    // initialize glfw
    glfwInit();

    // setting up opengl version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // setting up opengl profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // creating window
    GLFWwindow *my_window = glfwCreateWindow(WIDTH, HEIGHT, "hello triangle", NULL, NULL);
    if (my_window == NULL)
    {
        std::cout << "failed to create window" << std::endl;
        glfwTerminate();
    }

    // bind the window with opengl context
    glfwMakeContextCurrent(my_window);

    // initialize glew
    if (glewInit() != GLEW_OK)
    {
        std::cout << "failed to initialze GLEW" << std::endl;
        glfwTerminate();
    }

    // configure VBOs and VAOs
    GLuint VBO, VAO, EBO;

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // indexing the vertex data
    glEnableVertexAttribArray(0);

    // game loop
    while (!glfwWindowShouldClose(my_window))
    {
        // update

        // render
        glClearColor(0.2f, 0.1f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw
        glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // display
        glfwSwapBuffers(my_window);

        // pollevents
        glfwPollEvents();
    }

    // clear the mess
    glfwDestroyWindow(my_window);
    glfwTerminate();
    return 0;
}