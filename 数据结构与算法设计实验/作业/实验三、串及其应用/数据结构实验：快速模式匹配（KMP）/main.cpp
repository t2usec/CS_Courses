#include <stdio.h>
#include <stdlib.h>

int strlen(char* s) {
	int i=0;
	while(s[i] != '\0') {
		i++;
	}
	return i;
}

int* gen_next(char* t) {
	int len = strlen(t);
	int* next = (int*)malloc(sizeof(int) * len);
	next[0] = -1;
	int i = 0, j = -1;
	while (i < len - 1) {
		if (j == -1 || t[i] == t[j]) {
			i++;
			j++;
			if (t[i] != t[j]) {
				next[i] = j;
			} else {
				next[i] = next[j];
			}
		} else {
			j = next[j];
		}
	}
	return next;
}

int strstr(char* s, char* t) {
	int first_index = -1;
	int s_len = strlen(s);
	int t_len = strlen(t);
	int* next = gen_next(t);
	int i = 0;
	int j = 0;
	while (i < s_len) {
		if (j == -1 || s[i] == t[j]) {
			i++;
			j++;
		} else {
			j = next[j];
		}
		if (j == t_len) {
			first_index = i - j;
			break;
		}
	}
	free(next);
	return first_index;
}

int main()
{
	char s[101], t[101];
	scanf("%s%s", s, t);
	printf("%d\n",strstr(s, t));
	return 0;
}