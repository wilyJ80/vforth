#include "../lib/list.h"
#include "../lib/slre.h"
#include "../lib/sds.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 1024

int main(void) {

  char buffer[BUF_LEN];
  struct _ListEntry *data_stack = NULL;

  printf("VFORTH 0.0.2 - Enter Ctrl+D to exit\n");

  while (true) {
    printf("ok> ");

    // Get input, quit with EOF
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      return EXIT_SUCCESS;
    }

    // Empty input, skip
    if (buffer[0] == '\n') {
      continue;
    }

    sds buffer_to_sds = sdsnew(buffer);
    sdstrim(buffer_to_sds, "\n");

    ListValue list_value = buffer_to_sds;
    list_append(&data_stack, list_value);

    // TODO: Add eval() function here

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
