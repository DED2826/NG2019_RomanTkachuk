#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main()
{
    int pposx = 10;
    int pposy = 10;
    srand(time(0));
    char mas[30][30];
    char pmap[30][30];
    int sz = 30;

    for (int i=0; i<sz; i++)
    {
        for (int j=0; j<sz; j++)
        {
            pmap[i][j] = '*';
            mas[i][j] = ' ';
            if (j == sz-1 ||
                    j == 0 ||
                    i == sz-1 ||
                    i == 0)
                mas[i][j] = 't';
            else
            {
                int chance = rand()%40;
                if (chance == 0)
                    mas[i][j] = 's';
                if (chance == 1)
                    mas[i][j] = 't';
            }
        }
    }


    pmap[pposy][pposx] = '@';
    while (1)
    {
        system("clear");
        for (int i=0; i<sz; i++)
        {
            for (int j=0; j<sz; j++)
            {
                cout << pmap[i][j];
            }
            cout << endl;
        }
        int action = -1;
        cout << endl << endl << ">";
        cin >> action;
        int newposx = pposx;
        int newposy = pposy;
        switch (action) {
        case 8: newposy--; break;
        case 2: newposy++; break;
        case 4: newposx--; break;
        case 6: newposx++; break;
        case 0: cout << "bye!"; return 0;
        }

        if (newposx >= sz ||
                newposx < 0 ||
                newposy >= sz ||
                newposy < 0)
            cout << "WRONG MOVE" << endl;
        else
        {
            if (mas[newposy][newposx] == 't' ||
                    mas[newposy][newposx] == 's')
                cout << "Oh god! I can't step here" << endl;
            else
            {
                pmap[pposy][pposx] = mas[pposy][pposx];
                pmap[newposy][newposx] = '@';
                // Let's see all around us
                pmap[newposy][newposx+1] = mas[newposy][newposx+1];
                pmap[newposy][newposx-1] = mas[newposy][newposx-1];
                pmap[newposy-1][newposx] = mas[newposy-1][newposx];
                pmap[newposy+1][newposx] = mas[newposy+1][newposx];

                pmap[newposy-1][newposx+1] = mas[newposy-1][newposx+1];
                pmap[newposy+1][newposx+1] = mas[newposy+1][newposx+1];
                pmap[newposy-1][newposx-1] = mas[newposy-1][newposx-1];
                pmap[newposy+1][newposx-1] = mas[newposy+1][newposx-1];
                pposx = newposx;
                pposy = newposy;
            }
        }

    }
}
