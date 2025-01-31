#include<stdio.h>
int main(){
	//writing something to the file
	FILE *fp = fopen("example.txt","r");
	if(fp==NULL){
		printf("error in opening file\n");
		return 1;
	}

	fprintf(fp,"Welcome To Gx India\n");
	fclose(fp);
	printf("data inserted");
	return 0;
}
