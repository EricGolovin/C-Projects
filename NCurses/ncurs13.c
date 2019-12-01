#include <ncurses.h>

void show_help(WINDOW *help);

int main(void) {

  int ch;
  WINDOW *help;

  initscr();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);

  if ((help = newwin(10, 30, 4, 26)) == NULL) {
    addstr("Unable to allocate window memory\n");
    endwin();
    return (1);
  }
  mvwaddstr(help, 1, 7, "Help menu screen");
  mvwaddstr(help, 5, 3, "Press the ~ key to quit");
  mvwaddstr(help, 8, 4, "Press ENTER to go back");

  bkgd(COLOR_PAIR(1));
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
