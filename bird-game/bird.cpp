#include "bird.h"

Bird::Bird() {
	bird_position.x = 0.0;
	bird_position.y = 720.0 / 2;

	sf::Texture bird_texture;
	bird_texture.loadFromFile("resources/bird.png");
	bird_sprite.setTexture(bird_texture);
	bird_sprite.setPosition(bird_position);
}

sf::Sprite Bird::getSprite() const {
	return bird_sprite;
}

void Bird::jump() {
	bird_acceleration = 50.0f;
}

BirdState Bird::getState() const {
	return bird_state;
}

void Bird::move(sf::Time& dt) {
	bird_acceleration -= acceleration_of_gravity * dt.asSeconds();
	bird_position.y += bird_acceleration * dt.asSeconds() * dt.asSeconds() / 2;
}

bool Bird::touchedFloor() {
	return bird_position.y == 0 ? true : false;
}

void Bird::update(sf::Time& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		this->jump();
	}
	this->move(dt);
	if()
	bird_sprite.setPosition(bird_position);
}

void Bird::draw(sf::RenderWindow& window) const {
	window.draw(bird_sprite);
}