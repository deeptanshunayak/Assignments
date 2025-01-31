#include<stdio.h>


int main(){

	FILE *fp,*fp1;

	fp = fopen("emp_ctc.txt","w");
	fp1= fopen("emp_att.txt","w");
	if(fp==NULL){
		printf("error in opening file");
		return 0;
	}
	if(fp1==NULL){
	
		printf("error in opening file");
		return 0;
	}

	int id=101;
	char name[]="Rahul";
	int tdays =30;
	int sal=20000;	
	int pdays=25;
	fprintf(fp, "emp_id(%d), emp_name(%s), total_days(%d), month_sal(%d)\n", id, name, tdays, sal);
	fprintf(fp1,"emp_id(%d),present_days(%d)",id,pdays);
	fclose(fp);
	fclose(fp1);
	return 0;




}
