#pragma once
#include "Engine.h"
#include <vector>
#include <Windows.h>
#include <random>

using namespace std;

struct Point
{
	int x;
	int y;

	Point(int x = 0, int y = 0);

};

class Figure
{
protected:

	Point m_Position; 
	Point m_PositionBackup;

	vector<vector<Point>> m_Body;
	WORD m_Color;

	size_t m_CurrentRotate = 0;
	size_t m_CurrentRotateBackup = 0;

	double m_TimeFromLastUpdatec = 0;
	double m_TimeForUpdate = 500; //полсекунды

public:

	Figure(Point position);

	void update(double dt);

	void render(PaintDevice& paintDevice);

	void move_right();
	void move_left();

	const vector<Point>& get_body() const;
	Point get_position() const;
	void set_position(Point position);

	void backup();
	void restore();

	void boost();

	void rotate();

	vector<vector<Point>> randGen();

	void randColor();
	WORD getColor();
};