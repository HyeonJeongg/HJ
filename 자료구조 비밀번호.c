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
		printf("메뉴를 선택하세요 \n");
		printf("1. 비밀번호 입력, 2. 관리자 로그인\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			srand(time(NULL));
			randomv = rand() % m;
			randomw = rand() % n;


			printf("\n비밀번호를 입력하세요:");
			getchar();
			gets_s(str1, sizeof(str1));

			start = clock();
			nums1 = strlen(str1);
			arr[randomv][randomw] = nums1;
			if (k < 4) //비밀번호 자리수를 관리자 비밀번호로 순차 입력
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
			fprintf(stdout, "\n수행시간은 %lf 입니다\n", runtime);
			fprintf(fp, "\n수행시간은 %lf 입니다\n", runtime);
		}
		else if (choice == 2)
		{	getchar();
			
		printf("\n관리자 비밀번호: ");
			
			
			
			for (q = 0; q < 4; q++)
			{
				
				scanf("%1d", &input[q]); // %1d를 함으로써 한자리만 입력받음
			}
		
			

			r=adinput(admin, input);


			if (r == 4)
			{
				printf("\n 비밀번호가 일치합니다\n");
				fclose(fp);
				system("notepad.exe rand.txt");
				
			}
			else if(r==5){
				fclose(fp); 
				printf("\n 비밀번호가 일치하지 않습니다\n");
				
			}
			

		}
	}
	return 0;

}





int adinput(int* admin, int*input) //admin과 input을 비교
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