  #include <stdio.h>
  
  void write_file (int a,int b,int c){
	FILE *fp = fopen("coefficient.txt","w");
   	fprintf(fp," %d\n %d\n %d\n",a,b,c);
   	fclose(fp);
	
}
 void write_graph (){
 int a,b,c,i,j,x,y,z;
	FILE *fp = fopen("coefficient.txt","r");
   	fscanf(fp,"%d %d %d",&a,&b,&c);
   	fclose(fp);
   	FILE *fp2 = fopen("graph.txt","w");
	for(x=30;x>=0;x--){
	i=x-15;
	j=a*(i*i)+b*i+c;
	for(y=0;y<111;y++){
   if(x==15){
  break;
  }
else{
  
  if(y==j+57){
  fprintf(fp2,"#");
  }
  else if(y==55){
  fprintf(fp2,"|");
  }
  else fprintf(fp2," "); 
  }
  }
  if(x==15){
  for(z=0;z<110;z++){
  fprintf(fp2,"-");
  }
  fprintf(fp2,"\n");
  }
 else fprintf(fp2,"\n");
  }
  
  
  	
}
  void draw_graph(){
  void yellow() {
  printf("\033[1;33m");
}
void green() {
  printf("\033[0;36m");
}
void reset () {
  printf("\033[0m");
}
  int x,y,z,a,b,c,i,j;
  FILE *fp = fopen("coefficient.txt","r");
  if(fp == NULL)
   {
      printf("firstly you have to make part 1. there is no file."); 
	                
   }
   else{
  fscanf(fp,"%d %d %d",&a,&b,&c);
  fclose(fp);
  
  
  
  for(x=30;x>=0;x--){
  i=x-15;
  j=a*(i*i)+b*i+c;
  
  for(y=0;y<111;y++){
  
  if(x==15){
  break;
  }
  else{
  if(y==51 && x==0){
  printf("-15");
  y=y+3;
  }
  if(y==52 && x==5){
  printf("-10");
  y=y+3;
  }
  if(y==53 && x==10){
  printf("-5");
  y=y+2;
  }
  if(y==53 && x==20){
  printf("5");
  y=y+1;
  }
  if(y==51 && x==25){
  printf(" 10");
  y=y+3;
  }
  if(y==51 && x==30){
  printf(" 15");
  y=y+3;
  }
  if(y==0 && x==14){
  printf("-50");
  y=y+2;
  }
  if(y==10 && x==14){
  printf("-40");
  y=y+3;
  }
  if(y==20 && x==14){
  printf("-30");
  y=y+3;
  }
  if(y==30 && x==14){
  printf("-20");
  y=y+3;
  }
  if(y==40 && x==14){
  printf("-10");
  y=y+4;
  }
  if(y==67 && x==14){
  printf("10");
  y=y+2;
  }
  if(y==78 && x==14){
  printf("20");
  y=y+3;
  }
  if(y==89 && x==14){
  printf("30");
  y=y+3;
  }
  if(y==100 && x==14){
  printf("40");
  y=y+3;
  }
  if(y==110 && x==14){
  printf("50");
  y=y+3;
  }
  
  else if(y==j+57){
  yellow();
  printf("#");
  reset();
  }
  else if(y==55){
  green();
  printf("|");
  reset();
  }
  else printf(" "); 
  }
  }
  if(x==15){
  for(z=0;z<110;z++){
  green();
  printf("-");
  reset();
  }
  printf("\n");
  }
 else printf("\n");
  }
  }
  }
  
  int main(){
  int secenek,x,y,a,z,b,c,i=1;
  while(i=1){
  printf("select an operation...\n1 ->enter the coefficients\n2 ->draw the graph\n3 ->print the graph into graph.txt file\n4 ->exit\n\nchoice: ");
  scanf("%d",&secenek);
  switch(secenek){
  case 1:
  printf("please enter the coefficient fot the following equation : x=a*(y*y) + b*y + c\n");
  scanf("%d %d %d",&a,&b,&c);
  printf("a: %d\nb: %d\nc: %d\n",a,b,c); 
  write_file (a,b,c);
  printf("coefficient.txt file has been created");
  break;
  case 2:
  draw_graph();
  break;
  case 3:
  write_graph();
  printf("coefficients has been read from the coefficient file.\nthe graph of x=%d*(y*y) + %d*y + %d has been written to graph.txt",a,b,c);
  break;
  case 4:
  return 0;
  }
  }
  return 0;
  }
