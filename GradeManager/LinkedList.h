#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>

#include "Grade.h"

typedef struct
{
	Node* nextNodeLink;
	Grade* studentGrade;
} Node;


Node* InitNode();
void DeleteNode(Node* _node);

void SaveGrade(Grade* _grade)
{
	if (_grade == NULL)
	{
		printf("Save Error");
		exit(-1);
	}

	FILE* fp = fopen("GradeStroage.txt", "at");
	fprintf(fp, "%s %d %c\n", _grade->subjectName, _grade->subjectScore, _grade->subjectGrade);

	fclose(fp);
}

void LoadGrade(Grade* _grade)
{
	if (_grade == NULL)
	{
		printf("Load Error");
		exit(-1);
	}

	FILE* fp = fopen("GradeStroage.txt", "rt");

	if (!feof(fp))
	{
		fscanf(fp, "%s %d %c", _grade->subjectName, &_grade->subjectScore, &_grade->subjectGrade);
	}
	else
	{
		printf("Load buffer is out of range");
		exit(-1);
	}

	fclose(fp);
}


#endif 