#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu.h"
#include "gameoverwindow.h"
#include "game.h"

enum class State {GAME, GAMEOVER, MENU};

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Bird");
	window.setFramerateLimit(60);
	window.clear();
	
	sf::Texture gameover_texture;
	gameover_texture.loadFromFile("resources/back1.jpg");
	sf::Sprite gameover_sprite(gameover_texture);
	Menu menu("resources/back.jpg");
	menu.addButton(500, 200, "resources/Button2.png");
	menu.addButton(500, 400, "resources/Button3.png");
	GameOverWindow gameover_window;
	gameover_window.setPosition(300, 200);
	Game *pGame = new Game();
	sf::Texture background_texture;
	if (!background_texture.loadFromFile("resources/back.jpg")) {
		exit(1);
	}
	sf::Sprite background_sprite;
	background_sprite.setTexture(background_texture);
	pGame->setBackground(background_sprite);
	
	State state = State::MENU;
	MenuState menu_state = menu.getState();
	GameState game_state = GameState::ON;
	ButtonState button_state = ButtonState::NONE;
	GameOverState gameover_state = GameOverState::OFF;

	while (window.isOpen()) {

		window.clear();

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		if (pGame) {
			game_state = pGame->getState();
		}
		menu_state = menu.getState();
		button_state = menu.getButtonState();
		gameover_state = gameover_window.getState();

		if (game_state == GameState::LOSE) {
			if (pGame) {
				delete pGame;
				pGame = nullptr;
			}
			state = State::GAMEOVER;
			game_state = GameState::ON;
		}
		if (game_state == GameState::MENU || gameover_state == GameOverState::MENU) {
			if (pGame) {
				delete pGame;
				pGame = nullptr;
			}
			state = State::MENU;
			game_state = GameState::ON;
			gameover_state = GameOverState::ON;
		}
		if (button_state == ButtonState::START_GAME || gameover_state == GameOverState::OFF) {
			if (!pGame) {
				pGame = new Game();
				pGame->setBackground(background_sprite);
			}
			state = State::GAME;
			menu.setButtonState(ButtonState::NONE);
			gameover_window.setState(GameOverState::ON);
		}
		if (button_state == ButtonState::CLOSE) {
			if (pGame) {
				delete pGame;
				pGame = nullptr;
			}
			window.close();
		}

		switch (state) {
			case State::GAME:
				pGame->start(window);
				break;
			case State::MENU:
				menu.draw(window);
				break;
			case State::GAMEOVER:
				gameover_window.draw(window);
				break;
		}

		window.display();
	}

	if (pGame) {
		delete pGame;
		pGame = nullptr;
	}

	return 0;
}