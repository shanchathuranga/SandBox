#include <iostream>
#include "Window.h"

int main(void)
{
	sbox::Window::create(800, 600);

	while (!sbox::Window::isCloseRequested())
	{
		sbox::Window::update();
	}

	sbox::Window::destroy();

	return 0;
}