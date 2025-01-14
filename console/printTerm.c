#include "console.h"
void
printTerm (int addres, int input)
{
  if (addres > 127 || addres < 0)
    return;
  bc_box (67, 19, 78, 25, 7, 0, "IN-OUT", 2, 0);
  if (input == 1)
    {
      int new_value;
      mt_gotoXY (68, 20);
      printf ("%03d< ", addres);
      scanf ("%04d", &new_value);
      sc_MemorySet (addres, new_value);
      for (int f = 4; f >= 1; f--)
        {
          IN_OUT_addres[f] = IN_OUT_addres[f - 1];
          IN_OUT_arr[f] = IN_OUT_arr[f - 1];
        }
      IN_OUT_addres[0] = addres;
      IN_OUT_arr[0] = new_value;
    }
  for (int count = 0; count < 5; count++)
    {
      mt_gotoXY (68, 20 + count);
      printf ("%03d> ", IN_OUT_addres[count]);
      if (IN_OUT_arr[count] >> 31 == 1)
        printf ("-");
      else
        printf ("+");
      printf ("%04d", IN_OUT_arr[count]);
    }
  return;
}
