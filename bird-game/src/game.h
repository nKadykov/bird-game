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
	sf::Sprite m_background_sprite;
	GameState m_game_state;
	Bird m_bird;
	std::deque<Barrier> m_barrier_deque;
	sf::Font m_font;
	sf::Text m_score_text;
	int m_score_number = 0;
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
