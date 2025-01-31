#include<stdio.h>
#include<ctype.h>
int main(){

	FILE *fp = fopen("example.txt","r");
	if(fp==NULL){
		printf("error in opening file\n");
		return 0;
	}
	FILE *fp2 = fopen("result.txt","w");

	if(fp2==NULL){
		printf("error in opening file");
		return 0;
	}


	char ch;

	while((ch = fgetc(fp))!=EOF){
	if(islower(ch)){
	fputc(toupper(ch),fp2);
	}
	else{
	
	fputc(tolower(ch),fp2);
	}
	
	}

	fclose(fp2);
	fclose(fp);


	return 0;



}
