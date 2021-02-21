#include <config.h>
#include <stdlib.h>
#include <syslog.h>
#include "xcb.h"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{

  if (!xdev_connect())
  {
    return EXIT_FAILURE;
  }

  xdev_draw_window(0, 0, 640, 480);

  pause();

  atexit(xdev_disconnect);
  return EXIT_SUCCESS;
}
