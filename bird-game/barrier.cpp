#include "barrier.h"

Barrier::Barrier(sf::Sprite& sprite) {
	barrier_position.x = 720;
	barrier_position.y = -300.0;

	barrier_sprite = sprite;
}

Barrier::Barrier(float start_y) {
	barrier_position.x = 720;
	barrier_position.y = -1.0 * start_y;

	sf::Texture barrier_texture;
	barrier_texture.loadFromFile("resources/barrier.png");
	barrier_sprite.setTexture(barrier_texture);
}

void Barrier::setY(float start_Y) {
	barrier_position.y = start_Y;
}

void Barrier::moveLeft(sf::Time& dt) {
	barrier_position.x -= barrier_speed * dt.asSeconds();
}

sf::Sprite Barrier::getSprite() const {
	return barrier_sprite;
}

sf::Vector2f Barrier::getPosition() const {
	return barrier_position;
}

void Barrier::draw(sf::RenderWindow& window) {
	barrier_sprite.setPosition(barrier_position);
	window.draw(barrier_sprite);
}