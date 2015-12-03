#include "InputEventHandler.h"
#include "Algorithms.h"

namespace sbox
{

	InputEventHandler::InputEventHandler()
	{
	}

	InputEventHandler::~InputEventHandler()
	{
		for (KeyEventListeners::iterator it = m_keyEventListeners.begin(), ite = m_keyEventListeners.end(); it != ite; ++it)
		{
			delete (*it);
		}
		m_keyEventListeners.clear();

		for (MouseEventListeners::iterator it = m_mouseEventListeners.begin(), ite = m_mouseEventListeners.end(); it != ite; ++it)
		{
			delete (*it);
		}
		m_mouseEventListeners.clear();
	}

	void InputEventHandler::addKeyEventListener(IKeyEventListener* keyEventListener)
	{
		m_keyEventListeners.push_back(keyEventListener);
	}

	void InputEventHandler::removeKeyEventListener(IKeyEventListener* keyEventListener)
	{
		KeyEventListeners::iterator iter = std::find(m_keyEventListeners.begin(), m_keyEventListeners.end(), keyEventListener);
		if (iter != m_keyEventListeners.end())
		{
			m_keyEventListeners.erase(iter);
		}
	}

	void InputEventHandler::addMouseEventListener(IMouseEventListener* mouseEventListener)
	{
		m_mouseEventListeners.push_back(mouseEventListener);
	}

	void InputEventHandler::removeMouseEventListener(IMouseEventListener* mouseEventListener)
	{
		MouseEventListeners::iterator iter = std::find(m_mouseEventListeners.begin(), m_mouseEventListeners.end(), mouseEventListener);
		if (iter != m_mouseEventListeners.end())
		{
			m_mouseEventListeners.erase(iter);
		}
	}

	void InputEventHandler::injectKeyPress(int keyCode)
	{
		for (KeyEventListeners::iterator it = m_keyEventListeners.begin(), ite = m_keyEventListeners.end(); it != ite; ++it)
		{
			(*it)->keyPressed(keyCode);
		}
	}

	void InputEventHandler::injectKeyRelease(int keyCode)
	{
		for (KeyEventListeners::iterator it = m_keyEventListeners.begin(), ite = m_keyEventListeners.end(); it != ite; ++it)
		{
			(*it)->keyReleased(keyCode);
		}
	}

}