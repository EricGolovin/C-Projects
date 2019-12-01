#include <ncurses.h>

int main() {

  initscr();

  start_color();

  init_pair(1, COLOR_BLACK, COLOR_RED);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  attrset(COLOR_PAIR(1));
  addstr("Matrix has you, Neo...\n");
  attrset(COLOR_PAIR(2));
  addstr("Matrix has you, Neo...\n");
  attrset(COLOR_PAIR(1));
  addstr("Follow the white rabbit...\n");
  attrset(COLOR_PAIR(2));
  addstr("Follow the white rabbit and ");
  attron(A_BOLD);
  addstr("find us");
  attroff(A_BOLD);
  addch('!');
  refresh();
  getch();
  endwin();

  return 0;
}
