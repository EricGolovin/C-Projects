#include <ncurses.h>

int main() {

  char first[34];
  char last[32];

  initscr();

  addstr("What is your first name? ");
  refresh();
  getstr(first);

  addstr("What is your last name? ");
  refresh();
  getstr(last);

  printw("Matrix welcomes you, %s %s", first, last);
  refresh();
  getch();

  endwin();

  return 0;
}
