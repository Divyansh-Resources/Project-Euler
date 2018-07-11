#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    const int NO_OF_DIGITS = 100;

    const double PHI = 1.618033987;
    int answer = ceil( (NO_OF_DIGITS - 1 + log10(5)/2)/(log10(PHI)) );

    cout << answer << "\n";

    return 0;
}
