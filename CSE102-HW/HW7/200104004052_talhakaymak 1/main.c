#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int randomfile(){
	int number;
	int i=1;
	while(i=1){
	number = rand();
	if(number>=0 && number<50){
		return number;
	}
	
	
}
}
int randomword(){
	int number;
	int i=1;
	while(i=1){
		
	number = rand();
	if(number>=65 && number<=90){ // ı choose to use capital words so you can easily find the words
		return number;
	}
	
	
}
}
int place(){
	int number;
	int i=1;
	while(i=1){
	number = rand();
	if(number>=0 && number<2){
		return number;
	}
}
}
int place1(){
	int number;
	int i=1;
	while(i=1){
	number = rand();
	if(number>=2 && number<4){
		return number;
	}
}
}
int place2(){
	int number;
	int i=1;
	while(i=1){
	number = rand();
	if(number>=4 && number<6){
		return number;
	}
}
}
int place3(){
	int number;
	int i=1;
	while(i=1){
	number = rand();
	if(number>=6 && number<8){
		return number;
	}
}
}
int place4(){
	int number;
	int i=1;
	while(i=1){
	number = rand();
	if(number>=8 && number<10){
		return number;
	}
}
}
int place5(){
	int number;
	int i=1;
	while(i=1){
	number = rand();
	if(number>=10 && number<12){
		return number;
	}
}
}
int place6(){
	int number;
	int i=1;
	while(i=1){
	number = rand();
	if(number>=12 && number<15){
		return number;
	}
}
}


