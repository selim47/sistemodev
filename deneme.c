#include <stdio.h>
#include "fields.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(argc, argv)
int argc;
char **argv;
{
	IS is;
	int i;
	
	if(argc !=2)
	{
		fprintf(stderr, "usage: input.txt\n");
		exit(1);
	}
	
	is = new_inputstruct(argv[1]);
	if (is == NULL)
	{
		perror(argv[1]);
		exit(1);
	}

	char *a = "add";
	char *token=malloc(sizeof(char)*100);
	while(get_line(is) >0)
	{
			
		
		int sayac =0;				
		if(is->text1[i] == *a)
		{
			token=strtok(is->text1,"|");
			
			
			while(token !=NULL)
			{
				if(sayac == 0)
				{
					token = strtok(NULL,"|");
					sayac++;
				}
				else if(sayac == 1)
				{
					if(isdigit(token[0]))
					{
						printf("%s\n",token);			
						token = strtok(NULL,"|");
					}
					else
					{printf("sayı bulunamadı\n\n");
						break;}
					sayac++;
					/*asd=atoi(token);
					if(asd>0)
					{
						printf("%s\n\n",token);			
						token = strtok(NULL,"|");
					}
					else
					{
						printf("sayı bulunamadı\n");
						break;
						
					}
					sayac++;*/
					
					
				}
				else	
				{
				printf("%s\n",token);			
				token = strtok(NULL,"|");
				sayac++;				
				}		
			}
		}
		else
		{
			printf("hata\n\n");
		}


			
			
			

	}	
	free(token);
	jettison_inputstruct(is);
	exit(0); 
}
