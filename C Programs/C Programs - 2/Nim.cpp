#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    const int MAX_LENGTH = 30;

    vector <int> no_of_strings(MAX_LENGTH + 1);

    no_of_strings[1] = 2;
    no_of_strings[2] = 3;

    for(int i = 3; i <= MAX_LENGTH; i++)
    {
        no_of_strings[i] = no_of_strings[i - 1] + no_of_strings[i - 2];
    }

    printf("The number of numbers up to 2^30 with no consecutive 1s is %d\n", no_of_strings[MAX_LENGTH]);
    return 0;
}
