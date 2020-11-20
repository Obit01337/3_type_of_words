//TASK:
//Given a text, each character of which can be a small letter, a number or one of the signs +, -, *.
//By a group of letters we mean such a collection consecutive letters,
//which is not directly preceded and not immediately followed by a letter.
//Similarly define a group of numbers and a group of characters.
//Find out if something is true in a given there are more letter groups than character groups.

//REMARK:
//I make it harder for myself and look for which groups are more.

#include <stdio.h>
#include <stdlib.h>

int check();
char** create_string_array(char** pointer, int num_string, int string_length);
void gets_text(char** ptr, int num_string, int string_length);
void puts_text(char** pointer, int num_string);
int find_words_of_letters(char** pointer, int num_string, int string_length);
int find_words_of_numbers(char** pointer, int num_string, int string_length);
int find_words_of_sings(char** pointer,int num_string, int string_length);

int main()
{
    // Input text size
    puts("Enter number of strings: ");
    int num_string = check();
    puts("Enter max length of string");
    int string_length = check();
    char **text = NULL;
    // Creating array for text
    text = create_string_array(text, num_string, string_length);
    puts("Enter your text");
    // Input text
    gets_text(text, num_string, string_length);
    // Output text
    puts_text(text, num_string);
    // 38-43 find number of words and print it in console
    int words_letters = find_words_of_letters(text, num_string, string_length);
    printf_s("num words of letters = %d\n", words_letters);
    int words_numbers = find_words_of_numbers(text, num_string, string_length);
    printf_s("num words of numbers = %d\n", words_numbers);
    int words_sings = find_words_of_sings(text, num_string, string_length);
    printf_s("num words of sings = %d\n", words_sings);
    // Find the biggest number of words
    if (words_letters > words_numbers && words_letters > words_sings)
    {
        printf_s("number words of letters more than others and equal %d", words_letters);
    } else if (words_numbers > words_letters && words_numbers > words_sings)
    {
        printf_s("number words of numbers more than others and equal %d", words_numbers);
    }else if (words_sings > words_numbers && words_sings > words_letters)
    {
        printf_s("number words of sings more than others and equal %d", words_sings);
    }else if (words_letters == words_numbers && words_letters > words_sings)
    {
        printf_s("number words of letters equal number words of numbers and equal %d", words_letters);
    }else if (words_letters == words_sings && words_letters > words_numbers)
    {
        printf_s("number words of letters equal number words of sings and equal %d", words_letters);
    }else if (words_numbers == words_sings && words_numbers > words_letters)
    {
        printf_s("number words of numbers equal number words of sings and equal %d", words_numbers);
    }else if (words_letters == words_numbers == words_sings)
    {
        printf_s("number of words is the same and equal %d", words_letters);
    }
    // Freeing memory
    free(text);
    return 0;
}

// Function for correct input
int check()
{
    int number;
    char check;
    do
    {
        rewind(stdin);
        puts("Input\t");
    }while ( !(scanf_s("%d%c", &number, &check)) || check != '\n' || number <= 0);
    return number;
}

// Allocate memory for text, stop program if some problem
char** create_string_array(char** pointer, int num_string, int string_length)
{
    if (!(pointer = (char**)malloc(num_string*sizeof(char*))))
        exit(1);
    for (int i = 0; i < num_string; ++i)
        if (!(pointer[i] = (char*)malloc((string_length+1)*sizeof(char))))
            exit(1);
    return pointer;
}

// Get text according to the condition of the task
void gets_text(char** ptr, int num_string, int string_length)
{
    for (int i = 0; i < num_string; i++)
    {
        for (int j = 0; j < string_length; ++j)
        {
            ptr[i][j]=(char)getchar();
            if (ptr[i][j] == '\n')
            {
                ptr[i][j] = '\0';//mb j + 1
                break;
            }
            // Condition
            if (!(((int)ptr[i][j] >= 48 && (int)ptr[i][j] <= 57) || (int)ptr[i][j] == 42 || (int)ptr[i][j] == 43 || (int)ptr[i][j] == 45 || ((int)ptr[i][j] >= 97 && (int)ptr[i][j] <= 122)))
            {
                puts("You typed wrong symbol");
                puts("Try again");
                printf("num_string = %d\n", num_string);
                printf("string_length = %d\n", string_length);
                i--;
                break;
            }
            if (j == string_length-1)
                ptr[i][string_length]= '\0';
        }
        rewind(stdin);
    }
}

// 127-191 word count functions
int find_words_of_letters(char** pointer, int num_string, int string_length)
{
    int num_words = 0;
    for (int i = 0; i < num_string; ++i)
    {
        for (int j = 0; j < string_length; ++j)
        {
            int first = 1;
            for (int k = j; (int)pointer[i][k] >= 97 && (int)pointer[i][k] <= 122; ++k)
            {
                if(first == 1)
                {
                    num_words++;
                    first = 0;
                }
                j = k;
            }
        }
    }
    return num_words;
}

int find_words_of_numbers(char** pointer, int num_string, int string_length)
{
    int num_words = 0;
    for (int i = 0; i < num_string; ++i)
    {
        for (int j = 0; j < string_length; ++j)
        {
            int first = 1;
            for (int k = j; (int)pointer[i][k] >= 48 && (int)pointer[i][k] <= 57; ++k)
            {
                if(first == 1)
                {
                    num_words++;
                    first = 0;
                }
                j = k;
            }
        }
    }
    return num_words;
}

int find_words_of_sings(char** pointer, int num_string, int string_length)
{
    int num_words = 0;
    for (int i = 0; i < num_string; ++i)
    {
        for (int j = 0; j < string_length; ++j)
        {
            int first = 1;
            for (int k = j; (int)pointer[i][j] == 42 || (int)pointer[i][j] == 43 || (int)pointer[i][j] == 45; ++k)
            {
                if(first == 1)
                {
                    num_words++;
                    first = 0;
                }
                j = k;
            }
        }
    }
    return num_words;
}

// Outputs text
void puts_text(char** pointer, int num_string)
{
    for (int i = 0; i < num_string; i++)
        puts(pointer[i]);
}
