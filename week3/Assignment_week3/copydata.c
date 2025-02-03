#include<stdio.h>
void copylines(FILE *src,FILE *dest,int start,int end);

int main(){


	FILE *fp1,*fp2,*fp3;


	fp1 = fopen("file1.txt","r");
	fp2 = fopen("file2.txt","r");

	fp3 = fopen("file3.txt","w");



	if(fp1==NULL || fp2==NULL || fp3==NULL){

		perror("error in opening file");

		return 1;
	}
	//function call	
	copylines(fp1,fp3,20,80);//inputing lines from file1 from  20 to 80 
	fclose(fp1);
	copylines(fp2,fp3,50,90);//inputing lines from file2 from  50 to 90
	fclose(fp2);
	fclose(fp3);
        printf("lines has been inserted\n");
	return 0;
}

void copylines(FILE *src,FILE *dest,int start,int end){


	int current_line = 1;

	char ch;


	while((ch=fgetc(src))!=EOF){  // read charcter by character until end of file is detected

		if(current_line>=start && current_line<=end){// conditional check to input lines from start to end
			fputc(ch,dest);}

			if(ch=='\n'){  // increment current line when there is new line occured

				current_line++;

			}
		

	}


}
