#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

unsigned long i = 0x00;
char all[100];
char keya[20];
time_t t1,t2;
int status;

int z_passwd(char* name)
{
	i = 0x00;
	while(1)
	{
		t1 = time(NULL);
	a:	sprintf(keya,"%x",i++);
		sprintf(all,"7za x %s -aoa -p%s",name,keya);
		status = system(all);
		if(status != -1 && WIFEXITED(status) > 0 && WEXITSTATUS(status) == 0)
		{
			t2 = time(NULL);
			printf("\n密码为：%s\n",keya);
			printf("总共耗时%d秒...\n",t2-t1);
			return 0;
		}	
		else
		{
			sprintf(keya,"%X",i);
			sprintf(all,"7za x %s -aoa -p%s",name,keya);
			status = system(all);
			if(status != -1 && WIFEXITED(status) > 0 && WEXITSTATUS(status) == 0)
			{
				t2 = time(NULL);
				printf("\n密码为：%s\n",keya);
				printf("总共耗时%d秒...\n",t2-t1);
				return 0;
			}	
			else
				goto a;	
		}
	}
}

int zip_passwd(char* name)
{
	i = 0x00;
	while(1)
	{
		t1 = time(NULL);
	a:	sprintf(keya,"%x",i++);
		sprintf(all,"unzip -o -q -P %s %s",keya,name);
		status = system(all);
		if(status != -1 && WIFEXITED(status) > 0 && WEXITSTATUS(status) == 0)
		{
			t2 = time(NULL);
			printf("\n密码为：%s\n",keya);
			printf("总共耗时%d秒...\n",t2-t1);
			return 0;
		}	
		else
		{
			sprintf(keya,"%X",i);
			sprintf(all,"unzip -o -q -P %s %s",keya,name);
			status = system(all);
			if(status != -1 && WIFEXITED(status) > 0 && WEXITSTATUS(status) == 0)
			{
				t2 = time(NULL);
				printf("\n密码为：%s\n",keya);
				printf("总共耗时%d秒...\n",t2-t1);
				return 0;
			}	
			else
				goto a;	
		}
	}
}

int main()
{
	char fname[200];
	char name[200];
	short id = 0;

	printf("\t\t\t*************************\n");
	printf("\t\t\t*       1.zip格式       *\n");
	printf("\t\t\t*       2.tar格式       *\n");
	printf("\t\t\t*       3.tar.gz格式    *\n");
	printf("\t\t\t*       4.tar.bz2格式   *\n");
	printf("\t\t\t*       5.tar.xz格式    *\n");
	printf("\t\t\t*       6.jar格式       *\n");
	printf("\t\t\t*       7.7z格式        *\n");
	printf("\t\t\t*      按任意键退出！   *\n");
	printf("\t\t\t*************************\n");	

	printf("请选择文件压缩格式(1~7)：");
	scanf("%d",&id);

	printf("请输入文件名：");
	scanf("%s",fname);

	switch(id)
	{
		case 1:
		{
			zip_passwd(fname);
			break;
		}
/*		case 4:
		{
			strcpy(name," -ttar.bz2 ");
			strcat(fname,".tar.bz2");
			strcat(name,fname);
			z_passwd(name);
			break;
		}
*/		case 7:
		{
			strcat(fname,".7z");
			z_passwd(fname);
			break;
		}
		default:
		{
			printf("目前仅支持\"zip\"和\"7z\"两种格式！\n");
			printf("该种压缩暴力破解方式正在开发中。。。\n");
		}

	}

	return 0;
}
