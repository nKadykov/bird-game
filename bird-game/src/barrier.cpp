#include "barrier.h"

Barrier::Barrier(sf::Sprite& sprite) {
	m_barrier_position.x = 1280;
	m_barrier_position.y = 1000.0;

	m_barrier_sprite = sprite;
}

Barrier::Barrier(float start_y, sf::Sprite sprite) {
	m_barrier_position.x = 1280;
	m_barrier_position.y = start_y;

	m_barrier_sprite = sprite;
}

void Barrier::setSprite(sf::Sprite& sprite) {
	m_barrier_sprite = sprite;
}

void Barrier::setY(float start_Y) {
	m_barrier_position.y = start_Y;
}

void Barrier::moveLeft(sf::Time& dt) {
	m_barrier_position.x -= m_barrier_speed * dt.asSeconds();
	m_barrier_sprite.setPosition(m_barrier_position);
}

sf::Sprite Barrier::getSprite() const {
	return m_barrier_sprite;
}

sf::FloatRect Barrier::getPosition() const {
	return m_barrier_sprite.getGlobalBounds();
}

int Barrier::get_x() const {
	return m_barrier_position.x;
}

void Barrier::draw(sf::RenderWindow& window) {
	m_barrier_sprite.setPosition(m_barrier_position);
	window.draw(m_barrier_sprite);
}