int main(){
	int i,j,c,d,x,y,m,n,v,k,ce,de,xe,ye,aa,bb;
	int control=0;
	int score=0;
	int wrong=0;
	char quit[3]=":q";
	char board[15][15];
	char word1[10];
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			
			int rnd=randomword();
			
			board[i][j]=rnd;
		}
	}
	 FILE* ptr = fopen("wordlist.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
 char word[10];
 char stage[50][10];
 for(i=0;i<50;i++){
 	fscanf(ptr,"%s",word);
 strcpy(stage[i],word);
 	
 }
 
    srand(time(NULL));
    int a=randomfile();
    first:
    //word1
    word1[10];
    strcpy(word1,stage[a]);
    int b =strlen(stage[a]);
    //word2
	char word2[10];
			int z=randomfile();
            strcpy(word2,stage[z]);
            int t =strlen(stage[z]); 
            //word3
            char word3[10];
			int o=randomfile();
            strcpy(word3,stage[o]);
            int e =strlen(stage[o]);
            //word4
            char word4[10];
			int p=randomfile();
            strcpy(word4,stage[p]);
            int l =strlen(stage[p]);
            //word5
            char word5[10];
			int as=randomfile();
            strcpy(word5,stage[as]);
            int le =strlen(stage[as]);
            //word6
            char word6[10];
			int al=randomfile();
            strcpy(word6,stage[al]);
            int len =strlen(stage[al]);
            //word7
            char word7[10];
			int ale=randomfile();
            strcpy(word7,stage[ale]);
            int leng =strlen(stage[ale]);
            //here we check that all words different
            if(strcmp(word1,word2)==0 || strcmp(word1,word3)==0 || strcmp(word1,word4)==0 || strcmp(word1,word5)==0 || strcmp(word1,word6)==0 || strcmp(word1,word7)==0 ||
			strcmp(word2,word3)==0 ||strcmp(word2,word4)==0 ||strcmp(word2,word5)==0 ||strcmp(word2,word6)==0 ||strcmp(word2,word7)==0 ||strcmp(word3,word4)==0 ||   
			strcmp(word3,word5)==0 ||strcmp(word3,word6)==0 ||strcmp(word3,word7)==0 ||strcmp(word4,word5)==0 || strcmp(word4,word6)==0 || strcmp(word4,word7)==0 ||
			strcmp(word5,word6)==0 || strcmp(word5,word7)==0 || strcmp(word6,word7)==0 ){
				goto first;
			}
            again:
            c=place();
            d=place();
            again1:
	    x=place4();
            y=place6();
            again2:
	     m=place1();
            n=place4();
            again3:
	     v=place();
             k=place5();
            again4:
	     ce=place6();
             de=place();
            again5:
             xe=place4();
            ye=place2();
            again6:
             aa=place5();
             bb=place4();
           firstanswer:
	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			//we got first word here
		
			if(b==3 && d<13){
			board[c][d]=word1[0];
			board[c][d+1]=word1[1];
			board[c][d+2]=word1[2];
		}
		    else if(b==4 && d<12){
		    board[c][d]=word1[0];
			board[c][d+1]=word1[1];
			board[c][d+2]=word1[2];
			board[c][d+3]=word1[3];
			}
			else if(b==5 && d<11){
			board[c][d]=word1[0];
			board[c][d+1]=word1[1];
			board[c][d+2]=word1[2];
			board[c][d+3]=word1[3];
			board[c][d+4]=word1[4];
			}
			else{
				goto again;
			}
		
			//we got second word here
			
            if(t==3 && x<13){
			board[x][y]=word2[0];
			board[x+1][y]=word2[1];
			board[x+2][y]=word2[2];
		}
		    else if(t==4 && x<12){
		    board[x][y]=word2[0];
			board[x+1][y]=word2[1];
			board[x+2][y]=word2[2];
			board[x+3][y]=word2[3];
			}
			else if(t==5 && x<11){
			board[x][y]=word2[0];
			board[x+1][y]=word2[1];
			board[x+2][y]=word2[2];
			board[x+3][y]=word2[3];
			board[x+4][y]=word2[4];
			}
			else{
				goto again1;
			}
				//we got third word here
		    
            if(e==3 && m<13 && n<13){
			board[m][n]=word3[0];
			board[m+1][n+1]=word3[1];
			board[m+2][n+2]=word3[2];
		}
		    else if(e==4 && m<12 && n<12){
		    board[m][n]=word3[0];
			board[m+1][n+1]=word3[1];
			board[m+2][n+2]=word3[2];
			board[m+3][n+3]=word3[3];
			}
			else if(e==5 && m<11 && n<11){
			board[m][n]=word3[0];
			board[m+1][n+1]=word3[1];
			board[m+2][n+2]=word3[2];
			board[m+3][n+3]=word3[3];
			board[m+4][n+4]=word3[4];
			}
			else{
				goto again2;
			}
			//we got fourth word here
		    
            if(l==3 && k<13 && k>2){
			board[v][k]=word4[0];
			board[v][k-1]=word4[1];
			board[v][k-2]=word4[2];
		}
		    else if(l==4 && k<12 && k>3){
		    board[v][k]=word4[0];
			board[v][k-1]=word4[1];
			board[v][k-2]=word4[2];
			board[v][k-3]=word4[3];
			}
			else if(l==5 && k<11 && k>4){
			board[v][k]=word4[0];
			board[v][k-1]=word4[1];
			board[v][k-2]=word4[2];
			board[v][k-3]=word4[3];
			board[v][k-4]=word4[4];
			}
			else{
				goto again3;
			}
			//we got fifth word here
		
			if(le==3 && de<13){
			board[ce][de]=word5[0];
			board[ce][de+1]=word5[1];
			board[ce][de+2]=word5[2];
		}
		    else if(le==4 && de<12){
		    board[ce][de]=word5[0];
			board[ce][de+1]=word5[1];
			board[ce][de+2]=word5[2];
			board[ce][de+3]=word5[3];
			}
			else if(le==5 && de<11){
			board[ce][de]=word5[0];
			board[ce][de+1]=word5[1];
			board[ce][de+2]=word5[2];
			board[ce][de+3]=word5[3];
			board[ce][de+4]=word5[4];
			}
			else{
				goto again4;
			}
			//we got sixth word here
			if(len==3 && xe<13 && ye<13 && xe>2 && ye>2){
			board[xe][ye]=word6[0];
			board[xe-1][ye-1]=word6[1];
			board[xe-2][ye-2]=word6[2];
		}
		    else if(len==4 && xe<12 && ye<12 && xe>3 && ye>3){
		    board[xe][ye]=word6[0];
			board[xe-1][ye-1]=word6[1];
			board[xe-2][ye-2]=word6[2];
			board[xe-3][ye-3]=word6[3];
			}
			else if(len==5 && xe<11 && ye<11 && xe>4 && ye>4){
			board[xe][ye]=word6[0];
			board[xe-1][ye-1]=word6[1];
			board[xe-2][ye-2]=word6[2];
			board[xe-3][ye-3]=word6[3];
			board[xe-4][ye-4]=word6[4];
			}
			else{
				goto again5;
			}
			//we got seventh word here
			if(leng==3 && aa<13 && aa>0){
			board[aa][bb]=word7[0];
			board[aa-1][bb]=word7[1];
			board[aa-2][bb]=word7[2];
		}
		    else if(leng==4 && aa<12 && aa>1){
		    board[aa][bb]=word7[0];
			board[aa-1][bb]=word7[1];
			board[aa-2][bb]=word7[2];
			board[aa-3][bb]=word7[3];
			}
			else if(leng==5 && aa<11 && aa>2){
			board[aa][bb]=word7[0];
			board[aa-1][bb]=word7[1];
			board[aa-2][bb]=word7[2];
			board[aa-3][bb]=word7[3];
			board[aa-4][bb]=word7[4];
			}
			else{
				goto again6;
			}
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
	
	if(control==7){
		printf("you win the game\n");
		return 0;
	}
	int xcoor,ycoor;
	char answer[10];
	printf("FIRSTLY enter your word and THEN coordinate\n");
	scanf("%s",answer);
	if(strcmp(quit,answer)==0){
		return 0;
	}
	scanf("%d %d",&xcoor,&ycoor);
	
	//control of first word
if(d==xcoor && c==ycoor && strcmp(word1,answer)==0){
	if(b==3){
		printf("well done!\n");
		char threex[10]="XXX";
		strcpy(word1,threex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(b==4){
		printf("well done!\n");
		char fourx[10]="XXXX";
		strcpy(word1,fourx);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(b==5){
		printf("well done!\n");
		char fivex[10]="XXXXX";
		strcpy(word1,fivex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	
}
//control of second word
   if(y==xcoor && x==ycoor && strcmp(word2,answer)==0){
	if(t==3){
		printf("well done!\n");
		char threex[10]="XXX";
		strcpy(word2,threex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(t==4){
		printf("well done!\n");
		char fourx[10]="XXXX";
		strcpy(word2,fourx);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(t==5){
		printf("well done!\n");
		char fivex[10]="XXXXX";
		strcpy(word2,fivex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	
}
//control of third word
   if(n==xcoor && m==ycoor && strcmp(word3,answer)==0){
	if(e==3){
		printf("well done!\n");
		char threex[10]="XXX";
		strcpy(word3,threex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(e==4){
		printf("well done!\n");
		char fourx[10]="XXXX";
		strcpy(word3,fourx);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(e==5){
		printf("well done!\n");
		char fivex[10]="XXXXX";
		strcpy(word3,fivex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	
}
//control of fourth word
   if(k==xcoor && v==ycoor && strcmp(word4,answer)==0){
	if(l==3){
		printf("well done!\n");
		char threex[10]="XXX";
		strcpy(word4,threex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(l==4){
		printf("well done!\n");
		char fourx[10]="XXXX";
		strcpy(word4,fourx);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(l==5){
		printf("well done!\n");
		char fivex[10]="XXXXX";
		strcpy(word4,fivex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	
}
//control of fifth word
   if(de==xcoor && ce==ycoor && strcmp(word5,answer)==0){
	if(le==3){
		printf("well done!\n");
		char threex[10]="XXX";
		strcpy(word5,threex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(le==4){
		printf("well done!\n");
		char fourx[10]="XXXX";
		strcpy(word5,fourx);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(le==5){
		printf("well done!\n");
		char fivex[10]="XXXXX";
		strcpy(word5,fivex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	
}
//control of sixth word
   if(ye==xcoor && xe==ycoor && strcmp(word6,answer)==0){
	if(len==3){
		printf("well done!\n");
		char threex[10]="XXX";
		strcpy(word6,threex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(len==4){
		printf("well done!\n");
		char fourx[10]="XXXX";
		strcpy(word6,fourx);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(len==5){
		printf("well done!\n");
		char fivex[10]="XXXXX";
		strcpy(word6,fivex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	
}
//control of seventh word
   if(bb==xcoor && aa==ycoor && strcmp(word7,answer)==0){
	if(leng==3){
		printf("well done!\n");
		char threex[10]="XXX";
		strcpy(word7,threex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(leng==4){
		printf("well done!\n");
		char fourx[10]="XXXX";
		strcpy(word7,fourx);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	else if(leng==5){
		printf("well done!\n");
		char fivex[10]="XXXXX";
		strcpy(word7,fivex);
		score=score+2;
		printf("you got 2 points your total score is %d\n",score);
		control++;
		goto firstanswer;
	}
	
}

	printf("your answer is wrong\n");
	score=score-2;
	wrong++;
		printf("you lose 2 points your total score is %d\n",score);
		if(wrong==3){
		printf("you made 3 mistakes sorry\n");
		return 0;
		}
	goto firstanswer;
	return 0;
}
