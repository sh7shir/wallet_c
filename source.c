#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct student
{
    int rno;
    char name[20];
    float per;
    float income;
    float expense;
    struct student *next;
} student;

student *head;

void line(int n)
{
    for(int i=0; i< n; i++)
    {
        printf("-");
    }
}


void load(student *h)
{

    FILE *fp;
    fp = fopen("tr.dat", "r");
    student s1;

    while(fread(&s1,sizeof(student),1,fp))
    {

        if(h == NULL)
        {
            h = (student*)malloc(sizeof(student));
            h->rno = s1.rno;
            strcpy(h->name, s1.name);
            h->per = s1.per;
            h->next = NULL;
            head = h;
        }
        else
        {
            while(h->next != NULL)
            {
                h = h->next;
            }

            h->next = (student*)malloc(sizeof(student));
            h->next->rno = s1.rno;
            strcpy(h->next->name, s1.name);
            h->next->per = s1.per;
            h->next->next = NULL;

        }

    }

    printf("Loaded Data Manually");
    fclose(fp);


}
void save(student *h)
{
    FILE *fp;
    fp = fopen("tr.dat", "w");

    while(h!=NULL)
    {
        fwrite(h,sizeof(student),1,fp);
        h = h->next;
    }
    fclose(fp);
    printf("Records Saved Successfully");
}

void create(student *h)
{
    int rno;
    char name[50];
    float per;
    printf("Enter Transaction No: ");
    scanf("%d", &rno);
    fflush(stdin);
    printf("Enter Category Name: ");
    scanf("%[^\n]s", name);
    printf("Enter Amount: HUF ");
    scanf("%f", &per);
    if(h == NULL)
    {
        head = (student*)malloc(sizeof(student));
        head->rno = rno;
        strcpy(head->name, name);
        head->per = per;
        head->next = NULL;
    }
    else
    {
        while(h->next != NULL)
        {
            h = h->next;
        }

        h->next = (student*)malloc(sizeof(student));
        h->next->rno = rno;
        strcpy(h->next->name, name);
        h->next->per = per;
        h->next->next = NULL;

    }
}

void display(student *h)
{
    printf("\n\n\n");
    printf("%-20s%-30s%s\n", "Number", "Category", "Amount");
    line(65);
    printf("\n");
    while(h != NULL)
    {
        printf("%-20d%-30s%.2f\n", h->rno, h->name, h->per);
        h = h->next;
    }
}

void see() {}
void sort() {}

void menu()
{
    int ch;
    do
    {
        system("cls");
        printf("\n\nWallet APP");
        printf("\nNeptun Code: D7VMQU\n");
        line(30);
        printf("\n1.View Wallet");
        printf("\n2.Make a Transaction");
        printf("\n3.List Transactions");
        printf("\n4.Sort Transactions");
        printf("\n5.Exit\n");
        line(30);
        printf("\n\n\nChoose a number to Continue: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            see();
            break;
        case 2:
            create(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            sort(head);
            break;
        case 5:
            save(head);
            printf(" Program Saved using save() and Closed");
            return;
            break;
        }
        printf("\n\n\n");
        system("pause");
    }
    while(ch != 0);

}


int main()
{
    load(head);
    menu();


}

