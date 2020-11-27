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

int check_correct_input(void);
void text_input(char** text, int num_str, int size_str);
void text_output(char** text, int num_str);
int find_words_of_letters(char** text, int num_str);
int find_words_of_numbers(char** text, int num_str);
int find_words_of_sings(char** text, int num_str);

int main(void)
{
    // Input text size
    puts("Enter number of strings:");
    int num_str = check_correct_input();
    puts("Enter max length of string");
    int size_str = check_correct_input();
    char **text = NULL;
    // Creating array for text
    if (!(text = (char**)malloc(num_str * sizeof(char*))))
    {
        puts("Not enough memory\a");
        system("pause");
        return 1;
    }
    for (int i = 0; i < num_str; i++)
        if (!(text[i] = (char*)malloc((size_str + 1) * sizeof(char))))
        {
            for (int j = 0; j < i; j++)
                free(text[j]);
            free(text);
            puts("Not enough memory\a");
            system("pause");
            return 1;
        }
    puts("Enter your text");
    // Input text
    text_input(text, num_str, size_str);
    // Output text
    text_output(text, num_str);
    // Finding number of words and print it in console
    int count_let_words = find_words_of_letters(text, num_str);
    printf_s("num words of letters = %d\n", count_let_words);
    int count_num_words = find_words_of_numbers(text, num_str);
    printf_s("num words of numbers = %d\n", count_num_words);
    int count_sing_words = find_words_of_sings(text, num_str);
    printf_s("num words of sings = %d\n", count_sing_words);
    // Finding the biggest number of words
    if (count_let_words > count_num_words && count_let_words > count_sing_words)
        printf_s("number words of letters more than others and equal %d\n", count_let_words);
    else if (count_num_words > count_let_words && count_num_words > count_sing_words)
        printf_s("number words of numbers more than others and equal %d\n", count_num_words);
    else if (count_sing_words > count_num_words && count_sing_words > count_let_words)
        printf_s("number words of sings more than others and equal %d\n", count_sing_words);
    else if (count_let_words == count_num_words && count_let_words > count_sing_words)
        printf_s("number words of letters equal number words of numbers and equal %d\n", count_let_words);
    else if (count_let_words == count_sing_words && count_let_words > count_num_words)
        printf_s("number words of letters equal number words of sings and equal %d\n", count_let_words);
    else if (count_num_words == count_sing_words && count_num_words > count_let_words)
        printf_s("number words of numbers equal number words of sings and equal %d\n", count_num_words);
    else if (count_let_words == count_num_words && count_let_words == count_sing_words)
        printf_s("number of words is the same and equal %d\n", count_let_words);
    // Freeing memory
    for (int i = 0; i < num_str; i++)
        free(text[i]);
    free(text);
    system("pause");
    return 0;
}

// Function for correct input
int check_correct_input(void)
{
    int num;
    char enter;
    do
    {
        rewind(stdin);
        puts("Input");
    }while ((scanf_s("%d%c", &num, &enter)) != 2 || enter != '\n' || num <= 0);
    return num;
}

// Get text according to the condition of the task
void text_input(char** text, int num_str, int size_str)
{
    for (int i = 0; i < num_str; i++)
    {
        for (int j = 0; j < size_str; j++)
        {
            text[i][j] = (char)getchar();
            if (text[i][j] == '\n')
            {
                text[i][j] = '\0';
                break;
            }
            // Condition
            if (!((text[i][j] >= 48 && text[i][j] <= 57) || text[i][j] == 42 || text[i][j] == 43 || text[i][j] == 45 || (text[i][j] >= 97 && text[i][j] <= 122)))
            {
                puts("You typed wrong symbol");
                puts("Try again");
                printf("num_str = %d\n", num_str);
                printf("size_str = %d\n", size_str);
                i--;
                break;
            }
            if (j == size_str - 1)
                text[i][size_str]= '\0';
        }
        rewind(stdin);
    }
}

// 3 word count functions
int find_words_of_letters(char** text, int num_str)
{
    int num_words = 0;
    for (int i = 0; i < num_str; i++)
        for (int j = 0; text[i][j] != '\0'; j++)
        {
            int first = 1;
            for (int k = j; text[i][k] >= 97 && text[i][k] <= 122; k++)
            {
                if(first == 1)
                {
                    num_words++;
                    first = 0;
                }
                j = k;
            }
        }
    return num_words;
}

int find_words_of_numbers(char** text, int num_str)
{
    int num_words = 0;
    for (int i = 0; i < num_str; i++)
        for (int j = 0; j < text[i][j] != '\0'; j++)
        {
            int first = 1;
            for (int k = j; text[i][k] >= 48 && text[i][k] <= 57; k++)
            {
                if(first == 1)
                {
                    num_words++;
                    first = 0;
                }
                j = k;
            }
        }
    return num_words;
}

int find_words_of_sings(char** text, int num_str)
{
    int num_words = 0;
    for (int i = 0; i < num_str; i++)
        for (int j = 0; text[i][j] != '\0'; j++)
        {
            int first = 1;
            for (int k = j; text[i][j] == 42 || text[i][j] == 43 || text[i][j] == 45; k++)
            {
                if(first == 1)
                {
                    num_words++;
                    first = 0;
                }
                j = k;
            }
        }
    return num_words;
}

// Outputs text
void text_output(char** text, int num_str)
{
    for (int i = 0; i < num_str; i++)
        printf_s("%d %s\n", i, text[i]);
}
