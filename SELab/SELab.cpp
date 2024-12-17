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
            throw "Incorrect number entered.";
        }
        else
        {
            cin.ignore(32767, '\n');
            return a;
        }
    }
}

double CalculateIteration(double x, double n)
{
    double sum{}, mlt{ 1 };

    if (x < 0)
    {
        for (int i = 1; i <= n; i++)
        {
            mlt = mlt * (1 / (1 - x));
        }
        return mlt;
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
        return (sum + 4 * x);
    }
}


int main()
{
    double a, b, nx = 0, y;
    int n = 0;

    try
    {
        cout << "Enter interval\n";
        cout << "a= ";

        a = getValue();

        b = a;
        cout << "b (>a) = ";
        b = getValue();

        if (b <= a)
        {
            throw "Incorrect interval specified (b>a).";
        }
        cout << "Enter step\n";

        nx = getValue();

        if (nx <= 0 || nx > (b - a))
        {
            throw "Incorrect step specified.";
        }

        cout << "Enter n>2(The fractional part will be discarded): ";
        n = getValue();

        if (n <= 2)
        {
            throw "incorrect value n. The value must be greater than 2";
        }
        for (double x = a; x <= b; x = x + nx)
        {

            cout << "Argument (x)=" << x << "; Function value y(x)=" << CalculateIteration(x, n) << endl;
        }
    }
    catch (const char* error_input)
    {
        cout << error_input << endl;
        return -1;
    }

    
}