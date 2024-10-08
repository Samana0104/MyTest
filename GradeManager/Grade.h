/*
	저자 : 변한빛
	작성일 : 2024-04-16
*/

#ifndef __GRADE_H__
#define __GRADE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char subjectName[20];
	char subjectGrade;
	int subjectScore;
} Grade; // 구조체 특성으로 인해 Score 배치를 마지막으로 둠

void PrintGrade(Grade* _grade)
{
	if (_grade == NULL)
	{
		printf("Print Error");
		exit(-1);
	}

	printf("[과목 : %s][성적 : %d][학점 : %c]",
		_grade->subjectName,
		_grade->subjectScore,
		_grade->subjectGrade
	);
}

#endif 