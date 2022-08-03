#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 == score2)
    {
        printf("Tie!");
    }
    else
    {
        score1 < score2 ? printf("Player 2 wins!") : printf("Player 1 wins!");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int i = 0;
    int sum = 0;

    while (i < strlen(word))
    {
        if (islower(word[i]))
        {
            word[i] -= 'a' - 'A';
        }
        i++;
    }

    i = 0;
    while (i < strlen(word))
    {
        if (word[i] <= 'Z' && word[i] >= 'A')
        {
            sum += POINTS[word[i] - 'A'];
        }
        i++;
    }
    
    return (sum);
}
