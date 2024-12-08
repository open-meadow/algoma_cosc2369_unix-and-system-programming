#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 100
#define MAX_STUDENTS 50

// Define the Student struct to store student name and grade
typedef struct {
	char name[50];
	int grade;
} Student;

// Custom FILE structure for in-memory string
typedef struct {
	char *content;       // Content to read/write
	size_t current_pos;  // Current position in the content
	size_t size;         // Current size of the content buffer
	size_t capacity;     // Total allocated size of the content buffer
} MEM_FILE;

// Custom fopen to initialize MEM_FILE with initial content
MEM_FILE *mem_fopen(const char *initial_content) {
	MEM_FILE *mem_file = (MEM_FILE *)malloc(sizeof(MEM_FILE));
	if (mem_file != NULL) {
		size_t initial_size = strlen(initial_content);
		mem_file->capacity = initial_size + MAXLINE; // Allocate initial capacity with some extra room
		mem_file->content = (char *)calloc(1, mem_file->capacity);
		if (mem_file->content == NULL) {
			free(mem_file);
			return NULL;
		}
		strcpy(mem_file->content, initial_content); // Copy initial content
		mem_file->current_pos = 0;
		mem_file->size = initial_size;
	}
	return mem_file;
}

// Custom fgets to read from the in-memory string
char *mem_fgets(char *buffer, int size, MEM_FILE *mem_file) {
	if (mem_file->current_pos >= mem_file->size) {
		return NULL; // End of content
	}

	int i = 0;
	while (i < size - 1 && mem_file->current_pos < mem_file->size) {
		char c = mem_file->content[mem_file->current_pos++];
		buffer[i++] = c;
		if (c == '\n') {
			break; // Stop at the end of a line
		}
	}

	buffer[i] = '\0';
	return buffer;
}

// Custom fputs to write to the in-memory string
int mem_fputs(const char *str, MEM_FILE *mem_file) {
	size_t len = strlen(str);

	// Expand capacity if necessary
	if (mem_file->size + len >= mem_file->capacity) {
		size_t new_capacity = mem_file->capacity * 2;
		char *new_content = (char *)realloc(mem_file->content, new_capacity);
		if (new_content == NULL) {
			return EOF; // Allocation failed
		}
		mem_file->content = new_content;
		mem_file->capacity = new_capacity;
	}

	// Copy the string into the content buffer
	strcpy(mem_file->content + mem_file->size, str);
	mem_file->size += len;

	return 0;
}

// Custom fclose to free the MEM_FILE
void mem_fclose(MEM_FILE *mem_file) {
	free(mem_file->content);
	free(mem_file);
}

// Main function to manage student grades
int main() {
	// Step 1: Create the in-memory file with initial content
	const char *initial_content = "Alice 85\nBob 78\nCharlie 90\n";
	MEM_FILE *grades_fp = mem_fopen(initial_content);
	if (grades_fp == NULL) {
		fprintf(stderr, "Error: Unable to open grades memory file.\n");
		exit(1);
	}

	// Step 2: Add Student Grades
	printf("Enter student name and grade (or type 'done' to stop):\n");
	char name[50];
	int grade;
	char line[MAXLINE];
	while (1) {
		// Step 2.1: Input and Validate Name
		printf("Name: ");
		scanf("%s", name);

		if (strcmp(name, "done") == 0) {
			break;
		}

		// Validate: The first character of the name must be alphabetic
		if (!(isalpha(name[0]))) {
			printf("Invalid name. The first character must be alphabetic.\n");
			continue; // Retry for a valid name
		}

		// Step 2.2: Input and Validate Grade
		printf("Grade: ");
		scanf("%d", &grade);
		// Validate: Grade must be an integer between 0 and 100
		if (grade < 0 || grade > 100) {
			fprintf(stderr, "Invalid grade. Please enter a number between 0 and 100.\n");
			while (getchar() != '\n'); // Clear input buffer to handle invalid inputs
			continue; // Retry for a valid grade
		}

		// Step 2.3: Write the valid student entry to the in-memory "file"
		snprintf(line, sizeof(line), "%s %d\n", name, grade);
		mem_fputs(line, grades_fp);
	}

	// Step 3: Generate Summary Report
	// Reset the current position to the start to read from the beginning
	grades_fp->current_pos = 0;

	int student_count = 0, total_grade = 0;
	int highest_grade = -1, lowest_grade = 101;
	// Define an array below_average_students to store students scoring below average
	Student below_average_students[MAX_STUDENTS];
	int below_avg_count = 0;

	if (below_average_students == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		mem_fclose(grades_fp);
		exit(1);
	}

	// Student all_students[MAX_STUDENTS];

	// Read from in-memory file and calculate summary statistics
	while (mem_fgets(line, sizeof(line), grades_fp) != NULL) {
		// store name and grade from current line into temp variables
		char curr_name[50];
		int curr_grade;
		sscanf(line, "%s %d", curr_name, &curr_grade);

		student_count++;
		total_grade += curr_grade;
    
        // adjust highest and lowest grades
		if(curr_grade > highest_grade) {
			highest_grade = curr_grade;
		}

		if(curr_grade < lowest_grade) {
			lowest_grade = curr_grade;
		}


	}


	// Calculate average grade
	double average_grade = student_count > 0 ? (double)total_grade / student_count : 0;

	// Step 5: List students scoring below average
	grades_fp->current_pos = 0; // Reset the current position to read again
	while (mem_fgets(line, sizeof(line), grades_fp) != NULL) {
		char curr_name[50];
		int curr_grade;
		sscanf(line, "%s %d", curr_name, &curr_grade);

		if(curr_grade < average_grade) {
			strcpy(below_average_students[below_avg_count].name, curr_name);
			below_average_students[below_avg_count].grade = curr_grade;
			below_avg_count++;
		}
	}

	// Step 6: Print the summary report
	printf("\nAnalysis Report\n");
	printf("----------------------------\n");
	printf("Number of students: %d\n", student_count);
	printf("Average grade: %.2f\n", average_grade);
	printf("Highest grade: %d\n", highest_grade);
	printf("Lowest grade: %d\n", lowest_grade);
	printf("Students scoring below average: ");
	for (int i = 0; i < below_avg_count; i++) {
		printf("%s ", below_average_students[i].name);
	}
	printf("\n");

	// Step 7: Free memory and close the in-memory "file"
	free(below_average_students);
	mem_fclose(grades_fp);

	return 0;
}
