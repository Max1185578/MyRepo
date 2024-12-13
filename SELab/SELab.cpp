#include <iostream>
using namespace std;

double getValue()
{
    while (true)
    {
        double a;
        cin >> a;


        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            cin.ignore(32767, '\n');

            return a;
        }
    }
}


int main()
{
    double a, b, nx = 0, mlt, sum, y;
    int n = 0;

    cout << "Enter interval\n";
    cout << "a= ";
    a = getValue();
    b = a;

    cout << "b (>a) = ";

    while (b <= a)
    {
        b = getValue();
        if (b <= a)
        {
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
    }


    cout << "Enter step\n";

    while (nx <= 0 || nx > (b - a))
    {
        nx = getValue();

        if (nx <= 0 || nx > (b - a))
        {
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
    }


    cout << "Enter n>2(The fractional part will be discarded): ";

    while (n <= 2)
    {
        n = getValue();

        if (n <= 2)
        {
            cout << "Oops, that input is invalid.  Please try again.\n";
        }
    }

    for (double x = a; x <= b; x = x + nx)
    {
        sum = 0;
        mlt = 1;

        if (x < 0)
        {
            for (int i = 1; i <= n; i++)
            {
                mlt = mlt * (1 / (1 - x));
            }
            y = mlt;
        }
        else
        {
            for (int j = 0; j <= (n - 2); j++)
            {
                mlt = 1;
                for (int i = 0; i <= n + 1; i++)
                {
                    mlt = mlt * (x + i + j * j / (i + 1));
                }
                sum = sum + mlt;
            }
            y = sum + 4 * x;
        }
        cout << "Argument (x)=" << x << "; Function value y(x)=" << y << endl;
    }

}