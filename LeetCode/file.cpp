#include <stdio.h>
int main()
{
  FILE *fp= fopen("姓名.txt","r");  /*文本方式打开*/
  FILE *fout = fopen("D:\\姓.txt","w");  /*文本方式写入*/
  char c;
  while(!feof(fp))
  {
     c = fgetc(fp);
     if(!feof(fp))  /*双重判断，防止到达文件末尾时最后一个数据被读取两次*/
     {
         putchar(c);   /**/
         if('1' == c) c = '2';   /*修改字符1为2*/
         fputc(c,fout);
     }
   }
   fclose(fp);  /*关闭文件流*/
   fclose(fout);
   return 0;
}
