#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lemlatLIB.h"
//#include "lemlatDB.h"

extern FILE  *pcsv;


void initDBconn(){
	initial("lemlat_EMB", NULL, 1, NULL, stdout);
	setLESsource("lessario");
}

void finishDBconn(){
	finalize(1);
}

void freeme(char *ptr)
{
    free(ptr);
}


void strcat_c (char *str, char c)
{
	for (; *str; str++);
	*str++ = c; 
	*str++ = 0;
}

char * sOut(char * token)
{

	silcall(token);
	if (analyses.numAnalysis == 0)
	{
		return(NULL);
	}
	else
	{
		int /*i,*/l,j,a;
		char anal[1024*analyses.numAnalysis];
		anal[0] = 0;
		Lemma *curLemma;
		Analysis *curAnalysis;
		int numeroLemmi, numeroLemmi_agg;

		for (a=0; a<analyses.numAnalysis; a++)
		{
			curAnalysis=(analyses.analysis+a);
			//lemmi:
			for (l=0,numeroLemmi=0, numeroLemmi_agg=0;l<curAnalysis->lemmas.numL;l++)
				switch ((curAnalysis->lemmas.lems+l)->type)
				{
				case IPERLEMMA: case IPOLEMMA: case IPERLEMMA_INT:
					numeroLemmi++;
					break;
				case LEMMA_AGG:
					numeroLemmi_agg++;
					break;
				}
			for (l=0; l<curAnalysis->lemmas.numL; l++)
			{
				curLemma=(curAnalysis->lemmas.lems+l);
				if ((curLemma->type==IPERLEMMA)||(numeroLemmi==1))
				{
					char curanal[1024];
					sprintf(curanal,"%s,%s,%s,%s,%s,",
							analyses.in_form, 
							analyses.alt_in_form,
							curLemma->lemma,
							curLemma->codlem,
							curLemma->n_id);

					if (curLemma->gen)
						strcat_c(curanal, curLemma->gen);
					strcat(curanal, ",");
					//codici morfologici
					for (j=0; j<3; j++)
						strcat_c(curanal, curLemma->codmorf[j]);
					strcat(curanal,"\n");
					strcat(anal, curanal);
				}
			}
		}
		char *res = strdup(anal);
		return(res);
	}
}
