// HW 10: Find SQRT of Integer N using Binary Search with K point decimal precision
#include <iostream>
#include <vector>

using namespace std;

// INTEGER PART OF SQRT
int mySqrt(int n)
{
    int s = 0, e = n;
    int ans = 0;
    while (s <= e)
    {
        int mid = (e - s) / 2 + s;

        // predicate fn
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1; // go right
        }
        else
            e = mid - 1; // go left
    }
    return ans;
}

// INTEGER + PRECISION PART OF SQRT
double myPrecisionSqrt(int n)
{
    double sqrt = mySqrt(n);
    int precision = 10;
    double step = 0.1;
    for (int i = 0; i < precision; ++i)
    {
        double j = sqrt;
        while (j * j <= n)
        {
            sqrt = j;
            j += step;
        }
        step /= 10;
    }
    return sqrt;
}

int main()
{
    int n = 63;
    cout << myPrecisionSqrt(n) << endl;
    return 0;
}
