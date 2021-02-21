#include "xcb/xcb.h"
#include <unistd.h>
#include <syslog.h>

xcb_connection_t *conn;

int xdev_connect(void)
{
  conn = xcb_connect(NULL, NULL);
  int has_error = xcb_connection_has_error(conn);

  if (has_error)
  {
    syslog(LOG_ERR, "Cannot open display... %d", has_error);
  }

  syslog(LOG_ERR, "Connected sucessfully... %d", has_error);

  return !has_error;
}

void xdev_disconnect(void)
{
  syslog(LOG_INFO, "Exiting xdev...");
  xcb_disconnect(conn);
}

void xdev_draw_window(int x, int y, int width, int height)
{
  xcb_screen_t *first_screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;
  xcb_window_t window = xcb_generate_id(conn);
  xcb_create_window(
      conn,
      XCB_COPY_FROM_PARENT,
      window,
      first_screen->root,
      x,
      y,
      width,
      height,
      0,
      XCB_WINDOW_CLASS_INPUT_OUTPUT,
      first_screen->root_visual,
      0,
      NULL);

  xcb_map_window(conn, window);

  xcb_flush(conn);
}