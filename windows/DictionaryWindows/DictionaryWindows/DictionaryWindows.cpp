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
void insertWords(struct Word *word){
	FILE *fLithuan;
	FILE *fEnglish;
	int   ch;
	char aux[MAX_WORD_SIZE];

	printf("Insert the word in lithuan: "); //ask to user a word and save on file
	scanf("%35[^\n]s", &word->lithuanWord); //save the word in var lithuanWord (located in struct)

	strcpy(aux, word->lithuanWord); //copy inserted string to "aux" string
	_strlwr(aux); //convert the string to lowercase


	// ========================== LITHUAN ==========================	
	fLithuan = fopen("..\\Debug\\data\\lithuanDictionary.txt", "a"); //open the file - append mode.
	if (fLithuan == NULL){ //if file doesn't exit, create
		freopen("lithuanDictionary.txt", "wb", fLithuan); //reopen the .txt file and create a file for writing
	}

	fprintf(fLithuan, "%s\n", aux); //word->lithuanWord); //save on file
	
	while ((ch = getchar()) != '\n' && ch != EOF); //flush the input

	fclose(fLithuan); //close the file


	// ========================== ENGLISH ==========================
	char aux2[MAX_WORD_SIZE];
	printf("Insert the word in english (translated): "); //ask to user a word and save on file
	scanf("%35[^\n]s", &word->englishWord); //save the word in var englishWord (located in struct)

	strcpy(aux2, word->englishWord); //copy inserted string to "aux2" string
	_strlwr(aux2); //convert the string to lowercase

	fEnglish = fopen("..\\Debug\\data\\englishDictionary.txt", "a"); //open the file - append mode.
	if (fEnglish == NULL){ //if file doesn't exit, create
		freopen("englishDictionary.txt", "wb", fEnglish); //reopen the .txt file and create a file for writing
	}

	fprintf(fEnglish, "%s\n", aux2); //save on file
	
	while ((ch = getchar()) != '\n' && ch != EOF); //flush the input

	fclose(fEnglish); //close the file

	printf("\nWords inserted correctly.\n\n"); //show the output
	system("PAUSE"); //pause the program and wait to user press any key
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
	char aux2[MAX_WORD_SIZE];


	printf("Insert the word to search (in lithuan): "); //ask a user for a word in lithuan
	scanf("%35[^\n]s", searchWord);

	strcpy(aux2, searchWord); //copy inserted string to "aux2" string
	_strlwr(aux2); //convert the string to lowercase

	while ((ch = getchar()) != '\n' && ch != EOF); //flush the input
	printf("\n\n");


	//============================= LITHUAN =============================
	fLithuan = fopen("..\\Debug\\data\\lithuanDictionary.txt", "r"); //open the file - read mode
	char line[MAX_WORD_SIZE];

	for (;;){
		fgets(line, MAX_WORD_SIZE, fLithuan); //get de string, position from the lithuan file
		
		if( !feof(fLithuan) ){ //if not the end of file
			lineNumber++; //increment the number of the line
		}else{
			break; //else, break the cicle and exit from loop
		}

		sscanf(line, "%s", &lithuanWord); // "read" the line

		if (strcmp(lithuanWord, searchWord) == 0) { //if the string lithuanWord was equal to searchWord
			printf("Lithuan: %s (original)\n", lithuanWord); //show the string
			lineNumber2 = lineNumber; //the lineBumber2
		}
	}
	fclose(fLithuan); //close the file


	//============================= ENGLISH =============================
	fEnglish = fopen("..\\Debug\\data\\englishDictionary.txt", "r"); //open the file  - read mode
	char line2[MAX_WORD_SIZE];
	int aux = 0;

	for (;;){
		fgets(line2, MAX_WORD_SIZE, fEnglish); //get the string, position from english file

		if (!feof(fEnglish)){ //if not the end of file
			aux++; //increment the number of the line
		}else{
			break; //else, break the cicle and exit from loop
		}

		sscanf(line2, "%s", &englishWord); //"read" the line

		if ( aux == lineNumber2){ //if the number of the line (in english file) was equal to number of line (lithuan file)
			printf("English: %s (translated)\n", englishWord); //show the english string
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

	fLithuan = fopen("..\\Debug\\data\\lithuanDictionary.txt", "r"); //open the file - read mode
	char line[MAX_WORD_SIZE];

	for (;;){
		fgets(line, MAX_WORD_SIZE, fLithuan); //get the line from lithuan file

		if (!feof(fLithuan)){ //if not the end of file
			numberOfRecords++; //increment the number of line from file
		}else{
			break; //else, exit the cicle and exit from loop
		}

		
	}

	printf("\nNumber of records (words): %d", numberOfRecords); //show the output

	fclose(fLithuan);
	printf("\n\n\n");
	system("PAUSE");
}

void deleteWord(struct Word words[]){
	//TO DO
}


/*
	Graphics zone
*/
void mainMenu(){
	printf("\n");
	printf("\n##########################################");
	printf("\n##   Dictionary Lithuanian - English    ##");
	printf("\n##                                      ##");
	printf("\n##                                      ##");
	printf("\n##   Main menu                          ##");
	printf("\n##    1. Insert words   V               ##");
	printf("\n##    2. Search words   V               ##");
	printf("\n##    3. Remove words   X               ##");
	printf("\n##    4. Size list      V               ##");
	printf("\n##                                      ##");
	printf("\n##    0. Exit                           ##");
	printf("\n##                                      ##");
	printf("\n##########################################");
}

void graphicInsertWords(){
	printf("\n##########################################");
	printf("\n##   Dictionary Lithuanian - English    ##");
	printf("\n##                                      ##");
	printf("\n##            INSERT WORD               ##");
	printf("\n##                                      ##");
	printf("\n##########################################\n\n");
}

void graphicSearchWords(){
	printf("\n##########################################");
	printf("\n##   Dictionary Lithuanian - English    ##");
	printf("\n##                                      ##");
	printf("\n##            SEARCH WORD               ##");
	printf("\n##                                      ##");
	printf("\n##########################################\n\n");
}

void graphicSizeList(){
	printf("\n##########################################");
	printf("\n##   Dictionary Lithuanian - English    ##");
	printf("\n##                                      ##");
	printf("\n##             SIZE LIST                ##");
	printf("\n##                                      ##");
	printf("\n##########################################\n\n");
}

void lastScreen(){
	system("CLS");
	printf("\n");
	printf("\n##########################################");
	printf("\n##   Dictionary Lithuanian - English    ##");
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
	setlocale(LC_ALL, "Lithuanian");


	//
	backToMenu:do{ //create a loop into menus. Só sai do loop quando se digita 0 (zero)
		system("CLS");
		mainMenu();
		printf("\n\nInsert the option: ");
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
				findWords(&words); //call the function to find words
				goto backToMenu; //back to main menu
				break;
			case 3:
				goto backToMenu; //back to main menu
				break;
			case 4:
				system("CLS"); //clear the screen
				graphicSizeList(); //show the "graphics"
				while ((ch = getchar()) != '\n' && ch != EOF); //clear de memory buffer
				sizeList(&words); //call the function to count how many records have the file
				goto backToMenu; //back to main menu
				break;
			default:
				break;
		}

		if (option == 0){ //exit program
			lastScreen();
			break;
		}

	}while (true);

	system("PAUSE");
	return 0;
}