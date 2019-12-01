#include <ncurses.h>

void show_help(WINDOW *help);

int main(void) {

  int ch;
  WINDOW *help;

  initscr();

  if ((help = newwin(0, 0, 0, 0)) == NULL) {
    addstr("Unable to allocate window memory\n");
    endwin();
    return (1);
  }
  mvwaddstr(help, 6, 32, "Help menu screen");
  mvwaddstr(help, 9, 28, "Press the ~ key to quit");
  mvwaddstr(help, 12, 28, "Press ENTER to go back");

  addstr("Typer Program\n");
  addstr("Press + for help: \n\n");
  refresh();

  noecho();

  do {
    ch = getch();
    refresh();
    if (ch == '+') {
      show_help(help);
    } else {
      addch(ch);
    }
  } while (ch != '~');

  endwin();

  return 0;
}

void show_help(WINDOW *help) {
  touchwin(help);
  wrefresh(help);
  getch();
  touchwin(stdscr);
  refresh();
}
