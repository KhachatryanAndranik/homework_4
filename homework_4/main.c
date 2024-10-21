
//Write a C program that reads names into the array of strings and
//prints duplicate names.
/*
#include <stdio.h>

#define MAX_NAMES 5    
#define MAX_LENGTH 50   

int compare_strings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;  
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    int i, j;

    printf("Enter %d names:\n", MAX_NAMES);
    for (i = 0; i < MAX_NAMES; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", names[i]);  
    }

    printf("\nDuplicate names:\n");
    for (i = 0; i < MAX_NAMES; i++) {
        for (j = i + 1; j < MAX_NAMES; j++) {
            if (compare_strings(names[i], names[j])) {
                printf("%s\n", names[i]);
            }
        }
    }

    return 0;
}
*/

//Write a C program that reads two dimensional array of integers and
//prints the transpose of the matrix.
/*
#include <stdio.h>

int main() {
    int rows, columns;
    int matrix[7][7], transpose_matrix[7][7];
    int i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    printf("Enter the elements :\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            transpose_matrix[j][i] = matrix[i][j];  
        }
    }

    printf("\nTranspose of the matrix:\n");
    for (i = 0; i < columns; i++) { 
        for (j = 0; j < rows; j++) {
            printf("%d ", transpose_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100
#define DEFAULT_N 10

int main(int argc, char* argv[]) {
    char lines[MAX_LINES][MAX_LENGTH];
    int n = DEFAULT_N;
    int count = 0;
    int i;

    if (argc == 2 && argv[1][0] == '-') {
        n = atoi(argv[1] + 1);
    }

    printf("Enter lines (leave blank and press Enter to stop input):\n");
    while (fgets(lines[count], MAX_LENGTH, stdin) != NULL && count < MAX_LINES) {
        if (strcmp(lines[count], "\n") == 0) {  // Stop on empty line
            break;
        }
        count++;
    }

    if (n > count) {
        n = count;
    }

    printf("\nLast %d lines:\n", n);
    for (i = count - n; i < count; i++) {
        printf("%s", lines[i]);
    }

    return 0;
}
*/






//Write a C program that sorts array of strings based on the provided
//callback function.

#include <stdio.h>
#include <string.h>


int compare_value(char str1[], char str2[]) {
    return strcmp(str1, str2); 
}

void sort_strings(char array[][20], int size, int (*compare)(char[], char[])) {
    char temp[20]; 
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (compare(array[i], array[j]) > 0) {
                strcpy(temp, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], temp);
            }
        }
    }
}

int main() {
    char strings[5][20] = { 
        "computer",
        "apple",
        "phone",
        "ufar",
        "architecture"
    };
    int size = sizeof(strings) / sizeof(strings[0]);

    printf("Original array of strings:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", strings[i]);
    }

    sort_strings(strings, size, compare_value);

    printf("\nSorted array of strings:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
