#include <config.h>
#include <stdlib.h>
#include "xcb/xcb.h"

int default_screen = 0;
xcb_connection_t *conn;

int main(int argc, char const *argv[])
{

  conn = xcb_connect(NULL, &default_screen);

  if (xcb_connection_has_error(conn))
  {
    return EXIT_FAILURE;
  }

  xcb_disconnect(conn);

  return EXIT_SUCCESS;
}
