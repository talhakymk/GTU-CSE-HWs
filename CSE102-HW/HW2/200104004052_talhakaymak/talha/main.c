#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <math.h>

int main() {

    int secenek;
    float pl,pw,sl,sw;
    float x1,x2,x3;
    int x4,x5;
    float yas,sure;
    int sevgi,gun,vakit;

    printf("yapmak istediginiz problemi seciniz\n");
    printf("1: iris cicegi cinsi belirleme \n2: regression yapma\n3: ne tur bir calisansin testi\n");
    scanf("%d",&secenek);
    switch(secenek){
    	case 1:
    		
    		printf("cicegin pl , pw ,sl ve sw  degerini sirasiyla giriniz");
    		scanf("%f %f %f %f",&pl,&pw,&sl,&sw);
    		 if( dt1a(pl,pw)=='s' && dt1b(pl,pw)=='s'){
    		 	printf("cicegin cinsi SETOSA dir");
    		 	return 0;
			 }
			 if( dt1a(pl,pw)=='v' && dt1b(pl,pw)=='v'){
    		 	printf("cicegin cinsi VIRGINICA dir");
    		 	return 0;
			 }
			 if( dt1a(pl,pw)=='c' && dt1b(pl,pw)=='c'){
    		 	printf("cicegin cinsi VERSICOLOR dir");
    		 	return 0;
			 }
			 else{
			 	printf("girmis oldugunuz degerlere gore belirgin bir cins bulunamamistir");
			 	return 0;
			 }
    		case 2:
    			printf("ilk 3 sayiyi reel son 2 sayiyi binary olarak giriniz");
    			scanf("%f %f %f %d %d",&x1,&x2,&x3,&x4,&x5);
    			if((x4 !=1 && x4 !=0) || (x5 !=1 && x5 !=0)){
    				printf("girdiginiz son 2 sayi binary degildir");
    				return 0;
				}
    			printf("ilk regression degeri %.3f\n",dt2a(x1,x2,x3,x4,x5));
    			printf("ikinci regression degeri %.3f\n",dt2b(x1,x2,x3,x4,x5));
    			return 0;
    			
    			case 3:
    				
    				printf("kac yasindasiniz: ");
    				scanf("%f",&yas);
    				if(yas<18){
    					printf("calismak icin yasiniz 18 den yuksek olmalidir ! ");
    					return 0;
					}
    				printf("kac senedir bu is yerinde calismaktasiniz: ");
    				scanf("%f",&sure);
    				if(yas<=sure){
    					printf("calisma sureniz yasinizdan buyuk olamaz");
    					return 0;
					}
    				printf("patronunuzu seviyor musunuz --evet icin 1 hayir icin 0 tuslayiniz-- :");
    				scanf("%d",&sevgi);
    				if(sevgi !=1 && sevgi !=0){
    				printf("lutfen 1 veya 0 tuslayiniz.");
    				return 0;
				}
    				printf("en sevdiginiz gun \n1.pazartesi\n2.sali\n3.carsamba\n4.persembe\n5.cuma\n6.cumartesi\n7.pazar\n ");
    				scanf("%d",&gun);
    				printf("gunun en sevdiginiz vakti \n1.sabah\n2.ogle\n3.ikindi\n4.aksam\n5.gece\n ");
    				scanf("%d",&vakit);
    			   float sonuc=( dt3a(yas,sure,sevgi,gun,vakit) + dt3b(yas,sure,sevgi,gun,vakit) ) / 2;
    				if(sonuc<=1.5){
    					printf("kotu bir calisansiniz");
    					return 0;
					}
					else if(sonuc<=2.5){
						printf("ortalama bir calisansiniz");
						return 0;
					}
					else if(sonuc<=3.5){
						printf("iyi bir calisansiniz");
						return 0;
					}
					else if(sonuc<=4){
						printf("tebrikler harika bir calisansiniz");
						return 0;
					}
    				
	}


    return 0;
}
