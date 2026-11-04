#include <stdlib.h>

int my_string_index(char *str, char c)
{
	int i = 0;
	while (str[i]) {
		if (str[i] == c)
			return i;
		i++;
	}
	return -1;
}

char* inter(char* s1, char* s2)
{
	char *result = malloc(10000);
	int used[256] = {0};
	int seen[256] = {0}; // prevent duplicates in output
	int i = 0, j = 0;

	// mark all chars in s2
	while (s2[i]) {
		used[(unsigned char)s2[i]] = 1;
		i++;
	}

	i = 0;
	while (s1[i]) {
		unsigned char c = s1[i];
		if (used[c] && !seen[c]) {
			seen[c] = 1;
			result[j++] = c;
		}
		i++;
	}
	result[j] = '\0';
	return result;
}
