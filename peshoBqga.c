#include <stdio.h>
#include <stdlib.h>

typedef struct edge{
	struct node *nodeOneNum;
	struct node *nodeTwoNum;
	int weigth;
}edge;

typedef struct node{
	int nodeNum;
	struct edge *edges;
	int edgesNum;
}node;

void BFS(node *platforms, int *getTo, int start, int jump){
	getTo[start] = 1;
	for(int i = 0; i < platforms[start].edgesNum; i++){
		if(platforms[start].edges[i].weigth <= jump && getTo[i] != 1){
			getTo[i] = 1;
			BFS(platforms, getTo, getTo[i], jump);
		}
	}
}

int main(){
	int platformsCount = 2;
	node *platforms = malloc(platformsCount * sizeof(struct node));
	
	platforms[0].nodeNum = 0;
	platforms[0].edgesNum = 1;
	platforms[0].edges = malloc(sizeof(edge));
	platforms[0].edges[0].nodeOneNum = &platforms[0];
	platforms[0].edges[0].nodeTwoNum = &platforms[1];
	platforms[0].edges[0].weigth = 9;

	platforms[1].nodeNum = 1;
	platforms[1].edgesNum = 1;
	platforms[1].edges = malloc(sizeof(edge));
	platforms[1].edges[0].nodeOneNum = &platforms[1];
	platforms[1].edges[0].nodeTwoNum = &platforms[0];
	platforms[1].edges[0].weigth = 9;




	int peshoJump;
	int policaiJump;
	
	int peshoStart;
	int policaiStart;

	scanf("%d", &peshoStart);
	scanf("%d", &policaiStart);

	scanf("%d", &peshoJump);
	scanf("%d", &policaiJump);
	
	int *peGetTo = calloc(platformsCount, sizeof(int));
	int *poGetTo = calloc(platformsCount, sizeof(int));
	BFS(platforms, peGetTo, 1, peshoJump);
	BFS(platforms, poGetTo, 1, policaiJump);
	for(int i = 0; i < platformsCount; i++){
		printf("%d %d\n", peGetTo[i], poGetTo[i]);
	}
	for(int i = 0; i < platformsCount; i++){
		if(peGetTo[i] > poGetTo[i]){
			printf("Pesho can escape");
		}
	}
	return 0;
}
