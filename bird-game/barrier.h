#pragma once
#include <SFML/Graphics.hpp>

class Barrier
{
private:
	sf::Sprite barrier_sprite;
	float barrier_speed = 400.0f;
	sf::Vector2f barrier_position;
public:
	Barrier() = delete;
	Barrier(sf::Sprite&);
	Barrier(float, sf::Sprite);
	Barrier(const Barrier&) = default;
	Barrier(Barrier&&) = delete;
	Barrier& operator=(const Barrier&) = delete;
	Barrier& operator=(Barrier&&) = delete;
	~Barrier() = default;
	
	void setSprite(sf::Sprite&);
	void setY(float);
	sf::Sprite getSprite() const;
	sf::Vector2f getPosition() const;

	void moveLeft(sf::Time&);

	void draw(sf::RenderWindow&);
};