#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <array>
#include <vector>
#include<fstream>
#include <sstream>
#include <thread>
#include <windows.h>
using namespace std;
using namespace sf;
std::vector <double> arr;

void SelectionSort()
{
    RenderWindow Window(VideoMode(600, 800), "Selection Sort"); // you can change the size of the window if your array is really large.
    RectangleShape Rect;
    Event appEvent;
    double RectPosX = 0;
    double savedindex = NULL;
    while (Window.isOpen()) {
        while (Window.pollEvent(appEvent)) {
            if (appEvent.type == Event::Closed)
                Window.close();
        }
        for (int i = 0; i < arr.size() - 2; i++)
        {
            int curmin = arr[i], curpos = 0;
            for (int y = 1; y < arr.size() - 1 - i; y++)
            {
                if (arr[y + i] < curmin)
                {
                    curmin = arr[y + i];
                    curpos = y + i;
                }
            }
            if (curmin < arr[i])
            {
                int savedlargernum = arr[i];
                arr[i] = curmin;
                arr[curpos] = savedlargernum;
            }
            Window.clear(sf::Color::Black);
            RectPosX = 0;
            for (int z = 0; z < arr.size() - 1; z++)
            {
                Rect.setFillColor(Color(255, 0, 0));
                RectPosX += 2;
                if (z == i || z == i + 1)
                {
                    Rect.setFillColor(Color(0, 0, 255));
                }
                if (z == curpos)
                {
                    Rect.setFillColor(Color(0, 0, 255));
                }
                Rect.setPosition(RectPosX, 800);
                Rect.setSize(Vector2f(1, arr[z]));
                Rect.setRotation(180);
                Window.draw(Rect);
            }
            Window.display();
            while (Window.pollEvent(appEvent)) {
                if (appEvent.type == Event::Closed)
                    Window.close();
            }
            Sleep(50);
        }

    }
}

void InsertionSort()
{
    RenderWindow window(VideoMode(600, 800), "Selection/Insertion Sort");
    Event appEvent;
    RectangleShape Rect;
    double RectPosX = 0;
    double savedindex = 0;
    while (window.isOpen()) {
        while (window.pollEvent(appEvent)) {
            if (appEvent.type == Event::Closed)
                window.close();
        }
        for (int i = 1; i < arr.size() - 1; i++)
        {
            window.clear(sf::Color::Black);
            for (int x = 0; x < i; x++)
            {
                if (arr[i] < arr[x])
                {
                    double savedvar = arr[i];
                    double savedvar2 = arr[x];
                    arr[i] = savedvar2;
                    arr[x] = savedvar;
                    savedindex = x;
                }
            }
            RectPosX = 0;
            for (int z = 0; z < arr.size() - 1; z++)
            {
                Rect.setFillColor(Color(255, 0, 0));
                RectPosX += 2;
                if (z == i)
                {
                    Rect.setFillColor(Color(0, 0, 255));
                }
                Rect.setPosition(RectPosX, 800);
                Rect.setSize(Vector2f(1, arr[z]));
                Rect.setRotation(180);
                window.draw(Rect);
            }
            window.display();
            Sleep(50);
        }
    }
}
int main()
{
    bool finished = false;
    ifstream arraynumbers; // this takes the numbers from the txt file and puts them into the array, you can remove this and just add varriables yourself if you so desire.
    arraynumbers.open("Text.txt");
    for (int i = 0; !arraynumbers.eof(); i++)
    {
        string output;
        float intergeroutput;
        arraynumbers >> output;
        stringstream ssoutput(output);
        ssoutput >> intergeroutput;
        arr.push_back(intergeroutput);
    }
    InsertionSort();
}

