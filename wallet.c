#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct date //building struct for date
{
    int month, day, year;
};

struct // struct for Wallet info
{
    char name[60];
    int acc_no, age;
    char address[100];
    char citizenship[15];
    double phone;
    char acc_type[10];
    struct date dob;
    time_t tran_time;

} add;

typedef struct transaction
{
    /* The data to store trNo, name[50], per, income, expense, total */
    char name[50]; // Category Name
    float per;
    struct tot
    {
        time_t tran_day;
        time_t tran_month;
        time_t tran_year;
    } tot;
    float income;
    float expense;
    struct transaction *next; /* Pointer to the next list element */
} transaction;

transaction *head;

void line(int n)
{
    for(int i=0; i< n; i++)
    {
        printf("-");
    }
}

void see()
{

    FILE *ptr;
    int choice;
    float time;
    ptr = fopen("wallet.txt", "r");

    fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type);

    printf("\nAccount Number: %d\nName: %s \nDOB: %d/%d/%d \nAge: %d \nAddress: %s \nCitizenship Number: %s \nPhone number: %.0lf \nType Of Account: %s \n\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
           add.acc_type);

    fclose(ptr);


}

void load(transaction *h)
{

    FILE *fp;
    fp = fopen("transactions.dat", "r");
    transaction s1;

    while(fread(&s1,sizeof(transaction),1,fp))
    {

        if(h == NULL)
        {
            h = (transaction*)malloc(sizeof(transaction));
            strcpy(h->name, s1.name);
            h->per = s1.per;
            h->income = s1.income;
            h->expense = s1.expense;
            h->tot.tran_day = s1.tot.tran_day;
            h->tot.tran_month = s1.tot.tran_month;
            h->tot.tran_year = s1.tot.tran_year;
            h->next = NULL;
            head = h;
        }
        else
        {
            while(h->next != NULL)
            {
                h = h->next;
            }

            h->next = (transaction*)malloc(sizeof(transaction));
            strcpy(h->next->name, s1.name);
            h->next->per = s1.per;
            h->next->income = s1.income;
            h->next->expense = s1.expense;
            h->tot.tran_day = s1.tot.tran_day;
            h->tot.tran_month = s1.tot.tran_month;
            h->tot.tran_year = s1.tot.tran_year;
            h->next->next = NULL;

        }

    }
    fclose(fp);
}

void save(transaction *h)
{
    FILE *fp;
    fp = fopen("transactions.dat", "w");

    while(h!=NULL)
    {
        fwrite(h,sizeof(transaction),1,fp);
        h = h->next;
    }
    fclose(fp);
    printf("Records Saved Successfully");
}

void create(transaction *h)
{
    int choice;

    printf("\n\nSelect 1 for Income and 2 for Expense\n");
    printf("\n1. Income \n2. Expense\n\n");
    printf("Selected: ");
    scanf("%d", &choice);
    if(choice == 1)
    {
        int trNo;
        char name[50];
        float per;

        fflush(stdin);
        printf("Enter Category Name: ");
        scanf("%[^\n]s", name);
        printf("Enter Amount: HUF ");
        scanf("%f", &per);

        // Date from system
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        if(h == NULL)
        {
            head = (transaction*)malloc(sizeof(transaction));
            strcpy(head->name, name);
            head->per = per;
            head->income = per;
            head->tot.tran_day = tm.tm_mday;
            head->tot.tran_month = tm.tm_mon + 1;
            head->tot.tran_year = tm.tm_year + 1900;
            head->next = NULL;
        }
        else
        {
            while(h->next != NULL)
            {
                h = h->next;
            }

            h->next = (transaction*)malloc(sizeof(transaction));
            strcpy(h->next->name, name);
            h->next->per = per;
            h->next->income = per;
            h->next->tot.tran_day = tm.tm_mday;
            h->next->tot.tran_month = tm.tm_mon + 1;
            h->next->tot.tran_year = tm.tm_year + 1900;
            h->next->next = NULL;

        }
    }
    else if(choice == 2)
    {
        int trNo;
        char name[50];
        float per;
        fflush(stdin);
        printf("Enter Category Name: ");
        scanf("%[^\n]s", name);
        printf("Enter Amount: HUF ");
        scanf("%f", &per);
        // Date from system
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        if(h == NULL)
        {
            head = (transaction*)malloc(sizeof(transaction));
            strcpy(head->name, name);
            head->per = per;
            head->expense = per;
            head->tot.tran_day = tm.tm_mday;
            head->tot.tran_month = tm.tm_mon + 1;
            head->tot.tran_year = tm.tm_year + 1900;
            head->next = NULL;
        }
        else
        {
            while(h->next != NULL)
            {
                h = h->next;
            }

            h->next = (transaction*)malloc(sizeof(transaction));
            strcpy(h->next->name, name);
            h->next->per = per;
            h->next->expense = per;
            h->next->tot.tran_day = tm.tm_mday;
            h->next->tot.tran_month = tm.tm_mon + 1;
            h->next->tot.tran_year = tm.tm_year + 1900;
            h->next->next = NULL;

        }
    }
    else
    {
        printf("Enter a value between 1 and 2");
        create(head);

    }


}

void display(transaction *h)
{
    int tranNo = 1;
    float incomes, expenses, total;
    printf("\n\n");
    printf("Number of Transactions: %d \n\n", countNode(head));
    printf("%-20s%-30s%s\n", "Number", "Category", "Amount");
    line(65);
    printf("\n");
    while(h != NULL)
    {
        printf("%-20d%-30s%.2f\t%d/%d/%d\n", tranNo, h->name, h->per, h->tot.tran_day, h->tot.tran_month, h->tot.tran_year);
        incomes += h->income;
        expenses += h->expense;
        h = h->next;
        tranNo++;
    }
    total = incomes - expenses;

    printf("\n\n\nIncomes: HUF %.2f\nExpenses: HUF %.2f\nBalance: HUF %.2f\n", incomes, expenses, total);
}

int countNode(transaction *h)
{
    int count = 0;
    while(h!=NULL)
    {
        h = h->next;
        count++;
    }
    return count;
}

void sort(transaction *h)
{
    int numberOfNodes = countNode(head);
    transaction * currentNode, *nextNode;

    int nodeCtr, ctr, nodeDataCopy;

    int temp;

    for(nodeCtr = numberOfNodes-2; nodeCtr >= 0; nodeCtr--)
    {
        currentNode = head;
        nextNode = head->next;

        for(ctr = 0; ctr <=nodeCtr; ctr++)
        {
            if(currentNode->per > nextNode->per)
            {
                nodeDataCopy = currentNode->per;
                currentNode->per = nextNode->per;
                nextNode->per = nodeDataCopy;

            }
            currentNode = nextNode;
            nextNode = nextNode->next;

        }
    }
    display(head);
}

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

