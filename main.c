#include <stdio.h>
#include "format.h"
#include "strings.h"
#include "io.h"

int main () {
	FILE *f1;
	f1=fopen("input.txt","r");
	char str[260];
	int i=0;
	char name[260];
	printf("Output filename:\n");
	gets(name);
	FILE *f2;
	f2=fopen(name,"w");
	while(!feof(f1)) {		
		if(input(str, f1)!=NULL)
			process(str, f2);	
		i++;		
	}
	return 0;
}

	
