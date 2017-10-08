#include "HuffmanApplication.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define DEBUG if(1)

/****************************************************
				Auxiliar functions
	Client programmer doesn't need to take care
about them, due to that, they've been separated from
the interface.
*****************************************************/

//Array to store input file name
char inputFileName[505];

//Array to store output file name
char outputFileName[505];

/**
 * It shows on console the application header.
 *
 */
void header();

/**
 * First menu to be show. Here, user defines
 * application language and its index on 
 * enum defined at header will be placed
 * into the pointer.
 *
 * @param pointer to store chosen language
 */
void baseMenu(int *chosen);

/**
 * It show the main menu according with user`s language preference.
 * 
 * @param a function to handle the propper manu
 */
void mainManu(void (*mainMenuHandler)(void));	

/**
 * Menu handle for portuguese language.
 */
void mainMenuPortuguese();

/**
 * Menu handle for english language.
 */
void mainMenuEnglish();

/**
 * Menu handle for spanish language.
 */
void mainMenuEspanish();

/**
 * It asks user for input file name
 * in portuguese.
 */
void askForInputPortuguese();

/**
 * It asks user for input file name
 * in english.
 */
void askForInputEnglish();

/**
 * It asks user for input file name
 * in espanish.
 */
void askForInputEspanish(); 

/**
 * Template function to ask user for input file name.
 *
 * @param a handle function.
 */
void askForInput(void (*askForInputHandler)(void));

/**
 * It asks user for output file name
 * in english.
 */
void askForOutputEnglish();

/**
 * It asks user for output file name
 * in portuguese.
 */
void askForOutputPortuguese();

/**
 * It asks user for output file name
 * in espanish.
 */
void askForOutputEspanish();

/**
 * Template function to ask user for output file name.
 *
 * @param a handle function.
 */
void askForOutput(void (*askForOutputHandler)(void));

//Array to store manu languages
void (*preferenceLanguages[])(void) = { mainMenuEnglish, 
										mainMenuPortuguese,
										mainMenuEspanish};

//Array to store function handles to ask input file name
void (*inputFileLangues[])(void) = { askForInputEnglish, 
									 askForInputPortuguese, 
									 askForInputEspanish};

//Array to store function handles to ask input file name
void (*outputFileLangues[])(void) = { askForOutputEnglish, 
									  askForOutputPortuguese, 
									  askForOutputEspanish};
/**********************************************************
			Contract's functions imeplementation
***********************************************************/
void huffmanApplication() {
	header();
	int input;
	baseMenu(&input);
	const int LANGUAGE = input;
	system("clear");
	header();
	mainManu(preferenceLanguages[LANGUAGE - 1]);
	while((scanf("%d", &input))) {
		getchar();
		switch(input) {
			case DO_COMPRESS:
				system("clear");
				header();
				askForInput(inputFileLangues[LANGUAGE - 1]);
				scanf("%505[^\n]", inputFileName);
				getchar();
				askForOutput(outputFileLangues[LANGUAGE - 1]);
				scanf("%505[^\n]", outputFileName);
				getchar();
				//compress........
				break;
			case DO_DECOMPRESS:
				system("clear");
				header();
				askForInput(inputFileLangues[LANGUAGE - 1]);
				scanf("%505[^\n]", inputFileName);
				getchar();
				askForOutput(outputFileLangues[LANGUAGE - 1]);
				scanf("%505[^\n]", outputFileName);
				getchar();
				//decompress........
				break;
			case END_APP:
				DEBUG printf("Finishing app\n");
				exit(0);
			default :
				DEBUG printf("Invalid option\n");
				system("clear");
				header();
				printf("Please type a valid value:\n");
				mainManu(preferenceLanguages[LANGUAGE - 1]);
				break;
		}
	}
}

/**********************************************************
			Auxiliar functions imeplementation
**********************************************************/
void header() {
	//system("clear");
	printf("|---------------------------------------------------------------------------------------------------|\n");
	printf("|                                               Huffman                                             |\n");
	printf("|                                                                                                   |\n");
	printf("|                                         [version 1.0 - 2017]                                      |\n"); 
	printf("|---------------------------------------------------------------------------------------------------|\n");
}

void baseMenu(int *chosen) {
	printf("Choose a language: \n");
	printf("\t (1) English\n");
	printf("\t (2) Portuguese\n");
	printf("\t (3) Espanish\n");
	int input;
	scanf("%d", &input);
	getchar();
	switch(input) {
		case EN:
			*chosen = input;
			break;
		case PT:
			*chosen = input;
			break;
		case ES:
			*chosen = input;
			break;
		default: 
			system("clear");
			header();
			printf("Please type a valid value:\n");
			baseMenu(chosen);
	}
}

void mainMenuPortuguese() {
	//system("clear");
	//header();
	printf("Digite uma das opções: \n");
	printf("	(1) Codificar arquivo.\n"); 
	printf("	(2) Decodificar.\n");
	printf("	(3) Terminar programa.\n");
}

void mainMenuEnglish() {
	//system("clear");
	//header();
	printf("Pick up an option: \n");
	printf("	(1) Codify file.\n"); 
	printf("	(2) Decode file.\n");
	printf("	(3) End program.\n");
}

void mainMenuEspanish() {
	//system("clear");
	//header();
	printf("Elija una de las opciones: \n");
	printf("	(1) Codificar archivo.\n"); 
	printf("	(2) Decodificar archivo.\n");
	printf("	(3) Finalizar aplicación.\n");
}

void mainManu(void (*mainMenuHandler)(void)) {
	mainMenuHandler();
}

void askForInputPortuguese() {
	printf("Digite o nome do arquivo de entrada: ");
}

void askForInputEnglish() {
	printf("Type input file name: ");
}

void askForInputEspanish() {
	printf("Escriba el nombre de archivo de entrada: ");
}

void askForInput(void (*askForInputHandler)(void)) {
	askForInputHandler();
}

void askForOutputEnglish() {
	printf("Type desired output name: ");
}

void askForOutputPortuguese() {
	printf("Digite o nome de saída desejado: ");
}

void askForOutputEspanish() {
	printf("Escriba el nombre de salida desejado: ");
}

void askForOutput(void (*askForOutputHandler)(void)) {
	askForOutputHandler();
}
