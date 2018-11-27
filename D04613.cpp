
#include <iostream>
using namespace std;
#include <cstring>


int EditDistance(char *a, char *b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	int *v1 = new int [len2 + 1];
	int *v2 = new int [len2 + 1];
	int *temp;

	int i;
	for (i = 0; i <= len2; ++i)v2[i] = i;

	int n;
	for (n = 1; n <= len1; ++n)
	{
		temp = v2; v2 = v1; v1 = temp;

		v2[0] = n;
		for (i = 1; i <= len2; ++i)
		{
			if (a[n - 1] == b[i - 1])	v2[i] = v1[i - 1];
			else v2[i] = min(v2[i - 1], min(v1[i], v1[i - 1])) + 1;
		}
		// int z;
		// for (z = 0; z <= len2; ++z)cout << " " << v2[z];
		// cout << endl;
	}

	int result = v2[len2];
	delete []v1;
	delete []v2;
	return result;
}

int main(int argc, char const *argv[])
{
	char a[] = "abcdefgh";
	char b[] = "acxdeyfzh";
	cout << EditDistance(a, b) << endl;

	return 0;
}