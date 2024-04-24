#include "game.h"

Game::Game() {

	sf::Texture background_texture;
	background_texture.loadFromFile("resources/sky.jpg");
	sf::Sprite background_sprite;
	background_sprite.setTexture(background_texture);
	game_state = GameState::ON;
}

GameState Game::getState() const {
	return game_state;
}

void Game::draw(sf::RenderWindow& window) {
	window.draw(background_sprite);
	for (int i = 0; i < barrier_deque.size(); i++) {
		barrier_deque[i].draw(window);
	}
	bird.draw(window);
	window.display();
}

void Game::start(sf::RenderWindow& window) {

	sf::Texture barrier_texture;
	barrier_texture.loadFromFile("resources/barrier.png");
	sf::Sprite barrier_sprite;
	barrier_sprite.setTexture(barrier_texture);
	
	sf::Music music;
	music.openFromFile("resources/back1.mp3");
	sf::Clock clock;
	sf::Event event;
	sf::Time dt;
	float barrier_time = 0;
	float time = 0;

	while (window.isOpen() && game_state == GameState::ON) {

		dt = clock.getElapsedTime();
		clock.restart();

		time = dt.asSeconds();
		barrier_time += time;

		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (barrier_time > 3.0) {
			Barrier new_barrier(barrier_sprite);
			barrier_deque.push_back(new_barrier);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
			game_state = GameState::MENU;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			bird.jump();
		}

		for (int i = 0; i < barrier_deque.size(); i++){
			if (bird.getSprite().getGlobalBounds().intersects(barrier_deque[i].getSprite().getGlobalBounds())) {
				game_state = GameState::LOSE;
			}
		}
		if (barrier_deque[0].getPosition().x == 0) {
			barrier_deque.pop_front();
		}
		if (bird.touchedFloor()) {
			game_state = GameState::LOSE;
		}

		window.draw(background_sprite);
		for (int i = 0; i < barrier_deque.size(); i++) {
			barrier_deque[i].draw(window);
		}
		bird.draw(window);
	}
}