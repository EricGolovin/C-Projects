#include <ncurses.h>

int main() {
  char text[] = "The Matrix has you, Neo...";;
  char *t;

  initscr();
  t = text;

  while (*t) {
    addch(*t);
    t++;
    refresh();
    napms(100);
  }
  getch();
  endwin();
  return 0;
}
