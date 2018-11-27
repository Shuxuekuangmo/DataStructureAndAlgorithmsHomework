#include <iostream>
using namespace std;
#include <cstring>

bool StringMatch(char *a, char* b)
{
	// a is the string who is waiting to be matched
	int len1 = strlen(a);
	int len2 = strlen(b);
	bool *v1 = new bool [len1 + 1];
	bool *v2 = new bool [len1 + 1];
	bool *temp;

	int i, j, k;

	for (i = 1; i <= len1; ++i)v2[i] = false;
	v2[0] = true;

	// for (k = 0; k <= len1; ++k)
	// 	cout << v2[k] << " ";
	// cout << endl;


	for (i = 1; i <= len2; ++i)
	{
		temp = v2; v2 = v1; v1 = temp;
		v2[0] = false;
		for (j = 1; j <= len1; ++j)
		{
			if (b[i - 1] == '*')  v2[j] = (v2[j - 1] || v1[j]);
			else if (b[i - 1] == '?')  v2[j] = v1[j - 1];
			else v2[j] =  v1[j - 1] && (a[j - 1] == b[i - 1]);
		}
		// for (k = 0; k <= len1; ++k)
		// 	cout << v2[k] << " ";
		// cout << endl;
	}

	bool result = v2[len1];
	delete []v1;
	delete []v2;
	return result;
}
int main(int argc, char const *argv[])
{
	char a[] = "ABCDEFasdaswG";
	char b[] = "A?CD*G";
	cout << StringMatch(a, b) << endl;
	return 0;
}