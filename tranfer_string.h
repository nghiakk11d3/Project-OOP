
#ifndef TRANFER_STRING
#define TRANFER_STRING

#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <string.h>

int tranfer_string_customer(char string[])
{
	// find the length of the string
	int len = strlen(string);

	int exp = 1;
	int num_integer = 0;

	for (int i = 0; i <= len; i++)
	{
		if (string[i] == '\n')
		{
			len = len - 1;
		}
	}

	while (len > 0)
	{
		int temp = string[len - 1] - '0';
		num_integer = num_integer + temp * exp;
		exp *= 10;
		len--;
	}
	return num_integer;
}

int tranfer_string(char string[])
{
	// find the length of the string
	int len = strlen(string);
	int exp = 1;
	int num_integer = 0;

	for (int i = 0; i <= len; i++)
	{
		if (string[i] == '\n')
		{
			len = len - 1;
		}
	}

	while (len > 0)
	{
		int temp = string[len - 1] - '0';
		num_integer = num_integer + temp * exp;
		exp *= 10;
		len--;
	}
	return num_integer;
}

#endif