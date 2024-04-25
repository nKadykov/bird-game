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
	GameState game_state;
	Bird bird;
	std::deque<Barrier> barrier_deque;
public:
	Game();
	Game(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(const Game&) = delete;
	Game& operator=(Game&&) = delete;
	~Game() = default;

	void setState(GameState);
	void setBackground(sf::Sprite&);
	GameState getState() const;
	void draw(sf::RenderWindow&);

	void start(sf::RenderWindow&);
};
