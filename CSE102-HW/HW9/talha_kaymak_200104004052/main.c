
#include <stdio.h>

union Person
{
	char name[50];
	char address[50];
	int phone;	
};
union Loan
{
	float arr[3];
	
	
};
struct BankAccount
{
	union Person Customer;
	union Loan Loans[3];
};

int addCustomer(int id){
	FILE *fp;
	if ( (fp = fopen("customer.txt","a"))==NULL) {
        printf("file not found");
        return 0;
    }
    
	struct BankAccount ali;
    printf("Customer ID : %d\n",id);
	printf("Customer Name and Surname: ");
	scanf("%s",ali.Customer.name);
	fprintf(fp,"Customer name :%s ",ali.Customer.name);
	scanf("%s",ali.Customer.name);
	fprintf(fp,"%s\n",ali.Customer.name);
	printf("Customer Phone : ");
	scanf("%d",&ali.Customer.phone);
	fprintf(fp,"Customer Phone :%d\n",ali.Customer.phone);
	printf("Customer Address : ");
	scanf("%s",ali.Customer.address);
	fprintf(fp,"Customer Address :%s\n\n",ali.Customer.address);
	fclose(fp);
}
int customerlist(){
	FILE *fp2 = fopen("customer.txt", "r");

  while(! feof(fp2) ){
    putchar(fgetc(fp2));
  }

  fclose(fp2);

}

int newloan(){
	struct BankAccount cust;
	char customer[20];
	printf("enter name of customer\n");
	scanf("%s",customer);
	printf("enter amount:\n");
	scanf("%f",&cust.Loans[3].arr[1]);
	printf("enter period:\n");
	scanf("%f",&cust.Loans[3].arr[2]);
	printf("enter interesrRate:\n");
	scanf("%f",&cust.Loans[3].arr[3]);
    
	
}

int main(){
	int i=1;
	int id=0;	
	int choice;
	while (i=1){
		
	printf("Welcome to the Bank Management System\n========================================\n");
	printf("1. List All Customers\n2. Add New Customer\n3. New Loan Application\n4. Report Menu\n5. Exit\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			customerlist();
			break;
		case 2:
			id++;
			addCustomer(id);
		    break;
		case 3:
			newloan();
	    case 5:
	    	return 0;
		
		
}
}
	

	
	return 0;
}
