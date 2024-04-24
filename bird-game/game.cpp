#include "game.h"

Game::Game() {
	sf::Texture background_texture;
	background_texture.loadFromFile("resources/sky.jpg");
	sf::Sprite background_sprite;
	background_sprite.setTexture(background_texture);
	game_state = GameState::ON;
}

void Game::setState(GameState state) {
	game_state = state;
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
}

void Game::start(sf::RenderWindow& window) {

	srand(time(0));

	sf::Texture barrier_texture;
	barrier_texture.loadFromFile("resources/barrier.png");
	sf::Sprite barrier_sprite;
	barrier_sprite.setTexture(barrier_texture);
	sf::Texture bird_texture;
	bird_texture.loadFromFile("resources/bird.png");
	sf::Sprite bird_sprite;
	bird_sprite.setTexture(bird_texture);
	bird.setSprite(bird_sprite);

	sf::Texture background_texture;
	background_texture.loadFromFile("resources/sky.jpg");
	sf::Sprite background_sprite;
	background_sprite.setTexture(background_texture);
	window.draw(background_sprite);
	
	sf::Music music;
	music.openFromFile("resources/back1.mp3");

	sf::Clock clock;
	sf::Event event;
	sf::Time dt;
	float barrier_time = 0;
	float time = 0;

	Barrier new_barrier(1000.0, barrier_sprite);
	barrier_deque.push_back(new_barrier);

	BirdState bird_state = bird.getState();

	while (window.isOpen() || game_state == GameState::ON) {

		window.draw(background_sprite);

		dt = clock.getElapsedTime();
		clock.restart();
		time = dt.asSeconds();
		barrier_time += time;

		bird_state = bird.getState();

		//bird.move(dt);

		if (barrier_time > 2.0) {
			float start_y = 720 + rand() % 600;
			Barrier new_barrier(start_y, barrier_sprite);
			new_barrier.setSprite(barrier_sprite);
			barrier_deque.push_back(new_barrier);
			barrier_time = 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
			game_state = GameState::MENU;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			bird.jump();
		}

		for (int i = 0; i < barrier_deque.size(); i++){
			if (bird.getSprite().getGlobalBounds().intersects(barrier_deque[i].getSprite().getGlobalBounds()) || bird_state == BirdState::DEAD) {
				window.close();
				game_state = GameState::LOSE;
			}
		}

		for (int i = 0; i < barrier_deque.size(); i++) {
			barrier_deque[i].moveLeft(dt);
		}

		if (barrier_deque[0].getPosition().x == 0) {
			barrier_deque.pop_front();
		}

		window.clear();

		bird.update(dt);

		for (int i = 0; i < barrier_deque.size(); i++) {
			barrier_deque[i].draw(window);
		}
		bird.draw(window);
		window.display();
	}
	barrier_deque.clear();
}