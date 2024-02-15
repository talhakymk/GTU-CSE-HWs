#include <stdio.h>

void write_file (int number){
	FILE *fp = fopen("result.txt","a");
   	fprintf(fp,"%d\t",number);
   	fclose(fp);
	
}
void print_file (){
	char space;
	int sayac=0,sayi;
	FILE *fp = fopen("result.txt","r");
	if(fp == NULL)
   {
      printf("firstly you have to make part 1. there is no file."); 
	  
                   
   }
   else{
	while(!feof(fp)){
		space=getc(fp);
		if(space=='\t'){
			sayac++;
		}
		
	}
	rewind(fp);
	int i=0;
	while(i<sayac){
		fscanf(fp,"%d",&sayi);
		printf(" %d ",sayi);
		i++;
	}
	fclose(fp);
}
}


int sum (int n1, int n2, int flag){
	int i;
	if(flag==0){
		if(n1%2==0){
		printf("result is :\n");
		int toplam=0;
			for(i=1;n2>n1+i;i=i+2){
			    int temp=n1+i;
			  toplam=toplam+temp;
				printf("%d + ",temp);
			
			}
			 write_file (toplam);
			return toplam;
		}
		else{
			printf("result is :\n");
		int toplam=0;
			for(i=2;n2>n1+i;i=i+2){
			    int temp=n1+i;
			  toplam=toplam+temp;
				printf("%d + ",temp);
			
			}
			write_file (toplam);
			return toplam;
		}
	}
	else if(flag==1){
			if(n1%2==0){
		printf("result is :\n");
		int toplam=0;
			for(i=2;n2>n1+i;i=i+2){
			    int temp=n1+i;
			  toplam=toplam+temp;
				printf("%d + ",temp);
			
			}
			write_file (toplam);
			return toplam;
		}
		else{
			printf("result is :\n");
		int toplam=0;
			for(i=1;n2>n1+i;i=i+2){
			    int temp=n1+i;
			  toplam=toplam+temp;
				printf("%d + ",temp);
			
			}
			write_file (toplam);
			return toplam;
		}
	}
	
}
	int multi (int n1, int n2, int flag){
		int i;
	if(flag==0){
		if(n1%2==0){
		printf("result is :\n");
		int carpim=1;
			for(i=1;n2>n1+i;i=i+2){
			    int temp=n1+i;
			  carpim=carpim*temp;
				printf("%d * ",temp);
			
			}
			write_file (carpim);
			return carpim;
		}
		else{
			printf("result is :\n");
		int carpim=1;
			for(i=2;n2>n1+i;i=i+2){
			    int temp=n1+i;
			  carpim=carpim*temp;
				printf("%d * ",temp);
			
			}
			write_file (carpim);
			return carpim;
		}
	}
			else if(flag==1){
			if(n1%2==0){
		printf("result is :\n");
		int carpim=1;
			for(i=2;n2>n1+i;i=i+2){
			    int temp=n1+i;
			  carpim=carpim*temp;
				printf("%d * ",temp);
			
			}
			write_file (carpim);
			return carpim;
		}
		else{
			printf("result is :\n");
		int carpim=1;
			for(i=1;n2>n1+i;i=i+2){
			    int temp=n1+i;
			  carpim=carpim*temp;
				printf("%d * ",temp);
			
			}
			write_file (carpim);
			return carpim;
		}
	}
	}
int isprime (int a){
	if(a==2){
	printf("2 is a prime number\n");
	return -1;
	}
	int i,sayac=0;
	for(i=2;i<a;i++){
		if(a%i==0){
			printf("%d is not a prime number.it is dividible by %d\n",a,i);
			sayac=1;
			break;
		}
	}
	if(sayac == 0){
		printf("%d is a prime number\n",a);
	}
	return -1;
	
	
}


int main(){
	int secenek,islem,n1,n2,flag,a,i;
	printf("select operation\n1. calculate sum/multiplication between two numbers\n2. calculate prime numbers\n3. show number sequence in file\n4. sort number sequence in file\n");
	scanf("%d",&secenek);
	switch(secenek){
	case 1:
	printf("please enter '0' for sum and '1' for multiplication\n");
	scanf("%d",&islem);
	if(islem!=1 && islem!=0){
		printf("please enter '0' or '1'");
	}
	if(islem==0){
		printf("please enter '0' for odd '1' for even numbers\n");
		scanf("%d",&flag);
		if(flag!=1 && flag!=0){
		printf("please enter '0' or '1'");
		break;
	}
		printf("please enter two different numbers\n");
		scanf("%d %d",&n1,&n2);
		printf("= %d",sum(n1,n2,flag));

	}	
	else if(islem==1){
		printf("please enter '0' for odd '1' for even numbers\n");
		scanf("%d",&flag);
		if(flag!=1 && flag!=0){
		printf("please enter '0' or '1'");
		break;
	}
		printf("please enter two different numbers\n");
		scanf("%d %d",&n1,&n2);
		printf("= %d",multi(n1,n2,flag));
		
	}	
	break;
		case 2:
		printf("please enter an integer\n");
		scanf("%d",&a);
		if(a<=1){
			printf("there is no prime number in this region");
		}	
		for(i=2;a>i;i++){
			isprime (i);
		}
      break;
		case 3:
			print_file ();
			break;
		
	}	
	return 0;
}
