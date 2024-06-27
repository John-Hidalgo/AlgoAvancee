#include "KeyboardEvent.h"

namespace TGUIWSFML
{
	namespace Event
	{
		KeyBoardEvent KeyBoardEvent::FromSFMLMove(const GUIElement* GUIElement, const sf::Event& event) 
		{
			return 
			{
				
				event.mouseMove.x - GUIElement->left(),
				event.mouseMove.y - GUIElement->top(),

				event.mouseButton.button == sf::Mouse::Button::Left,
				event.mouseButton.button == sf::Mouse::Button::Middle,
				event.mouseButton.button == sf::Mouse::Button::Right,

				GUIElement
			};
		}

		KeyBoardEvent KeyBoardEvent::FromSFMLClick(const GUIElement* GUIElement, const sf::Event& event)
		{
			return 
			{
				
				
			};
		}
	}
}