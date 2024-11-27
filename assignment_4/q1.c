#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAXLINE 1000

// Structure for a binary tree node
struct tnode
{
    char *word;          // Pointer to the word text
    int lines[MAXLINE];  // Array to store line numbers where the word appears
    int line_count;      // Number of occurrences (distinct lines)
    struct tnode *left;  // Pointer to the left child
    struct tnode *right; // Pointer to the right child
};

// Function prototypes
struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
struct tnode *talloc(void);
char *strsave(char *);
void getword(char *, int *, char *[], int *);

int main()
{
    struct tnode *root = NULL;
    char word[MAXWORD];
    int line_number = 0;
    int word_index = 0;

    // Sample input (array of pointers to strings)
    char *sample[] = {
        "This is a sample text",
        "It contains some words, and it also contains repeated words.",
        "The goal is to list each word and the lines where it occurs."};
    int num_lines = 3;

    // Read each word from the sample array and add to the binary tree
    while (1)
    {
        getword(word, &word_index, sample, &line_number);
        if (word[0] == '\0')
        { // End of sample array
            break;
        }
        if (isalpha(word[0]))
        { // Check if the word starts with an alphabetical character
            root = addtree(root, word, line_number);
        }
    }

    // Print the words and their line occurrences
    printf("Words and the line numbers where they occur\n");
    treeprint(root);
    return 0;
}

// Add word to binary tree and track line number
struct tnode *addtree(struct tnode *p, char *w, int line)
{
    // enter code here
    if (p == NULL)
    {
        p = talloc();
        p->word = strsave(w);
        p->line_count = 0;
        p->lines[p->line_count++] = line; // searched from internet
        p->left = p->right = NULL;
    }
    else if (strcmp(p->word, w) > 0)
    {
        // right
        p->right = addtree(p->right, w, line);
    }
    else if (strcmp(p->word, w) < 0)
    {
        // left
        p->left = addtree(p->left, w, line);
    }
    else
    {
        // same word - searched from internet
        if (p->lines[p->line_count - 1] != line)
        {
            p->lines[p->line_count++] = line;
        }
    }

    return p;
}

// Print the words and their line numbers in alphabetical order
void treeprint(struct tnode *p)
{
    // enter code here
    if (p != NULL)
    {
        treeprint(p->right);
        printf("%s: ", p->word);
        for (int i = 0; i < p->line_count; i++)
        {
            printf("%d, ", p->lines[i]);
        }
        printf("\n");
        treeprint(p->left);
    }
}

// Allocate memory for new tree node
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

// Save a copy of a string
char *strsave(char *s)
{
    char *p;

    p = (char *)malloc(strlen(s) + 1); // Allocate memory for the string (+1 for '\0')
    if (p != NULL)
    {
        strcpy(p, s); // Copy the string to the allocated memory
    }
    return p;
}

// Get the next word from the sample array
void getword(char *word, int *word_index, char *sample[], int *line_number)
{
    static int line_idx = 0;
    static char *current_line = NULL;
    static int current_pos = 0;

    // Move to the next line if the current line is empty or end reached
    if (current_line == NULL || current_line[current_pos] == '\0')
    {
        if (line_idx >= 3)
        {
            word[0] = '\0';
            return;
        }
        current_line = sample[line_idx++];
        current_pos = 0;
        (*line_number)++;
    }

    // Skip whitespaces and punctuation
    while (isspace(current_line[current_pos]) || ispunct(current_line[current_pos]))
    {
        current_pos++;
        if (current_line[current_pos] == '\0')
        {
            current_line = NULL;
            return;
        }
    }

    // Read the word
    char *w = word;
    while (current_line[current_pos] != '\0' && !isspace(current_line[current_pos]) && !ispunct(current_line[current_pos]))
    {
        *w++ = tolower(current_line[current_pos++]);
    }
    *w = '\0';
}