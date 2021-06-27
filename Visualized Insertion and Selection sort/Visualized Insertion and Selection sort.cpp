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

void ShellSort()
{
    RenderWindow Window(VideoMode(1100, 900), "Bubble Sort"); // you can change the size of the window if your array is really large.
    RectangleShape Rect;
    Event appEvent;
    double PosX = 0;
    double savedindex = NULL;
    while (Window.isOpen()) {
        Rect.setFillColor(Color(255, 0, 0));
        while (Window.pollEvent(appEvent)) {
            if (appEvent.type == Event::Closed)
                Window.close();
        }
        int n = arr.size();
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < arr.size(); i++)
            {
                for (int x = i - gap; x >= 0; x -= gap)
                {
                    if (arr[x + gap] >= arr[x])
                    {
                        break;
                    }
                    else
                    {
                        double savedvar = arr[x];
                        double savedvar2 = arr[x + gap];
                        arr[x] = savedvar2;
                        arr[x + gap] = savedvar;
                        std::cout << "array at: " << savedvar << " switches with: " << savedvar2 << std::endl;
                    }
                    Window.clear(sf::Color::Black);
                     double PosX = 0;
                    for (int z = 0; z < arr.size() - 1; z++)
                    {
                        Rect.setFillColor(Color(255, 0, 0));
                        PosX += 2;
                        if (z == i || z == i + 1)
                        {
                            Rect.setFillColor(Color(0, 0, 255));
                        }
                        Rect.setPosition(PosX, 900);
                        Rect.setSize(Vector2f(1, arr[z]));
                        Rect.setRotation(180);
                        Window.draw(Rect);
                    }
                    Window.display();
                    Sleep(25);
                }
            }

        }
    }
}
void BubbleSort()
{
    RenderWindow Window(VideoMode(600, 900), "Bubble Sort"); // you can change the size of the window if your array is really large.
    RectangleShape Rect;
    Event appEvent;
    double PosX = 0;
    double savedindex = NULL;
    while (Window.isOpen()) {
        Rect.setFillColor(Color(255, 0, 0));
        while (Window.pollEvent(appEvent)) {
            if (appEvent.type == Event::Closed)
                Window.close();
        }
        PosX = 0;
        int slot = 0;
        double totalmoves = 0;
        bool arraychange = true;
         for (int i = 0; arraychange; i++)
         {
             arraychange = false;
             for (int y = 0; y < arr.size() - 2; y++)
             {
                 if (arr[y] > arr[y + 1])
                 {
                     double varone = arr[y];
                     double vartwo = arr[y + 1];
                     arr[y + 1] = varone;
                     arr[y] = vartwo;
                     savedindex = y;
                     totalmoves++;
                     arraychange = true;
                 }

                 // code for drawing every complition of the array, change all x's to y's

                    // *NOTE*: TO PROPERLY RENDER THE OTHER WAY (USING THE COMMENTED OUT CODE) REMOVE THE FOR LOOP ABOVE AND REMOVE THE WINDOW.DISPLAY() and window.clear()
                    // BELOW THIS COMMENT. THAN UNCOMMENT THE WINDOW.DISPLAY() AT THE END OF THE WHILE LOOP.

             }
             Window.clear(sf::Color::Black);
             PosX = 0;
             for (int z = 0; z < arr.size() - 1; z++)
             {
                 Rect.setFillColor(Color(255, 0, 0));
                 PosX += 2;
                 if (z == savedindex + 1)
                 {
                     Rect.setFillColor(Color(0, 0, 255));
                 }
                 Rect.setPosition(PosX, 900);
                 Rect.setSize(Vector2f(1, arr[z]));
                 Rect.setRotation(180);
                 Window.draw(Rect);
             }
             Window.display();
             Sleep(50);
         }
    }
}
void SelectionSort()
{
    RenderWindow Window(VideoMode(600, 900), "Visualized Sorting"); // you can change the size of the window if your array is really large.
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
                Rect.setPosition(RectPosX, 900);
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
void CocktailSort()
{
    RenderWindow window(VideoMode(600, 900), "Visualized Sorting");
    Event appEvent;
    RectangleShape Rect;
    double RectPosX = 0;
    double savedindex = 0;
    bool arrchange = false;
    while (window.isOpen()) {
        while (window.pollEvent(appEvent)) {
            if (appEvent.type == Event::Closed)
                window.close();
        }
        while (!arrchange)
        {
            arrchange = true;
            for (int i = 0; i < arr.size() - 2; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    double savedvar = arr[i], savedvar2 = arr[i + 1];
                    arr[i] = savedvar2;
                    arr[i + 1] = savedvar;
                    savedindex = i;
                    arrchange = false;
                }
                window.clear(sf::Color::Black);
                RectPosX = 0;
                for (int z = 0; z < arr.size() - 1; z++)
                {
                    Rect.setFillColor(Color(255, 0, 0));
                    if (z == savedindex || z == savedindex + 1) Rect.setFillColor(Color(0, 0, 255));
                    RectPosX += 2;
                    Rect.setPosition(RectPosX, 900);
                    Rect.setSize(Vector2f(1, arr[z]));
                    Rect.setRotation(180);
                    window.draw(Rect);
                   
                }
                window.display();
            }
            while (window.pollEvent(appEvent)) {
                if (appEvent.type == Event::Closed)
                    window.close();
            }
            for (int x = arr.size() - 1; x > 0; x--)
            {
                if (arr[x] < arr[x - 1])
                {
                    double savedvar = arr[x], savedvar2 = arr[x - 1];
                    arr[x] = savedvar2;
                    arr[x - 1] = savedvar;
                    savedindex = x;
                    arrchange = false;
                }
                window.clear(sf::Color::Black);
                RectPosX = 0;
                for (int z = 0; z < arr.size() - 1; z++)
                {
                    Rect.setFillColor(Color(255, 0, 0));
                    if (z == savedindex || z == savedindex - 1) Rect.setFillColor(Color(0, 0, 255));
                    RectPosX += 2;
                    Rect.setPosition(RectPosX, 900);
                    Rect.setSize(Vector2f(1, arr[z]));
                    Rect.setRotation(180);
                    window.draw(Rect);
                }
                window.display();
            }
            
        }
    }
}
void InsertionSort()
{
    RenderWindow window(VideoMode(600, 900), "Visualized Sorting");
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
                Rect.setPosition(RectPosX, 900);
                Rect.setSize(Vector2f(1, arr[z]));
                Rect.setRotation(180);
                window.draw(Rect);
            }
            while (window.pollEvent(appEvent)) {
                if (appEvent.type == Event::Closed)
                    window.close();
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
  ShellSort();
}

