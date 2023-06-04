#include "Tetris.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Tetris::Tetris()
{
	paint_device().resize(Size(m_Width + 7, m_Height));
	m_GameField.resize(m_Width, m_Height);
	m_Figure = new Figure(Point(5, 1));
	m_NextFigure = new Figure(Point(16, 1));

	track_key(VK_LEFT);
	track_key(VK_RIGHT);
	track_key(VK_DOWN);
	track_key(VK_SPACE);
}

void Tetris::DrawScore(PaintDevice& paintDevice)
{
	string score = to_string(m_score);

	Vector2 v1(15, 7);
	paintDevice.set_char(v1, 'S');
	Vector2 v2(16, 7);
	paintDevice.set_char(v2, 'C');
	Vector2 v3(17, 7);
	paintDevice.set_char(v3, 'O');
	Vector2 v4(18, 7);
	paintDevice.set_char(v4, 'R');
	Vector2 v5(19, 7);
	paintDevice.set_char(v5, 'E');

	for (size_t i = 0; i < score.size(); i++)
	{
		Vector2 v6(17 + i, 8);
		paintDevice.set_char(v6, score[i]);
	}
}

bool Tetris::end() const
{
	return this->m_End;
}

void Tetris::on_button_press(const int button)
{
	m_Figure->backup();

	switch (button)
	{
	case VK_LEFT:
		this->m_Figure->move_left();
		break;
	case VK_RIGHT:
		this->m_Figure->move_right();
		break;
	case VK_DOWN:
		this->m_Figure->boost();
		break;
	case VK_SPACE:
		this->m_Figure->rotate();
		break;

	}

	if (m_GameField.has_collision(*m_Figure)) m_Figure->restore();

}

void Tetris::update(const int dt)
{
	m_Figure->backup();
	m_Figure->update(dt);
	if (m_GameField.has_collision(*m_Figure))
	{
		m_Figure->restore();
		m_score += m_GameField.merge(*m_Figure, m_Figure->getColor());
		if (m_score > 999999) m_score = 999999;
		//m_GameField.merge(*m_Figure, m_Figure->getColor());
		m_Figure = m_NextFigure; 
		m_Figure->set_position(Point(5,1));
		m_NextFigure = new Figure(Point(16, 1));
	}
	if (m_GameField.has_collision(*m_Figure)) m_End = true;
}

void Tetris::render(PaintDevice& paintDevice)
{
	m_GameField.render(paintDevice);
	m_Figure->render(paintDevice);
	m_NextFigure->render(paintDevice);
	this->DrawScore(paintDevice);
}
