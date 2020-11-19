#include <stdio.h>
#include <stdlib.h>

int check();
char** create_string_array(char** pointer, int num_string, int string_length);
void gets_text(char** ptr, int num_string, int string_length);
void puts_text(char** pointer, int num_string);

int main()
{
    puts("Enter number of strings: ");
    int num_string = check();
    puts("Enter max length of string");
    int string_length = check();
    char **text = NULL;
    text = create_string_array(text, num_string, string_length);
    puts("Enter your text");
    gets_text(text, num_string, string_length);
    puts_text(text, num_string);
    return 0;
}

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

char** create_string_array(char** pointer, int num_string, int string_length)
{
    if (!(pointer = (char**)malloc(num_string*sizeof(char*))))
        exit(1);
    for (int i = 0; i < num_string; ++i)
        if (!(pointer[i] = (char*)malloc((string_length+1)*sizeof(char))))
            exit(1);
    return pointer;
}

void gets_text(char** ptr, int num_string, int string_length)
{
    for (int i = 0; i < num_string; i++)
    {
        for (int j = 0; j < string_length; ++j)
        {
            ptr[i][j]=(char)getchar();
            if (ptr[i][j] == '\n')
            {
                ptr[i][j + 1] = '\0';
                break;
            }
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

void puts_text(char** pointer, int num_string)
{
    for (int i = 0; i < num_string; i++)
        puts(pointer[i]);
}
