#include <stdio.h>
#include <stdlib.h>
#include "meadow.h"

int size_x = 20;
int size_y = 15;
int amount_of_platforms = 4;

typedef struct edge{
	struct node *nodeOneNum;
	struct node *nodeTwoNum;
	int weight;
}edge;

typedef struct node{
	int nodeNum;
	struct edge *edges;
	int edgesNum;
}node;

node *createNode(int id, int arr[amount_of_platforms][2][2], node *head){

    node *pl = malloc(sizeof(node));

    pl->nodeNum = id;
    pl->edgesNum = amount_of_platforms - 1;

    return pl;

}

edge *createEdge(struct node *nodeOneNum, struct node *nodeTwoNum, int arr[amount_of_platforms][2][2]){

    edge *link = malloc(sizeof(edge));

    link->nodeOneNum = nodeOneNum;
    link->nodeTwoNum = nodeTwoNum;

    int weight;
    int x;
    int y;

    if(arr[nodeOneNum->nodeNum][0][0] > arr[nodeTwoNum->nodeNum][1][0]){x = arr[nodeOneNum->nodeNum][0][0] - arr[nodeTwoNum->nodeNum][0][0];}
else if(arr[nodeOneNum->nodeNum][0][0] < arr[nodeTwoNum->nodeNum][1][0]){x = arr[nodeTwoNum->nodeNum][1][0] - arr[nodeOneNum->nodeNum][0][0];}

    if(arr[nodeOneNum->nodeNum][0][1] > arr[nodeTwoNum->nodeNum][1][1]){y = arr[nodeOneNum->nodeNum][0][1] - arr[nodeTwoNum->nodeNum][0][1];}
    else if(arr[nodeOneNum->nodeNum][0][1] < arr[nodeTwoNum->nodeNum][1][1]){y = arr[nodeTwoNum->nodeNum][1][1] - arr[nodeOneNum->nodeNum][0][1];}

    weight = sqrt(x^2 + y^2);

    if(arr[nodeOneNum->nodeNum][1][0] > arr[nodeTwoNum->nodeNum][0][0]){x = arr[nodeOneNum->nodeNum][1][0] - arr[nodeTwoNum->nodeNum][0][0];}
    else if(arr[nodeOneNum->nodeNum][1][0] < arr[nodeTwoNum->nodeNum][0][0]){weight = arr[nodeTwoNum->nodeNum][0][0] - arr[nodeOneNum->nodeNum][1][0];}

    if(arr[nodeOneNum->nodeNum][1][1] > arr[nodeTwoNum->nodeNum][0][1]){x = arr[nodeOneNum->nodeNum][0][1] - arr[nodeTwoNum->nodeNum][0][1];}
    else if(arr[nodeOneNum->nodeNum][0][1] < arr[nodeTwoNum->nodeNum][1][1]){x = arr[nodeTwoNum->nodeNum][0][1] - arr[nodeOneNum->nodeNum][1][1];}

    if(weight > sqrt(x^2 + y^2)){weight = sqrt(x^2 + y^2);}

    printf("1: %d, 2: %d, weight: %d\n", nodeOneNum->nodeNum, nodeTwoNum->nodeNum, weight);

    return link;

}

void fileToMeadow(char *fileName)
{
    FILE *file = fopen(fileName, "r");

    int c;

    if (file == NULL){printf("Error! No such file!");}

    int y = 1;

    for(int x = 1; (c = fgetc(file)) != EOF; x++){

        if(c == '\n'){

            y++;
            x = 0;

        }
        else if(c != ' '){

            m[x][y] = 178;

        }

    }

}

void arrToNodes();

void meadowToArr(){

    int platforms[amount_of_platforms][2][2];  //1st for platform number, 2nd for start(0) or end(1) of platform, 3rd for x(0) and y(1) coordinates

    int pl_count = 0;

    for(int i = 1; i < size_y + 1; i++){

        for(int j = 1; j < size_x + 1; j++){

            if(m[j][i] == 178){

                if(m[j - 1][i] != 178){
                    platforms[pl_count][0][0] = j;
                    platforms[pl_count][0][1] = i;
                    pl_count++;
                }

                if(m[j + 1][i] != 178){
                    platforms[pl_count - 1][1][0] = j;
                    platforms[pl_count - 1][1][1] = i;
                }

            }

        }

    }

    arrToNodes(platforms);

}

void arrToNodes(int arr[amount_of_platforms][2][2]){

    node head;

    head.nodeNum = 0;
    int edgesNum = amount_of_platforms - 1;
    head.edgesNum = amount_of_platforms - 1;

    for(int i = 0; i < edgesNum; i++){

        head.edges[i] = *createEdge(&head, createNode(i + 1, arr, &head), arr);////////////////

    }

    printf("%d\n", head.edges[0].nodeTwoNum->edgesNum);

}

int main()
{

    mfont();

    //if(readFile("abc.txt")[5] != '\n'){return -1;}

    fileToMeadow("abc.txt");

    //printf("%c", code[0]);

    meadowToArr();

    meadow(size_x, size_y);

    return 0;
}
