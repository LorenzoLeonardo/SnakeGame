//Created By : Lorenzo T. Leonardo
//Contact Number : 09226960651
//Email: enzotechcomputersolutions@gmail.com
//Date Created : January 16, 2022

#include "CSnake.h"

CSnake::CSnake(COORD screenSize)
{
	m_direction = Snake_Direction::RIGHT;
	m_head = { 0,0 };
	m_tail = { 0,0 };
	COORD coord = { 0,2 };

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
inline void CSnake::CheckBodyCollision()
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
void CSnake::GrowBonus(COORD pos, int nLength)
{
	for(int i = 0; i< nLength; i++)
		m_vBody.push_back(pos);
	m_tail = pos;
	m_nlength = (int)m_vBody.size();

	if (m_nlength >= (m_screenSize.X * m_screenSize.Y))
		m_bIsAlive = false;
}
void CSnake::Grow(COORD pos)
{
	m_vBody.push_back(pos);
	m_tail = pos;
	m_nlength = (int)m_vBody.size();

	if(m_nlength >= (m_screenSize.X * m_screenSize.Y))
		m_bIsAlive = false;
}
void CSnake::Crawl()
{
	switch (m_direction)
	{
		case Snake_Direction::RIGHT:
				for (int i = m_nlength - 1; i > 0; i--)
				{
					m_vBody[i] = m_vBody[i - 1];
				}
				m_vBody[0].X++;
				if (m_vBody[0].X >= m_screenSize.X)
				{
					m_vBody[0].X = 0;
				}
			break;
		case Snake_Direction::LEFT:
				for (int i = m_nlength - 1; i > 0; i--)
				{
					m_vBody[i] = m_vBody[i - 1];
				}
				m_vBody[0].X--;
				if (m_vBody[0].X < 0)
				{
					m_vBody[0].X = m_screenSize.X - 1;
				}
			break;
		case Snake_Direction::UP:
				for (int i = m_nlength - 1; i > 0; i--)
				{
					m_vBody[i] = m_vBody[i - 1];
				}
				m_vBody[0].Y--;
				if (m_vBody[0].Y < 0)
				{
					m_vBody[0].Y = m_screenSize.Y - 1;
				}
			break;
		case Snake_Direction::DOWN:
				for (int i = m_nlength - 1; i > 0; i--)
				{
					m_vBody[i] = m_vBody[i - 1];
				}
				m_vBody[0].Y++;
				if (m_vBody[0].Y >= (m_screenSize.Y))
				{
					m_vBody[0].Y = 0;
				}
			break;
	}

	m_head = m_vBody[0];
	m_tail = m_vBody[m_vBody.size() - 1];

	CheckBodyCollision();
}
void CSnake::SetDirection(Snake_Direction dir)
{
	m_direction = dir;
}