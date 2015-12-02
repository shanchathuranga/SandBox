#ifndef __Window_h__
#define __Window_h__

#include "windows.h"
#include "gl/glew.h"
#include "GLFW/glfw3.h"

namespace sbox
{
	class Window
	{
	public:
		static void create(int width, int height);

		static bool isCloseRequested();

		static void update();

		static void destroy();

	private:

		static GLFWwindow* m_window;
	};
}

#endif