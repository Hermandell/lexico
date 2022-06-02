/* Importing the libraries that are needed for the program to run. */
/* Importing the library that contains the boolean data type. */
/* Importación de la biblioteca que contiene el tipo de datos booleano. */
#include <stdbool.h>
/* Importing the standard input/output library. */
/* Importación de la biblioteca estándar de entrada/salida. */
#include <stdio.h>
/* Importing the string library. */
/* Importación de la biblioteca de cadenas. */
#include <string.h>
/* Importing the standard library. */
/* Importación de la biblioteca estándar. */
#include <stdlib.h>

// Returns 'true' if the character is a DELIMITER.
/**
 * It returns true if the character is a delimiter, false otherwise
 *
 * @param ch The character to be checked.
 *
 * @return The function isDelimiter() returns true if the given character is a delimiter.
 */

/**
 * Devuelve verdadero si el carácter es un delimitador, falso en caso contrario
 *
 * @param ch El carácter a comprobar.
 *
 * @return La función isDelimiter() devuelve verdadero si el carácter dado es un delimitador.
 */
bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}

// Returns 'true' if the character is an OPERATOR.
/**
 * It returns true if the character passed to it is an operator, otherwise it returns false
 *
 * @param ch The character to be checked.
 *
 * @return The function isOperator() returns true if the given character is an operator, else it
 * returns false.
 */

/**
 * Devuelve verdadero si el carácter es un operador, falso en caso contrario
 *
 * @param ch El carácter a comprobar.
 *
 * @return La función isOperator() devuelve verdadero si el carácter dado es un operador; de lo
 * contrario, devuelve falso.
 */
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}

// Returns 'true' if the string is a VALID IDENTIFIER.
/**
 * If the first character of the string is a digit or a delimiter, return false. Otherwise, return true
 *
 * @param str The string to be checked.
 *
 * @return a boolean value.
 */

/**
 * Si el primer carácter de la cadena es un dígito o un delimitador, entonces la cadena no es un
 * identificador válido
 *
 * @param str La cadena que se va a comprobar.
 *
 * @return un valor booleano.
 */
bool validIdentifier(char *str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isDelimiter(str[0]) == true)
        return (false);
    return (true);
}

// Returns 'true' if the string is a KEYWORD.
/**
 * It checks if the string is a keyword or not
 *
 * @param str The string to check.
 *
 * @return a boolean value.
 */

/**
 * Si la cadena es igual a cualquiera de las palabras clave, devuelve verdadero
 *
 * @param str La cadena a comprobar
 *
 * @return un valor booleano.
 */
