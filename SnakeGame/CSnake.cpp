//Created By : Lorenzo T. Leonardo
//Contact Number : 09226960651
//Email: enzotechcomputersolutions@gmail.com
//Date Created : January 16, 2022

#include "CSnake.h"

CSnake::CSnake(COORD screenSize)
{
	m_direction = RIGHT;
	m_head = { 0,0 };
	m_tail = { 0,0 };
	COORD coord = { 0,0 };

	for (int i = 5; i > 0; i--)
	{
		coord.X = i;
		m_vBody.push_back(coord);

	}
	m_head = m_vBody[0];
	m_tail = m_vBody[m_vBody.size()-1];
	m_nlength = (int)m_vBody.size();
	m_screenSize = screenSize;
	m_bIsAlive = true;
}
CSnake::~CSnake()
{

}
void CSnake::CheckBodyCollision()
{
	for (int i = 1; i < m_nlength; i++)
	{
		if ((m_vBody[i].X == m_head.X) &&
			(m_vBody[i].Y == m_head.Y))
		{
			m_bIsAlive = false;
			break;
		}
	}
}
void CSnake::Grow(COORD pos)
{
	m_vBody.push_back(pos);
	m_tail = pos;
	m_nlength = (int)m_vBody.size();

	if(m_nlength >= (m_screenSize.X * m_screenSize.Y))
		m_bIsAlive = false;
}
void CSnake::Crawl(Snake_Direction direction)
{
	m_direction = direction;

	if (m_direction == RIGHT)
	{
		for (int i = m_nlength - 1; i > 0; i--)
		{
			m_vBody[i] = m_vBody[i-1];
		}
		m_vBody[0].X++;
		if (m_vBody[0].X >= m_screenSize.X)
		{
			m_vBody[0].X = 0;
		}
	}
	else if (m_direction == LEFT)
	{
		for (int i = m_nlength - 1; i > 0; i--)
		{
			m_vBody[i] = m_vBody[i - 1];
		}
		m_vBody[0].X--;
		if (m_vBody[0].X < 0)
		{
			m_vBody[0].X = m_screenSize.X - 1;
		}
	}
	else if (m_direction == UP)
	{
		for (int i = m_nlength - 1; i > 0; i--)
		{
			m_vBody[i] = m_vBody[i - 1];
		}
		m_vBody[0].Y--;
		if (m_vBody[0].Y < 0)
		{
			m_vBody[0].Y = m_screenSize.Y - 1;
		}
	}
	else if (m_direction == DOWN)
	{
		for (int i = m_nlength - 1; i > 0; i--)
		{
			m_vBody[i] = m_vBody[i - 1];
		}
		m_vBody[0].Y++;
		if (m_vBody[0].Y >= (m_screenSize.Y))
		{
			m_vBody[0].Y = 0;
		}
	}
	m_head = m_vBody[0];
	m_tail = m_vBody[m_vBody.size() - 1];

	CheckBodyCollision();
}
void CSnake::SetDirection(Snake_Direction dir)
{
	m_direction = dir;
}