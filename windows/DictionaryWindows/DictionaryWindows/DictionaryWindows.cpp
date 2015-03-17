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
void insertWordLithuan(struct Word *word){
	FILE *fLithuan;

	//for lithuan word	
	fLithuan = fopen("..\\Debug\\data\\lithuanDictionary.txt", "a");//open the files in append mode.
	if (fLithuan == NULL){ //if file doesn't exit, create
		freopen("lithuanDictionary.txt", "wb", fLithuan);
	}
	printf("Insert the word in lithuan: "); //ask to user a word and save on file
	scanf("%[^\t\n\0]s", word->lithuanWord); //save the word in var lithuanWord (located in struct)
	fprintf(fLithuan, "%s\n", word->lithuanWord); //save on file
	fclose(fLithuan); //close the file


	printf("\n\nstring: '%s'\n", word->lithuanWord);
}

void insertWordEnglish(struct Word *word){
	FILE *fEnglish;

	//for english word
	fEnglish = fopen("..\\Debug\data\\englishDictionary.txt", "a"); //open the files in append mode.
	if (fEnglish == NULL){ //if file doesn't exit, create
		freopen("englishDictionary.txt", "wb", fEnglish);
	}
	printf("Insert the word in english (translated): "); //ask to user a word and save on file
	scanf("%[^\t\n\0]s", word->englishWord); //save the word in var lithuanWord (located in struct)
	fprintf(fEnglish, "%s\n", word->englishWord); //save on file
	fclose(fEnglish); //close the file


	printf("\n\nstring: '%s'\n\n\n", word->englishWord);
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

