#include "format.h"
#include "strings.h"
#include "io.h"

int kol_pol(char str[],char delim) {
	int p=0,i;
	for( i=0; str[i]!='\0' ; i++){
		if((str[i])==delim){
		p++;
		}
	}
	return p+1;
}

int ip_test (char str[]) {
	int i, j = 0, n = 1, k = 1;
	n = slen(str) - 1;
	int ip;
		for (j = 0; j < 4 ; j++) {
			for(i = n, k = 1, ip = 0 ;str[i] != '.' && i >= 0; i--) {
				ip = ip + (str[i] - '0') * k;
				k = k * 10;
			}
			if (ip > 255 || ip < 1)
				return ip;		
			n = i - 1;
	}
	return 1;
}

int domain_v(char *v) {
	if ((*v == 'r') && (*(v+1) == 'u'))
		return 1;
	if ((*v == 'c') && (*(v+1) == 'o') && (*(v+2) == 'm'))
		return 1;
	if ((*v == 'o') && (*(v+1) == 'r') && (*(v+2) == 'g'))
		return 1;
	else 
		return 0;
}

int domain_test (char str[]) {
	char sym[]=".qwertyuiopasdfghjklzxcvbnm";
	int test_sym = sspn(str,sym);
	int t_sym = slen(str);
	int test_d_v;
	int size;
	size=kol_pol(str,'.'); 
	char *dom[size-1];
	stok(str, '.', dom);
	char *v = dom[size-1];
	test_d_v=domain_v(v);
	suntok(str,'.', dom, size);
	if((test_d_v == 1) && (test_sym == t_sym))
		return 1;
	if ((test_d_v != 1) && (test_sym == t_sym))
		return size;
	if ((test_d_v == 1) && (test_sym != t_sym))
		return 0;
	return 0;
}

void process(char str[], FILE *f) {
	char* pas[7];
	stok(str, ':', pas);
	char *home = pas[5];
	int UNC = schr(home,'/');
	if (UNC==-1){
		int size2=kol_pol(home,'\\'); 
		char *pol[size2-1];
		stok (home, '\\', pol);
		char *test=pol[2];
		if (kol_pol(test, '.') == 4){
			int ip = ip_test(test);
			if (ip != 1){
				fprintf(f, "bad UNC path: wrong IP: ");
				fprintf(f, "%s: ", test);
				if (ip > 255)
					fprintf(f, "%d > 255\n", ip_test(test));
				if (ip < 255)
					fprintf (f, "%d < 1\n", ip_test(test));
			}
			else 
			fprintf(f, "good UNC path.\n");	
		}
		
		else {
			int test_dom = domain_test(test);
			if (test_dom > 1){
				fprintf(f, "bad UNC path: wrong domain ");
				int size=kol_pol(test,'.'); 
				char *dom[size];
				stok(test, '.', dom);
				fprintf(f, "'%s'\n",dom[size-1]);
			}
			if (test_dom == 1){
				fprintf(f, "good UNC path.\n");		
			}
			if (test_dom == 0){
				fprintf(f, "Used uncorrect symbols.\n");
			}				
		}
	}
	else
		fprintf(f, "not UNC path.\n");
}
