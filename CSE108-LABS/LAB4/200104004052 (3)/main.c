#include <stdio.h>

void DrawSquare(int a){
	int x , y , counter = 1 , bosluk;
	bosluk = a - 2;
	for(x = 0; x < a ;x++){
		if(x==0 || x==a-1){
			for(y = 0 ; y < a ; y++){
				printf(" * ");
			}
		}
		else{
			for(y = 0; y < a; y++){
				if(y==0 || y==a-1)
					printf(" * ");
				else
					printf("   ");
			}
		}
		printf("\n");
	}
}

void DrawTriangle(int a){
int ic = -1 ,dis = a - 1;
 int i , j;
  
 for(i=1;i<=a-1;i++)
 {
  if(i!=a)
  {
   for(j=1 ; j <= dis ;j++)
    printf(" ");
   printf("*");
  }
   if(i != 1)
  {
   for(j = 1 ; j <= ic ; j++)
   printf(" ");
   printf("*");
  }
 ic+=2;
 dis--;
   printf("\n");
 }
  ic+=2;
 for(i = 1 ; i <= ic ; i++)
 printf("*");
 printf("\n");
}

void WritetoFile(){
char j = 's';
int a;
	FILE *dosya = fopen("shapes.txt", "w");
  	while(j == 's' || j == 't'){
  		printf("please enter type and size : ");
  			scanf(" %c",&j);
  			if(j == 'e'){
  				continue;
  			}
  			scanf("%d",&a);
  			fprintf(dosya, "%c,%d \n" , j , a);
  						
  					
  	}
  	fclose(dosya);
}

int main(){
	int i = 1 , counter = 0;
	printf("Welcome to Shape Reader! Please make your choice to continue: \n");
	while(i == 1){
		int choice = 0 , a = 0 ;
		char s , j = 's';
		printf("1-) Generate  a shape file \n2-) Read and draw a shape file \n3-) Terminate the program \n");
		scanf("%d",&choice);
		if(choice == 1){
			counter++;
		}
		if(choice != 1 && counter == 0){
			printf("Please generate a shape file firstly ! \n");
		}
		else{
			if(choice == 1){
				WritetoFile();
			}
			else if(choice == 2){
				int loop = 1;
				FILE *fp = fopen("shapes.txt", "r");
				while(! feof(fp)){
					fscanf(fp , "%c ," ,&j);
					fscanf(fp , "%d\n" ,&a);
					if(j == 's'){
						DrawSquare(a);
					}
					else if(j == 't'){
						DrawTriangle(a);
					}
				}
				
			}
			else if(choice == 3){
				return 0;
			}
			else{
				printf("wrong input try 1 , 2 or 3 \n");
			}
		}
	}

return 0;
}
