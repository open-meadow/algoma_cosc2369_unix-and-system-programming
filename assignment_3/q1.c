#include <stdio.h>
#include <string.h>
#define ALLOCSIZE 1000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
	if (allocp + n <= allocbuf + ALLOCSIZE) { /* fits */
		allocp += n;
		return (allocp - n); /* old p */
	} else /* not enough room */
		return (NULL);
}

void afree(char *p) /* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

#define LINES 100 /* max number of lines to be sorted */
#define MAXLEN 1000
#define TOLOWER(c) (((c) >= 'A' && (c) <= 'Z') ? ((c) + 'a' - 'A') : (c))

void sort(char *v[], int n, int (*comp)(const char *, const char *), int reverse);
void writelines(char *lineptr[], int nlines);

int main(int argc, char *argv[]) {
	char *lineptr[LINES];
	int nlines = 0;
	int numeric = 0, reverse = 0, fold_case = 0;

	while (--argc > 0 && (*++argv)[0] == '-') {
		switch ((*argv)[1]) {
		case 'n':
			numeric = 1;
			break;
		case 'r':
			reverse = 1;
			break;
		case 'f':
			fold_case = 1;
			break;
		default:
			printf("sort: illegal option %c\n", (*argv)[1]);
			argc = 0;
			break;
		}
	}

	// get input from command line arguments into lineptr
	/* your code here */
	while(*argv) {
		// printf("%s\n", (*argv));
		lineptr[nlines] = (*argv);
		nlines++;
		*argv++;
	}

	lineptr[nlines] = NULL;
	printf("nLines:  %d, fold_case: %d\n", nlines, fold_case);

	if (nlines > 0) {
		printf("Enter me!\n");
		if (fold_case == 1) {
			// Make a copy of each line with lowercase for comparison purposes
			char *lower_lineptr[LINES];
			/* your code here */
			printf("I'm here now\n");
			int i;
			for(i = 0; lineptr[i] != NULL; i++) {
			 //   printf("lineptr[%d]: %s\n", i, lineptr[i]);
			    int j;
			    for(int j = 0; lineptr[i][j] != '\0'; j++) {
			        //printf("lineptr[%d][%d]: %c\n", i, j, TOLOWER(lineptr[i][j]));
			        lower_lineptr[i][j] = TOLOWER(lineptr[i][j]);
			    }
			    lower_lineptr[i][j] = '\0';
			    printf("lower_lineptr[%d]: %s\n", i, lower_lineptr[i]);
			}
			lower_lineptr[i] = NULL;

			sort(lower_lineptr, nlines, strcmp, reverse);
			writelines(lineptr, nlines);
		} else {
			sort(lineptr, nlines, strcmp, reverse);
			writelines(lineptr, nlines);
		}
	} else {
		printf("No input provided to sort\n");
	}
	return 0;
}

/* Write output lines */
void writelines(char *lineptr[], int nlines) {
	for (int i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

/* Sort function that sorts using the given comparison function */
void sort(char *v[], int n, int (*comp)(const char *, const char *), int reverse) {
	int gap, i, j;
	char *temp;
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++) {
			for (j = i - gap; j >= 0; j -= gap) {
				if ((reverse ? (*comp)(v[j], v[j + gap]) < 0 : (*comp)(v[j], v[j + gap]) > 0)) {
					temp = v[j];
					v[j] = v[j + gap];
					v[j + gap] = temp;
				} else {
					break;
				}
			}
		}
	}
}