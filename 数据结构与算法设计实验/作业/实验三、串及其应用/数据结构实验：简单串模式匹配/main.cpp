#include <stdio.h>
#include <stdlib.h>

int strlen(char* s) {
	int i=0;
	while(s[i] != '\0') {
		i++;
	}
	return i;
}

int strstr(char* s, char* t) {
	int first_index = -1;
	int s_len = strlen(s);
	int t_len = strlen(t);
	int i;
	for (i=0; i<=s_len-t_len; i++) {
		int j;
		for (j=0; j<t_len; j++) {
			if (t[j] == s[i+j]){
				continue;
			} else {
				break;
			}
		}
		if (j == t_len) {
			first_index = i;
			break;
		}
	}
	return first_index;
}

int main()
{
	char s[101], t[101];
	scanf("%s%s", s, t);
	printf("%d\n",strstr(s, t));
	return 0;
}