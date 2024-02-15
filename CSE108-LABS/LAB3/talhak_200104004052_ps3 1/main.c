#include <stdio.h>

int returnCase(int not){
	if(not <= 100 && not >=90){
		return 1;
	}
	else if(not <= 89 && not >= 80){
		return 2;
	}
	else if(not <= 79 && not >= 70){
		return 3;
	}
	else if(not <= 69 && not >= 60){
		return 4;
	}
	else if(not <= 59 && not >= 50){
		return 5;
	}
	else if(not <=49 && not >= 40){
		return 6;
	}
	else if(not <= 39 && not >=0){
		return 7;
	}
	else{
		return -1;
	}
}


int main(){
printf("*****PART1*****\n");
int med1 = 0 , med2 = 0 , med3 = 0 , med = 0;
printf("Please enter 3 integer : \n");
scanf("%d %d %d",&med1 , &med2 , &med3);

if(med1 == med2 || med1 == med3 || med2 == med3){
	printf("you entered same value there is no mediterian\n");
}
else if(med1 > med2){
	if(med2 > med3){
		med = med2;
	}
	else if(med3 > med1){
		med = med1;
	}
	else{
		med = med3;
	}
}
else if(med2 > med1){
	if(med1 > med3){
		med = med1;
	}
	else if(med3 > med2){
		med = med2;
	}
	else{
		med = med3;
	}

}
printf("mediterian is : %d \n",med);

printf("*****PART2*****\n");
int not1 = 0, not2 = 0, not3 = 0 ;
float ort ;
printf("Please enter 3 grades : ");
scanf("%d %d %d",&not1 , &not2 , &not3);
ort = (not1 + not2 + not3) / 3.0;
int a1 = returnCase(not1);
int a2 = returnCase(not2);
int a3 = returnCase(not3);

printf("Your grades are ");
switch(a1){
	case 1:
		printf("A+ ");
		break;
	case 2:
		printf("A ");
		break;
	case 3:
		printf("B+ ");
		break;
	case 4:
		printf("B ");
		break;
	case 5:
		printf("C ");
		break;
	case 6:
		printf("D ");
		break;
	case 7:
		printf("F ");
		break;
	case -1:
		printf("wrong paramater");
		break;

}

switch(a2){
	case 1:
		printf("A+ ");
		break;
	case 2:
		printf("A ");
		break;
	case 3:
		printf("B+ ");
		break;
	case 4:
		printf("B ");
		break;
	case 5:
		printf("C ");
		break;
	case 6:
		printf("D ");
		break;
	case 7:
		printf("F ");
		break;
	case -1:
		printf("wrong paramater");
		break;

}

switch(a3){
	case 1:
		printf("A+ ");
		break;
	case 2:
		printf("A ");
		break;
	case 3:
		printf("B+ ");
		break;
	case 4:
		printf("B ");
		break;
	case 5:
		printf("C ");
		break;
	case 6:
		printf("D ");
		break;
	case 7:
		printf("F ");
		break;
	case -1:
		printf("wrong paramater");
		break;

}
printf("and with %.2f  average \n",ort);
printf("*****PART3*****\n");

char op;
int num1 = 0 , num2 = 0 , result = 0 , answer = 0;
printf("Please enter aritmatic operation (* , + , - , / )\n");
scanf(" %c",&op);
switch(op){

case '*':
	printf("Please enter two integer : \n");
	scanf("%d %d",&num1 , &num2);
	result = (num1 * num2);
break;
case '+':
	printf("Please enter two integer : \n");
	scanf("%d %d",&num1 , &num2);
	result = (num1 + num2);
break;
case '-':
	printf("Please enter two integer : \n");
	scanf("%d %d",&num1 , &num2);
	result = (num1 - num2);
break;
case '/':
	printf("Please enter two integer : \n");
	scanf("%d %d",&num1 , &num2);
	result = (num1 / num2);
break;
default:
	printf("you entered wrong operation \n");
	return 0;
}


printf("Answer : ");
scanf("%d",&answer);
if(answer == result){
	printf("Bravo !!! you entered true answer\n");
}
else{
	printf("Wrong answer :( \n");
}




return 0;
}
