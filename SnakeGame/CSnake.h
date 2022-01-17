//Created By : Lorenzo T. Leonardo
//Contact Number : 09226960651
//Email: enzotechcomputersolutions@gmail.com
//Date Created : January 16, 2022

#pragma once
#include <Windows.h>
#include <algorithm>
#include <vector>

using namespace std;


typedef enum
{
	UP, DOWN, RIGHT, LEFT
}Snake_Direction;

class CSnake
{

private:
	vector<COORD> m_vBody;
	COORD m_head;
	COORD m_tail;
	Snake_Direction m_direction;
	int m_nlength;
	COORD m_screenSize;
	bool m_bIsAlive;

public:
	CSnake(COORD coord);
	~CSnake();

	void Crawl(Snake_Direction direction);
	void Grow(COORD pos);
	void SetDirection(Snake_Direction dir);
	void CheckBodyCollision();

	vector<COORD> GetBodyLocation()
	{
		return m_vBody;
	}
	bool IsAlive()
	{
		return m_bIsAlive;
	}
	COORD getTail()
	{
		return m_tail;
	}
	COORD getHead()
	{
		return m_head;
	}
	Snake_Direction GetDirection()
	{
		return m_direction;
	}
	int GetLength()
	{
		return m_nlength;
	}
};

