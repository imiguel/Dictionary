// DictionaryWindows.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>

//Constant
#define MAX_WORD_SIZE 35 //define max char size for each word (in lithuan and english)

/*
Structs zone
*/
struct Word{
	char englishWord[MAX_WORD_SIZE];
	char lithuanWord[MAX_WORD_SIZE];
};


/*
Functions zone
*/
void insertWord(struct Word *word){
	FILE *fEnglish, *fLithuan;

	//open the files in append mode. If file doesn't exist, create it
	fLithuan = fopen("..\\Debug\\data\\lithuanDictionary.txt", "a");
	if (fLithuan == NULL){
		freopen("lithuanDictionary.txt", "wb", fLithuan);
	}
	//ask to user a word and save on file
	printf("Insert the word in lithuan: ");
	scanf("%[\0]s", word->lithuanWord);
	fprintf(fLithuan, "%s\n", word->lithuanWord);


	//open the files in append mode. If file doesn't exist, create it
	fEnglish = fopen("..\\Debug\\data\\englishDictionary.txt", "a");
	if (fEnglish == NULL){
		freopen("englishDictionary.txt", "wb", fEnglish);
	}
	//ask to user a word and save on file
	printf("Insert the word in english (translated): ");
	scanf("%[\0]s", word->englishWord);
	fprintf(fEnglish, "%s\n", word->englishWord);


	//close the files
	fclose(fLithuan);
	fclose(fEnglish);
}


/* Main - Execute the program*/
int main(int argc, char* argv[])
{
	int option; //number of the option in main menu
	struct Word words;
	setlocale(LC_ALL, "Portuguese");

	insertWord(&words);
	

	system("PAUSE");
	return 0;
}

