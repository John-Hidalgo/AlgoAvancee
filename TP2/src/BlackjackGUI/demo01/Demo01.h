#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Window/Window.h"
#include "Component/Label.h"
#include "Component/Button.h"


class Demo01 : public TGUIWSFML::Window::Window {
public:
	Demo01();
	~Demo01();
	void ChangeCarte()
	{
		this->m_imageAsCoeur->backgroundTexture(texture("svg_playing_cards/fronts/png_96_dpi/clubs_ace"));
	};
	void Quitter()
	{
		test = true;
		show();
		componentsInitialization();
		//this->loop() == false;
		//exit(0);
		
	};
	void handleKeyboardEvent(const sf::Event& event)
	{
		// Check if the label has been clicked
		if (labelClicked)
		{
			// Handle key presses here
			m_labelHello->text(getPressedKey(event));
			// Check for Enter key to reset the state variable
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
				labelClicked = false; // Reset the state variable
			}
		}
		else
		{
			// The label hasn't been clicked, so ignore key presses
		}
	}

   void run()
    {
        while (m_window.isOpen())
        {
            sf::Event event;
            while (m_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    m_window.close();
                else if (event.type == sf::Event::TextEntered)
                {
                    //handleTextEntered(event.text.unicode);
                }
            }

            // Update your GUI system
            // ...

            m_window.clear();
            // Draw your GUI components
            // ...
            m_window.display();
        }
    }

	std::string getPressedKey(const sf::Event& event)
	{
		// Check if a key is pressed
		if (event.type == sf::Event::KeyPressed)
		{
			// Check for valid letters (A-Z)
			for (int letter = sf::Keyboard::A; letter <= sf::Keyboard::Z; ++letter)
			{
				if (event.key.code == static_cast<sf::Keyboard::Key>(letter))
				{
					// Convert the pressed key to a string
					char pressedLetter = static_cast<char>('A' + letter - sf::Keyboard::A);
					return std::string(1, pressedLetter);
				}
			}

			// Check for additional keys (e.g., Space, Enter, etc.)
			if (event.key.code == sf::Keyboard::Space)
			{
				return "Space";
			}
			else if (event.key.code == sf::Keyboard::Return)
			{
				return "Enter";
			}
			// Add more key checks as needed

			// If no matching key is found, return an empty string
			return "";
		}

		// If no key was pressed, return an empty string
		return "";
	}









	virtual void componentsInitialization();
private:
	
	TGUIWSFML::Component::Label* m_labelHello;
	TGUIWSFML::Component::Button* m_FPSOn;
	TGUIWSFML::Component::Button* m_FPSOff;
	TGUIWSFML::Component::Button* m_testHover;

	TGUIWSFML::Component::Label* m_labelLeftAligned;
	TGUIWSFML::Component::Label* m_labelCenterAligned;
	TGUIWSFML::Component::Label* m_labelRightAligned;

	TGUIWSFML::Component::Label* m_imageAsCoeur;

	TGUIWSFML::Component::Button* m_drawingDebugOff;
	TGUIWSFML::Component::Button* m_drawingDebugOn;
	TGUIWSFML::Component::Button* m_toogleFPSLimit;
	std::unordered_map<sf::Keyboard::Key, bool> keyStates;
	bool test = false;
	bool labelClicked = false;
};