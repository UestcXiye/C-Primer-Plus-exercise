#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
int main(void)
{
    FILE *fp;
    char words[SIZE];
    int i = 0; // iΪ���ʱ��

    if ((fp = fopen("file.txt", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open file.txt.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter the words,press ");
    puts("# at the beginning of a line to terminate:");
    while (fscanf(fp, "%s", words) == 1) // ͳ��ԭ�еĵ�����
        i++;
    while (fscanf(stdin, "%40s", words) == 1 && words[0] != '#') // �����հ��ַ������뵥�ʽ���
        fprintf(fp, "%d%s\n", ++i, words);                       // �����µ��ʣ���Ϊ����
    rewind(fp);
    puts("File content:");
    while (fscanf(fp, "%s", words) == 1)
        puts(words);
    while (fclose(fp) != 0)
        fprintf(stderr, "Error in closing file.\n");

    return 0;
}