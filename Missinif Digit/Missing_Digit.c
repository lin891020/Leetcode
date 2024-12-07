#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************************************
* Function: containsX
* Checks if the string contains the character 'x'.
* Parameters:
*   - str: Pointer to the input string.
* Returns: Non-zero if 'x' is found; otherwise, 0.
**************************************************/
int containsX(const char *str) {
    return strchr(str, 'x') != NULL;
}

/*************************************************
* Function: stringToIntWithX
* Replaces 'x' in the string with a specified digit
* and converts the result to an integer.
* Parameters:
*   - str: Pointer to the input string.
*   - x: Character to replace 'x' with.
* Returns: The resulting integer value.
**************************************************/
int stringToIntWithX(const char *str, char x) {
    char *temp = strdup(str);
    for (int i = 0; temp[i] != '\0'; i++) {
        if (temp[i] == 'x') {
            temp[i] = x;
        }
    }
    int value = atoi(temp);
    free(temp);
    return value;
}

/*************************************************
* Function: parseEquation
* Splits the equation string into its components.
* Parameters:
*   - str: Pointer to the equation string.
* Returns: Structure containing the components.
**************************************************/
typedef struct {
    char *part1;
    char operator;
    char *part2;
    char *result;
} EquationParts;

EquationParts parseEquation(const char *str) {
    EquationParts eq;
    char *copy = strdup(str);
    char *token = strtok(copy, " ");
    eq.part1 = strdup(token);
    token = strtok(NULL, " ");
    eq.operator = token[0];
    token = strtok(NULL, " ");
    eq.part2 = strdup(token);
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    eq.result = strdup(token);
    free(copy);
    return eq;
}

/*************************************************
* Function: freeEquationParts
* Frees memory allocated for equation components.
* Parameters:
*   - eq: Structure containing the components.
* Returns: None
**************************************************/
void freeEquationParts(EquationParts eq) {
    free(eq.part1);
    free(eq.part2);
    free(eq.result);
}

/*************************************************
* Function: findMissingDigit
* Determines the missing digit that satisfies the
* equation by substituting 'x' with digits 0-9.
* Parameters:
*   - str: Pointer to the equation string.
* Returns: The missing digit if found; otherwise, -1.
**************************************************/
int findMissingDigit(const char *str) {
    EquationParts eq = parseEquation(str);
    int missingDigit = -1;

    for (char digit = '0'; digit <= '9'; digit++) {
        int part1Value = stringToIntWithX(eq.part1, digit);
        int part2Value = stringToIntWithX(eq.part2, digit);
        int resultValue = stringToIntWithX(eq.result, digit);
        int valid = 0;

        switch (eq.operator) {
            case '+':
                valid = (part1Value + part2Value == resultValue);
                break;
            case '-':
                valid = (part1Value - part2Value == resultValue);
                break;
            case '*':
                valid = (part1Value * part2Value == resultValue);
                break;
            case '/':
                if (part2Value != 0) {
                    valid = (part1Value / part2Value == resultValue);
                }
                break;
        }

        if (valid) {
            missingDigit = digit - '0';
            break;
        }
    }

    freeEquationParts(eq);
    return missingDigit;
}

/*************************************************
* Function: MissingDigit
* Finds and prints the missing digit in the equation.
* Parameters:
*   - str: Pointer to the equation string.
* Returns: None
**************************************************/
void MissingDigit(char *str) {
    int varOcg = findMissingDigit(str); // __define-ocg__
    printf("%d\n", varOcg);
}

/*************************************************
* Function: main
* Entry point of the program. Reads an equation
* from the user and finds the missing digit.
* Parameters: None
* Returns: Exit status
**************************************************/
int main(void) {
    char equation[100];
    printf("Enter the equation: ");
    fgets(equation, sizeof(equation), stdin);
    equation[strcspn(equation, "\n")] = '\0'; // Remove newline
    MissingDigit(equation);
    return 0;
}