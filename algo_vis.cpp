#ifdef _WIN32
#include <windows.h>
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
#include <cstdlib>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#define LENGTH 2 // YOU CAN CHANGE THIS TOO
#define WIDTH 2  // THIS TOO
using namespace std;

int count = 0;
size_t size;

class Bar
{
private:
    string box;

public:
    int length;
    int guideIndex;
    int highIndex;

    Bar(int length, int guideIndex, int highIndex) : length(length), guideIndex(guideIndex), highIndex(highIndex)
    {
        displayBar();
    }

    void displayBar()
    {
        for (int i = 0; i < WIDTH * length * 2; i++)
        {
            if (i % (WIDTH * 2) == 0 && i != 0)
            {
                box.push_back(' ');
                box.push_back('*');
            }
            else
                box.push_back('*');
        }

        box.push_back('\n');

        for (int i = 0; i < LENGTH / 2; i++)
        {
            for (int j = 0; j <= WIDTH * length * 2; j++)
            {
                if (j == 0)
                    box.push_back('*');
                else if (j % (WIDTH * 2) == 0)
                {
                    if (j == WIDTH * length * 2)
                    {
                        for (int i = 0; i < to_string(length).length(); i++)
                        {
                            box.push_back(to_string(length)[i]);
                        }
                    }
                    else
                    {
                        box.push_back('*');
                        box.push_back(' ');
                        box.push_back('*');
                    }
                }
                else
                {
                    if (j % (WIDTH * 2 - 1) == 0)
                        continue;
                    else
                        box.push_back(' ');
                }
            }
            box.push_back('\n');
        }
        for (int i = 0; i < WIDTH * length * 2; i++)
            if (i % (WIDTH * 2) == 0 && i != 0)
            {
                box.push_back(' ');
                box.push_back('*');
            }
            else
                box.push_back('*');
        
        #ifdef _WIN32
            static int color = 1;
            if (highIndex == guideIndex)
            {
                SetConsoleTextAttribute(console, color);
                color++;
            }

            cout << box << endl;
            SetConsoleTextAttribute(console, 15);
        #elif __linux__
            static int color = 30;
            if (highIndex == guideIndex){
                    cout << "\033[1;" << color << "m" << box << "\033[0m\n";
                    color++;
            }
            else
                cout << box << endl;
        #endif
        count++;
        // this_thread::sleep_for(chrono::milliseconds(250)); uncomment for a surprise (jk)

        if (count % size == 0 && count != size * size)
        {
            this_thread::sleep_for(chrono::milliseconds(500));
        #ifdef _WIN32
            system("cls");
        #elif __linux__
            system("clear");
        #endif
        }
    }
};

void bubbleSort(int arr[], int size, vector<Bar> sortedBars)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] < arr[j])
                swap(arr[i], arr[j]);

            sortedBars.push_back(Bar(arr[j], j, i));
        }
    }
}

int main()
{
    int list[] = {30, 24, 1, 23, 15, 9, 7, 29}; // ONLY EDIT THIS
    size = sizeof(list) / sizeof(list[0]);
    vector<Bar> bars;

    bubbleSort(list, size, bars);

    cout << "Sorted List: ";
    for (int i : list)
        cout << i << " ";

    return 0;
}
