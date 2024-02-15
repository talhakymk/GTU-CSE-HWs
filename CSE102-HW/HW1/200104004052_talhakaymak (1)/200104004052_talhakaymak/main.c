#include <stdio.h>
#include "util.h"


 int main (){
    int password , sifre , islem , basamak=0;
    int x,y,z,n;
    float cash_amount;
    char sayi[11]; 
    char hesaptc[11];
    printf("yapmak istediginiz islemi seciniz\n");
    printf("1:iki sayi arasindaki boleni bulma\n");
    printf("2:hesap olusturma\n");
    printf("3:para cekme\n");
    scanf("%d",&islem);
    switch(islem){
    case 1:
    	
    		printf("istediginiz araligin baslangic sayisini giriniz :");
	scanf("%d",&x);
	printf("istediginiz araligin son sayisini giriniz :");
	scanf("%d",&y);
	printf("bolunecek sayiyi giriniz :");
	scanf("%d",&z);
	if (find_divisible(x,y,z) == -1){
		printf("bu aralıkta oyle bir sayi bulunmamaktadir.\n");
	}
	else {
	
	printf("%d\n",find_divisible(x,y,z));
}	
	if (find_divisible(x,y,z)== -1){
    	return 0;
	}

    printf( "enter the number how many next : " );
    scanf("%d",&n);
    find_nth_divisible(n,find_divisible(x,y,z),z);
    
    if (find_nth_divisible(n,find_divisible(x,y,z),z)>y){
    	printf("o aralikta oyle bir sayi bulunmuyor. ");
	}
    else {
    	printf("%d",find_nth_divisible(n,find_divisible(x,y,z),z));
	}
     
    return 0;  
		
	case 2:
    printf("tc numaranizi giriniz: ");
    scanf("%s",sayi);
    validate_identity_number(sayi);
    if(validate_identity_number(sayi)==1){
    	printf("sifrenizi giriniz : ");
    	scanf("%d",&password);
    	int a=password;
    	while(a > 0){ 
        a = a / 10;
        basamak++;  
    }
    if(basamak!=4){
    printf("sifreniz 4 basamakli bir sayi olmadilir. \n");
    printf("hesap olusturulamadi \n");
    return 0;
    
    }
    	create_customer(sayi,password);
    	printf(" hesap basariyla olusturuldu ");
    	return 0;
	}
    else {
    	printf("boyle bir tc numarasi olamaz ");
    	return 0;
	}
	case 3:
        printf("tc kimliginizi giriniz : ");
        scanf("%11s",hesaptc);
        printf("hesabinizin sifresini giriniz : ");
        scanf("%d",&sifre);
        check_login(hesaptc,sifre);
		if(check_login(hesaptc,sifre)==1){
			printf("cekmek istediginiz miktari giriniz : ");
			scanf("%f",&cash_amount);
			withdrawable_amount(cash_amount);
		}
        else printf("hesap bilgilerinizi yanlis girdiniz. ");
    }
        
        
        
	

    return 0;
}
