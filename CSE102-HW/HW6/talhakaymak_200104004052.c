#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMap(int p1,int p2){
char map[16][31];
int i,j;


for(i=0;i<15;i++){
	for(j=0;j<30;j++){  //bu dongu icinde ana tablomuzu olusturuyoruz
if(i==0){
	map[i][j]='.';
}		

else if(i==14){
	map[i][j]='.';
}
else if(j==0 && i>0){
	map[i][j]=':';
}
else if(j==29 && i>0){
	map[i][j]=':';
}
else if(i==2 && j>1 && j<28){
	map[i][j]='.';
}
else if(i==12 && j>1 && j<28){
	map[i][j]='.';
}
else if(i>2 && i<12 && j==2){
	map[i][j]=':';
}
else if(i>2 && i<12 && j==27){
	map[i][j]=':';
}
else if(i==4 && j>3 && j<26){
	map[i][j]='.';
}
else if(i==10 && j>3 && j<26){
	map[i][j]='.';
}
else if(j==4 && i>4 && i<10){
	map[i][j]=':';
}
else if(j==25 && i>4 && i<10){
	map[i][j]=':';
}
else if((i==1 && j==14) || (i==7 && j==28) || (i==13 && j==14) || (i==3 && j==10) || (i==3 && j==18) || (i==5 && j==26) || (i==10 && j== 26) || (i==11 && j==10) || (i==11 && j==18)){
	map[i][j]='X';
	
}
else{
	map[i][j]=' ';
}
}
}

map[2][1]='_';
map[4][3]='_';
if(p1<28){   // gelen p1 ve p2 degerlerini 0 lamadan üzerine ekleyerek arttırdıgımdan p1 ve p2 degerleri bu kadar artıyor
map[1][p1+1]='1';  //matrisin 2. degeri degistirilerek saga hareketi saglanıyor
}
else if(p1>40 && p1<68){
	p1=p1-40;
	map[13][28-p1]='1';  //burada matrisin 2. degerini degistirerek sayımızın sola hareketi saglanıyor
}
else if(p1>68 && p1<79){
	p1=p1-68;
	map[13-p1][1]='1'; //matrisin ilk degeri degistirilerek yukarı hareketi saglanıyor
}
else if(p1>=79){
	printf("***PLAYER 1 won the game***");
	
}
else{
p1=p1-28;
map[p1+1][28]='1';
}
if(p2<24){
map[3][p2+3]='2';   //matrisin 2. degeri degistirilerek saga hareketi saglanıyor
}
else if(p2>32 && p2<56){
	p2=p2-32;
	map[11][26-p2]='2';  //burada matrisin 2. degerini degistirerek sayımızın sola hareketi saglanıyor
}
else if(p2>56 && p2<63){
	p2=p2-56;
	map[11-p2][3]='2';  //matrisin ilk degeri degistirilerek yukarı hareketi saglanıyor
}
else if(p2>=63){
	printf("***PLAYER 2 won the game***");
	
}
else{
p2=p2-24;
map[p2+3][26]='2';
}
for(i=0;i<15;i++){
	for(j=0;j<30;j++){

printf("%c ",map[i][j]);
}
printf("\n");
}
}
int dice(){
	int dice;
	int i=1;
	while(i=1){
	dice = rand();
	if(dice>0 && dice<7){ //gelen degeri 1 ve 6 arası olmasını saglıyor
		return dice;
	}
}
	
	
}

int starttogame(){
	char space,SPACE; //kullanıcı entera bastıgında bos deger almak icin olusturdugum karakterler
	int i;
printf("To start to game, players should dice and decide who is going to start first according to it...\n ");
while(i=1){
printf("PLAYER 1... press ENTER to dice: ");
scanf("%c",&space);
srand(time(NULL));
int a=dice();
printf("DICE: %d\n",a);
printf("PLAYER 2... press ENTER to dice: ");
scanf("%c",&SPACE);
int b=dice();
srand(time(NULL));
printf("DICE: %d\n",b);
if(a==b){
	printf("same dice value please try again\n");
}
else if(a>b){
	printf("*** PLAYER 1 start to game ***\n");
	return 1;
}
else if(a<b){
	printf("*** PLAYER 2 start to game ***\n");
	return 2;
}
}

}
int main(){
int z=1,p1=0,p2=0,b=0,a=0;
printMap(0,0); //ilk basta bos basması icin 0 degerlerini gönderiyoruz
int c=starttogame();
if(c==1){
	char space; //kullanıcı entera bastıgında bos deger almak icin olusturdugum karakter
	while (z=1){
	printf("PLAYER 1... press ENTER to dice: ");
	scanf("%c",&space);
srand(time(NULL));
a=dice();
 p1=a+p1; //p1 degeri sıfırlanmadan gelen her zar ile artmakta
printf("DICE: %d\n",a);
printf("PLAYER 2... press ENTER to dice: ");
scanf("%c",&space);
b=dice();
 p2=b+p2; //p2 degeri sıfırlanmadan gelen her zar ile artmakta
srand(time(NULL));
printf("DICE: %d\n",b);

if(p1>=79 && p2<63){  //p1 belli bi degere gelince finish noktasını gecmis sayılıyor ve oyunu kazanıyor
		printf("***PLAYER 1 won the game***");
	return 0;
}
else if(p1<79 && p2>=63 ) {  //p2 belli bi degere gelince finish noktasını gecmis sayılıyor ve oyunu kazanıyor
		printf("***PLAYER 2 won the game***"); 
		return 0;
}
if(p1==13 || p1==34 || p1==54){
	printf("PLAYER 1 touch the penalty point\n"); //penaltı noktasına degen sayılar 2 birim geri ceza alıyor
	p1=p1-2;
}
if(p2==7 || p2==15 || p2==26 || p2==31 || p2==40 || p2==48){ 
	printf("PLAYER 2 touch the penalty point\n"); //penaltı noktasına degen sayılar 2 birim geri ceza alıyor
	p2=p2-2; 
}	
printMap(p1,p2);
}
}
else if(c==2){
	char space; // kullanıcıdan entera basarken alınan bos deger
	while (z=1){
	printf("PLAYER 2... press ENTER to dice: ");
	scanf("%c",&space);
srand(time(NULL));
b=dice();
 p2=b+p2; //p2 degeri sıfırlanmadan gelen her zar ile artmakta
printf("DICE: %d\n",b);
printf("PLAYER 1... press ENTER to dice: ");
	scanf("%c",&space);
srand(time(NULL));
a=dice();
 p1=a+p1; //p1 degeri sıfırlanmadan gelen her zar ile artmakta
printf("DICE: %d\n",a);

if(p1>=79 && p2<63){
		printf("***PLAYER 1 won the game***"); //p1 belli bi degere gelince finish noktasını gecmis sayılıyor ve oyunu kazanıyor
	return 0;
}
else if(p1<79 && p2>=63){
		printf("***PLAYER 2 won the game***"); //p2 belli bi degere gelince finish noktasını gecmis sayılıyor ve oyunu kazanıyor
		return 0;
}	
if(p1==13 || p1==34 || p1==54){
	printf("PLAYER 1 touch the penalty point\n");
	p1=p1-2;
}
if(p2==7 || p2==15 || p2==26 || p2==31 || p2==40 || p2==48){
	printf("PLAYER 2 touch the penalty point\n");
	p2=p2-2;
}
printMap(p1,p2);
}
}


return 0;
}


