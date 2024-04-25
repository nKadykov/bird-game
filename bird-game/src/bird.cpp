#include "bird.h"

Bird::Bird() {
	bird_position.x = 100.0;
	bird_position.y = 720.0 / 2;

	bird_sprite.setPosition(bird_position);
	sf::Texture bird_texture;
	bird_texture.loadFromFile("resources/bird.png");
	sf::Sprite bird_sprite;
	bird_sprite.setTexture(bird_texture);
}

sf::Sprite Bird::getSprite() const {
	return bird_sprite;
}

void Bird::jump() {
	bird_acceleration = -50000.0f;
}

sf::FloatRect Bird::getPosition() const {
	return bird_sprite.getGlobalBounds();
}

void Bird::setSprite(sf::Sprite& sprite) {
	bird_sprite = sprite;
}

void Bird::move(sf::Time& dt) {
	bird_acceleration -= acceleration_of_gravity * dt.asSeconds();
	bird_position.y += bird_acceleration* dt.asSeconds() * dt.asSeconds() / 2;
}

void Bird::bounceTop() {
	if (bird_position.y < 0) {
		bird_position.y = 0;
	}
}

void Bird::bounceFloor() {
	if (bird_position.y > 650) {
		bird_position.y = 650;
		acceleration_of_gravity = 0.0f;
	}
	else {
		acceleration_of_gravity = -98000.0f;
	}
}

void Bird::update(sf::Time& dt) {
	bird_sprite.setPosition(bird_position);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		this->jump();
	}
	this->bounceTop();
	this->bounceFloor();
	this->move(dt);
}

void Bird::draw(sf::RenderWindow& window) const {
	window.draw(bird_sprite);
}