# Bubble_Sort

#include <stdio.h>
#include <stdlib.h>
void save(FILE *fp, int* a, int n);
void sort(int*a, int n);
	
	  	//fputc(fgetc(in),out);
void copyFile()
{
	   FILE *in;
	   int i,a[14], j = 0, n ;
	   char *p="D:\\C程序\\xinlin2\\1.txt";
	   if ((in = fopen(p,"r")) == NULL)     // 1.txt文件中存放着原始数据；
	   { 
	       printf("canot find the file!\n");
	       exit(0);
	   }
	   
	  // i = getw(in);	   // getw()函数的目的是将 1.txt文件中的内容取出来存放到i中去
	   while (j<14)
	   {    
		  // a[j] = i;
	      // i = getw(in);
		   //j++;
		   fscanf(in, "%d",a[j] );
		   j++;
		   //putw(a[j],in);
	   }

	   n = sizeof(a)/sizeof(int);
	   sort(a,n);		     // 用冒泡排序对文件中的内容	排序
	   save(in, a, n);	     //	   排序后输出并保存1.txt文件的内容到2.txt中
	   fclose(in);
	  
}

void sort(int*a, int n)	    // 用冒泡排序对1.txt文件中的内容	排序
{	   
	int i,j,temp;
	for(i=0; i<n; i++)
	{
		 for(j=0; j<n-i-1; j++)
		  {
				if(a[j] > a[j+1])
				{
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
		   }
		}
	
}
	
void save(FILE* fp, int* a, int n)
{   
	   FILE *out;	  
	   int  m;
	   if((out = fopen("2.txt","w") ) == NULL)
	   { 
	      printf("canot find the file!\n");
          exit(0);
	   }

	  m = getw(fp);
      while (m!=EOF)
	  { 
	     putw(getw(fp),out);
	  }
  
	  fclose(fp);
	  fclose(out);       
	}	
	

int main()
{  
   copyFile();
   system("pause");
   return 0;
}
