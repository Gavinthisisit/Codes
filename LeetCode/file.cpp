#include <stdio.h>
int main()
{
  FILE *fp= fopen("����.txt","r");  /*�ı���ʽ��*/
  FILE *fout = fopen("D:\\��.txt","w");  /*�ı���ʽд��*/
  char c;
  while(!feof(fp))
  {
     c = fgetc(fp);
     if(!feof(fp))  /*˫���жϣ���ֹ�����ļ�ĩβʱ���һ�����ݱ���ȡ����*/
     {
         putchar(c);   /**/
         if('1' == c) c = '2';   /*�޸��ַ�1Ϊ2*/
         fputc(c,fout);
     }
   }
   fclose(fp);  /*�ر��ļ���*/
   fclose(fout);
   return 0;
}
