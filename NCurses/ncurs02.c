#include <ncurses.h>

int main() {

  char text01[] = "The Matrix has you, Neo...\n";
  char text02[] = "Follow the white rabbit...";

  initscr();

  addstr(text01);
  addstr(text02);
  move(2, 0);
  addstr("MATRIX");

  refresh();

  getch();
  endwin();
  return 0;
}
