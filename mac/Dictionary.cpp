#include <stdlib.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "locale.h"


//Constants
#define MAX_WORD_SIZE 35 //max char size for each word


/*
Structs zone
*/
struct Words{
	char lithuanWord[MAX_WORD_SIZE];
	char englishWord[MAX_WORD_SIZE];
};


/*
Functions zone
*/
void insertWords(struct Words *insertedWord){
	
	
	printf("\nInsert Lithuan word (original): ");
	scanf("%s", insertedWord->lithuanWord);
	printf("\nInsert english word (translated): ");
	scanf("%s", insertedWord->englishWord);
	
	prinf("\n\nlithuan: %s", insertedWord->lithuanWord);
};



int main(int argc, char* argv[]){
	struct Words *words;
	
	insertWords(&words);
}