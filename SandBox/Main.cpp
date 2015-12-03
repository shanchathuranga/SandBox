#include <iostream>
#include "RenderWindow.h"
#include "InputEventHandler.h"

using namespace sbox;

class ApplicationExecuter : public IKeyEventListener
{
public:
	ApplicationExecuter() : m_stopped(false)
	{}

	void keyPressed(int keyCode)
	{
		std::cout << "Pressed : " << keyCode << std::endl;
		if (keyCode == 256)
		{
			m_stopped = true;
		}
	}

	void keyReleased(int keyCode)
	{
		std::cout << "Released : " << keyCode << std::endl;
	}

	bool isStopped() const
	{
		return m_stopped;
	}

private:
	bool m_stopped;

};


int main(void)
{
	InputEventHandler* eventHandler = new InputEventHandler;
	RenderWindow* renderWindow = new RenderWindow(eventHandler);
	ApplicationExecuter* executer = new ApplicationExecuter;

	eventHandler->addKeyEventListener(executer);

	renderWindow->create(800, 600, "title");

	while (!renderWindow->isCloseRequested() && !executer->isStopped())
	{
		renderWindow->update();
	}

	renderWindow->destroy();

	delete renderWindow;
	delete eventHandler;

	return 0;
}