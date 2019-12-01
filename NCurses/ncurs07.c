#include <ncurses.h>

int main() {

  initscr();

  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_GREEN, COLOR_WHITE);
  init_pair(3, COLOR_RED, COLOR_GREEN);

  addstr("Matrix has you, Neo...");
  bkgd(COLOR_PAIR(1) | '.');
  refresh();
  getch();

  bkgd(COLOR_PAIR(2) | '.');
  refresh();
  getch();

  bkgd(COLOR_PAIR(3) | '.');
  refresh();
  getch();

  endwin();

  return 0;
}
