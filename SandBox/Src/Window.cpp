#include "Window.h"
#include <iostream>

namespace sbox
{
	GLFWwindow* Window::m_window = NULL;

	void Window::create(int width, int height)
	{
		if (glfwInit() != GL_TRUE)
		{
			throw std::exception("GLFW init failed");
		}

		glfwWindowHint(GLFW_SAMPLES, 4); // 4x anti aliasing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 

		m_window = glfwCreateWindow(width, height, "GLWindow", NULL, NULL);
		if (!m_window)
		{
			throw std::exception("window creation failed");
		}

		glfwMakeContextCurrent(m_window);

		glewExperimental = true;
		if (glewInit() != GLEW_OK)
		{
			throw std::exception("GLEW init failed");
		}
	}

	bool Window::isCloseRequested()
	{
		return (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS && glfwWindowShouldClose(m_window) != 0);
	}

	void Window::update()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	void Window::destroy()
	{
		glfwTerminate();
	}
}