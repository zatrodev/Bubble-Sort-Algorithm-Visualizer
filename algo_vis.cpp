#include <cstdlib>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#define LENGTH 4 // YOU CAN CHANGE THIS TOO
#define WIDTH 4  // THIS TOO
using namespace std;

int count = 0;
size_t size;

class Bar
{
private:
    string box;

public:
    int length;

    Bar(int length) : length(length)
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
                        box.push_back(to_string(length)[0]);
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

        cout << box << endl;
        count++;
        // this_thread::sleep_for(chrono::milliseconds(250)); uncomment for a surprise (jk)

        if (count % size == 0)
        {
            this_thread::sleep_for(chrono::milliseconds(750));
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

            sortedBars.push_back(Bar(arr[j]));
        }
    }
}

int main()
{
    int list[] = {4, 5, 3, 9, 8, 11}; // ONLY EDIT THIS
    size = sizeof(list) / sizeof(list[0]);
    vector<Bar> bars;

    for (int i = 0; i < size; i++)
        bars.push_back(Bar(list[i]));

    bubbleSort(list, size, bars);

    return 0;
}
