#include <stdio.h>
#include <stdlib.h>
#include "runfile.h"
#include "prompt.h"

int main(int argc, char *argv[])
{
	if (argc > 2) {
		fprintf(stderr, "Usage: vforth <script>\n");
		return EXIT_FAILURE;

	} else if (argc == 2) {
		printf("Running file...\n");
		const char* file = read_file(argv[1]);
		run_file(file);

	} else {
		printf("Running prompt...\n");
		prompt();
	}

	return EXIT_SUCCESS;
}
