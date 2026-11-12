#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char enrollment[8];
    char name[50];
    float grade;
} Data;

int compare(const void *a, const void *b)
{
    const Data *elem1 = (const Data *)a;
    const Data *elem2 = (const Data *)b;

    return strcmp(elem1->name, elem2->name);
}

int main()
{
    char buffer[256];
    FILE *fp1;
    fp1=fopen("alunos.txt", "r");
    if (fp1 == NULL)
    {
        printf("File not found\n");
        exit(1);
    }

    FILE *fp2 = fopen("saída.txt", "w");

    fgets(buffer, sizeof(buffer), fp1);

    Data alunos[256];
    Data aluno = {0, "", "", -1};
    int i = 0;
    while(fscanf(fp1, "%d;%7[^;];%49[^;];%f\n",  &aluno.id, &aluno.enrollment, &aluno.name, &aluno.grade) == 4)
    {
        alunos[i] = aluno;
        i++;
    }

    qsort(alunos, i, sizeof(Data), compare);

    for(int j = 0; j < i; ++j)
    {
        fprintf(fp2, "%d;%s;%s;%.1f\n", alunos[j].id, alunos[j].enrollment, alunos[j].name, alunos[j].grade);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
