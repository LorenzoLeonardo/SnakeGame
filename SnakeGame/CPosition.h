//Created By : Lorenzo T. Leonardo
//Contact Number : 09226960651
//Email: enzotechcomputersolutions@gmail.com
//Date Created : January 16, 2022
#pragma once
class CPosition
{
protected:
	int m_xPos;
	int m_yPos;
	int m_displayHeight;
	int m_displayWidth;

public:
	int getHorizontalPos()
	{
		return m_xPos;
	}
	int getVerticalPos()
	{
		return m_yPos;
	}
};

