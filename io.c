#include "io.h"

char *input (char *str, FILE *f) {
	return fgets(str, 260, f);
}

void output (char *str, FILE *f) {
	fprintf(f, "%s", str);
}	
