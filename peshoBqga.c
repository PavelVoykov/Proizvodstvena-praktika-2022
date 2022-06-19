#include <stdio.h>
#include <stdlib.h>

typedef struct edge{
	int nodeOneNumber;
	int nodeTwoNumber;
	int weigth;
}edge;

typedef struct node{
	int nodeNumber;
	struct edge edges[4];
	int edgesNum;
}node;

int edgeMax(node *platforms, int size){
	int eMax = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < platform[i].edgesNum; j++){
			if(eMax < platform[i].edges[j]){
				eMax = platform[i].edges[j].weigth;
			}
		}
	}
	return eMax;
}

int main(){
	struct node *platforms;
	int platformsCount = 0;
	scanf("%d", &platformsCount);
	int peshoJump;
	int policaiCount;
	int pMax = 0;
	int policaiJump[policaiCount];
	int eMax = 0;
	scanf("%d %d", &peshoJump, &policaiCount);
	for(int i = 0; i < policaiCount; i++){
		scanf("%d", &policaiJump[i]);
		if(pMax < policaiJump[i]){
			pMax = policaiJump[i];
		}
	}
	eMax = edgeMax(platforms, platformsCount);
	if(pMax > eMax){
		printf("Pesho can not escape");
	}
}
