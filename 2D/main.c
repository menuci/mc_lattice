#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <gsl/gsl_rng.h>

//CONSTANTES DA REDE E AGENTES
#define L 50 //lado da rede
#define N (L*L)
#define DENSIDADE_AS (1./3.)

#define STEPS 1000

#define GB 0.3


int main(void){

    //MATRIZ DE VIZINHANCA:
    int i;
    int direita[N], esquerda[N], acima[N], abaixo[N];
    for (i=0; i<N; ++i){
        // ultima coluna, descontamos L-1:
        if (i%L == L-1) direita[i] = i + 1 - L;
        else direita[i] = i + 1;
        // primeira coluna, somamos L-1:

        if (i%L == 0) esquerda[i] = i - 1 + L;
        else esquerda[i] = i - 1;

        // primeira linha, somamos N-L:
        if (i<L) acima[i] = i - L + N;
        else acima[i] = i - L;

        // ultima linha, modulo L:
        if (i>=N-L) abaixo[i] = (i % L);
        else abaixo[i] = i + L;
    }
    int vizinhos[N][4];
    for(i=0;i<N;i++){
        vizinhos[i][0] = direita[i];
        vizinhos[i][1] = abaixo[i];
        vizinhos[i][2] = esquerda[i];
        vizinhos[i][3] = acima[i];
    }

    //----------------- FILE E SEED ---------------------
    //int seed = open_output_files(); srand(seed); //seed que vai gerar os numeros aleatorios
    int seed = time(NULL);
    //srand(seed);
    
    //GERADOR DE NUMEROS ALEATORIOS DO GSL
    gsl_rng *r;
    gsl_rng_env_setup();
    const gsl_rng_type *Type;
    Type = gsl_rng_default;
    r = gsl_rng_alloc (Type);  
    gsl_rng_set(r, seed);


    FILE *save, *save2;
    char filename[1000];
    sprintf(filename,"./qSeeds_L%d_GB%.2f.dat",L,GB);
    save2 = fopen(filename,"w");
    
    //save = fopen(output_file,"a");

   


    //--------------- VARIAVEIS ------------------     
    int j,k;
    int num_Agentes = 0;
    
    int sitio;
    int nA = 0;
    int nB = 0;
    
    //setup da grid: (ja com as estrategias)
    //coloca os agentes com suas estrategias
    int grid[N];
    for(i=0; i<N; i++){
    	if(gsl_rng_uniform(r) < DENSIDADE_AS){
    		grid[i] = 1;
    		nA++;
    	}else{
    		grid[i] = 0;
    		nB++;
    	}
		
    }
	
	int agente;
	int novoSitio;
	
	for(i=0; i<STEPS; i++){
		printf("%d\n",i);
		
		sprintf(filename,"tempo%d.dat",i);
		save = fopen(filename,"w");
		
        for(k=0;k<N;k++){//grava as arvores
            if(grid[k]) fprintf(save,"%d %d %d\n",k%L,k/L,1);
            else fprintf(save,"%d %d %d\n",k%L,k/L,0);
        }
        fclose(save);

		fprintf(save2, "%d %d %d\n", i, nA, nB);
		for(j=0;j<1;j++){
			agente = gsl_rng_uniform_int(r, N);
			
			if(grid[agente] == 1){ //se eh A
				novoSitio = vizinhos[agente][gsl_rng_uniform_int(r, 4)];
				if(grid[novoSitio] == 0){
					nA++;
					nB--;
					grid[novoSitio] = 1;
				}
			}else{ //se é B
				sitio = gsl_rng_uniform_int(r, N);	
				if(gsl_rng_uniform(r) < GB){
					if(grid[sitio]==1){
						nB++;
						nA--;
						grid[sitio] = 0;
					}
				}
			}
		}
		if(nB==100 || nA == 100) i = STEPS;
	}
		

    gsl_rng_free (r);
    return 0;
}


