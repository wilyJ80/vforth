#include "prompt.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF_LEN 1024

int prompt() {

	char buffer[BUF_LEN];

	while (true) {
		printf("vf> ");

		// Get input, quit with EOF
		if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
			return EXIT_SUCCESS;
		}

		// Empty input, skip
		if (buffer[0] == '\n') {
			continue;
		}

		// eval()
	}
}
