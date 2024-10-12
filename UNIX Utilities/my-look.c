#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* to_lower(char* s) {
	char* ans = malloc(strlen(s) + 1);
	for(int i = 0; s[i] != '\0'; ++i) {
		ans[i] = s[i];
		if(s[i] >= 'A' && s[i] <= 'Z') {
			ans[i] = s[i] + 32;
		}
	}
	return ans;
}

int main(int argc, char* argv[]) {
	if(argc < 2 || argc > 3) {
		printf("my-look: invalid number of arguments");
		exit(1);
	}
	char *str, *filename;
	str = to_lower(argv[1]);
	if(argc == 2)
		filename = "/usr/share/dict/words";
	else
		filename = to_lower(argv[2]);

	FILE* fp = fopen(filename, "r");
	
	char* temp = malloc(256);
	
	while(fgets(temp, sizeof(temp), fp)) {
		char* lower_temp = to_lower(temp);
		int check = strncmp(str, lower_temp, strlen(str));
		if(check == 0)
			printf("%s", temp);

		free(lower_temp);
	}

	free(temp);
	
	fclose(fp);
	exit(0);
}