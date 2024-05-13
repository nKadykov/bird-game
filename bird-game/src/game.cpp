#include "game.h"
#include <iostream>

Game::Game() {
	m_game_state = GameState::ON;
}

void Game::setState(GameState state) {
	m_game_state = state;
}

void Game::setBackground(sf::Sprite& sprite) {
	m_background_sprite = sprite;
}

GameState Game::getState() const {
	return m_game_state;
}

void Game::draw(sf::RenderWindow& window) {
	window.draw(m_background_sprite);
	for (int i = 0; i < m_barrier_deque.size(); i++) {
		m_barrier_deque[i].draw(window);
	}
	m_bird.draw(window);
}

void Game::start(sf::RenderWindow& window) {

	srand(time(0));

	sf::Texture barrier_texture;
	if (!barrier_texture.loadFromFile("resources/barrier.png")) {
		exit(1);
	}
	sf::Sprite barrier_sprite;
	barrier_sprite.setTexture(barrier_texture);

	sf::Texture bird_texture;
	if (!bird_texture.loadFromFile("resources/bird.png")) {
		exit(1);
	}
	sf::Sprite bird_sprite;
	bird_sprite.setTexture(bird_texture);
	m_bird.setSprite(bird_sprite);
	
	sf::Music music;
	music.openFromFile("resources/back1.mp3");
	music.play();

	sf::Clock clock;
	sf::Event event;
	sf::Time dt;
	float barrier_time = 0;
	float time = 0;

	Barrier new_barrier(-100.0, barrier_sprite);
	m_barrier_deque.push_back(new_barrier);

	while (window.isOpen() && m_game_state == GameState::ON) {

		dt = clock.getElapsedTime();
		clock.restart();
		time = dt.asSeconds();
		barrier_time += time;

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (barrier_time > 2.0) {
			float start_y = rand() % 600 - rand() % 600;
			Barrier new_barrier(start_y, barrier_sprite);
			new_barrier.setSprite(barrier_sprite);
			m_barrier_deque.push_back(new_barrier);
			barrier_time = 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
			m_game_state = GameState::MENU;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			m_bird.jump();
		}

		m_bird.update(dt);

		for (int i = 0; i < m_barrier_deque.size(); i++) {
			if (m_bird.getPosition().intersects(m_barrier_deque[i].getPosition())) {
				m_game_state = GameState::LOSE;
			}
		}

		for (int i = 0; i < m_barrier_deque.size(); i++) {
			m_barrier_deque[i].moveLeft(dt);
		}

		if (m_barrier_deque[0].get_x() < (0 - barrier_sprite.getGlobalBounds().width)) {
			m_barrier_deque.pop_front();
		}

		window.clear();
		this->draw(window);

		window.display();
	}
	m_barrier_deque.clear();
}