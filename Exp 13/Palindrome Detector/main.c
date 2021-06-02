#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024


int main() {
    char str[MAX_LEN];
    memset(str, 0, sizeof(char) * MAX_LEN);
    //    scanf("%s", str);
    gets(str);
    strupr(str);

    // Initialization of left and right pointers
    char *lptr = str;
    char *rptr = lptr + MAX_LEN - 1;
    while (!(*rptr >= 'A' && *rptr <= 'Z'))
        --rptr;

    // Scan towards middle
    int is_palindrome = 1;
    while (lptr < rptr) {
        if (*lptr != *rptr) {
            is_palindrome = 0;
            break;
        }
        ++lptr;
        --rptr;
        while (!(*lptr >= 'A' && *lptr <= 'Z')) {
            ++lptr;
        }
        while (!(*rptr >= 'A' && *rptr <= 'Z')) {
            --rptr;
        }

    }

    if (is_palindrome) {
        printf("Palindrome.\n");
    } else {
        printf("Not a Palindrome.\n");
    }


    return 0;
}
