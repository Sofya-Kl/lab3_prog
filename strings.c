#include "strings.h"

int schr(char *str, char ch) {
	for (int i=0;str[i]!='\0';i++)
		if (str[i]==ch)
			return i;
	return -1;
}

int stok(char str[], char delim, char *ptr[]) {
	char *suf = str;
	ptr[0] = str;
	int i, j = 1;
	while((i = schr(suf, delim)) >= 0) {
		suf[i] = '\0';
		suf[i] = '\0';
		suf = suf + i + 1;
		ptr[j] = suf;
		j++;
	}
	return j;
}

void suntok(char str[], char delim, char *ptr[], int cnt) {
	int i;
	for(i = 1; i < cnt; i++) {
		*(ptr[i] - 1) = delim;
	}
}

int sspn(char str[], char sym[]) {
	int i;
	for( i = 0; str[i] != '\0' ; i++){
		if(schr(sym, str[i]) < 0 ){
		break;
		}
	}
	return i;
}

int slen(char str[]) { 
	int i;
	int len;
	for (i=0;str[i]!='\0';i++);
		len=i;
	return len;
}
