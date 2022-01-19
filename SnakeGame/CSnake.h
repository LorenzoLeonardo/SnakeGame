//Created By : Lorenzo T. Leonardo
//Contact Number : 09226960651
//Email: enzotechcomputersolutions@gmail.com
//Date Created : January 16, 2022

#pragma once
#include "CPosition.h"
#include <Windows.h>
#include <algorithm>
#include <vector>

using namespace std;

enum class Snake_Direction
{
	UP, DOWN, RIGHT, LEFT
};


class CSnake : public CPosition
{

private:
	vector<COORD> m_vBody;
	COORD m_head;
	COORD m_tail;
	Snake_Direction m_direction;
	int m_nlength;
	bool m_bIsAlive;
	inline void CheckBodyCollision();

public:
	CSnake(COORD coord);
	~CSnake();

	void Crawl();
	void Grow(COORD pos);
	void GrowBonus(COORD pos, int nLength);
	void SetDirection(Snake_Direction dir);
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

