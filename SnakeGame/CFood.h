//Created By : Lorenzo T. Leonardo
//Contact Number : 09226960651
//Email: enzotechcomputersolutions@gmail.com
//Date Created : January 16, 2022

#pragma once
#include "CPosition.h"
#include <cstdlib>
#include <iostream>
#include <windows.h>
using namespace std;

class CFood : public CPosition
{

public:
	CFood();
	CFood(COORD coord);
	~CFood();

	bool CreateFood();


};

