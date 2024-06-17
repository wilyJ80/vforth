#include "list.h"
#include "slre.h"
#include "sds.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 1024
#define DATASTACK_LEN 1024

int main(void) {

  char buffer[BUF_LEN];
  struct _ListEntry *data_stack = NULL;

  printf("VFORTH 0.0.1 - Enter Ctrl+D to exit\n");

  while (true) {
    printf("ok> ");

    // Get input, quit with EOF
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      return EXIT_SUCCESS;
    }

    // Remove trailing newline
    buffer[strcspn(buffer, "\n")] = '\0';
    
    sds buffer_to_sds = sdsnew(buffer);

    // Empty input, skip
    if (buffer[0] == '\0') {
      sdsfree(buffer_to_sds);
      continue;
    }

    // Check valid integer
    // Currently not accepting words, only numbers!
    /* if (slre_match("^[\\d]+$", buffer, strlen(buffer),NULL, 0, 0) <= 0) {
      printf("Not integer\n");
      continue;
    }
*/
    /* int value = atoi(buffer);
    int *value_ptr = malloc(sizeof(int));
    *value_ptr = value;
    ListValue list_value = value_ptr;
    list_prepend(&data_stack, list_value); */

    ListValue list_value = buffer_to_sds;
    list_prepend(&data_stack, list_value);

    // print stack
    ListIterator iter;
    list_iterate(&data_stack, &iter);
    while (list_iter_has_more(&iter)) {
      ListValue value = list_iter_next(&iter);
      printf("%s ", (char *)value);
    }
  }

  // free data stack memory
  ListIterator iter;
  list_iterate(&data_stack, &iter);
  while (list_iter_has_more(&iter)) {
    ListValue value = list_iter_next(&iter);
    sdsfree((sds)value);
  }

  list_free(data_stack);

  return EXIT_SUCCESS;
}
