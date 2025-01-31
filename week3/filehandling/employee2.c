#include <stdio.h>

int main() {
	FILE *fp1, *fp2, *fp3;
	int id, tdays, sal, pdays;
	char name[50];


	fp1 = fopen("emp_ctc.txt", "r");
	fp2 = fopen("emp_att.txt", "r");
	fp3 = fopen("emp_sal.txt", "w");


	if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
		printf("Error in opening file\n");
		return 1;
	}


	fscanf(fp1, "emp_id(%d), emp_name(%[^)]), total_days(%d), month_sal(%d)", 
			&id, name, &tdays, &sal);


	fscanf(fp2,"emp_id(%d),present_days(%d)",&id,&pdays);


	if (tdays == 0) {
		printf("Error: total_days cannot be zero!\n");
		return 1;
	}


	int adays = tdays - pdays;
	float dailys =(float)( sal/tdays); 
	float ds = adays * dailys;
	float nets = sal - ds;


	fprintf(fp3, "emp_id(%d), emp_name(%s), total_days(%d), absent_days(%d), month_sal(%d), deducted_sal(%.2f), net_sal(%.2f)\n",
			id, name, tdays, adays, sal, ds, nets);


	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	printf("Salary details processed successfully.\n");
	return 0;
}

