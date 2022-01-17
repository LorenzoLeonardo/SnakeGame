// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Created By : Lorenzo T. Leonardo
//Contact Number : 09226960651
//Email: enzotechcomputersolutions@gmail.com
//Date Created : January 16, 2022
//
//A simple snake game in C++ for Windows Platform Console
//

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include<string>
#include <iostream>
#include "CSnake.h"
#include "CFood.h"
#include <thread>
#include <mmsystem.h>

using namespace std;

class CMain
{
private:
    HANDLE m_console;
    COORD m_cursorPosition;
    COORD m_screenSize;
    char m_foodChar;
    char m_snakeChar;
    char m_deleteTrailingChar;
    Snake_Direction m_dir;
    int m_nGameSpeed;

    void GotoXY(int x, int y)
    {
        m_cursorPosition.X = x; // Locates column
        m_cursorPosition.Y = y; // Locates Row
        SetConsoleCursorPosition(m_console, m_cursorPosition); // Sets position for next thing to be printed 
    }
    void DrawSnake(CSnake &snake)
    {
        GotoXY(snake.getTail().X, snake.getTail().Y);
        cout << m_deleteTrailingChar;

        GotoXY((m_screenSize.X / 2) - 15, m_screenSize.Y / 2);
        cout << "Lorenzo Leonardo's Snake Game";

        snake.Crawl(m_dir);

        for (int i = 0; i < snake.GetLength(); i++)
        {
            GotoXY(snake.GetBodyLocation()[i].X, snake.GetBodyLocation()[i].Y);
            cout << m_snakeChar;
        }
    }
    void DrawFood(CFood &food)
    {
        food.CreateFood();
        GotoXY(food.getHorizontalPos(), food.getVerticalPos());
        cout << m_foodChar;
    }
    bool ListenForKeyPress()
    {
        if (GetAsyncKeyState(VK_LEFT) && m_dir != RIGHT)
        {
            m_dir = LEFT;
        }
        else if (GetAsyncKeyState(VK_RIGHT) && m_dir != LEFT)
        {
            m_dir = RIGHT;
        }
        else if (GetAsyncKeyState(VK_UP) && m_dir != DOWN)
        {
            m_dir = UP;
        }
        else if (GetAsyncKeyState(VK_DOWN) && m_dir != UP)
        {
            m_dir = DOWN;
        }
        else if (GetAsyncKeyState(VK_ESCAPE))
        {
            return false;
        }
        return true;
    }
    bool HasEaten(CSnake& snake, CFood& food)
    {
        return ((snake.getHead().X == food.getHorizontalPos()) && snake.getHead().Y == food.getVerticalPos());
    }
public:
    CMain()
    {
        m_foodChar = '0';
        m_snakeChar = '@';
        m_deleteTrailingChar = ' ';
        m_dir = RIGHT;
        m_nGameSpeed = 50;
        m_console = NULL;
        m_cursorPosition = { 0,0 };
        m_screenSize = { 0,0 };
    }
    void InitializeArea()
    {
        m_console = GetStdHandle(STD_OUTPUT_HANDLE);
        // get handle to the console window
        HWND consoleWindow = GetConsoleWindow();

        //disable console resizing
        SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
        // retrieve screen buffer info

        CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
        GetConsoleScreenBufferInfo(m_console, &scrBufferInfo);

        // current window size
        short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
        short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

        // current screen buffer size
        short scrBufferWidth = scrBufferInfo.dwSize.X;
        short scrBufferHeight = scrBufferInfo.dwSize.Y;

        // to remove the scrollbar, make sure the window height matches the screen buffer height
        m_screenSize.X = scrBufferWidth;
        m_screenSize.Y = winHeight;

        // set the new screen buffer dimensions
        int Status = SetConsoleScreenBufferSize(m_console, m_screenSize);
        if (Status == 0)
        {
            cout << "SetConsoleScreenBufferSize() failed! Reason : " << GetLastError() << endl;
            exit(Status);
        }
        // print the current screen buffer dimensions
        //GetConsoleScreenBufferInfo(m_console, &scrBufferInfo);
        // cout << "Screen Buffer Size : " << scrBufferInfo.dwSize.X << " x " << scrBufferInfo.dwSize.Y << endl;

        CONSOLE_CURSOR_INFO lpCursor;
        lpCursor.bVisible = false;
        lpCursor.dwSize = sizeof(CONSOLE_CURSOR_INFO);
        SetConsoleCursorInfo(m_console, &lpCursor);
    }

    void Run()
    {
        CFood food(m_screenSize);
        CSnake snake(m_screenSize);
       
        m_dir = RIGHT;
        DrawFood(food);

        while (snake.IsAlive() && ListenForKeyPress())
        {
            DrawSnake(snake);

            if (HasEaten(snake,food))
            {
                COORD posEaten;
                posEaten.X = food.getHorizontalPos();
                posEaten.Y = food.getVerticalPos();

                snake.Grow(posEaten);
                DrawFood(food);
                PlaySound(TEXT("ding.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            Sleep(m_nGameSpeed);
        }
        PlaySound(TEXT("chord.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(1000);
    }
};

int main()
{
    CMain main;

    main.InitializeArea();
    main.Run();

    return 0;
}
