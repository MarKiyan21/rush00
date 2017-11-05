#include "AEntities.hpp"
#include "Player.hpp"
#include "Enemies.hpp"

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

//int		main()
//{
//	Player	player = Player();
//
//	initscr();
//	noecho();
////	start_color();
//	int		c = 0;
////	int		maxh;
////	int 	maxw;
//	WINDOW	*win;
//	win = newwin(H, W, 0, 0);
//	while (1) {
//		make_frame(win, H, W, '$');
//		c = getch();
////		wrefresh(win);
//
//		if (c == 27)
//			exit(0);
//		else if (c == 97)
//			player.move(-1, 0);
//		else if (c == 100)
//			player.move(1, 0);
//		else if (c == 119)
//			player.move(0, -1);
//		else if (c == 115)
//			player.move(0, 1);
//
//		make_clean_win(win, H, W, ' ');
//
////		mvwaddch(win, player.getY(), player.getX(), (chtype)player.getType());
//		mvwprintw(win, player.getY(), player.getX(), player.getType());
//
//
//
//
//
//		usleep(10000);
////		refresh();
//		wrefresh(win);
//		make_clean_win(win, maxw, maxh, ' ');
////		mvprintw(0, 0, "Keycode: %d, and the character: %c", c, c);
//		mvprintw(player.getY(), player.getX(), player.getType());


//		wrefresh(win);
//	}
//	delwin(win);
//	refresh();
////	getch();
//	endwin();
//	return 0;
//}



//make_clean_win(win, maxheight, maxwidth, ' ');

//		mvwaddch(win, player.getY(), player.getX(), (chtype)player.getType());
//mvwprintw(win, player.getY(), player.getX(), player.getType());


//make_frame(win, maxheight, maxwidth, oldalchar);


//usleep(10000);
//refresh();
//wrefresh(win);

//void make_clean_win(WINDOW *win, int maxheight, int maxwidth, char clean)
//{
//	for (int i = 0; i < maxheight; ++i)
//	{
//		for (int j = 0; j < maxwidth; ++j)
//		{
//			mvwaddch(win, i, j, clean);
//		}
//	}
//}
//
//void make_frame(WINDOW * win, int maxheight, int maxwidth, char oldalchar)
//{
//	for(int i=0;i<maxwidth;i++)
//	{
//		wmove(win,0,i);
//		waddch(win,oldalchar);
//	}
//
//	for(int i=0;i<maxheight;i++)
//	{
//		wmove(win, i, 0);
//		waddch(win, oldalchar);
//	}
//	for(int i=0;i<maxwidth;i++)
//	{
//		wmove(win, maxheight-1,i);
//		waddch(win, oldalchar);
//	}
//	for(int i=0;i<maxheight;i++)
//	{
//		wmove(win,i,maxwidth-1);
//		waddch(win, oldalchar);
//	}
//}

int main()
{
	Player	player = Player();

	int maxheight;
	int maxwidth;
	int t_maxh;
	int t_maxw;
	int	c = 0;

	Enemies	enemies = Enemies();
	initscr();
	WINDOW * win = newwin(H, W, 0, 0);
	nodelay(stdscr,true);
	noecho();
	while (c != 27)
	{
		enemies.createEnemy();
		enemies.move(0, 1);
		for (int j = 0; j < 50; ++j)
		{
			if (enemies.enemiesArray[j] == NULL)
				break;
			if (enemies.enemiesArray[j]->collision(player)) {
				enemies.enemiesArray[j]->bam(j);
				//добавить на уменьшение здоровья игрока
			}
		}
		c = getch();

		if (c == 97)
			player.move(-1, 0);
		else if (c == 100)
			player.move(1, 0);
		else if (c == 119)
			player.move(0, -1);
		else if (c == 115)
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
			if (enemies.enemiesArray[i])
				mvwaddch(win, enemies.enemiesArray[i]->getY(), enemies.enemiesArray[i]->getX(), *enemies.enemiesArray[i]->getType());
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