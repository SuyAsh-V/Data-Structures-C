#include <stdio.h>

struct Student{
    int roll;
    char name[50];
};

void input(struct Student s[], int n);
void display(struct Student s[], int n);
void linearSearch(struct Student s[], int n);
void bubbleSort(struct Student s[], int n);
void binarySearch(struct Student s[], int n);
void insertionSort(struct Student s[], int n);
void selectionSort(struct Student s[], int n);
void shellSort(struct Student s[], int n);

int main(){
    int n, choice;
    struct Student s[100];

    printf("Enter number of students: ");
    scanf("%d", &n);

    do {
        printf("\n====== MENU ======\n");
        printf("1. Input Student Details\n");
        printf("2. Display Student Details\n");
        printf("3. Linear Search\n");
        printf("4. Bubble Sort\n");
        printf("5. Binary Search\n");
        printf("6. Selection Sort\n");
        printf("7. Insertion Sort\n");
        printf("8. Shell Sort\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input(s, n);
                break;

            case 2:
                display(s, n);
                break;

            case 3:
                linearSearch(s, n);
                break;

            case 4:
                bubbleSort(s, n);
                break;

            case 5:
                binarySearch(s, n);
                break;

            case 6:
                selectionSort(s, n);
                break;

            case 7:
                insertionSort(s, n);
                break;

            case 8:
                shellSort(s, n);
                break;

            case 9:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 9);

    return 0;
}

void input(struct Student s[], int n){
    int i;

    for (i=0; i<n; i++){
        printf("\nEnter details of student %d\n", i+1);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);
    }
}

void display(struct Student s[], int n){
    int i;

    printf("Student Details\n");
    printf("Roll No.\tStudent Name\n");
    
    for (i=0; i<n; i++){
        printf("%d\t\t%s\n", s[i].roll, s[i].name);
    }
}

void linearSearch(struct Student s[], int n){
    int key, i;
    int found=0;

    printf("\nEnter Roll No. to be searched:");
    scanf("%d", &key);

    for (i=0; i<n; i++){
        if (key==s[i].roll){
            printf("Roll No : %d\n", s[i].roll);
            printf("Name    : %s\n", s[i].name);
            found=1;
            break;
        }
    }
    if (found==0){
        printf("\nStudent not found!!\n");
    }
}

void bubbleSort(struct Student s[], int n){
    int i, j;
    int swap=0;
    struct Student temp;

    for (i=0; i<n; i++){
        swap=0;
        for (j=0; j<n-1; j++){
            if (s[j].roll>s[j+1].roll){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                swap=1;
            }
        }
        if (swap==0) break;
    }
    printf("\nStudents sorted successfully by Roll Number.\n");
}

void binarySearch(struct Student s[], int n){
    int key;
    int low=0, high=n-1, mid;

    printf("\nEnter Roll No. to be searched:");
    scanf("%d", &key);

    while (low<=high){
        mid=low+(high-low)/2;

        if (s[mid].roll==key){
            printf("Roll No : %d\n", s[mid].roll);
            printf("Name    : %s\n", s[mid].name);
            return;
        }

        else if(s[mid].roll<key){
            low=mid+1;
        }

        else{
            high=mid-1;
        }
    }
    printf("\nStudent not found!!\n");
}

void insertionSort(struct Student s[], int n){
    struct Student key;
    int i, j;

    for (i=1; i<n; i++){
        key=s[i];
        j=i-1;

        while (j>=0 && s[j].roll>key.roll){
            s[j+1]=s[j];
            j=j-1;
        }
        s[j+1]=key;
    }
    printf("\nStudents sorted successfully using Insertion Sort.\n");
}

void selectionSort(struct Student s[], int n){
    int i, j, min;
    struct Student temp;

    for (i=0; i<n-1; i++){
        min=i;
        for (j=i+1; j<n; j++){
            if (s[j].roll<s[min].roll){
                min=j;
            }
        }

        if (min!=i){
            temp=s[i];
            s[i]=s[min];
            s[min]=temp;
        }
    }
    printf("\nStudents sorted successfully using Selection Sort.\n");
}

void shellSort(struct Student s[], int n){
    int i, j;
    int gap=n/2;
    struct Student temp;
    int swap;

    while (gap>0){
        while(1){
            swap=0;
            for (i=0; i<n-gap; i++){
                if (s[i].roll>s[i+gap].roll){
                    temp=s[i];
                    s[i]=s[i+gap];
                    s[i+gap]=temp;
                    swap=1;
                }
            }

            if (swap==0){
                break;
            }
        }
        gap=gap/2;
    }
    printf("\nStudents sorted successfully using Shell Sort.\n");
}