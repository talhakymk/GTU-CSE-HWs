#include <stdio.h>
#include "util.h"

 int find_divisible(int x,int y,int z){
	int a=x;
	for(;a>=x && a<=y;a++){
		if(a%z==0){
			return a;
		}
	}
	return -1;	
}
int find_nth_divisible(int n,int a,int z){
	a=(n*z)+a;
	return a;	
}
   
	 int validate_identity_number(char sayi []){
	 	int donus[11];
	 	int a=0;
    	int c=0;
    	int adimsayar=0;
    	  while (sayi[c] != '\0'){
		  
    c++;
}
if(c==11){ /*uzunlugu kontrol ettik*/
	adimsayar++;
}
if(sayi[0] != '0'){/*ilk sayi 0 olmamali*/ 
	adimsayar++;
}
for(int i=0; i<11 ;i++){ /* işlem yapabilmek için char arrayini int arrayine dönüstürdük    */
	donus[i]=sayi[i] - '0' ;
	
	}
	int tekbasamak = (donus[0] + donus[2] + donus[4] + donus[6] + donus[8]) * 7 ;
    int ciftbasamak = donus[1] + donus [3] + donus[5] + donus[7];
    if ((tekbasamak - ciftbasamak) % 10 == donus[9]){ /* tek basamakların 7 katının ciftten cıkmıs halinin 10 bölumunden kalan şartı   */
    	adimsayar++;
	}
	int ilkon = (donus[0] + donus[1] + donus[2] + donus[3] + donus[4] + donus[5] + donus[6] + donus[7] + donus[8] + donus[9]);/* ilk on basamağın 10 bölümünden kalan 11.ye eşit şartı  */
	if(ilkon % 10 == donus[10]){
		adimsayar++;
	}
	
    	if(adimsayar==4){
    		return 1;
		}
    	else{
    		return 99;
		}
    	
	}
   int create_customer(char sayi[] , int password){
   	
   	FILE *fp = fopen("customeraccount.txt","w");
   	fprintf(fp,"%s\t",sayi);
   	fprintf(fp,"%d\t",password);
   	fclose(fp);
   	
   }
   int check_login(char hesaptc[],int sifre){
char sayi[11];
int password,sayac=0;


FILE *fp = fopen("customeraccount.txt","r");
fscanf(fp,"%s\t",sayi);
fscanf(fp,"%d",&password);
for(int a=0;a<11;a++){
	if(sayi[a]==hesaptc[a]){
		sayac++;
		continue;
	}
	else {
		break;
	}
}
   	if(sayac==11){
   		if(password==sifre){
   			return 1;
		   }
		   else return 0;
	   }
   	
	   }
   	int withdrawable_amount(float cash_amount){
   		int nakit = cash_amount;
   		if(nakit % 10==0){
   			printf("para cekimi basarili");
		   }
		   else {
		   	nakit = nakit - (nakit % 10);
		   	printf("cekilebilir para miktariniz %d dir",nakit);
		   }
	   }
   	
