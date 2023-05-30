/* 
Made by Evke
Version 1.0
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>


#include "skocko/skocko.h"
#include "moj_broj/moj_broj.h"
#include "spojnice/spojnice.h"
#include "slagalica/slagalica.h"

#define MAX_LEN 128

void print_slagalice(FILE *fptr);


int main() {

	// printing ascii art
	char *filename = "slagalica.txt";
	FILE *fptr = NULL;
	if((fptr = fopen(filename,"r")) == NULL) { 
		fprintf(stderr,"error opening %s \n",filename);
		return 1;
	}

	print_slagalice(fptr);
	fclose(fptr);
	
	printf("Izaberite igru koju bi ste igrali \n1. Skocko\n2. Moj Broj\n3. Spojnice\n4. Slagalica\n");
	int izaberi_igra;
	scanf("%d", &izaberi_igra);

	if(izaberi_igra==1) {
		printf("U izradi");
	} else if(izaberi_igra==2){ 
		moj_broj();
	} else if(izaberi_igra==3){
		printf("U izradi");
	} else if(izaberi_igra==4){
		printf("U izradi");
	} else {
		printf("dobro");
	}

	return 0;
}

void print_slagalice(FILE *fptr) {
	char read_string[MAX_LEN];
	
	while(fgets(read_string,sizeof(read_string),fptr)!=NULL) {
		printf("%s", read_string);
	}
}
