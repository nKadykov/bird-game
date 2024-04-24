#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <deque>
#include "bird.h"
#include "barrier.h"

enum class GameState {ON, LOSE, MENU};

class Game
{
private:
	sf::Sprite background_sprite;
	Bird bird;
	std::deque<Barrier> barrier_deque;
	GameState game_state;
public:
	Game();
	Game(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(const Game&) = delete;
	Game& operator=(Game&&) = delete;
	~Game() = default;

	void setState(GameState);
	GameState getState() const;
	void draw(sf::RenderWindow&);

	void start(sf::RenderWindow&);
};
