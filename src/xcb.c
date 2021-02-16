#include "xcb/xcb.h"
#include <unistd.h>
#include <stdbool.h>

xcb_connection_t *conn;

bool connect()
{
  conn = xcb_connect(NULL, NULL);
  return !xcb_connection_has_error(conn);
}

void disconnect(void)
{
  xcb_disconnect(conn);
}