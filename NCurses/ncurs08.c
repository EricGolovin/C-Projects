#include <ncurses.h>

int main() {

  initscr();

  addstr("Matrix has you!\n");
  beep();
  refresh();
  getch();
  addstr("Matrix says, it had you!\n");
  flash();
  refresh();
  getch();
  endwin();

  return 0;
}
