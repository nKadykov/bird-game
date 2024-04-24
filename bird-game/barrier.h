#pragma once
class Barrier
{
private:
	sf::Sprite barrier_sprite;
	float barrier_speed = 100.0f;
public:
	Barrier();
	Barrier(const Barrier&) = delete;
	Barrier(Barrier&&) = delete;
	Barrier& operator=(const Barrier&) = delete;
	Barrier& operator=(Barrier&&) = delete;
	~Barrier() = default;

	
};

