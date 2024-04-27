#pragma once
#include <SFML/Graphics.hpp>

class Barrier
{
private:
	sf::Sprite m_barrier_sprite;
	float m_barrier_speed = 400.0f;
	sf::Vector2f m_barrier_position;
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
	int get_x() const;
	sf::FloatRect getPosition() const;

	void moveLeft(sf::Time&);

	void draw(sf::RenderWindow&);
};