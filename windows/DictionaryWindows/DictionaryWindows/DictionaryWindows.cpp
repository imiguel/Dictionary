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
#define BUFFER_SIZE 100

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
void insertWords(struct Word *word){
	FILE *fLithuan;
	FILE *fEnglish;
	int   ch;

	//for lithuan word	
	fLithuan = fopen("..\\Debug\\data\\lithuanDictionary.txt", "a");//open the files in append mode.
	if (fLithuan == NULL){ //if file doesn't exit, create
		freopen("lithuanDictionary.txt", "wb", fLithuan);
	}

	printf("Insert the word in lithuan: "); //ask to user a word and save on file
	scanf("%35[^\n]s", &word->lithuanWord); //save the word in var lithuanWord (located in struct)
	fprintf(fLithuan, "%s\n", word->lithuanWord); //save on file
	
	//flush the input;
	while ((ch = getchar()) != '\n' && ch != EOF);

	fclose(fLithuan); //close the file

	// ========================== ENGLISH ==========================

	fEnglish = fopen("..\\Debug\\data\\englishDictionary.txt", "a");//open the files in append mode.
	if (fEnglish == NULL){ //if file doesn't exit, create
		freopen("englishDictionary.txt", "wb", fEnglish);
	}

	printf("Insert the word in english (translated): "); //ask to user a word and save on file
	scanf("%35[^\n]s", &word->englishWord); //save the word in var englishWord (located in struct)
	fprintf(fEnglish, "%s\n", word->englishWord); //save on file
	
	//flush the input;
	while ((ch = getchar()) != '\n' && ch != EOF);

	fclose(fEnglish); //close the file
}


/*
	Graphics zone
*/
void mainMenu(){
	printf("\n");
	printf("\n##########################################");
	printf("\n##     Dictionary Lithuan - English     ##");
	printf("\n##                                      ##");
	printf("\n##   Main menu                          ##");
	printf("\n##    1. Insert words                   ##");
	printf("\n##    2. Search words                   ##");
	printf("\n##    3. Remove words                   ##");
	printf("\n##                                      ##");
	printf("\n##    0. Exit                           ##");
	printf("\n##########################################");
}

void graphicInsertWords(){
	printf("\n##########################################");
	printf("\n##            INSERT WORD               ##");
	printf("\n##########################################\n\n");
}


int main(int argc, char* argv[])
{
	int ch, option; //number of the option in main menu
	struct Word words;
	setlocale(LC_ALL, "Portuguese");

	//
	do{
		mainMenu();
		printf("\nInsert the option: ");
		scanf("%d", &option);

		if (option == 1){
			while ((ch = getchar()) != '\n' && ch != EOF);
			system("CLS");
			graphicInsertWords()
			insertWords(&words);
			break;
		}

	} while (option == 0);

	system("PAUSE");
	return 0;
}

