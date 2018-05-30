#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    const int NO_OF_LINES = 1000;
	int answer_line_no;
	long long best_result = 0;

	for(int i = 1; i <= NO_OF_LINES; i++)
	{
		int base, exponent;
		scanf("%d,%d", &base, &exponent);

		long double result = exponent*log(base);

		if(result > best_result)
			best_result = result, answer_line_no = i;
	}

	printf("%d\n", answer_line_no);
	return 0;
}
