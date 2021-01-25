#pragma once
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned long ulong;


// String
uint GetLength(char* str);
void CopyString(char* dest, char* src);
char* Clone(char* src);
int CompareString(char* s1, char* s2);

unsigned int GetHash(char* str);
unsigned int GetJump(unsigned int index, unsigned int prime);

// Linked List
template <class T>
struct List
{
	T Value;
	List<T>* Next;
};

template <class T>
List<T>* Add(List<T>** head, T value);

template <class T>
void Remove(List<T>** head, T value);

template <class T>
void Clear(List<T>** head);

#include "Heap.h"
#include "Sort.h"

