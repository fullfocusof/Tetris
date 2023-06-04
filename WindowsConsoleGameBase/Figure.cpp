#include "Figure.h"

Figure::Figure(Point position)
{
	this->m_Position = position;
	this->m_Body = this->randGen();
	this->randColor();
}

void Figure::update(double dt)
{
	this->m_TimeFromLastUpdatec += dt;

	if (this->m_TimeFromLastUpdatec > this->m_TimeForUpdate)
	{
		this->m_TimeFromLastUpdatec = 0;
		++this->m_Position.y;
	}
}

void Figure::render(PaintDevice& paintDevice)
{
	for (const Point& point : m_Body[m_CurrentRotate])
	{
		Vector2 v(point.x + m_Position.x, point.y + m_Position.y);
		paintDevice.set_char(v, 0x25D8, this->m_Color);
	}
}

void Figure::move_right()
{
	++this->m_Position.x;
}

void Figure::move_left()
{
	--this->m_Position.x;
}

const vector<Point>& Figure::get_body() const
{
	return this->m_Body[m_CurrentRotate];
}

Point Figure::get_position() const
{
	return this->m_Position;
}

void Figure::set_position(Point position)
{
	this->m_Position = position;
}

void Figure::backup()
{
	this->m_PositionBackup = this->m_Position;
	this->m_CurrentRotateBackup = this->m_CurrentRotate;
}

void Figure::restore()
{
	this->m_Position = this->m_PositionBackup;
	this->m_CurrentRotate = this->m_CurrentRotateBackup;
}

void Figure::boost()
{
	this->m_TimeForUpdate = 50;
}

void Figure::rotate()
{
	++m_CurrentRotate;
	if (m_CurrentRotate >= m_Body.size())
	{
		m_CurrentRotate = 0;
	}
}

vector<vector<Point>> Figure::randGen()
{
	switch (rand() % 7)
	{
	case 0:
	{
		return { { Point(1,0), Point(1,1), Point(1,2), Point(1,3) },  // I
				 { Point(0,2), Point(1,2), Point(2,2), Point(3,2) },
				 { Point(2,0), Point(2,1), Point(2,2), Point(2,3) },
				 { Point(0,1), Point(1,1), Point(2,1), Point(3,1) } };
	}
	break;

	case 1:
	{
		return { { Point(0,0), Point(0,1), Point(0,2), Point(-1,2) },  // J
				 { Point(0,0), Point(0,1), Point(1,1), Point(2,1) }, 
				 { Point(0,0), Point(1,0), Point(0,1), Point(0,2) }, 
				 { Point(0,0), Point(1,0), Point(2,0), Point(2,1) } };
	}
	break;
	
	case 2:
	{
		return { { Point(0,0), Point(1,0), Point(2,0), Point(1,1) },  // T
				 { Point(1,0), Point(1,1), Point(1,2), Point(0,1) },
				 { Point(0,1), Point(1,1), Point(2,1), Point(1,0) },
				 { Point(0,0), Point(0,1), Point(0,2), Point(1,1) } };
	}
	break;

	case 3:
	{
		return { { Point(0,0), Point(0,1), Point(0,2), Point(1,2) },  // L
				 { Point(0,0), Point(1,0), Point(2,0), Point(0,1) },
				 { Point(0,0), Point(1,0), Point(1,1), Point(1,2) },
				 { Point(0,0), Point(-2,1), Point(-1,1), Point(0,1) } };
	}
	break;

	case 4:
	{
		return { { Point(0,0), Point(1,0), Point(0,1), Point(1,1) }, }; // O
	}
	break;

	case 5:
	{
		return { { Point(0,0), Point(1,0), Point(1,1), Point(2,1) },  // Z
				 { Point(0,0), Point(0,1), Point(-1,1), Point(-1,2) }, };
	}
	break;

	case 6:
	{
		return { { Point(0,0), Point(1,0), Point(-1,1), Point(0,1) },  // S
				 { Point(0,0), Point(0,1), Point(1,1), Point(1,2) }, };
	}
	break;

	default:
		break;
	}
}

void Figure::randColor()
{
	this->m_Color = rand() % 15 + 1;
}

WORD Figure::getColor()
{
	return this->m_Color;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}