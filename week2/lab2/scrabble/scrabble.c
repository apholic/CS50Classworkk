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
    
    if (score1 > score2)
    {
        printf("Player 1 wins! \n");
    }
    if (score1 < score2)
    {
        printf("Player 2 wins! \n");
    }
    else
    {
        printf("Tie! \n");
    }

}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int i, l, n, p;
    int sum = 0;
    for (i = 0, l = strlen(word); i < l; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            n = word[i] - 65;  //这里出错了，因为大写的A从65开始，小写的a是从97，而输入不一定大小写统一，所以要先做统一大小写的步骤。
            p = POINTS [n];
        }
        else
        {
            p = 0;
        }
           sum = sum + p;
    }
    printf("%d\n",sum);
    return sum;
}
