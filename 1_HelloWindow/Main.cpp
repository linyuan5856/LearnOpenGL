#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>


using namespace std;

const int ScreenWidth = 800;
const int ScreenHeight = 600;

int InitGLFW(void);

void framebuff_size_callback(GLFWwindow*, int width, int height);

void ProcessInput(GLFWwindow*window)
{
	if (glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window,GLFW_TRUE);
	}
}

void framebuff_size_callback(GLFWwindow*, int width, int height)
{
	glViewport(0, 0, width, height);
}

int InitGLFW(void)
{

	if (glfwInit() == -1)
	{
		cout << "Error Init GLFW Failed" << endl;
		return -1;
	};

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_VERSION_MAJOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	GLFWwindow*window = glfwCreateWindow(ScreenWidth, ScreenHeight, "StudyOpenGL", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to Creat GLFW WINDOW" << endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to Init GLAD" << endl;
		return -1;
	}

	glViewport(0, 0, ScreenWidth, ScreenHeight);

	glfwSetFramebufferSizeCallback(window, framebuff_size_callback);

	while(!glfwWindowShouldClose(window))
	{
		ProcessInput(window);
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwTerminate();

	return 0;
}


int main()
{
	int state = InitGLFW();

	return state;
}