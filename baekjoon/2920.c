#include <stdio.h>

int main()
{
	int i, acnt = 0, dcnt = 0;
	int a[8];
	scanf("%d", a);
	for (i = 1; i < 8; i++)
	{
		scanf("%d", a+i);
		if (a[i] > a[i - 1]) acnt++;
		else if (a[i] < a[i - 1]) dcnt++;
	}

	if (acnt == 7) printf("ascending");
	else if (dcnt == 7) printf("descending");
	else printf("mixed");

	return 0;
}
