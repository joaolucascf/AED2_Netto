#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
/*             0     1    2     3   4      5     6       7         8      */
typedef enum
{
  BLACK,
  BLUE,
  GREEN,
  CYAN,
  RED,
  MAGENTA,
  BROWN,
  LIGHTGRAY,
  DARKGRAY,
  LIGHTBLUE,
  LIGHTGREEN,
  LIGHTCYAN,
  LIGHTRED,
  LIGHTMAGENTA,
  YELLOW,
  WHITE
} COLORS;
/* 9         10        11        12        13          14    15          */
static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

void textcolor(int letra, int fundo)
{
  __FOREGROUND = letra;
  __BACKGROUND = fundo;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                          letra + (__BACKGROUND << 4));
}
void gotoxy(int x, int y)
{
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int main()
{
  int li = 1, tecla;
  setlocale(LC_ALL, "");
  for (;;)
  {
    for (;;)
    {
      switch (li)
      {
      case 1:
        system("cls");
        printf("\t\tMENU\n");
        textcolor(0, 15);
        printf("\t1 - ADICIONAR SÉRIES\n");
        textcolor(15, 0);
        printf("\t2 - EDITAR    SÉRIES\n");
        printf("\t3 - REMOVER   SÉRIES\n");
        printf("\t4 - lISTAR    SÉRIES\n");
        printf("\t5 - PESQUISAR SÉRIES\n");
        printf("\t6 - SAIR\n");
        break;
      case 2:
        system("cls");
        printf("\t\tMENU\n");
        printf("\t1 - ADICIONAR SÉRIES\n");
        textcolor(0, 15);
        printf("\t2 - EDITAR    SÉRIES\n");
        textcolor(15, 0);
        printf("\t3 - REMOVER   SÉRIES\n");
        printf("\t4 - lISTAR    SÉRIES\n");
        printf("\t5 - PESQUISAR SÉRIES\n");
        printf("\t6 - SAIR\n");
        break;
      case 3:
        system("cls");
        printf("\t\tMENU\n");
        printf("\t1 - ADICIONAR SÉRIES\n");
        printf("\t2 - EDITAR    SÉRIES\n");
        textcolor(0, 15);
        printf("\t3 - REMOVER   SÉRIES\n");
        textcolor(15, 0);
        printf("\t4 - lISTAR    SÉRIES\n");
        printf("\t5 - PESQUISAR SÉRIES\n");
        printf("\t6 - SAIR\n");
        break;
      case 4:
        system("cls");
        printf("\t\tMENU\n");
        printf("\t1 - ADICIONAR SÉRIES\n");
        printf("\t2 - EDITAR    SÉRIES\n");
        printf("\t3 - REMOVER   SÉRIES\n");
        textcolor(0, 15);
        printf("\t4 - lISTAR    SÉRIES\n");
        textcolor(15, 0);
        printf("\t5 - PESQUISAR SÉRIES\n");
        printf("\t6 - SAIR\n");
        break;
      case 5:
        system("cls");
        printf("\t\tMENU\n");
        printf("\t1 - ADICIONAR SÉRIES\n");
        printf("\t2 - EDITAR    SÉRIES\n");
        printf("\t3 - REMOVER   SÉRIES\n");
        printf("\t4 - lISTAR    SÉRIES\n");
        textcolor(0, 15);
        printf("\t5 - PESQUISAR SÉRIES\n");
        textcolor(15, 0);
        printf("\t6 - SAIR\n");
        break;
      case 6:
        system("cls");
        printf("\t\tMENU\n");
        printf("\t1 - ADICIONAR SÉRIES\n");
        printf("\t2 - EDITAR    SÉRIES\n");
        printf("\t3 - REMOVER   SÉRIES\n");
        printf("\t4 - lISTAR    SÉRIES\n");
        printf("\t5 - PESQUISAR SÉRIES\n");
        textcolor(0, 15);
        printf("\t6 - SAIR\n");
        textcolor(15, 0);
        break;
      }
      tecla = 0;
      tecla = getch();
      if (tecla == 224)
        tecla = getch();
      if (tecla == 72)
        li--;
      else if (tecla == 80)
        li++;
      else if (tecla == 13)
        break;
      if (li > 6)
        li = 1;
      else if (li < 1)
        li = 6;
    }
    system("cls");
    switch (li)
    {
    case 1:
      system("cls");
      printf("1");
      break;
    case 2:
      system("cls");
      printf("2");
      break;
    case 3:
      system("cls");
      printf("3");
      break;
    case 4:
      system("cls");
      printf("4");
      break;
    case 5:
      system("cls");
      printf("5");
      break;
    case 6:
      return 0;
    }
  }
  return 0;
}