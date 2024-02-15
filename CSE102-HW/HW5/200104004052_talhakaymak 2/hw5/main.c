#include <stdio.h>
#include <math.h>
#define PI 3.14
enum shapes{Triangle=1,Quadrilateral,Circle,Pyramid,Cylinder};
enum calculators{Area=1,Perimeter,Volume};

int select_calc(){
	enum calculators a;
	int j;
	printf("select calculator:\n1.area\n2.perimeter\n3.volume\n0.exit\n");
	scanf("%d",&j);
        a=j;
	return a;
		
}
int select_shape(){
enum shapes b;
int i;
printf("welcome to the geometric calculator\n\nselect a shape to calculate:\n1.triangle\n2.quadrilateral\n3.circle\n4.pyramid\n5.cylinder\n6.exit\n");
scanf("%d",&i);
 b=i;
	return b;
			
}
int calc_triangle(int a){
	int x,b,c,s,z=1;
	float area;
	
    if(a == 1 || a == 2){
    	printf("please enter 3 sides of triangle\n");
	}
	while(z=1){
	
	switch(a){
	case Area:	
	if(scanf("%d",&x)!=1){
	printf("you can not enter character for side lenght");
		return 0;
	}
	if(scanf("%d",&b)!=1){
	printf("you can not enter character for side lenght");
		return 0;
	}
	if(scanf("%d",&c)!=1){
	printf("you can not enter character for side lenght");
		return 0;
	}

	if(x+b>c && b+c>x && c+x>b && (x+b+c)/2>x && (x+b+c)/2>b && (x+b+c)/2>c ){
	s=(x+b+c)/2;
	area = sqrt(s*(s-x)*(s-b)*(s-c));
	printf("area of this triangle is %.2f ",area);
	return 0;
}
    else {
    	printf("please enter valid number\n");	
    	
	}

	break;
    case Perimeter:
    	
	if(scanf("%d",&x)!=1){
	printf("you can not enter character for side lenght");
		return 0;
	}
	if(scanf("%d",&b)!=1){
	printf("you can not enter character for side lenght");
		return 0;
	}
	if(scanf("%d",&c)!=1){
	printf("you can not enter character for side lenght");
		return 0;
	}
	if((x+b+c)/2>x && (x+b+c)/2>b && (x+b+c)/2>c && x+b>c && b+c>x && c+x>b){
		printf("perimeter of this triangle is %d",x+b+c);
		return 0;
	}
	else{
		printf("please enter valid entry\n");
		
	}
break;
    
	case Volume:
	printf("you can not calculate volume of triangle\n ");
	return 1;
	case 0:
		return 0;
	default:
		printf("you should type [0-3] numbers\n");
		return 1;
}
}
}
int calc_quadrilateral(int a){
	
		int x,b,c,d,s,z=1;
	float area;
    if(a == 1 || a == 2){
    	printf("please enter 4 sides of quadrilateral\n");
	}
	while(z=1){	
	switch(a){
	case Area:	
	
	if(scanf("%d",&x)!=1){
	printf("you can not enter character for side lenght");
		return 0;
	}
	if(scanf("%d",&b)!=1){
	printf("you can not enter character for side lenght");
		return 0;
	}
	if(scanf("%d",&c)!=1){
	printf("you can not enter character for side lenght");
		return 0;
	}
	if(scanf("%d",&d)!=1){
	printf("you can not enter character for side lenght");
	return 0;
	}
	if(x>0 && b>0 && c>0 && d>0){
	s=(x+b+c+d)/2;
	area = sqrt((s-x)*(s-b)*(s-c)*(s-d));
	printf("area of this quadrilateral is %.2f ",area);
	       return 0;
}
    else {
    	printf("please enter a valid entry\n");	
	}

	break;
    case Perimeter:
    	
	if(scanf("%d",&x)!=1){
	printf("you can not enter character for side lenght");
		return 0;
	}
	if(scanf("%d",&b)!=1){
	printf("you can not enter character for side lenght");
		return 0;
	}
	if(scanf("%d",&c)!=1){
	printf("you can not enter character for side lenght");
		return 0;
	}
	if(scanf("%d",&d)!=1){
	printf("you can not enter character for side lenght");
	       return 0;
	}
	if(x>0 && b>0 && c>0 && d>0 ){
		printf("perimeter of this quadrilateral is %d",x+b+c+d);
		return 0;
	}
	else{
		printf("please enter valid entry\n");
	}
break;
    
	case Volume:
	printf("you can not calculate volume of quadrilateral\n ");
	return 1;
	case 0:
		return 0;
		default:
		printf("you should type [0-3] numbers\n");
		return 1;
}
}
	
}
int calc_circle(int a){
	
		int r,z=1;
	float area;
    if(a == 1 || a == 2){
    	printf("please enter radius of circle\n");
	}
	while(z=1){	
	switch(a){
	case Area:	
	
	if(scanf("%d",&r)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	
	if(r>0){
	area = PI*(r*r);
	printf("area of this circle is %.2f ",area);
	return 0;
}
    else {
    	printf("please enter a valid number\n");	
	}

	break;
    case Perimeter:
    	
	if(scanf("%d",&r)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	if(r>0){
		printf("perimeter of this quadrilateral is %.2f",2*PI*r);
		return 0;
	}
	else{
		printf("please enter a valid number\n");
	}
break;
    
	case Volume:
	printf("you can not calculate volume of circle\n ");
	return 1;
	case 0:
		return 0;
		default:
		printf("you should type [0-3] numbers\n");
		return 1;
}
}
	
}
int calc_pyramid(int a){
	
	int x,h,l,z=1;
	float area1,area2,area3;
    
	while(z=1){	
	switch(a){
	case Area:	
		printf("please enter base side and slant height of pyramid\n");	
	if(scanf("%d",&x)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	if(scanf("%d",&l)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	if(x>0 && l>0){
	area1=(x*x);
	area2=(2*x*l);
	area3=area1+area2;
	printf("base surface area of a pyramid is %.2f \n",area1);
	printf("laterai surface area of a pyramid is %.2f \n",area2);
	printf("surface area of a pyramid is %.2f \n",area3);
	return 0;
}
    else {
    	printf("please enter a valid entry\n");	
	}

	break;
    case Perimeter:
    printf("please enter base side of pyramid\n");
	if(scanf("%d",&x)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	
	if(x>0){
	float perimeter=(x*4);
		printf("base perimeter of pyramid is %.2f",perimeter);
		return 0;
	}
	else{
		printf("please enter a valid entry\n");
	}
break;
    
	case Volume:
	printf("please enter the base side and height of a pyramid\n");
	if(scanf("%d",&x)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	if(scanf("%d",&h)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	if(x>0 && h>0){
	float volume=((x*x)*h)/3;
		printf("volume of pyramid is %.2f\n",volume);
		return 0;
	}
	else{
		printf("please enter a valid entry\n");
	}
	break;
	case 0:
		return 0;
		default:
		printf("you should type [0-3] numbers\n");
		return 1;
}
}
	
}
int calc_cylinder(int a){
	
	int r,h,z=1;
	float area1,area2,area3;
    
	while(z=1){	
	switch(a){
	case Area:	
		printf("please enter the radius and height of cylinder\n");	
	if(scanf("%d",&r)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	if(scanf("%d",&h)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	if(r>0 && h>0){
	area1=PI*(r*r);
	area2=PI*2*r*h;
	area3=2*PI*r*(r+h);
	printf("base surface area of a cylinder is %.2f \n",area1);
	printf("laterai surface area of a cylinder is %.2f \n",area2);
	printf("surface area of a cylinder is %.2f \n",area3);
	return 0;
}
    else {
    	printf("please enter a valid entry\n");	
	}

	break;
    case Perimeter:
    printf("please enter the radius and height of pyramid\n");
	if(scanf("%d",&r)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	if(scanf("%d",&h)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	if(r>0 && h>0){
	float perimeter=(2*PI*r);
		printf("base perimeter of pyramid is %.2f",perimeter);
		return 0;
	}
	else{
		printf("please enter a valid entry\n");
	}
break;
    
	case Volume:
	printf("please enter the radius and height of a cylinder\n");
	if(scanf("%d",&r)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	if(scanf("%d",&h)!=1){
	printf("you can not enter character for lenght");
		return 0;
	}
	if(r>0 && h>0){
	float volume=PI*(r*r)*h;
		printf("volume of pyramid is %.2f\n",volume);
		return 0;
	}
	else{
		printf("please enter a valid entry\n");
	}
	break;
	case 0:
		return 0;
		default:
		printf("you should type [0-3] numbers\n");
		return 1;
}
}
	
	
}

int calculate(int  calc(),int  shape()){
	int a;
switch(shape()){
	case Triangle:
		a=calc();
		calc_triangle(a);
		 
		break;
	case Quadrilateral:
		a=calc();
	    calc_quadrilateral(a);
	    break;
	case Circle:
		a=calc();
	    calc_circle(a);
	    break;
	case Pyramid:
		a=calc();
	    calc_pyramid(a);
	    break;
	case Cylinder:
		a=calc();
	    calc_cylinder(a);    
	    break;
	case 6:
	    break; 
	default :
	printf("you should type [1-6] numbers\n") ;
	return 1;
}
}
 int main(){
 	int t=1;
 	while (t=1){
 if(calculate(select_calc,select_shape) !=1){
 	return 0;
 }
 else {
 	calculate(select_calc,select_shape);
 }
}

	
	return 0;
}


 
