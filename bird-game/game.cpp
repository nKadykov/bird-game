#include "game.h"

Game::Game() {
	sf::Texture background_texture;
	sf::Sprite background_sprite;
	game_state = GameState::ON;
}

GameState Game::getState() const {
	return game_state;
}

void Game::draw(sf::RenderWindow& window) const {
	window.draw(background_sprite);
	bird.draw(window);
	window.display();
}

void Game::start(sf::RenderWindow& window) {
	sf::Clock clock;
	sf::Time dt;
}