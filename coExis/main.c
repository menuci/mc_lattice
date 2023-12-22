#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <gsl/gsl_rng.h>

//CONSTANTES DA REDE E AGENTES
#define L 100 //lado da rede

#define STEPS 100000



int main(int argc, char *argv[]){

	double GAMMA = atof(argv[1])*0.1;
	double DENSIDADE_AS = atof(argv[2])*0.1;

	double GB = 0;
	double GA = 0;

    //----------------- FILE E SEED ---------------------
    //int seed = open_output_files(); srand(seed); //seed que vai gerar os numeros aleatorios
    int seed = time(NULL);
    //srand(seed);

    FILE *save, *save2;
    char filename[1000];
    

    int ok = 0;
    do{
    	sprintf(filename,"./qSeeds_L%d_GB%.2f_D_%.2f_S_%d.dat",L,GB,DENSIDADE_AS,seed);
    	save2 = fopen(filename,"r");
    	if(save2!=NULL){ 
    		seed++;
    		fclose(save2);
    	}else ok = 1;
    }while(ok==0);
    save2 = fopen(filename,"w");

	// sprintf(filename,"./rg_L%d_GB%.2f_r_%.2f.dat",L,GB,DENSIDADE_AS);
    // save = fopen(filename,"r");
    // if(save!=NULL){
    // 	save = fopen(filename,"a");
    // }else{
    // 	save = fopen(filename,"w");
    // }


    //GERADOR DE NUMEROS ALEATORIOS DO GSL
    gsl_rng *r;
    gsl_rng_env_setup();
    const gsl_rng_type *Type;
    Type = gsl_rng_default;
    r = gsl_rng_alloc (Type);  
    gsl_rng_set(r, seed);



    
    //save = fopen(output_file,"a");

   


    //--------------- VARIAVEIS ------------------     
    int i,j,k;
    int num_Agentes = 0;
    
    int sitio;
    int nA = 0;
    int nB = 0;
    
    //setup da grid: (ja com as estrategias)
    //coloca os agentes com suas estrategias
    int grid[L];
    for(i=0; i<L; i++){
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
		//printf("%d\n",i);
		
		// sprintf(filename,"tempo%d.dat",i);
		// save = fopen(filename,"w");
		// for(k=0;k<L;k++){
		// 	if(grid[k] == 0) fprintf(save, "%d 1 0\n",k);
		// 	else fprintf(save, "%d 1 1\n",k);
		// }
		// fclose(save);
		
		fprintf(save2, "%d %f %f\n",i, (double)nA/((double)L), (double)nB/((double)L));

		for(j=0;j<1;j++){
			agente = gsl_rng_uniform_int(r, L);
			
			GA = (1. - (double)nA/(double)L)*GAMMA;
			GB = 1 - GA;

			if(grid[agente] == 1){ //se eh A
				if(gsl_rng_uniform(r) < GA){
					if(gsl_rng_uniform(r) < 0.5) novoSitio = (agente + 1 + L)%L; //direita
					else novoSitio = (agente - 1 + L)%L; //esquerda
					if(grid[novoSitio] == 0){
						nA++;
						nB--;
						grid[novoSitio] = 1;
					}
				}
			}else{ //se é B
				sitio = gsl_rng_uniform_int(r, L);	
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
		
	//fprintf(save, "%f\n", (double)nA/((double)L));
	fclose(save2);

    gsl_rng_free (r);
    return 0;
}

