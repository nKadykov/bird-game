#include "bird.h"

Bird::Bird() {
	m_bird_position.x = 100.0;
	m_bird_position.y = 720.0 / 2;

	m_bird_sprite.setPosition(m_bird_position);
	sf::Texture bird_texture;
	bird_texture.loadFromFile("resources/m_bird.png");
	sf::Sprite m_bird_sprite;
	m_bird_sprite.setTexture(bird_texture);
}

sf::Sprite Bird::getSprite() const {
	return m_bird_sprite;
}

void Bird::jump() {
	m_bird_acceleration = -50000.0f;
}

sf::FloatRect Bird::getPosition() const {
	return m_bird_sprite.getGlobalBounds();
}

void Bird::setSprite(sf::Sprite& sprite) {
	m_bird_sprite = sprite;
}

void Bird::move(sf::Time& dt) {
	m_bird_acceleration -= m_acceleration_of_gravity * dt.asSeconds();
	m_bird_position.y += m_bird_acceleration* dt.asSeconds() * dt.asSeconds() / 2;
}

void Bird::bounceTop() {
	if (m_bird_position.y < 0) {
		m_bird_position.y = 0;
	}
}

void Bird::bounceFloor() {
	if (m_bird_position.y > 650) {
		m_bird_position.y = 650;
		m_acceleration_of_gravity = 0.0f;
	}
	else {
		m_acceleration_of_gravity = -98000.0f;
	}
}

void Bird::update(sf::Time& dt) {
	m_bird_sprite.setPosition(m_bird_position);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		this->jump();
	}
	this->bounceTop();
	this->bounceFloor();
	this->move(dt);
}

void Bird::draw(sf::RenderWindow& window) const {
	window.draw(m_bird_sprite);
}