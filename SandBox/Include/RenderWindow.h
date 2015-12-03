#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include "Containers.h"
#include "InputEventHandler.h"

namespace sbox
{

	class RenderWindow
	{
	public:
		RenderWindow(InputEventHandler* inputEventHandler);

		~RenderWindow();
		
		void create(int width, int height, std::string title);

		bool isCloseRequested();

		void setMouseVisibility(bool visible);

		void setMousePosition(int px, int py);

		void getMousePosition(int& px, int& py);

		int getWidth() const;

		int getHeight() const;

		void update();

		void destroy();

	private:
		class Impl;
		Impl* m_impl;

	};

}

#endif