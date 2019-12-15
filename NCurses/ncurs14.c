#include <ncurses.h>
#include <stdlib.h>

void bomb();

int main() {
  WINDOW *a, *b, *c, *d;
  int maxX, maxY, halfX, halfY;

  initscr();

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
  wrefresh(a);
  mvwaddstr(b, 0, 0, "This is window B\n");
  wrefresh(b);
  mvwaddstr(c, 0, 0, "This is window C\n");
  wrefresh(c);
  mvwaddstr(d, 0, 0, "This is window D\n");
  wrefresh(d);

  getch();
  endwin();

  return 0;
}

void bomb() {
  addstr("Unable to allocate memory for new window.\n");
  refresh();
  endwin();
  exit(1);
}
