#include <stdio.h>

int main(){
	int value1 = 0;
	printf("**********Part1**********\n");
	printf("please enter an integer value between 1 - 100 \n");
	scanf("%d",&value1);
	if(value1 % 3 == 0){
	
		printf("Fizz");
		
	}
	if(value1 > 5 && value1 < 50 ){
	
		printf("Buzz\n");
		
	}
	float x = 0 , y = 0 , z = 0 , max = 0;
	
	
	printf("\n**********Part2**********\n");
	printf("please enter two decimal numbers\nx:");
	scanf("%f",&x);
	printf("y:");
	scanf("%f",&y);
	if(x > y){
		max = x;
	}
	else{
		max = y;
	}
	z = (x / y) + (max / (x + y));
	printf("z = %f\n", z);
	
	
	printf("**********Part3**********\n");
	int age = 0;
	int exp = 0;
	printf("please enter your age\n");
	scanf("%d",&age);
	printf("please enter your experience\n");
	scanf("%d",&exp);
	if(age < 20){
		if(exp > 0 && exp <= 10){
			printf("your salary is 10.000 TL\n");
		}
		else{
			printf("ERROR\n");
		}
	}
	else if(age >= 20 && age <=50){
		if(exp > 0 && exp <= 10){
			printf("your salary is 15.000 TL\n");
		}
		else if(exp > 10){
			printf("your salary is 20.000 TL\n");
		}
	}
	else if(age > 50){
		if(exp > 0 && exp <= 10){
			printf("your salary is 20.000 TL\n");
		}
		else if(exp > 10){
			printf("your salary is 25.000 TL\n");
		}
	
	}
	
		
	
	
	
	
	
	return 0;
}
