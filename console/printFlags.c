#include "console.h"
void
printFlags ()
{
  mt_gotoXY (85, 2);
  printf ("%s ", (flags & IT_MASK) == IT_MASK ? "I" : "_");
  printf ("%s ", (flags & MC_MASK) == MC_MASK ? "M" : "_");
  printf ("%s ", (flags & SF_MASK) == SF_MASK ? "S" : "_");
  printf ("%s ", (flags & ZD_MASK) == ZD_MASK ? "Z" : "_");
  printf ("%s ", (flags & OO_MASK) == OO_MASK ? "O" : "_");
  return;
}