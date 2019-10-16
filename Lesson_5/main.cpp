#include <iostream>

using namespace std;

int getMax(int values[], int valuesSize)
{
    int maximum = values[0];
    for (int i=1; i<valuesSize; i++)
        if (values[i] > maximum)
            maximum = values[i];
    return maximum;
}

void showSumm(int values[], int valuesSize)
{
    int summ = 0;
    for (int i=0; i<valuesSize; i++)
        summ += values[i];
    cout << summ;
}

int main()
{
    int numbers[5];
    numbers[0] = 5;
    numbers[1] = 7;
    numbers[2] = 2;
    numbers[3] = 1;
    numbers[4] = 9;

    showSumm(numbers, 5);
    cout << endl << "Maximum: " << getMax(numbers, 5);

    return 0;
}
