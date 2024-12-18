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

int CheckValidParams(double a, double b, double nx, int n)
{
    int err{};

    if (b <= a) 
    {
        err = 1;
    }
    if (nx <= 0 || nx > (b - a))
    {
        err = err + 2;
    }
    if (n <= 2)
    {
        err = err + 4;
    }
    if (err)
    {
        throw err;
    }
    return 1;
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
    double a, b, nx = 0;
    int n = 0;

    try
    {
        cout << "Enter interval\n";
        cout << "a= ";

        a = getValue();

       // b = a;
        cout << "b (>a) = ";
        b = getValue();

        cout << "Enter step\n";
        nx = getValue();

        cout << "Enter n>2(The fractional part will be discarded): ";
        n = getValue();

        CheckValidParams(a, b, nx, n);

        for (double x = a; x <= b; x = x + nx)
        {

            cout << "Argument (x)=" << x << "; Function value y(x)=" << CalculateIteration(x, n) << endl;
        }
    }
    catch (const int error_input)
    {
        if (error_input & 1)
        {
            cout << "Incorrect interval specified (b>a).\n";
        }
        if (error_input & 2)
        {
            cout << "Incorrect step specified.\n";
        }
        if (error_input & 4)
        {
            cout << "incorrect value n. The value must be greater than 2.\n";
        }

        return -1;
    }
    catch (const char* error)
    {
        cout << error<< "\n";
    }
}