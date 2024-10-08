/*
	���� : ���Ѻ�
	�ۼ��� : 2024-04-16
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
} Grade; // ����ü Ư������ ���� Score ��ġ�� ���������� ��

void PrintGrade(Grade* _grade)
{
	if (_grade == NULL)
	{
		printf("Print Error");
		exit(-1);
	}

	printf("[���� : %s][���� : %d][���� : %c]",
		_grade->subjectName,
		_grade->subjectScore,
		_grade->subjectGrade
	);
}

#endif 