#include "algorithm.h"

// djb2 algorithm
// http://www.cse.yorku.ca/~oz/hash.html
unsigned int GetHash(char* str)
{
	unsigned int hash = 5381;

	while (*str != 0)
	{
		hash = ((hash << 5) + hash + *str);
	}

	return hash;
}

// double hashing
unsigned int GetJump(unsigned int index, unsigned int prime)
{
	return (prime - (index % prime));
}