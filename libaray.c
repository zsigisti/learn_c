#include <stdio.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int year;
    int isBorrowed;
};

void printGreet(void) {
    printf("\n library management system \n");
    printf("1. add book\n");
    printf("2. display all books\n");
    printf("3. search book by id\n");
    printf("4. borrow book\n");
    printf("5. return book\n");
    printf("6. display available books\n");
    printf("7. display borrowed books\n");
    printf("0. exit\n");
}

int addBook(struct Book book[100], int *count) {
    if (*count < 100) {
        printf("\n adding book \n");
        printf("title?\n");
        while (getchar() != '\n');
        fgets(book[*count].title, 50, stdin);
        printf("author?\n");
        fgets(book[*count].author, 50, stdin);
        printf("release year?\n");
        scanf("%d", &book[*count].year);
        printf("is it borrowed? enter 0 for no, 1 for yes\n");
        scanf("%d", &book[*count].isBorrowed);
        book[*count].id = *count + 1;
        while (getchar() != '\n');
        ++(*count);
        return 0;
    } else {
        return -1;
    }

}

void printBook(struct Book book[100], int count) {
    if (count == 0) {
        printf("no books in the library yet\n");
        return;
    } else {
        for (int i = 0; i < count; i++) {
            printf("book id: %d\n", i + 1);
            printf("title: %s\n",book[i].title);
            printf("author: %s\n",book[i].author);
            printf("year: %d\n",book[i].year);
            if (book[i].isBorrowed == 0) {
                printf("the books is currently not borrowed");
            } else {
                printf("the books have been borrowed");
            }
        }
    }


}

void searchBook(struct Book book[100], int count) {
    int choice;
    printf("what is the id of the book you are looking for?");
    scanf("%d", &choice);
    if (choice < 1 || choice > count) {
        printf("invalid book ID\n");
    } else {
        printf("title: %s\n", book[choice - 1].title);
        printf("author: %s\n",book[choice - 1].author);
        printf("year: %d\n",book[choice - 1].year);
        if (book[choice - 1].isBorrowed == 0) {
            printf("the book is currently not borrowed");
        } else {
            printf("the book have been borrowed");
        }
    }

}

int rentBook(struct Book *book, int count) {
    int choice, confirm;
    printf("what is the id of the book you want to mark as borrowed?");
    scanf("%d", &choice);
    if (choice < 1 || choice > count) {
        printf("invalid book ID\n");
        return 0;
    } else {
        printf("title: %s\n",book[choice - 1].title);

        printf("is this the book you'd like to borrow? press 1 if yes, 0 if no");
        scanf("%d", &confirm);
        if (confirm == 1) {
            book[choice - 1].isBorrowed = 1;
            printf("the book is successfully rented");
            return 0;
        } else {
            return 1;
        }
    }

}

int returnBook(struct Book *book, int count) {
    int choice, confirm;
    printf("what is the id of the book you want to return?");
    scanf("%d", &choice);
    if (choice < 1 || choice > count) {
        printf("invalid book ID\n");
        return 0;
    } else {
            printf("title: %s\n",book[choice - 1].title);
            printf("is this the book you'd like to return? press 1 if yes, 0 if no");
            scanf("%d", &confirm);
            if (confirm == 1) {
                    book[choice - 1].isBorrowed = 0;
                    printf("the book is successfully returned");
                    return 0;
                } else {
                    return 1;
                }
            }





}

void availableBooks(struct Book book[100], int count) {
    for (int i = 0; i < count; i++) {
        if (book[i].isBorrowed == 0) {
            printf("id: %d\n", i + 1);
            printf("title: %s\n", book[i].title);
            printf("author: %s\n", book[i].author);
            printf("year: %d\n", book[i].year);

        }
    }

}

void rentedBooks(struct Book book[100], int count) {
    for (int i = 0; i < count; i++) {
        if (book[i].isBorrowed == 1) {
            printf("id: %d\n", i + 1);
            printf("title: %s\n", book[i].title);
            printf("author: %s\n", book[i].author);
            printf("year: %d\n", book[i].year);
        }
    }
}

int main() {
    struct Book book[100];
    int count = 0;
    int choice;
    do {
        printGreet();
        scanf("%d", &choice);
        switch (choice) {
            case 1: // add new book
                int result;
                result = addBook(book, &count);
                if (result == -1) {
                    printf("no more space for new books!");
                } else {
                    printf("%d books have been added.\n", count);
                }
                break;
            case 2: // list all books
                printBook(book, count);
                break;
            case 3: //search for books by id
                searchBook(book, count);
                break;
            case 4:
                rentBook(book, count);
                break;
            case 5:
                returnBook(book, count);
                break;
                case 6:
                availableBooks(book, count);
                break;
            case 7:
                rentedBooks(book, count);
                break;
        }
    } while (choice != 0);
}

