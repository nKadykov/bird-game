#pragma once
#include <SFML/Graphics.hpp>
#include "bird.h"
#include "barrier.h"

enum class GameState {ON, LOSE, MENU};

class Game
{
private:
	sf::Sprite background_sprite;
	Bird bird;
	Barrier barrier;
	GameState game_state;
public:
	Game();
	Game(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(const Game&) = delete;
	Game& operator=(Game&&) = delete;
	~Game() = default;

	GameState getState() const;
	void draw(sf::RenderWindow&) const;

	void start(sf::RenderWindow&);
};
