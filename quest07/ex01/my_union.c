#include <stdlib.h>

int	my_string_index(char *str, char c)
{
	int i = 0;
	while (str[i]) {
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char* my_union(char* param_1, char* param_2)
{
	char *result = malloc(10000); // safe big size for now
	int seen[256] = {0};
	int i = 0;
	int j = 0;

	while (param_1[i]) {
		unsigned char c = param_1[i];
		if (!seen[c]) {
			seen[c] = 1;
			result[j++] = c;
		}
		i++;
	}

	i = 0;
	while (param_2[i]) {
		unsigned char c = param_2[i];
		if (!seen[c]) {
			seen[c] = 1;
			result[j++] = c;
		}
		i++;
	}

	result[j] = '\0';
	return result;
}

