//Created By : Lorenzo T. Leonardo
//Contact Number : 09226960651
//Email: enzotechcomputersolutions@gmail.com
//Date Created : January 16, 2022

#include "CFood.h"


CFood::CFood()
{
	srand((unsigned int)time(NULL));
	m_xPos = 0;
	m_yPos = 0;
	m_displayHeight = 0;
	m_displayWidth = 0;
}
CFood::CFood(COORD coord)
{
	srand((unsigned int)time(NULL));
	m_xPos = 0;
	m_yPos = 0;
	m_displayHeight = coord.Y;
	m_displayWidth = coord.X;
}
CFood::~CFood()
{

}

bool CFood::CreateFood()
{

	if (rand() % 5 == 1)
		m_bIsBonus = true;
	else
		m_bIsBonus = false;

	m_yPos = rand() % (m_displayHeight - 1);
	m_xPos = rand() % m_displayWidth;

	return true;
}