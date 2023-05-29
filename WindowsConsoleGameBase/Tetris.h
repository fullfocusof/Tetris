#pragma once
#include "Engine.h"
#include "GameField.h"
#include <string>
#include <Windows.h>

class Tetris : public Engine 
{
	GameField m_GameField;
	const size_t m_Width = 14;
	const size_t m_Height = 26;
	size_t m_score = 0u;

	Figure* m_Figure;
	Figure* m_NextFigure;

	bool m_End = false;
	
	void DrawScore(PaintDevice& paintDevice);

	virtual void render(PaintDevice& paintDevice) override;

public:

	Tetris();

	virtual bool end() const override;
	virtual void on_button_press(const int button) override;
	virtual void update(const int dt) override;
};