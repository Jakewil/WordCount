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
    	
    	//读取文件的内容
		fp = fopen(argv[2],"r");
		
		//打开失败 
		if(fp == NULL){
			printf("错误：无法打开%s\n",argv[2]);
			exit(1);
		} 
			//对参数进行匹配 
		    if(!strcmp(argv[1],"-c")){//统计字符数 
		        number = getChar(fp);
		     	printf("字符数为%d\n",number);
		    }
		
		    else if(!strcmp(argv[1],"-w")){//统计单词数 
			    number = getWord(fp);
			    printf("单词数为%d\n",number); 
		   }
	}
	
	else {
		printf("错误：参数输入错误，请重新输入\n");
	}
	
} 

//统计字符数 
int getChar(FILE *fp){
	char ch;
	int number=0;
	while((ch=fgetc(fp))!=EOF){//当函数fgetc返回的ASCII值不为 EOF，表示还可以继续读 
		if((ch!='\n')&&(ch!=' ')&&(ch!='\t')){
			number++;
		}
	}
	rewind(fp);
	return number;
}

//统计单词数 
int getWord(FILE *fp){
	int flag=0;
	int number=0;
	char ch;
	while(!feof(fp))
    {
        ch = fgetc(fp);
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            flag = 0;
        else if(flag == 0 && (ch != '-' && ch != '/'&& ch != '\'')) //如果进入这个循环，代表不符合上面的循环，即返回的不是字母或者数字 
        {
            number++;
            flag = 1;
        }
    }
    rewind(fp);
    return number;
}





