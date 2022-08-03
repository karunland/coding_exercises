#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_senteces(string text);

int main(void)
{
    string msentence = get_string("Text: "); // ask name for user
    float cletter = count_letters(msentence);
    float cwords = count_words(msentence);
    float csentences = count_senteces(msentence);

    // define variables for 'readability tests' that going to calc the result
    float L = (cletter / cwords) * 100, S = (csentences / cwords) * 100;

    float grade = 0.0588 * (100 * cletter / cwords) - 0.296 * (100 * csentences / cwords) - 15.8;
    // round the value,
    int index = (int)round(grade);

    // compare results
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}

// find how many letters in text
int count_letters(string text)
{
    int letter = 0;

    for (int i = 0; text[i]; i++)
    {
        if (isalnum(text[i]))
        {
            letter++;
        }
    }

    return letter;
}

// find how many words in text
int count_words(string text)
{
    //  every sentence has to have word so init value is 1
    int word = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        // if there is a space and and next char is not empty, there is word
        if (text[i] == ' ' && text[i + 1] != ' ')
        {
            word++;
        }
    }

    return word;
}

// find how many sentences in text
int count_senteces(string text)
{
    int sentence = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // find how many  sentence there is with this chars
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }

    return sentence;
}