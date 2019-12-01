#include <ncurses.h>

#define MENUMAX 6

void drawmenu(int item) {
  char mainmenu[] = "Main Menu";
  char menu[MENUMAX][21] = {"Answer E-mail", "Off to the Web", "Word processing", "Financial managment", "Maintenance", "Shutdown"};

  clear();
  addstr(mainmenu);
  for (int i = 0; i < MENUMAX; i++) {
    if (i == item) {
      attron(A_REVERSE);
    }
    mvaddstr(3 + (i * 2), 20, menu[i]);
    attroff(A_REVERSE);
  }
  mvaddstr(17, 25, "Use arrow keys to move; Enter to select:");
  refresh();
}

int main() {
  int key, menuitem;

  menuitem = 0;

  initscr();

  drawmenu(menuitem);
  keypad(stdscr, TRUE);
  noecho();

  do {
    key = getch();
    switch (key) {
      case KEY_DOWN:
      menuitem++;
      if (menuitem > MENUMAX - 1) {
        menuitem = 0;
      }
      break;
      case KEY_UP:
      menuitem--;
      if (menuitem < 0) {
        menuitem = MENUMAX - 1;
      }
      break;
      default:
      break;
    }
    drawmenu(menuitem);
  } while (key != '\n');

  echo();
  endwin();

  return 0;
}
