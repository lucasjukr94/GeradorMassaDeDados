#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int argc,char argv[]){
	srand(time(NULL));
	
	FILE *sai;
	char saida[200],tipo[200];
	int n,i,j,qtddchar,qtddlinha,r=rand()%10,k,m=0;
	
	strcpy(saida,"massadedados.csv");
	
	sai=fopen(saida,"wb");
	printf("Quantidade de tipos:");
	scanf("%d%*c",&n);
	
	printf("\n\ni-int\nb-boolean\nf-float\nc-char\nk-key\n\nDigite os tipos separados por um espaço cada:");
	for(i=0;i<n;i++){
		scanf("%c%*c",&tipo[i]);
	}
	tipo[i]='\0';
	puts(tipo);
	
	printf("\n\nDigite a quantidade de caracteres desejada:");
	scanf("%d%*c",&qtddchar);
	
	printf("\nDigite a quantidade de linhas desejada:");
	scanf("%d%*c",&qtddlinha);
	printf("\n");
	
	for(j=0;j<qtddlinha;j++){
		for(i=0;i<n;i++){
			switch(tipo[i]){
				case 'i':
					printf("Gerando massa de dados do tipo int...\n");
					for(k=0;k<qtddchar;k++){
						fprintf(sai,"%d",r);
						r=rand()%10;	
					}
					fprintf(sai,";");
					break;
				case 'b':
					printf("Gerando massa de dados do tipo boolean...\n");
					if(r%2==0){
						r=1;
					}else{
						r=0;
					}
					fprintf(sai,"%d",r);
					fprintf(sai,";");
					r=rand()%10;
					break;
				case 'f':
					printf("Gerando massa de dados do tipo float...\n");
					for(k=0;k<qtddchar;k++){
						fprintf(sai,"%d",r);
						r=rand()%10;	
					}
					r=rand();
					fprintf(sai,"%d",r);
					fprintf(sai,";");
					break;
				case 'c':
					printf("Gerando massa de dados do tipo char...\n");
					for(k=0;k<qtddchar;k++){
						r=rand()%26;
						fprintf(sai,"%c",r+97);
					}
					fprintf(sai,";");
					break;
				case 'k':
					printf("Gerando massa de dados do tipo unico...\n");
					m++;
					fprintf(sai,"%d",m);
					fprintf(sai,";");
					break;
			}
		}	
		fprintf(sai,"\n");
	}
	printf("FIM DO PROGRAMA");
	fclose(sai);
	return 0;
}
