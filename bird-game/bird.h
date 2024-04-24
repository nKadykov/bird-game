#pragma once
#include <SFML/Graphics.hpp>

enum class BirdState {ALIVE, DEAD};

class Bird
{
private:
	sf::Sprite bird_sprite;
	sf::Vector2f bird_position;
	float acceleration_of_gravity = -98000.0f;
	float bird_acceleration = -50000.0f;
	BirdState bird_state = BirdState::ALIVE;
public:
	Bird();
	Bird(const Bird&) = delete;
	Bird(Bird&&) = delete;
	Bird& operator=(const Bird&) = delete;
	Bird& operator=(Bird&&) = delete;
	~Bird() = default;

	sf::Sprite getSprite() const;
	BirdState getState() const;
	sf::FloatRect getPosition() const;

	void setSprite(sf::Sprite&);

	void jump();
	void move(sf::Time&);
	bool touchedFloor() const;

	void update(sf::Time&);
	void draw(sf::RenderWindow&) const;
};