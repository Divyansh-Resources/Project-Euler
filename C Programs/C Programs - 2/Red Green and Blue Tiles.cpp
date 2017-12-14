#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    const int BLOCKS = 50;

    vector <long long> tilings(BLOCKS + 1, 1);

    tilings[2] = tilings[1] + tilings[0];
    tilings[3] = tilings[2] + tilings[1] + tilings[0];

    for(int i = 4; i <= BLOCKS; i++)
        tilings[i] = tilings[i - 1] + tilings[i - 2] + tilings[i - 3] + tilings[i - 4];

    printf("There are %I64d ways of tiling %d blocks.\n", tilings[BLOCKS], BLOCKS);
    return 0;
}
