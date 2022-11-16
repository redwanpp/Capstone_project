//main page of library management

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int d = 1;

void password();
void heading();
void mainmenu();
void add_book();
void view_book();
void search_book();
void edit_book();
void delete_book();
void documentation();


typedef struct book_info Info;

struct book_info {
    int id;
    char name[10];
    char author[10];
    int quantity;
    int rack;
};

Info a;

FILE *file, *file2;

int main() {
    password();

    return 0;
}

void mainmenu() {
    system("cls");
    int choice;

    printf("\n\n \t\t*****************Main Menu*****************\n");

    printf("\n");
    printf("\t\t 1. add book\n");
    printf("\t\t 2. view book list\n");
    printf("\t\t 3. search book\n");
    printf("\t\t 4. edit book\n");
    printf("\t\t 5. delete book\n");
    printf("\t\t 6. documentation\n");
    printf("\t\t 7. exit\n");

    printf("\n\n \t\t *********************************\n");
    printf("\t\t Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_book();
            break;
        case 2:
            view_book();
            break;
        case 3:
            search_book();
            break;
        case 4:
            edit_book();
            break;
        case 5:
            delete_book();
            break;
        case 6:
            documentation();
            break;
        case 7:
            exit(0);
            break;
        default: {
            printf("\t\tInvalid choice\n");   
            printf("\t\t Try Again....");

            fflush(stdin);
            getchar();

            mainmenu();
        }
    }

    fflush(stdin);
    getchar();
}

void heading() {
    system("cls");
    printf("\n\n\t\t ***************Library Project***********\n");

    // fflush(stdin);
    // getchar();
}

void password(){

    heading();

    char pwd1[10] = {"admin"};
    char pwd2[10];

    printf("\n \t\tEnter password: ");
    scanf("%s", pwd2);

    if(strcmp(pwd1, pwd2) == 0) {
        printf("\n\n\t\tMatch password\n");
        printf("\n\n\t\tPress any key... ... ...\n");
    }
    else {
        if(d == 3) {
            exit(0);
        }

        printf("\n\n\tWrong password %d to 3\n", d);
        printf("\n\n\t   Try again....");
        d++;

        fflush(stdin);
        getchar();

        password();
    }

    fflush(stdin);
    getchar();

    mainmenu();

}

//book add function
void add_book() {
    system("cls");

    int d, count = 0;

    printf("\n\n \t\t ***************** Add Book *************\n");
    
    file = fopen("Books.dat", "ab+");

    printf("\t\t Enter Book ID: ");
    scanf("%d", &d);

    rewind(file);

    while(fread(&a, sizeof(a), 1, file) == 1) {
        if(d == a.id) {
            printf("\n\n\t\t This book is already in library..........\n");
            count = 1; 
        }
    }

    if(count == 1) {
        fflush(stdin);
        getchar();
        mainmenu();
    }

    a.id = d;

    printf("\n\n \t\t Enter Book Name: ");
    scanf("%s", a.name);
    printf(" \t\t Author Name: ");
    scanf("%s", a.author);
    printf(" \t\t Enter Quantity: ");
    scanf("%d", &a.quantity);
    printf(" \t\t Enter Rack Number: ");
    scanf("%d", &a.rack);

    fseek(file, 0, SEEK_END);
    fwrite(&a, sizeof(a), 1, file); 

    fclose(file);

    printf("\n\n \t\t Add Book Successfully!\n");
    printf("\n\n press any key......\n");

    fflush(stdin);
    getchar();

    mainmenu();
}

//Diplay book list function
void view_book() {
    system("cls");

    int count = 0;

    printf("\n\n \t\t ************ View Book List **********\n\n");
    printf("\tID\tName\tAuthor\tQNT\tRack\n");

    file = fopen("Books.dat",  "rb+");

    while(fread(&a, sizeof(a), 1, file) == 1) {
        printf("\t%d", a.id);
        printf("\t%s", a.name);
        printf("\t%s", a.author);
        printf("\t%d", a.quantity);
        printf("\t%d\n", a.rack);

        count += a.quantity; 
    }

    printf("\n\n \t\t Total Books = %d\n", count);

    fclose(file);

    printf("\npress any key.....");
    fflush(stdin);
    getchar();

    mainmenu();
}

