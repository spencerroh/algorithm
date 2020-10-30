#pragma once
#include "algorithm.h"

uint GetLength(char* str)
{
	uint length = 0;
	while (*str++ != 0) length++;
	return length;
}

void CopyString(char* dest, char* src)
{
	while((*dest++ = *src++));
}

int CompareString(char* s1, char* s2)
{
	while (*s1 && (*s1++ == *s2++));
	return *s1 - *s2;
}

char* Clone(char* src)
{
	uint length = GetLength(src);
	char* clone = new char[length];
	CopyString(clone, src);

	return clone;
}
