#include "barrier.h"

Barrier::Barrier(sf::Sprite& sprite) {
	barrier_position.x = 1280;
	barrier_position.y = 1000.0;

	barrier_sprite = sprite;
}

Barrier::Barrier(float start_y, sf::Sprite sprite) {
	barrier_position.x = 1280;
	barrier_position.y = start_y;

	barrier_sprite = sprite;
}

void Barrier::setSprite(sf::Sprite& sprite) {
	barrier_sprite = sprite;
}

void Barrier::setY(float start_Y) {
	barrier_position.y = start_Y;
}

void Barrier::moveLeft(sf::Time& dt) {
	barrier_position.x -= barrier_speed * dt.asSeconds();
	barrier_sprite.setPosition(barrier_position);
}

sf::Sprite Barrier::getSprite() const {
	return barrier_sprite;
}

sf::FloatRect Barrier::getPosition() const {
	return barrier_sprite.getGlobalBounds();
}

int Barrier::get_x() const {
	return barrier_position.x;
}

void Barrier::draw(sf::RenderWindow& window) {
	/*barrier_sprite.rotate(180);*/
	barrier_sprite.setPosition(barrier_position);
	window.draw(barrier_sprite);
}