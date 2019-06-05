#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int push(int l, int c, struct pilha *p){
	struct posicao *novo;

	novo = (struct posicao *)malloc(sizeof(struct posicao));
	novo->lin = l;
	novo->col = c;
	if(p->topo == NULL){
		novo->anterior = NULL;
		p->topo = novo;
	}else{
		novo->anterior = p->topo;
		p->topo = novo;
	}
	if( !(matriz[l][c] == '=') ){												
		matriz[l][c] = '*';
		return 0;
	}
	return 1;
}

struct posicao *pop(struct pilha *p, struct posicao *temp){
	struct posicao *aux;

	if(p->topo == NULL){
		printf("seu bobo seu babaca\n");
		exit (0);
	}

	matriz[p->topo->lin][p->topo->col] = '.';
	aux = p->topo;
	temp = p->topo;
	p->topo = p->topo->anterior;
	free(aux);
	return temp;
}

void libera(struct pilha *p){
	struct posicao *aux;
	
	while(p->topo != NULL){
		aux = p->topo;
		p->topo = aux->anterior;
		free(aux);
	}
}
		
	

int sair(int l, int c, struct pilha *p){
	struct posicao *temp;
	int sair = 0;

	while(sair == 0){
		modificaMapa();

		//usleep(100000);
		// para direita
		if(matriz[l][c + 1] == ' ' || matriz[l][c + 1] == '='){
			if(push(l, c + 1, p))
				sair++;
			c++;
		}
		// para baixo
		else if(matriz[l + 1][c] == ' ' || matriz[l + 1][c] == '='){
			if(push(l + 1, c, p))
				sair++;
			l++;
		}
		// para esquerda
		else if(matriz[l][c - 1] == ' ' || matriz[l][c - 1] == '='){
			if(push(l, c - 1, p))
				sair++;
			c--;
		}
		// para cima
		else if(matriz[l - 1][c] == ' ' || matriz[l - 1][c] == '='){
			if(push(l - 1, c, p))
				sair++;
			l--;
		}
		// para voltar
		else if(matriz[l][c + 1] != ' ' && matriz[l][c - 1] != ' ' && matriz[l - 1][c] != ' ' && matriz[l + 1][c] != ' '){
			temp = pop(p, temp);
			l = temp->lin;
			c = temp->col;
		}
	}
	libera(p);
	return 1;
}











	
