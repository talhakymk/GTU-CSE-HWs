#include <stdio.h>
#include "util.h"
#include <math.h>


char dt1a(float pl,float pw){
	if(pl<2.45){
		return 's';
	}
	else if(pw>1.75){
			return 'v';
	}
	else if(pl>4.95){
			return 'v';
	}
	else if(pw>1.65){
			return 'v';
	}
	else if(pw<1.65){
			return 'c';
	}
}
char dt1b(float pl,float pw){
		if(pl<2.55){
			return 's';
	}
	else if(pw>1.69){
			return 'v';
	}
	else if(pl>4.85){
			return 'v';
	}
	else if(pl<4.85){
			return 'c';
	}
}
	double dt2a(float x1,float x2,float x3,int x4, int x5){
		if(x1<31.5){
			if(x2>-2.5){
				return 5.0;
			}
			else if(x2-0.1 <= x1 && x2+0.1 >=x1){
				return 2.1;
			}
			else{
				return -1.1;
			}
		}
		else{
			if(x3>= -1 && x3 <=2){
				return 1.4;
			}
			else if(x4 && x5){
				return -2.23;
			}
			else {
				return 11.0;
			}
		}
	}
		double dt2b(float x1,float x2,float x3,int x4, int x5){
		if(x1<22 && x1>12){
			if(x3>(5/3)){
				return -2.0;
			}
			else if(x1-0.1 <= x3 && x1+0.1 >=x3){
				return 1.01;
			}
			else{
				return -8;
			}
		}
		else{
			if(x4 && x5){
				return -1;
			}
			else if(x2>=-1 && x2<=2){
				return -0.142;
			}
			else {
				return (sqrt(2)/3);
			}
		}
	}
	int dt3a(float yas,float sure,int sevgi,int gun,int vakit){
		if(yas<32){
			if(sure<5){
				return 2;
			}
			else if(sure>=5){
				if(sevgi ==1){
					if(gun <= 3){
						return 4;
					}
					else if(gun>3){
						return 3;
					}
				}
				else if(sevgi ==0){
					return 1;
				}
			}
		}
		else if(yas>=32){
			if(vakit<=3){
				return 4;
			}
			else {
				if(sure>10){
					return 4;
				}
				else{
					return 2;
				}
			}
		}
	}
int dt3b(float yas,float sure,int sevgi,int gun,int vakit){
	if(yas>=18 && yas<=25){
		if(vakit>3){
			if(sevgi==1){
				return 3;
			}
			else{
				return 1;
			}
		}
		else if(vakit<=3){
			return 4;
		}
	}
	else if(yas>25){
		if(gun>4){
			if(sure>=1 && sure <=8){
				return 2;
			}
			else {
				return 3;
			}
				}
				else if(gun<=4){
					if(sevgi==1){
						return 4;
					}
					else {
						return 2;
					}
				}
	}
}


