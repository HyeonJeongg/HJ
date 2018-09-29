#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int fact(int n);
void hanoi(int n, int start, int work, int target,FILE* p);

int main()
{
	FILE* p;
	int n, result=1;
	double d1,d2;
	clock_t start, finish, s, f;
	while (1) {
		printf("\n���ڸ� �Է��ϼ���:");
		scanf("%d", &n);
		s = clock();
		start = clock();
		if (n < 0)
			break;
		else
			p = fopen("test.txt", "at+");
			
			hanoi(n, 'A', 'B', 'C',p);
			f = clock();

			
			result = fact(n);
			printf("\n%d!�� ���� %d�Դϴ�\n", n, result);
			finish = clock();
		
		d1 = (double)(f - s) / CLOCKS_PER_SEC;
		d2 = (double)(finish - start) / CLOCKS_PER_SEC;
		fprintf(p, "\n�ϳ���Ÿ�� �ɸ��ð��� %lf�Դϴ�\n", d1);
		fprintf(stdout,"�ϳ���Ÿ�� �ɸ��ð��� %lf�Դϴ�\n", d1);
		fprintf(p, "\n���丮�� �Լ� �ɸ��ð��� %lf�Դϴ� \n", d2);
		fprintf(stdout, "\n���丮�� �Լ� �ɸ��ð��� %lf�Դϴ� \n", d2);
		fclose(p);
		system("notepad.exe test.txt");
	}


	getchar();
	return 0;
}

void hanoi(int n, int start, int work, int target, FILE* p)
{
	if (n == 1)
		printf("%c���� ����%d�� %c�� �̵�\n", start, n, target);

	else
	{
		hanoi(n - 1, start, target, work,p);
		printf("%c���� ����%d�� %c�� �̵�\n", start, n, target);
		hanoi(n - 1, work, start, target,p);
	}
}

int fact(int n) {
	int i, value = 1;
	if (n <= 1) {
		
		return 1;
	}
	else {
		
		for (i = n; i > 0; i--)
			value = (value*i);
		return value;
	}
}