bool isKeyword(char *str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
        !strcmp(str, "continue") ||
        !strcmp(str, "int") ||
        !strcmp(str, "double") ||
        !strcmp(str, "float") ||
        !strcmp(str, "return") ||
        !strcmp(str, "char") ||
        !strcmp(str, "case") ||
        !strcmp(str, "char") ||
        !strcmp(str, "sizeof") ||
        !strcmp(str, "long") ||
        !strcmp(str, "short") ||
        !strcmp(str, "typedef") ||
        !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

// Returns 'true' if the string is an INTEGER.
/**
 * It returns true if the string contains only digits and is non-empty, and false otherwise
 *
 * @param str The string to check.
 *
 * @return A boolean value.
 */

/**
 * Comprueba si una cadena es un número entero
 *
 * @param str La cadena que se va a comprobar.
 *
 * @return un valor booleano.
 */
bool isInteger(char *str)
{
    int i, len = strlen(str);

    /* Checking if the string is an integer. If the string is empty, it will return false. If the
    string is not empty, it will check if the string contains only digits. If it does, it will
    return true. If it does not, it will return false. */

    /* Comprobando si la cadena es un número entero. Si la cadena está vacía, devolverá falso. Si la
    cadena no está vacía, verificará si la cadena contiene solo dígitos. Si lo hace, devolverá
    verdadero. Si no es así, devolverá falso. */
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' &&
                str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' ||
            (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

// Returns 'true' if the string is a REAL NUMBER.
/**
 * If the string is empty, or if it contains any characters other than digits, a decimal point, or a
 * minus sign in the first position, then it's not a real number
 *
 * @param str The string to check.
 *
 * @return a boolean value.
 */

/**
 * Comprueba si una cadena es un número real
 *
 * @param str La cadena que se va a comprobar.
 *
 * @return un valor booleano.
 */
bool isRealNumber(char *str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;

    /* Checking if the string is a real number. */

    /* Comprobando si la cadena es un número real. */
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

// Extracts the SUBSTRING.
/**
 * It returns a substring of the given string from the given left index to the given right index
 *
 * @param str The string to be split.
 * @param left The starting index of the substring.
 * @param right the index of the last character in the substring
 *
 * @return A pointer to a string.
 */

/**
 * Toma una cadena, un índice izquierdo y un índice derecho, y devuelve una subcadena de la cadena
 * desde el índice izquierdo al índice derecho
 *
 * @param str La cadena de la que se va a extraer la subcadena.
 * @param left El índice inicial de la subcadena.
 * @param right El índice derecho de la subcadena.
 *
 * @return Un puntero a la subcadena.
 */
char *subString(char *str, int left, int right)
{
    int i;
    /* Allocating memory for the substring. */

    /* Asignación de memoria para la subcadena. */
    char *subStr = (char *)malloc(
        sizeof(char) * (right - left + 2));

    /* Copying the substring from the given string. */

    /* Copiando la subcadena de la cadena dada. */
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

// Parsing the input STRING.
/**
 * It takes a string as input and parses it into tokens
 *
 * @param str The string to be parsed
 *
 * @return a pointer to a character.
 */

/**
 * Comprueba si el carácter es un delimitador o no. Si no es un delimitador, incrementará la variable
 * derecha. Si es un delimitador, verificará si la variable de la izquierda es igual a la variable de
 * la derecha. Si es así, comprobará si el carácter es un operador. Si lo es, imprimirá que es un
 * operador. Si no es así, incrementará la variable derecha y establecerá la variable izquierda igual a
 * la variable derecha. Si la variable de la izquierda no es igual a la variable de la derecha,
 * comprobará si el carácter es un delimitador. Si es así, comprobará si el carácter es una palabra
 * clave. Si es así, imprimirá que es una palabra clave. Si no es así, comprobará si el carácter es un
 * número entero. Si es así, imprimirá que es un número entero. Si no es así, comprobará si el carácter
 * es un número real. Si es así, imprimirá que
 *
 * @param str La cadena a analizar
 *
 * @return nada.
 */
void parse(char *str)
{
    int left = 0, right = 0;
    /* Encontrar la longitud de la cuerda. */
    int len = strlen(str);

    /* Checking if the character is a delimiter or not. If it is not a delimiter, it will increment the
    right variable. If it is a delimiter, it will check if the left variable is equal to the right
    variable. If it is, it will check if the character is an operator. If it is, it will print that
    it is an operator. If it is not, it will increment the right variable and set the left variable
    equal to the right variable. If the left variable is not equal to the right variable, it will
    check if the character is a delimiter. If it is, it will check if the character is a keyword. If
    it is, it will print that it is a keyword. If it is not, it will check if the character is an
    integer. If it is, it will print that it is an integer. If it is not, it will check if the
    character is a real number. If it is, it will print that it is a real number. If it is not, it
    will check if the character is a valid identifier. If it is, it will print that it is a valid
    identifier. If it is not */

    while (right <= len && left <= right)
    {
        if (isDelimiter(str[right]) == false)
            right++;

        if (isDelimiter(str[right]) == true && left == right)
        {
            if (isOperator(str[right]) == true)
                printf("'%c' IS AN OPERATOR\n", str[right]);

            right++;
            left = right;
        }
        else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right))
        {
            char *subStr = subString(str, left, right - 1);

            if (isKeyword(subStr) == true)
                printf("'%s' IS A KEYWORD\n", subStr);

            else if (isInteger(subStr) == true)
                printf("'%s' IS AN INTEGER\n", subStr);

            else if (isRealNumber(subStr) == true)
                printf("'%s' IS A REAL NUMBER\n", subStr);

            else if (validIdentifier(subStr) == true && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS A VALID IDENTIFIER\n", subStr);

            else if (validIdentifier(subStr) == false && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
            left = right;
        }
    }
    return;
}

// DRIVER FUNCTION
/**
 * It takes a string as input and prints the tokens in the string
 *
 * @return the number of tokens in the string.
 */

/**
 * Toma una cadena como entrada e imprime los tokens en la cadena
 *
 * @return el número de tokens encontrados en la cadena.
 */
int main()
{
    // maximum length of string is 100 here
    /* Declarar una cadena con una longitud máxima de 100 caracteres. */

    // char str[100] = "if (1a == b){ a = b; while (a < b) main() { a = a + 1; } } int a=0;";
    char str[100];
    printf("Dame un codigo:\n");
    scanf("%[^\n]s", str);
    getchar();
    printf("\n");
    /* Llamando a la función de análisis. */
    parse(str);
    getchar();

    return (0);
}
