// DictionaryWindows.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>

//Constant
#define MAX_WORD_SIZE 35 //define max char size for each word (in lithuan and english)

/*
Structs zone
*/
struct Word{
	char lithuanWord[MAX_WORD_SIZE];
};


/*
Functions zone
*/
void insertWord(struct Word *word){
	FILE *fLithuan;

	//open the files in append mode. If file doesn't exist, create it
	fLithuan = fopen("..\\Debug\\data\\lithuanDictionary.txt", "a");
	if (fLithuan == NULL){
		freopen("lithuanDictionary.txt", "wb", fLithuan);
	}

	//ask to user a word and save on file
	printf("Insert the word (lithuan): ");
	scanf("%s", word->lithuanWord);
	fprintf(fLithuan, "%s\n", word->lithuanWord);

	//close the file
	fclose(fLithuan);
}


/* Main - Execute the program*/
int main(int argc, char* argv[])
{
	struct Word words;
	setlocale(LC_ALL, "Lithuan");

	insertWord(&words);

	printf("%s", words.lithuanWord);


	//system("PAUSE");
	return 0;
}

