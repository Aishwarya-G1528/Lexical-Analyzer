#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "lexer.h"

char *keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

int is_keyword(char *word)
{
    int i;
    for(i = 0;i < 32;i++)
    {
        if(strcmp(word, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}


void lexical_analyzer(FILE *fp)
{
    char ch;
    char word[50];
    int i;

    while((ch = fgetc(fp)) != EOF)
    {
        if(isalpha(ch) || ch == '_')
        {
            i = 0;

            while(isalnum(ch) || ch == '_')
            {
                word[i++] = ch;
                ch = fgetc(fp);
            }
            word[i] = '\0';

            if(is_keyword(word))
            {
                printf("%s : Keyword\n", word);
            }
            else
            {
                printf("%s : Identifier\n", word);
            }
            if(ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']')
            {
                printf("%c : Special Symbol\n", ch);
            }
        }
        else if(isdigit(ch))
        {
            i = 0;
            while(isdigit(ch))
            {
                word[i++] = ch;
                ch = fgetc(fp);
            }
            if(ch == '.')
            {
                word[i++] = ch;
                ch = fgetc(fp);

                while(isdigit(ch))
                {
                    word[i++]= ch;
                    ch = fgetc(fp);
                }
            word[i] = '\0';
            printf("%s : Float\n", word);
        }
        else
        {
            word[i] = '\0';
            printf("%s : Integer\n", word);
        }
        if(ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']')
        {
            printf("%c : Special Symbol\n", ch);
        }
    }
    else if(ch == '/')
    {
    ch = fgetc(fp);

    if(ch == '/')
    {
        while((ch = fgetc(fp)) != '\n' && ch != EOF);
    }
    else if(ch == '*')
    {
        while(1)
        {
            ch = fgetc(fp);

            if(ch == '*' )
            {
                ch = fgetc(fp);

                if(ch == '/')
                    break;
            }

            if(ch == EOF)
                break;
        }
    }
    else
    {
        printf("%s : Arithmetic Operator\n", word);
    }
}
else if(ch == '+' || ch == '-' || ch == '*' || ch == '%')
{
    char next;
    next = fgetc(fp);
    if((ch == '+' && next == '+') || (ch == '-' && next == '-') || (ch == '+' && next == '=') || (ch == '-' && next == '=') || (ch == '*' && next == '=') || (ch == '/' && next == '='))
    {
        printf("%c%c : Operator\n", ch, next);
    }
    else
    {
    printf("%c : Arithmetic Operator\n", ch);
    }
}
    else if(ch == '=' || ch == '>' || ch == '<' || ch == '!')
    {
        char next;
        next = fgetc(fp);
        if(next == '=')
        {
            printf("%c%c : Operator\n", ch, next);
        }
        else
        {
        printf("%c : Operator\n", ch);
        }
    }
    else if(ch == '&' || ch == '|')
    {
    char next;
    next = fgetc(fp);

    if(ch == '&' && next == '&')
    {
        printf("&& : Logical Operator\n");
    }
    else if(ch == '|' && next == '|')
    {
        printf("|| : Logical Operator\n");
    }
    else if(ch == '&')
    {
        printf("& : Operator\n");
        if(isalpha(next) || next == '_')
        {
            i = 0;
            word[i++] = next;
            ch = fgetc(fp);

            while(isalnum(ch) || ch == '_')
            {
                word[i++] = ch;
                ch = fgetc(fp);
            }

            word[i] = '\0';
            printf("%s : Identifier\n", word);

            if(ch == ')')
            {
                printf(") : Special Symbol\n");
            }
        }
    }
}
    else if(ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']')
    {
        printf("%c : Special Symbol\n", ch);
    }
    else if(ch == '"')
    {
        i = 0;
        word[i++] = ch;
        ch = fgetc(fp);
        while(ch != '"' && ch != EOF)
        {
            word[i++] = ch;
            ch = fgetc(fp);
        }
        word[i++] = ch;
        word[i] = '\0';
        
        printf("%s : String Literal\n", word);
    }
    else if(ch == '\'')
    {
        i = 0;
        word[i++] = ch;
        ch = fgetc(fp);

        word[i++] = ch;
        ch = fgetc(fp);
        
        if(ch == '\'')
        {
            word[i++] = ch;
            word[i] = '\0';

            printf("%s : Character Literal\n", word);
        }
    }
}
}