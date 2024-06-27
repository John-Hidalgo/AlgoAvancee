#pragma once

#include <functional>

namespace TGUIWSFML {
	namespace Event {
		struct MouseEvent;
		struct KeyboardEvent;
		typedef std::function<void(const KeyboardEvent& keyboardEvent)> KeyboardEventHandler;
		typedef std::function<void(const MouseEvent& mouseEvent)> MouseEventHandler;
	}
}
