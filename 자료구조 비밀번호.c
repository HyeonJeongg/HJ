#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

int adinput(int* admin, int*input);


int main()
{
	FILE* fp;
	clock_t start, finish;
	double runtime;
	srand(time(NULL));
	int m = (rand() % 19)+2, n = (rand() % 19)+2;
	int randomv, randomw;
	int **arr;
	int i, j, k = 0,q=0,r, choice, nums1;
	int str1[20], admin[5], input[5];;


	arr = (int**)malloc(sizeof(int)*m);


	for (i = 0; i < m; i++)
		arr[i] = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			arr[i][j] = 0;
	}


	while (1)
	{
		printf("�޴��� �����ϼ��� \n");
		printf("1. ��й�ȣ �Է�, 2. ������ �α���\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			srand(time(NULL));
			randomv = rand() % m;
			randomw = rand() % n;


			printf("\n��й�ȣ�� �Է��ϼ���:");
			getchar();
			gets_s(str1, sizeof(str1));

			start = clock();
			nums1 = strlen(str1);
			arr[randomv][randomw] = nums1;
			if (k < 4) //��й�ȣ �ڸ����� ������ ��й�ȣ�� ���� �Է�
			{
				admin[k] = nums1;
				k++;
			}
			fp = fopen("rand.txt", "at+");

			for (i = 0; i < m; i++)
			{
				fprintf(fp, "\n");
				for (j = 0; j < n; j++)
				{
					fprintf(fp, "%2d", arr[i][j]);



				}
			}
			fprintf(fp, "\n");


			finish = clock();
			runtime = (double)(finish - start) / CLOCKS_PER_SEC;
			fprintf(stdout, "\n����ð��� %lf �Դϴ�\n", runtime);
			fprintf(fp, "\n����ð��� %lf �Դϴ�\n", runtime);
		}
		else if (choice == 2)
		{	getchar();
			
		printf("\n������ ��й�ȣ: ");
			
			
			
			for (q = 0; q < 4; q++)
			{
				
				scanf("%1d", &input[q]); // %1d�� �����ν� ���ڸ��� �Է¹���
			}
		
			

			r=adinput(admin, input);


			if (r == 4)
			{
				printf("\n ��й�ȣ�� ��ġ�մϴ�\n");
				fclose(fp);
				system("notepad.exe rand.txt");
				
			}
			else if(r==5){
				fclose(fp); 
				printf("\n ��й�ȣ�� ��ġ���� �ʽ��ϴ�\n");
				
			}
			

		}
	}
	return 0;

}





int adinput(int* admin, int*input) //admin�� input�� ��
{
	int u,w=0;
	for (u = 0; u < 4; u++) {

		if (admin[u] == input[u])
		{
			w++;
			
		
		}
		else if (admin[u] != input[u]) {
			return 5;
		}
	}
	if (w == 4) {
		return 4;
	}
}