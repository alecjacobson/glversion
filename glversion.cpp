#include <GLFW/glfw3.h>
#include <iostream>

int main(int argc, char *argv[])
{
  using namespace std;
  if(!glfwInit())
  {
     cerr<<"Could not initialize glfw"<<endl;
     return EXIT_FAILURE;
  }
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  // Use background window
  glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
  GLFWwindow* window = glfwCreateWindow(640, 480, "WebGL", NULL, NULL);
  if(!window)
  {
    glfwTerminate();
    cerr<<"Could not create glfw window"<<endl;
    return EXIT_FAILURE;
  }
  glfwMakeContextCurrent(window);
  int major, minor, rev;
  major = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MAJOR);
  minor = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MINOR);
  rev = glfwGetWindowAttrib(window, GLFW_CONTEXT_REVISION);
  printf("OpenGL version           %d.%d.%d\n", major, minor, rev);
  printf("Supported OpenGL is      %s\n", (const char*)glGetString(GL_VERSION));
  printf("Supported GLSL is        %s\n", (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
}

