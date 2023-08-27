/******************************************************************************
Problem : Finding division of two very large numbers.
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A function to perform division of large numbers
char* longDivision(const char* number, int divisor)
{
    // As result can be very large store it in string
    char* ans = (char*)malloc((strlen(number) + 1) * sizeof(char));
    int ansIndex = 0;

    // Find prefix of number that is larger
    // than divisor.
    int index = 0;
    int temp = number[index] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++index] - '0');

    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number[index] != '\0') {
        // Store result in answer i.e. temp / divisor
        ans[ansIndex++] = (temp / divisor) + '0';

        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++index] - '0';
    }

    // Null-terminate the result string
    ans[ansIndex] = '\0';

    // If divisor is greater than number
    if (ans[0] == '\0') {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        free(ans);
        return result;
    }

    // else return ans
    return ans;
}


int main()
{
    char* number;
    char num[1024];
    int divisor;
    printf("enter number: ");
    scanf("%s",num);
    number=num;
    printf("enter divisor: ");
    scanf("%d",&divisor);
    char* result = longDivision(number, divisor);
    printf("%s\n", result);
    free(result);
    return 0;
}
