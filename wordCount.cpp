#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<io.h> 

int getChar(FILE *fp);
int getWord(FILE *fp);


int main(int argc,char*argv[]){
	FILE *fp;
	int number;
	char string;

    if(argc==3){
    	
    	//��ȡ�ļ�������
		fp = fopen(argv[2],"r");
		
		//��ʧ�� 
		if(fp == NULL){
			printf("�����޷���%s\n",argv[2]);
			exit(1);
		} 
			//�Բ�������ƥ�� 
		    if(!strcmp(argv[1],"-c")){//ͳ���ַ��� 
		        number = getChar(fp);
		     	printf("�ַ���Ϊ%d\n",number);
		    }
		
		    else if(!strcmp(argv[1],"-w")){//ͳ�Ƶ����� 
			    number = getWord(fp);
			    printf("������Ϊ%d\n",number); 
		   }
	}
	
	else {
		printf("���󣺲��������������������\n");
	}
	
} 

//ͳ���ַ��� 
int getChar(FILE *fp){
	char ch;
	int number=0;
	while((ch=fgetc(fp))!=EOF){//������fgetc���ص�ASCIIֵ��Ϊ EOF����ʾ�����Լ����� 
		if((ch!='\n')&&(ch!=' ')&&(ch!='\t')){
			number++;
		}
	}
	rewind(fp);
	return number;
}

//ͳ�Ƶ����� 
int getWord(FILE *fp){
	int flag=0;
	int number=0;
	char ch;
	while(!feof(fp))
    {
        ch = fgetc(fp);
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            flag = 0;
        else if(flag == 0 && (ch != '-' && ch != '/'&& ch != '\'')) //����������ѭ�����������������ѭ���������صĲ�����ĸ�������� 
        {
            number++;
            flag = 1;
        }
    }
    rewind(fp);
    return number;
}





