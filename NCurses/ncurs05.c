#include <ncurses.h>

int main() {

  initscr();

  attron(A_BOLD);
  addstr("Matrix has you, Neo...\n");
  attron(A_BLINK);
  addstr("Matrix has you, Neo...\n");
  attroff(A_BOLD);
  addstr("Matrix has you, Neo...\n");
  addstr("Matrix has you, Neo...\n");
  attrset(A_NORMAL);
  addstr("Matrix has you, Neo...\n");
  addstr("Matrix has you, Neo...\n");
  refresh();

  getch();
  endwin();

  return 0;
}
