#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int main(void)
{
    // Prompting user for input
    string text = get_string("Text: ");

    // Declaring variables
    int n = strlen(text);  // The total length of string
    int i = 0;             // Array indexer
    int letters = 0;       // Letters count
    int words = 1;         // Words count
    int sentences = 0;     // Sentences count

    // Finding the count of each element
    while (i < n)
    {
        // Letters
        if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90))
        {
            letters++;
        }
        // Words
        if (text[i] == 32)
        {
            words++;
        }
        // Sentences
        if (text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            sentences++;
        }
        i++;
    }

    // Doing the Coleman-Liau index
    float ratio = 100 / (float)words;  // Ratio of 100 words

    float L = ratio * letters;  // Evaluating the average number of letters in 100 words
    float S = ratio * sentences;  // Evaluating the average number of sentences in 100 words

    float index = 0.0588 * L - 0.296 * S - 15.8;  // Evaluating the Coleman-Liau index
    
    // printing text details
    printf("\nLetters: %d", letters);
    printf("\nWords: %d, words);
    printf("\nSentences: %d, sentences);
    printf("\n\n Estimated Grade level: ");
    // Doing final check on the Results and printing them out
    if (round(index) < 1)
    {
        printf("\nBefore Grade 1\n");
    }
    else if (round(index) > 16)
    {
        printf("\nGrade 16+\n");
    }
    else
    {
        printf("\n Grade %.0f\n", round(index));
    }


}
