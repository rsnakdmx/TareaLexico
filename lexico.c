#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool matchPattern(const char *, char * restrict);

int main(int argc, char *argv[])
{
	if (argc > 1)
		return -1;

	else
	{
		char string[256];

		printf("Escribe la cadena a evaluar: ");
		scanf("%256s", string);

		if (matchPattern("aeiou", string))
		{
			printf("Match!");
			return 0x0;
		}

		else
		{
			printf("Not match!");
			return -1;
		}
	}
}

bool matchPattern(const char * pattern, char * restrict string)
{
	if (!pattern || !string)
		return false;

	else
	{
		int size = strlen(string), pattSize = strlen(pattern), match = 0, idx = 0;

		for (int i = 0; i < size; i++)
		{
			if (pattern[idx] == string[i])
			{
				match++;

				if (size > (i + 1) && pattSize > idx && pattern[idx + 1] == string[i + 1])
					idx++;
			}
		}

		if (match == size && idx == (pattSize - 1))
			return true;

		return false;
	}
}