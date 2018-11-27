

#include <iostream>
using namespace std;
#include <cstring>


bool inchararray(char* a, int k, int i)
{
	int n;
	for (n = k ; n < i; ++n)
	{
		if (a[n] == a[i])return true;
	}
	return false;
}

void CPerm(char *a, int n, int k = 0)
{
	int i;
	char c;
	if (k == n)
	{
		for (i = 0; i < n; ++i)cout << a[i];
		cout << endl;
		return;
	}

	for (i = k; i < n; ++i)
	{

		if (!inchararray(a, k , i))
		{
			c = a[i]; a[i] = a[k]; a[k] = c;
			CPerm(a, n, k + 1);
			c = a[i]; a[i] = a[k]; a[k] = c;
		}
	}

}
void CPerm(char * a)
{
	CPerm(a, strlen(a), 0);
}

int main(int argc, char const *argv[])
{
	char str[] = "aac";
	CPerm(str);
	return 0;
}