#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int stu_score[15];
int b;
int stu_num = 15;

void score() {
	FILE *fp = fopen("student_score.txt", "r");
	char c[100];
	for(int u = 0; u<=15; u++){
		fscanf(fp, "%d %s %d", &b, c, &stu_score[u]);
	}
	printf("\n");
	fclose(fp);
}




void list() {
	char buffer[5] = { 0, };    // ���ڿ� ������ 4����Ʈ NULL 1����Ʈ. 4 + 1 = 5
	int count = 0;
	int total = 0;

	FILE *fp = fopen("student_score.txt", "r");    // hello.txt ������ �б� ���(r)�� ����.
										   // ���� �����͸� ��ȯ

	while (feof(fp) == 0)    // ���� �����Ͱ� ������ ���� �ƴ� �� ��� �ݺ�
	{
		count = fread(buffer, sizeof(char), 4, fp);    // 1����Ʈ�� 4��(4����Ʈ) �б�
		printf("%s", buffer);                          // ���� ���� ���
		memset(buffer, 0, 5);                          // ���۸� 0���� �ʱ�ȭ                             // ���� ũ�� ����
	}


	fclose(fp);    // ���� ������ �ݱ�


}

float sum() {
	float sum = 0;
	for (int n = 0; n < stu_num; n++) {
		sum += stu_score[n];
	}
	sum = sum / stu_num;

	return sum;

}

float mode() {
	float mode = 0;
	int freq = 1;
	int count = 1;

	for (int i = 0; i < stu_num; i++) {

		freq = 1;
		
		for (int j = 1; j <= stu_num; j++) {
			
			if (stu_score[i] == stu_score[j]) {

				freq++;

			}
				if (freq >= count) {
					mode = stu_score[i];
					count = freq;

			}

		}
	}

	return mode;

}


float var() {
	float sum = 0;
	float var = 0;
	for (int n = 0; n < stu_num; n++) {
		sum += stu_score[n];
	}
	sum = sum / stu_num;
	for (int i = 0; i < stu_num; i++) {
		var += (stu_score[i] - sum)*(stu_score[i] - sum);
	}

	return var;
}

	

int main(void) {
	int y = 0;

	list();
	printf("\n---------------------------");
	printf("\n�л����� ����� Ȯ���մϴ�\n");
	printf("---------------------------\n");
	scanf("%d", &y);
	if (y == 1) {


		score();


		for (int i = 0; i <= 20; i++) {
			int y = 100 - 5 * i;

			if (y < 10) {
				printf(" %d ", y);
			}
			else if (y == 100) {
				printf("%d", y);
			}
			else if (10 < y < 100) {
				printf(" %d", y);
			}

			for (int j = 0; j < 15; j++) {
				if (20 - i <= stu_score[j] / 5) printf("  *  ");
				else printf("     ");
			}
			printf("\n");
		}

		printf("     ");
		for (int i = 1; i <= stu_num; i++) {
			if (i >= 10) {
				printf("%d   ", i);
			}
			else printf("%d    ", i);
		}
		printf("\n");
		printf("----------------------------------------------------------------------------------\n");
		printf("��հ�:%f                  �ֺ�:%f", sum(), mode());
		printf("\n----------------------------------------------------------------------------------\n");
		printf("�л�:%f                ǥ������:%f\n", var(), sqrt(var()));

		printf("\nby.ȫ����\n");

	}
	return 0;
}

