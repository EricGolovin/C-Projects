#include <ncurses.h>
#include <stdlib.h>

void bomb();

int main() {
  WINDOW *a, *b, *c, *d;
  int maxX, maxY, halfX, halfY;
  int ch;

  initscr();
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_BLUE);
  init_pair(2, COLOR_BLACK, COLOR_RED);
  init_pair(3, COLOR_BLACK, COLOR_GREEN);
  init_pair(4, COLOR_BLACK, COLOR_CYAN);

  getmaxyx(stdscr, maxY, maxX);
  halfX = maxX >> 1;
  halfY = maxY >> 1;

  if ((a = newwin(halfY, halfX, 0, 0)) == NULL) {
    bomb();
  }
  if ((b = newwin(halfY, halfX, 0, halfX)) == NULL) {
    bomb();
  }
  if ((c = newwin(halfY, halfX, halfY, 0)) == NULL) {
    bomb();
  }
  if ((d = newwin(halfY, halfX, halfY, halfX)) == NULL) {
    bomb();
  }

  mvwaddstr(a, 0, 0, "This is window A\n");
  wbkgd(a, COLOR_PAIR(1));
  wrefresh(a);
  mvwaddstr(b, 0, 0, "This is window B\n");
  wbkgd(b, COLOR_PAIR(2));
  wrefresh(b);
  mvwaddstr(c, 0, 0, "This is window C\n");
  wbkgd(c, COLOR_PAIR(3));
  wrefresh(c);
  mvwaddstr(d, 0, 0, "This is window D\n");
  wbkgd(d, COLOR_PAIR(4));
  wrefresh(d);

  do {
    ch = wgetch(a);
    waddch(b, ch);
    waddch(c, ch);
    waddch(d, ch);
    wrefresh(b);
    wrefresh(c);
    wrefresh(d);
  } while (ch != '~');

  endwin();

  return 0;
}

void bomb() {
  addstr("Unable to allocate memory for new window.\n");
  refresh();
  endwin();
  exit(1);
}
