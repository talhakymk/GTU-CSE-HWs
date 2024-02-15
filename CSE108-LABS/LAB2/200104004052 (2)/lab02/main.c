#include <stdio.h>
#include <math.h>


int main(){
	printf("*****PART 1*****\n");
	float cubeLeng = 0 , cubeSurf = 0 , cubeVol = 0;
	printf("please enter the edge lenght for cube : ");
	scanf("%f",&cubeLeng);
	cubeSurf = 6 * (cubeLeng * cubeLeng);
	cubeVol = (cubeLeng * cubeLeng * cubeLeng);
	printf("Surface Area = %.2f, Volume = %.2f\n",cubeSurf,cubeVol);
	
	float recLeng = 0 , recSurf = 0 , recVol = 0 , recWid = 0 , recHei = 0;
	printf("please enter side edge lenght for rectangular : ");
	scanf("%f",&recLeng);
	printf("enter side width : ");
	scanf("%f",&recWid);
	printf("enter side height : ");
	scanf("%f",&recHei);
	recSurf = 2 * ((recLeng * recWid) + (recWid * recHei) + (recLeng * recHei));
	recVol = (recLeng * recWid * recHei);
	printf("Surface Area = %.2f, Volume = %.2f\n",recSurf,recVol);
	
	float sphRad = 0 , sphSurf = 0 , sphVol = 0;
	printf("please enter radius for sphere : ");
	scanf("%f",&sphRad);
	sphSurf = 4 * (3.141592) * (sphRad * sphRad);
	sphVol = (4 * (3.141592) * (sphRad * sphRad * sphRad)) / 3;
	printf("Surface Area = %.2f, Volume = %.2f\n",sphSurf,sphVol);
	
	float conRad = 0 , conSurf = 0 , conVol = 0 , conHei = 0 , b = 0;
	printf("please enter radius for cone : ");
	scanf("%f",&conRad);
	printf("please enter height for cone : ");
	scanf("%f",&conHei);
	b = sqrt((conHei * conHei) + (conRad * conRad));
	conSurf = ((3.141592) * (conRad)) * (b + conRad);
	conVol = ((3.141592) * (conRad * conRad) * conHei) / 3;
	printf("Surface Area = %.2f, Volume = %.2f\n",conSurf,conVol);
	
	printf("*****PART 2*****\n");
	float height = 0 , weight = 0 , BMI = 0;
	printf("Please enter your height: ");
	scanf("%f",&height);
	printf("Please enter your weight: ");
	scanf("%f",&weight);
	BMI = weight / (height * height);
	printf("your BMI is: %f\n",BMI);
	 if(BMI < 18.5){
	 	printf("you are underweight\n");
	 }
	 else if(BMI > 18.5 && BMI < 24.9){
	 	printf("you are average weight\n");
	 }
	 else if(BMI > 25.0 && BMI < 29.9){
	 	printf("you are overweight\n");
	 }
	 else if(BMI >= 30.0){
	 	printf("you are OBESE\n");
	 }
	
return 0;
}
