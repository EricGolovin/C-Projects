#include <ncurses.h>
#include <string.h>

void fill(void);

int main() {
  char text[] = "The Matrix has you, Neo... Follow the white rabbit...";
  char *t;
  int len;

  initscr();

  fill();
  refresh();

  len = strlen(text);
  t = text;

  while (len) {
    move(5, 5);
    insch(*(t + len - 1));
    refresh();
    napms(100);
    len--;
  }
  getch();
  endwin();

  return 0;
}

void fill(void) {
  int a, x, y;
  getmaxyx(stdscr, y, x);

  for (a = 0; a < y; a++) {
    addstr("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
  }
}
