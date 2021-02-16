#include <config.h>
#include <stdlib.h>
#include "xcb.h"

int main(int argc, char const *argv[])
{
  if (connect())
  {
    return EXIT_FAILURE;
  }

  atexit(disconnect);

  return EXIT_SUCCESS;
}
