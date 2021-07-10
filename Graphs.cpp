#include <iostream>
#include <string>

using namespace std;

void points(int n, int x)
{
    int ch[10] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 };
    char c[10] = { '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' };
    int vih[10] = { 0,0,0,0,0,0,0,0,0,0 };
    int vho[10] = { 0,0,0,0,0,0,0,0,0,0 };
    int* vi, * vh;
    string otvet;
    cout << " From which points to which paths exist, answer in the format: x0-x2 " << endl;

    vi = new int[n];
    vh = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> otvet;
        for (int j = 0; j <= 9; j++)
        {
            if (otvet[1] == c[j])
            {
                vi[i] = ch[j];
            }
            if (otvet[4] == c[j])
            {
                vh[i] = ch[j];
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ch[i] == vi[j])
            {
                vih[i] = vih[i] + 1;
            }
            if (ch[i] == vh[j])
            {
                vho[i] = vho[i] + 1;
            }
        }
    }

    for (int l = 0; l < x; l++)
    {
        cout << " do(x" << l << ") =" << vih[l] << endl;
    }
    cout << endl;
    for (int l = 0; l < x; l++)
    {
        cout << " dt(x" << l << ") =" << vho[l] << endl;
    }
    cout << endl;

    for (int l = 0; l < x; l++)
    {
        if (vih[l] == 0)
        {
            if (vho[l] == 0)
                cout << " (x" << l << ") - isolated point " << endl;
            else
                cout << " (x" << l << ") - dead end point " << endl;
        }
        else if (vho[l] == 0)
        {
            cout << " (x" << l << ") - âhanging point " << endl;
        }
    }
}

void matr_smeg(int n, int x)
{
    int ch[10] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 };
    char c[10] = { '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' };
    int* vi, ** vh, * vs;
    vi = new int[n];
    vh = new int* [x];
    string otvet;
    cout << " From which points to which paths exist, answer in the format: x0-x2 " << endl;

    for (int i = 0; i < x; i++)
    {
        vh[i] = new int[x];
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            vh[i][j] = 0;
        }
    }

    for (int i = 0; i < n * 2; i = i + 2)
    {
        cin >> otvet;
        for (int j = 0; j <= 9; j++)
        {
            if (otvet[1] == c[j])
            {
                vi[i] = ch[j];
            }
            if (otvet[4] == c[j])
            {
                vi[i + 1] = ch[j];
            }
        }

    }

    for (int l = 0; l < x; l++)
    {
        for (int f = 0; f < x; f++)
        {
            for (int i = 0; i < n * 2; i = i + 2)
            {
                if (l == vi[i] && f == vi[i + 1])
                {
                    vh[l][f] = 1;
                    vi[i] = 99;
                    vi[i + 1] = 99;
                }
            }
        }
    }

    cout << " \nAdjacency matrix: " << endl;
    cout << "  ";
    for (int j = 0; j < x; j++)
    {
        cout << "x" << j << " ";
    }
    cout << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "x" << i << " ";
        for (int j = 0; j < x; j++)
        {
            cout << vh[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    setlocale(0, "");
    int x1, n1, vvod;
    cout << " Enter quantity points: ";
    cin >> x1;
    cout << " Enter quantity of roads: ";
    cin >> n1;
    cout << "\nEnter number:\n \nHalf-way in and out - 1 \nAdjacency matrix - 2\n";
    cin >> vvod;
    cout << endl;
    switch (vvod)
    {
    case 1: points(n1, x1);
        break;
    case 2: matr_smeg(n1, x1);
        break;
    default: cout << " Invalid number entered. " << endl;
    }
}