//searching function
void search_book() {
    system("cls");
    int scan_id, flag = 0;
    printf("\n\n \t\t **************** Search Book **************\n");
    printf("\n\t\tSearching..........\n\n");

    file = fopen("Books.dat", "rb");

    printf("\n\t\t Enter ID: ");
    scanf("%d", &scan_id);

    while(fread(&a, sizeof(a), 1, file) == 1) {
        if(scan_id == a.id) {
            printf("\n\n\tBook is found!\n");
            printf("\tID\tName\tAuthor\tQNT\tRack\n");
            printf("\t%d", a.id);
            printf("\t%s", a.name);
            printf("\t%s", a.author);
            printf("\t%d", a.quantity);
            printf("\t%d\n", a.rack);

            flag = 0;
        }
    }

    if(flag == 0) {
        printf("\n\nBook is not found ! ");
    }

    printf("\n\n \t\t press any key......");
    fflush(stdin);
    getchar();

    mainmenu();
}

//editing function
void edit_book() {
    system("cls");

    int inpt_id, flag = 0;

    printf("\n\n \t\t*************** Edit Search **************");

    file = fopen("Books.dat", "rb+");

    printf("\n\t\t Enter ID: ");
    scanf("%d", &inpt_id);

    while(fread(&a, sizeof(a), 1, file) == 1) {
        if(inpt_id == a.id) {
            printf("\n\t\t Book is available!\n");
            printf("\n\n ID: %d", a.id);
            printf("\n\t\t Enter new name: ");
            scanf("%s", a.name);
            printf("\n\t\t Enter new author: ");
            scanf("%s", a.author);
            printf("\n\t\t Enter new quantity: ");
            scanf("%d", &a.quantity);
            printf("\n\t\t Enter new rack: ");
            scanf("%d", &a.rack);

            fseek(file, ftell(file)-sizeof(a), 0);

            fwrite(&a, sizeof(a), 1, file);
            fclose(file);

            flag = 1;
        }
    }

    if(flag == 0) {
        printf("\n\n\t\tThis book is not found\n");
    }

    printf("\n\n\t\t Press any key....");
    fflush(stdin);
    getchar();

    mainmenu();
}

//delete function
void delete_book() {
    system("cls");

    int inpt_id, flag = 0;
    printf("\n\n \t\t ************** Delete Book ***********\n");
    printf("\n\n\t\t Enter ID for delete Book: ");
    scanf("%d", &inpt_id);

    file = fopen("Books.dat", "rb+");
    
    rewind(file);

    while(fread(&a, sizeof(a), 1, file) == 1) {
        if(inpt_id == a.id) {
            printf("\n\t\t Book is Available!");
            printf("\n\t\t Book name is: %s", a.name);
            printf("\n\t\t Rack Number: %d", a.rack);

            flag = 1;
        }
    }

    if(flag == 0) {
        printf("\n\t\t Book is not Available");
    }
    else {
        file2 = fopen("text.dat",  "wb+");

        rewind(file);
        while(fread(&a, sizeof(a), 1, file) == 1) {
             fseek(file2, ftell(file2)-sizeof(a), 0);
             fwrite(&a, sizeof(a), 1,file2);
        }
    }

    fclose(file);
    fclose(file2);

    remove("Books.dat");
    
    rename("text.dat", "Books.dat");

    file = fopen("Books.dat", "rb");

    fclose(file);

    fflush(stdin) ;
    getchar();

    mainmenu();
}

//documentation function
void documentation() {
    system("cls");

    printf("\n\n \t\t *************** Documentation ***************\n\n");
    printf("\t\t  1. This is a simple libray management programe\n\n");
    printf("\t\t  2. Password: admin\n\n");
    printf("\t\t  3. See all feature in main menu\n\n");
    printf("\t\t  4. For more info contact: \n\t\t\t\tEmail:developer@gmail.com\n\n");
    printf("\t\t  5. For mainmenu press any key......\n\n");

    fflush(stdin);
    getchar();

    mainmenu();
}