#ifndef INPUT_EVENT_HANDLER_H
#define INPUT_EVENT_HANDLER_H

#include "Interfaces/IKeyEventListener.h"
#include "Interfaces/IMouseEventListener.h"
#include "Containers.h"

namespace sbox
{

	class InputEventHandler
	{
	public:
		InputEventHandler();

		~InputEventHandler();

		void addKeyEventListener(IKeyEventListener* keyEventListener);

		void removeKeyEventListener(IKeyEventListener* keyEventListener);

		void addMouseEventListener(IMouseEventListener* mouseEventListener);

		void removeMouseEventListener(IMouseEventListener* mouseEventListener);

		void injectKeyPress(int keyCode);

		void injectKeyRelease(int keyCode);

	private:
		typedef std::vector<IKeyEventListener*> KeyEventListeners;
		typedef std::vector<IMouseEventListener*> MouseEventListeners;

		KeyEventListeners m_keyEventListeners;
		MouseEventListeners m_mouseEventListeners;

	};

}

#endif