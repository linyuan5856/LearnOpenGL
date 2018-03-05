#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>
#include "../3_Shaders/Shader.h"

using namespace std;

const int ScreenWidth = 800;
const int ScreenHeight = 600;

float Trianglevertices[] =
{
	//位置              //颜色
	.5f,.5f,0.0f,      1.0f,0.0f,0.0f,
	.5f,-.5f,0.0f,     0.0f,1.0f,0.0f,
	-0.5f,-0.5f,0.0f,  0.0f,0.0f,1.0f,
	-0.5f,0.5f,0.0f,   0.5f,0.5f,0.5f
};

unsigned int indices[] =
{
	0,1,3,
	1,2,3
};

void framebuff_size_callback(GLFWwindow*, int width, int height);

void ProcessInput(GLFWwindow*);



void ProcessInput(GLFWwindow*window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void framebuff_size_callback(GLFWwindow*, int width, int height)
{
	glViewport(0, 0, width, height);
}


int main()
{

	if (glfwInit() == -1)
	{
		cout << "Error Init GLFW Failed" << endl;
		return -1;
	}

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
	glfwSetFramebufferSizeCallback(window, framebuff_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to Init GLAD" << endl;
		return -1;
	}

	Shader ourShader("shader.vs", "shader.fs");

	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Trianglevertices), Trianglevertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	//GL_STATIC_DRAW  数据不会改变
	//GL_DYNAMIC_DRAW 数据会改变很多
	//GL_STREAM_DRAW  数据每次绘制都改变

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); GL_LINE
	while (!glfwWindowShouldClose(window))
	{
		ProcessInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/*float timeValue = glfwGetTime();
		float greenValue = sin(timeValue) / 2.0f + .5f;
		int vertexColorLocation = glGetUniformLocation(ourShader.ID, "uColor");*/
	
		ourShader.use();
		//glUniform4f(vertexColorLocation, .0f, greenValue, .0f, 1.0f);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);



		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwTerminate();

	return 0;
}

