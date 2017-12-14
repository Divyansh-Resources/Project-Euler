#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    const int BLOCKS = 50;

    vector <long long> red(BLOCKS + 1, 1);
    for(int i = 2 ; i <= BLOCKS; i++)
        red[i] = red[i - 1] + red[i - 2];

    vector <long long> green(BLOCKS + 1, 1);
    for(int i = 3 ; i <= BLOCKS; i++)
        green[i] = green[i - 1] + green[i - 3];

    vector <long long> blue(BLOCKS + 1, 1);
    for(int i = 4; i <= BLOCKS; i++)
        blue[i] = blue[i - 1] + blue[i - 4];

    long long total_red = red[BLOCKS] - 1, total_green = green[BLOCKS] - 1, total_blue = blue[BLOCKS] - 1;
    long long total = total_red + total_green + total_blue;

    printf("There are %I64d ways to tile %d blocks.\n", total, BLOCKS);
    return 0;
}
