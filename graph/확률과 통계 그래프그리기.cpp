// Ȯ���� ��� �׷����׸���.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include <stdio.h>

#include <math.h> //sin�Լ� �������� ���



#define PI 3.141592



void sine(); //�Լ� ����



int main(void)

{

	sine();


	return 0;

}



void sine(void) //sin���� �׷����� ����ϴ� �Լ�

{

	double temp; //sine���� ���� ����

	int i, j;



	for (i = 0; i <= 360; i += 15) {

		temp = sin((i*(PI / 180))); //sin�� ���Ȱ� �־���

		printf("sin(%3d) = %+.2lf", i, temp);

		for (j = -10; j<temp * 10; j++) //sin�� ��ŭ �����

			printf(" ");

		printf("*\n"); //�׷��� ��� �ٹٲ�

	}



}

