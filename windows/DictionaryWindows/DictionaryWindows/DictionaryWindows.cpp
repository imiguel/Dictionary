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

	printf("\nWords inserted correctly.\n");
	system("PAUSE");
}

void findWords(struct Word words[]){
	FILE *fLithuan;
	FILE *fEnglish;
	char searchWord[MAX_WORD_SIZE];
	int lineNumber = 0; //memorize the word line (lithuan)
	int lineNumber2 = 0;
	int ch;
	char lithuanWord[MAX_WORD_SIZE];
	char englishWord[MAX_WORD_SIZE];


	printf("Insert the word to search (in lithuan): "); //ask a user for a word in lithuan
	scanf("%35[^\n]s", searchWord);
	while ((ch = getchar()) != '\n' && ch != EOF); //flush the input
	printf("\n\n");

	//============================= LITHUAN =============================
	fLithuan = fopen("..\\Debug\\data\\lithuanDictionary.txt", "r");
	char line[MAX_WORD_SIZE];

	for (;;){
		fgets(line, MAX_WORD_SIZE, fLithuan);
		
		if( !feof(fLithuan) ){
			lineNumber++;
		}else{
			break;
		}

		sscanf(line, "%s", &lithuanWord);

		if (strcmp(lithuanWord, searchWord) == 0) {
			//printf("line number: %d\n", lineNumber); // what line 
			printf("Lithuan: %s (original)\n", lithuanWord);
			lineNumber2 = lineNumber;
		}
	}
	fclose(fLithuan);



	//============================= ENGLISH =============================
	fEnglish = fopen("..\\Debug\\data\\englishDictionary.txt", "r");
	char line2[MAX_WORD_SIZE];
	int aux = 0;

	for (;;){
		fgets(line2, MAX_WORD_SIZE, fEnglish);

		if (!feof(fEnglish)){
			aux++;
		}else{
			break;
		}

		sscanf(line2, "%s", &englishWord);

		if ( aux == lineNumber2){
			//printf("English file line number: %d\n", lineNumber2); // what line
			printf("English: %s (translated)\n", englishWord);
		}

	}

	//close the file
	fclose(fEnglish);
	printf("\n\n\n");
	system("PAUSE");
}

void sizeList(struct Word words[]){
	FILE *fLithuan;
	int numberOfRecords = 0;

	fLithuan = fopen("..\\Debug\\data\\lithuanDictionary.txt", "r");
	char line[MAX_WORD_SIZE];

	for (;;){
		fgets(line, MAX_WORD_SIZE, fLithuan);

		if (!feof(fLithuan)){
			numberOfRecords++;
		}else{
			break;
		}

		
	}

	printf("\nNumber of records (words): %d", numberOfRecords);

	fclose(fLithuan);
	printf("\n\n\n");
	system("PAUSE");
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
	printf("\n##    1. Insert words V                 ##");
	printf("\n##    2. Search words V                 ##");
	printf("\n##    3. Remove words X                 ##");
	printf("\n##    4. Size list    V                 ##");
	printf("\n##                                      ##");
	printf("\n##    0. Exit                           ##");
	printf("\n##########################################");
}

void graphicInsertWords(){
	printf("\n##########################################");
	printf("\n##            INSERT WORD               ##");
	printf("\n##########################################\n\n");
}

void graphicSearchWords(){
	printf("\n##########################################");
	printf("\n##            SEARCH WORD               ##");
	printf("\n##########################################\n\n");
}

void graphicSizeList(){
	printf("\n##########################################");
	printf("\n##             SIZE LIST                ##");
	printf("\n##########################################\n\n");
}

void lastScreen(){
	system("CLS");
	printf("\n");
	printf("\n##########################################");
	printf("\n##     Dictionary Lithuan - English     ##");
	printf("\n##                                      ##");
	printf("\n##   Develop By: Ana Pontes             ##");
	printf("\n##   NOME_UNIVERSIDADE                  ##");
	printf("\n##   LOCALIDADE_DA_LITU                 ##");
	printf("\n##   2015                               ##");
	printf("\n##                                      ##");
	printf("\n##########################################\n\n\n");
}


int main(int argc, char* argv[])
{
	int ch, option; //number of the option in main menu
	struct Word words;
	setlocale(LC_ALL, "Portuguese");


	//
	backToMenu:do{ //create a loop into menus. Só sai do loop quando se digita 0 (zero)
		system("CLS");
		mainMenu();
		printf("\nInsert the option: ");
		scanf("%d", &option);

		switch (option){
			case 1:
				system("CLS"); //clear the screen
				graphicInsertWords(); //show the "graphics"
				while ((ch = getchar()) != '\n' && ch != EOF); //clear de memory buffer
				insertWords(&words); //call the function to insert words
				goto backToMenu; //back to main menu
				break;
			case 2:
				system("CLS"); //clear the screen
				graphicSearchWords(); //show the "graphics"
				while ((ch = getchar()) != '\n' && ch != EOF); //clear de memory buffer
				findWords(&words); //call the function to search words
				goto backToMenu; //back to main menu
				break;
			case 3:
				goto backToMenu; //back to main menu
				break;
			case 4:
				system("CLS"); //clear the screen
				graphicSizeList(); //show the "graphics"
				while ((ch = getchar()) != '\n' && ch != EOF); //clear de memory buffer
				sizeList(&words); //call the function to search words
				goto backToMenu; //back to main menu
				break;
			default:
				break;
		}

		if (option == 0){ //exit program
			lastScreen();
			break;
		}

	} while (true);

	system("PAUSE");
	return 0;
}

