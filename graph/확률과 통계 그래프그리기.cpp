// 확률과 통계 그래프그리기.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>

#include <math.h> //sin함수 쓰기위해 사용



#define PI 3.141592



void sine(); //함수 선언



int main(void)

{

	sine();


	return 0;

}



void sine(void) //sin값과 그래프를 출력하는 함수

{

	double temp; //sine값을 받을 변수

	int i, j;



	for (i = 0; i <= 360; i += 15) {

		temp = sin((i*(PI / 180))); //sin에 라디안값 넣어줌

		printf("sin(%3d) = %+.2lf", i, temp);

		for (j = -10; j<temp * 10; j++) //sin값 만큼 띄워줌

			printf(" ");

		printf("*\n"); //그래프 찍고 줄바꿈

	}



}

