#pragma once
#include <SFML/Graphics.hpp>

class Bird
{
private:
	sf::Sprite m_bird_sprite;
	sf::Vector2f m_bird_position;
	float m_acceleration_of_gravity = 98000.0f;
	float m_bird_acceleration = -50000.0f;
public:
	Bird();
	Bird(const Bird&) = delete;
	Bird(Bird&&) = delete;
	Bird& operator=(const Bird&) = delete;
	Bird& operator=(Bird&&) = delete;
	~Bird() = default;

	sf::Sprite getSprite() const;
	sf::FloatRect getPosition() const;

	void setSprite(sf::Sprite&);

	void jump();
	void move(sf::Time&);
	void bounceTop();
	void bounceFloor();

	void update(sf::Time&);
	void draw(sf::RenderWindow&) const;
};