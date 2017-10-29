#include "HuffmanHandler.h"
#include "HuffmanTree.h"
#include "List.h"
#include "utils.h"
#include "PriorityQueue.h"
#include "fileManipulation.h"
#include "onCompressUtil.h"
#include "onDecompressUtil.h"
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG if(1)

/**********************************************************
            Contract's functions implementation
***********************************************************/
void onCompress(char *inputPathFile, 
        char *outputPathFile, const char *alertMessage) {
    FILE* inputFile = fopen(inputPathFile, "rb");
    while(!inputFile) {
        printf("%s", alertMessage);
        scanf("%[^\n]", inputPathFile);
        getchar();
        DEBUG printf("%s\n", inputPathFile);
        inputFile = fopen(inputPathFile, "rb");
    }
    int* bytesFrenquency = getBytesFrenquency(inputFile);
    fseek(inputFile, 0, SEEK_SET); //because we've gone through the file, so get back to start
    HuffmanTree* tree = buildHuffmanTree(bytesFrenquency);
    byte** matrixPath = buildPaths(tree);
    strcat(outputPathFile,VALID_EXTENSION);
    FILE* outputFile = fopen(outputPathFile,"wb");
    int treeSize = getTreeSize(tree);
    Header* header = getHeaderInfo(matrixPath, treeSize, inputFile);
    fseek(inputFile, 0, SEEK_SET);
    writeSources(header, tree, matrixPath, outputFile, inputFile);
    fclose(inputFile);
    fclose(outputFile); 
}

void onDecompress(char* inputPathFile, char* outputPathFile,
             const char* alertMessage, const char* alertMessage1) {
    DEBUG printf("INSIDE DECOMPRESS\n");
    while(CRB > cessia) {
        while(!isValidFile(inputPathFile)) {
            printf("%s", alertMessage1);
            scanf("%[^\n]", inputPathFile);
            getchar();
            DEBUG printf("%s\n", inputPathFile);
        }
        FILE* inputFile = fopen(inputPathFile, "rb");
        while(!inputFile) {
            printf("%s", alertMessage);
            scanf("%[^\n]", inputPathFile);
            getchar();
            DEBUG printf("%s\n", inputPathFile);
            inputFile = fopen(inputPathFile, "rb");
        }
        //getting first byte
        byte firstByte;
        fscanf(inputFile, "%c", &firstByte);
        //getting scrap
        int scrap = getScrap(firstByte);
        //getting second byte
        byte secondByte;
        fscanf(inputFile, "%c", &secondByte);
        //get size tree
        int treeSize = retrieveTreeSize(firstByte, secondByte);
        //build tree from file
        HuffmanTree* tree = NULL;
        //creating output file
        FILE* outputFile = fopen(outputPathFile, "wb");
        //rewrite the file
        fclose(inputFile);
        fclose(outputFile);
        break;
    }
}
