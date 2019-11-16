/*HEX ENCODER... BY M1GNUS*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A_SIZE 2048

/*Declaring the functions! OLD SCHOOL TEACHING*/
char* encode(char* plain);
char* parse(char* encoded);
void error(int type);

int main(int argc, char** argv){
	char* plaintext;
	char* encoded_text;
	if(argc!=2) error(100);
	if(*(*(argv+1))==' '){
		if((strlen(*(argv+1)) -1)%5!=0) error(102);
		encoded_text=*(argv+1);
		plaintext=parse(encoded_text);
		printf("decoded hex -> %s\n", plaintext);
		free(plaintext);
	}
	else{
		plaintext=*(argv+1);
		encoded_text=encode(plaintext);
		printf("encoded hex -> %s\n", encoded_text);
		free(encoded_text);
	}
	encoded_text=NULL;
	plaintext=NULL;
	return 0;
}

void error(int type){
	switch(type){
		case 100:
			printf("\n~WRONG NUMBER OF ARGUMENTS!~\n");
			break;
		case 101:
			printf("\n~RUNTIME ERROR: WRONG INPUT!~\n");
			printf("may the source be with you captain! by m1gnus... Maybe you can find it... WHERE?\n");
			break;
		case 102:
			printf("\n~LENGTH OF THE ARGUMENT IS NOT CORRECT~\n");
			break;
		case 103:
			printf("\n~ERROR WHILE PARSING~\n");
			break;
		default:
			printf("\n~UNDEFINED ERROR~\n");
			break;
	}
	exit(type);
}

/*M1gnus hex encoder*/
char* encode(char* plain){
	char* encoded=(char*) malloc(A_SIZE);
	char* chars=(char*) malloc(5);
	char c;
	int cnt=0, cnt2=0;
	while((c=*(plain+cnt))!='\0'){
		switch(c){
			case '0':
				chars="////#";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case '1':
				chars="/**-+";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case '2':
				chars="/&*^-";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case '3':
				chars="//@#$";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case '4':
				chars="/++*-";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case '5':
				chars="/*(*)";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case '6':
				chars="/+==+";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case '7':
				chars="/.,*.";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case '8':
				chars="///!@";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case '9':
				chars="//==/";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case 'a':
				chars="/&&/&";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case 'b':
				chars="/+/!@";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case 'c':
				chars="/[{}]";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case 'd':
				chars="//-/+";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case 'e':
				chars="/^/^$";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			case 'f':
				chars="///#/";
				strcpy(encoded+cnt2, chars);
				cnt2+=5;
				break;
			default:
				error(101);
		}
		cnt-=-1; //ehehe... this is funny
	}
	return encoded;
}

/*M1gnus hex parser*/
char* parse(char* encoded){
	char* decoded=(char*) malloc(A_SIZE);
	char* chars=(char*) malloc(5);
	char c;
	int cnt=0, cnt2=1;

	while(*(encoded+cnt2)!='\0'){
		chars=strncpy(chars,(encoded+cnt2),5);
		if(!strncmp(chars,"////#",5))
			*(decoded+cnt)='0';
		else if(!strncmp(chars,"/**-+",5))
			*(decoded+cnt)='1';
		else if (!strncmp(chars,"/&*^-",5))
			*(decoded+cnt)='2';
		else if (!strncmp(chars,"//@#$",5))
			*(decoded+cnt)='3';
		else if (!strncmp(chars,"/++*-",5))
			*(decoded+cnt)='4';
		else if (!strncmp(chars,"/*(*)",5))
			*(decoded+cnt)='5';
		else if (!strncmp(chars,"/+==+",5))
			*(decoded+cnt)='6';
		else if (!strncmp(chars,"/.,*.",5))
			*(decoded+cnt)='7';
		else if (!strncmp(chars,"///!@",5))
			*(decoded+cnt)='8';
		else if (!strncmp(chars,"//==/",5))
			*(decoded+cnt)='9';
		else if (!strncmp(chars,"/&&/&",5))
			*(decoded+cnt)='a';
		else if (!strncmp(chars,"/+/!@",5))
			*(decoded+cnt)='b';
		else if (!strncmp(chars,"/[{}]",5))
			*(decoded+cnt)='c';
		else if (!strncmp(chars,"//-/+",5))
			*(decoded+cnt)='d';
		else if (!strncmp(chars,"/^/^$",5))
			*(decoded+cnt)='e';
		else if (!strncmp(chars,"///#/",5))
			*(decoded+cnt)='f';
		else error(103);
		cnt++;
		cnt2+=5;
	}
	*(decoded+cnt)='\0';
	return decoded;
}
