#ifndef IKEY_EVENT_LISTENER_H
#define IKEY_EVENT_LISTENER_H

#include "KeyCodes.h"

namespace sbox
{

	class IKeyEventListener
	{
	public:
		virtual ~IKeyEventListener(){}

		virtual void keyPressed(int keyCode) = 0;

		virtual void keyReleased(int keyCode) = 0;
	};

}

#endif