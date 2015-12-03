#include "RenderWindow.h"
#include <windows.h>
#include <gl/glew.h>
#include <GLFW/glfw3.h>


namespace sbox
{
	//////////////////////////////////////////////////////////////////////////

	class RenderWindow::Impl
	{
	public:
		class InputEventHandlerHolder
		{
		public:
			void setInputEventHandler(InputEventHandler* inputEventHandler)
			{
				m_inputEventHandler = inputEventHandler;
			}

			InputEventHandler* getInputEventHandler()
			{
				return m_inputEventHandler;
			}

		private:
			InputEventHandler* m_inputEventHandler;
		};

		Impl() : m_window(NULL)
		{}

		~Impl()
		{}
		
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (action == GLFW_PRESS)
			{
				m_inputEventHandlerHolder->getInputEventHandler()->injectKeyPress(key);
			}
			else if (action == GLFW_RELEASE)
			{
				m_inputEventHandlerHolder->getInputEventHandler()->injectKeyRelease(key);
			}
		}

		static InputEventHandlerHolder* m_inputEventHandlerHolder;
		GLFWwindow* m_window;
		int m_width;
		int m_height;	

	};

	RenderWindow::Impl::InputEventHandlerHolder* RenderWindow::Impl::m_inputEventHandlerHolder = new RenderWindow::Impl::InputEventHandlerHolder;

	//////////////////////////////////////////////////////////////////////////

	RenderWindow::RenderWindow(InputEventHandler* inputEventHandler)
	{
		m_impl = new Impl;
		m_impl->m_inputEventHandlerHolder->setInputEventHandler(inputEventHandler);
	}

	RenderWindow::~RenderWindow()
	{
		delete m_impl;
	}

	void RenderWindow::create(int width, int height, std::string title)
	{
		m_impl->m_width = width;
		m_impl->m_height = height;

		if (glfwInit() != GL_TRUE)
		{
			throw std::exception("GLFW init failed");
		}

		glfwWindowHint(GLFW_SAMPLES, 4); // 4x anti aliasing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 

		m_impl->m_window = glfwCreateWindow(width, height, "GLWindow", NULL, NULL);
		if (!m_impl->m_window)
		{
			throw std::exception("window creation failed");
		}

		glfwMakeContextCurrent(m_impl->m_window);
		glfwSetKeyCallback(m_impl->m_window, &Impl::keyCallback);

		glewExperimental = true;
		if (glewInit() != GLEW_OK)
		{
			throw std::exception("GLEW init failed");
		}
	}

	bool RenderWindow::isCloseRequested()
	{
		return (glfwWindowShouldClose(m_impl->m_window) != 0);
	}

	void RenderWindow::setMouseVisibility(bool visible)
	{
		if (visible)
		{
			glfwSetInputMode(m_impl->m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
		else
		{
			glfwSetInputMode(m_impl->m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
	}

	void RenderWindow::setMousePosition(int px, int py)
	{
		glfwSetCursorPos(m_impl->m_window, (double)px, (double)py);
	}

	void RenderWindow::getMousePosition(int& px, int& py)
	{
		double x, y;
		glfwGetCursorPos(m_impl->m_window, &x, &y);
		px = (int)std::floor(x);
		py = (int)std::floor(y);
	}

	int RenderWindow::getWidth() const
	{
		return m_impl->m_width;
	}

	int RenderWindow::getHeight() const
	{
		return m_impl->m_height;
	}

	void RenderWindow::update()
	{
		glfwSwapBuffers(m_impl->m_window);
		glfwPollEvents();
	}

	void RenderWindow::destroy()
	{
		setMouseVisibility(true);
		glfwTerminate();
	}

}