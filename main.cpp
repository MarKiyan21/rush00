#include "AEntities.hpp"
#include "Player.hpp"
#include "Enemies.hpp"
#include "Bullets.hpp"

void	make_clean_win(WINDOW *win, int maxheight, int maxwidth, char clean)
{
	for (int i = 0; i < maxheight; ++i)
	{
		for (int j = 0; j < maxwidth; ++j)
		{
			mvwaddch(win, i, j, clean);
		}
	}
}

void	make_frame(WINDOW * win, int maxheight, int maxwidth, char oldalchar)
{
	for(int i=0;i<maxwidth;i++)
	{
		wmove(win,0,i);
		waddch(win,oldalchar);
	}

	for(int i=0;i<maxheight;i++)
	{
		wmove(win, i, 0);
		waddch(win, oldalchar);
	}
	for(int i=0;i<maxwidth;i++)
	{
		wmove(win, maxheight-1,i);
		waddch(win, oldalchar);
	}
	for(int i=0;i<maxheight;i++)
	{
		wmove(win,i,maxwidth-1);
		waddch(win, oldalchar);
	}
}

int		main()
{
	Player	player = Player();
	Enemies	enemies = Enemies();
	Bullets bullets = Bullets();

	int maxheight;
	int maxwidth;
	int t_maxh;
	int t_maxw;
	int	c = 0;

	initscr();
	WINDOW * win = newwin(H, W, 0, 0);
	nodelay(stdscr,true);
	noecho();
	keypad(stdscr, true);
	while (c != 27)
	{
		enemies.createArray();
		if (c == KEY_MOUSE)
			bullets.createArray(player.getX(), player.getY() - 1);
		enemies.move(0, 1);
		bullets.move(0, 0);

		c = getch();

		if (c == 97 || c == 260)
			player.move(-1, 0);
		else if (c == 100 || c == 261)
			player.move(1, 0);
		else if (c == 119 || c == 259)
			player.move(0, -1);
		else if (c == 115 || c == 258)
			player.move(0, 1);

		getmaxyx(stdscr,t_maxh,t_maxw);

		if (t_maxh < H)
			maxheight = t_maxh;
		else
			maxheight = H;

		if (t_maxw < W)
			maxwidth = t_maxw;
		else
			maxwidth = W;

		make_clean_win(win, maxheight, maxwidth, ' ');
		mvwaddch(win, player.getY(), player.getX(), *player.getType());
		for (int i = 0; i < 50; ++i)
		{
			if (enemies.enemiesArray[i]) {
				if (enemies.enemiesArray[i]->collision(player)) {
					delete enemies.enemiesArray[i];
					enemies.enemiesArray[i] = new Enemies();
					player.setCHP(-20);
//					if (player.getCHP() == 0)  сделать выход из игры
//						exit(0);
				}
				else
					mvwaddch(win, enemies.enemiesArray[i]->getY(), enemies.enemiesArray[i]->getX(), *enemies.enemiesArray[i]->getType());
			}
			else
				break;

		}
		make_frame(win, maxheight, maxwidth, '$');

		usleep(100000);
		refresh();
		wrefresh(win);

	}
	endwin();

	return 0;
}