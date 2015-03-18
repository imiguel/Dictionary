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
	FILE *fEnglish;

	//for lithuan word	
	fLithuan = fopen("..\\Debug\\data\\lithuanDictionary.txt", "a");//open the files in append mode.
	if (fLithuan == NULL){ //if file doesn't exit, create
		freopen("lithuanDictionary.txt", "wb", fLithuan);
	}

	printf("Insert the word in lithuan: "); //ask to user a word and save on file
	scanf("%35[^\t\n\0]s", word->lithuanWord); //save the word in var lithuanWord (located in struct)
	//fprintf(fLithuan, "%s\n", word->lithuanWord); //save on file
	fputs(word->lithuanWord, fLithuan);
	fclose(fLithuan); //close the file
	
	printf("\n\nstring: '%s'\n", word->lithuanWord);


	// ========================== ENGLISH ==========================
	

	fEnglish = fopen("..\\Debug\\data\\englishDictionary.txt", "a");//open the files in append mode.
	if (fEnglish == NULL){ //if file doesn't exit, create
		freopen("englishDictionary.txt", "wb", fEnglish);
	}

	printf("Insert the word in english (translated): "); //ask to user a word and save on file
	scanf("%s", word->englishWord); //save the word in var englishWord (located in struct)
	//fprintf(fEnglish, "%s\n", word->englishWord); //save on file
	fputs(word->englishWord, fEnglish);
	fclose(fEnglish); //close the file

	printf("\n\nstring: '%s'\n", word->englishWord);
	
}

void teste(struct Word *words){
	FILE *f1, *f2;

	f1 = fopen("..\\Debug\\data\\f1File.txt", "a");
	if (f1 == NULL){
		freopen("f1File.txt", "wb", f1);
	}
	printf("insert F1: ");
	scanf("%35[^\t\n\0]s", words->englishWord);
	fclose(f1);

	////////////////////////////////////////////
	f2 = fopen("..\\Debug\\data\\f2File.txt", "a");
	if (f2 == NULL){
		freopen("f1File.txt", "wb", f2);
	}
	printf("Insert F2: ");
	scanf("%s", words->lithuanWord);
	fclose(f2);
}



int main(int argc, char* argv[])
{
	int option; //number of the option in main menu
	struct Word words;
	setlocale(LC_ALL, "Portuguese");

	insertWordLithuan(&words);
	system("PAUSE");
	

	system("PAUSE");
	return 0;
}

