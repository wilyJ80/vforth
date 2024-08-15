#include <stdio.h>
#include <stdlib.h>
#include "runfile.h"

const char* read_file(const char *file_name) {

	FILE* fp;

	fp = fopen(file_name, "r");
	if (fp == NULL) {
		fprintf(stderr, "File not opened.\n");
		return NULL;
	}

	/* ***********
		* WTF?
	* ***********/
	// Determine the file size
	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	// Allocate memory for the file contents
	char *buffer = malloc(file_size + 1); // +1 for null terminator
	if (buffer == NULL) {
		fprintf(stderr, "Memory allocation failed.\n");
		fclose(fp);
		return NULL;
	}

	// Read the file into the buffer
	size_t bytes_read = fread(buffer, 1, file_size, fp);
	if (bytes_read != file_size) {
		fprintf(stderr, "File read error.\n");
		free(buffer);
		fclose(fp);
		return NULL;
	}

    // Null-terminate the string
    buffer[file_size] = '\0';

	fclose(fp);

	return buffer;
}

int run_file(const char *file_as_string) {
	// TODO parse
	printf("%s", file_as_string);
	return 0;
}
