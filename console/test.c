#include "console.h"

void
printCell (int address)
{
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (memory[address], sign, command, operand);
  printf ("sign = %d\n command = %d\n operand = %d\n", *sign, *command,
          *operand);
}

void
printCounters ()
{
  printf ("Counter = %d \n", ICount);
}

void
printAccumulator ()
{
  printf ("Accumulator = %d \n", Accum);
}

void
printFlags ()
{
  printf ("Flag 0 is: %s \n", (flags & IT_MASK) == IT_MASK ? "I" : "_");
  printf ("Flag 1 is: %s \n", (flags & MC_MASK) == MC_MASK ? "M" : "_");
  printf ("Flag 2 is: %s \n", (flags & SF_MASK) == SF_MASK ? "S" : "_");
  printf ("Flag 3 is: %s \n", (flags & ZD_MASK) == ZD_MASK ? "Z" : "_");
  printf ("Flag 4 is: %s \n", (flags & OO_MASK) == OO_MASK ? "O" : "_");
}

int
main ()
{
  // Инициализация оперативной памяти, аккумулятора, счетчика команд и
  // регистра флагов
  sc_MemoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  // Установка произвольных значений в оперативную память и вывод ее
  // содержимого (в данном примере установим все ячейки памяти в значение 5)
  for (int i = 7; i < 52; i++)
    {
      sc_MemorySet (i, 5);
    }

  // Вывод содержимого оперативной памяти
  for (int i = 0; i < MEMORY_SIZE; i++)
    {
      printCell (i);
    }
  printf ("\n");

  // Попытка задать недопустимое значение ячейке памяти
  int invalidMemoryValue = 40000;
  int result = sc_MemorySet (10, invalidMemoryValue);
  printf ("Status of setting invalid memory value: %d\n", result);

  // Установка произвольных значений флагов и вывод их содержимого
  sc_regSet (3, 1);
  sc_regSet (2, 0);
  sc_regSet (4, 1);
  printFlags ();

  // Попытка установить некорректное значение флага
  result = sc_regSet (1, 2);
  printf ("Status of setting invalid flag value: %d\n", result);

  // Установка значения аккумулятора и вывод его на экран
  sc_accumulatorSet (100);
  printAccumulator ();

  // Попытка задать недопустимое значение аккумулятору
  int invalidAccValue = 40000;
  result = sc_accumulatorSet (invalidAccValue);
  printf ("Status of setting invalid accumulator value: %d\n", result);

  // Установка значения счетчика команд и вывод его на экран
  sc_icounterSet (50);
  printCounters ();

  // Попытка задать недопустимое значение счетчику команд
  int invalidCounterValue = -10;
  result = sc_icounterSet (invalidCounterValue);
  printf ("Status of setting invalid counter value: %d\n", result);

  // Декодирование произвольной ячейки памяти и значения
  // аккумулятора
  printCell (8);
  printf ("\n");
  printAccumulator ();

  // Кодирование команды и вывод полученного значения в разных системах
  // счисления
  int command = 0x33;
  int encodedValue;
  sc_commandEncode (0, command, 0x59, &encodedValue);
  printf ("\n");

  return 0;
}