#include <cmath>

#include <iostream>
#include <glad.h>
#include <GLFW/glfw3.h>
#include <Shader.h>
#include <Object.h>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
GLFWwindow* initWindow()
{
    //Setup window and context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return window;
}
char* read_shader(const char* path)
{
    std::ifstream is(path,std::ifstream::binary);
    if(!is)
        return nullptr;
    is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);
    char* buffer = new char[length + 1];
    is.read(buffer,length);
    buffer[length] = '\0';
    return buffer;
}
int main()
{
    //INIT
    glfwInit();
    GLFWwindow* window = initWindow();
    char* vertexShaderSource = read_shader("shaders/vert.glsl");
    char* fragmentShaderSource = read_shader("shaders/frag.glsl");
    Shader* shader = new Shader(vertexShaderSource, fragmentShaderSource);

//    float vertices[] = {
//            0.5f,  0.5f, 0.0f,  // top right
//            0.5f, -0.5f, 0.0f,  // bottom right
//            -0.5f, -0.5f, 0.0f,  // bottom left
//            -0.5f,  0.5f, 0.0f   // top left
//    };
//    unsigned int indices[] = {  // note that we start from 0!
//            0, 1, 3,   // first triangle
//            1, 2, 3    // second triangle
//    };
    float oneOverSqrt2 = 1.0f/sqrt(2);
    float vertices[] = {
            1.0f,  0.5f, -oneOverSqrt2, 1.0f,0.0f,0.0f,
            -1.0f, -0.5f, -oneOverSqrt2,1.0f,0.0f,0.0f,
            0.0f, 1.0f, oneOverSqrt2,1.0f,0.0f,0.0f,

            1.0f,  0.5f, -oneOverSqrt2,0.0f,1.0f,0.0f,
            -1.0f, -0.5f, -oneOverSqrt2,0.0f,1.0f,0.0f,
            0.0f,  -1.0f, oneOverSqrt2,0.0f,1.0f,0.0f,

            1.0f,  0.5f, -oneOverSqrt2,0.0f,0.0f,1.0f,
            0.0f, 1.0f, oneOverSqrt2,0.0f,0.0f,1.0f,
            0.0f,  -1.0f, oneOverSqrt2,0.0f,0.0f,1.0f,

            -1.0f, -0.5f, -oneOverSqrt2,0.0f,0.0f,0.0f,
            0.0f, 1.0f, oneOverSqrt2,0.0f,0.0f,0.0f,
            0.0f,  -1.0f, oneOverSqrt2,0.0f,0.0f,0.0f
    };
    unsigned int indices[] = {  // note that we start from 0!
            0, 1, 2,   // first triangle
            3, 4, 5,    // second triangle
            6,7,8,
            9,10,11
    };
    Object* object1 = new Object(vertices,72,indices,12);

    shader->use();

    glm::mat4 view = glm::mat4(1.0f);
// note that we're translating the scene in the reverse direction of where we want to move
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    int projectionLoc = glGetUniformLocation(shader->ID, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader->use();
        float timeValue = glfwGetTime();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::scale(model,glm::vec3(0.5));
        model = glm::rotate(model, glm::radians(-55.0f*timeValue), glm::vec3(1.0f/sqrt(3)));

        int modelLoc = glGetUniformLocation(shader->ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        int viewLoc = glGetUniformLocation(shader->ID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        object1->use();
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    delete object1;
    delete shader;
    glfwTerminate();
    return 0;
}
