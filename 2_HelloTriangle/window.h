#pragma once
#include <glfw3.h>
#include  <glad/glad.h>
#include <iostream>

const int ScreenWidth = 800;
const int ScreenHeight = 600;

int InitGLFW(void);

void framebuff_size_callback(GLFWwindow*, int width, int height);

