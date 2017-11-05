#include "AEntities.hpp"
#include "Player.hpp"
#include "Enemies.hpp"
#include "Bullets.hpp"

static int			num_symb(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int			pow(int num, int len)
{
	int res;

	if (len <= 0)
		return (1);
	res = 1;
	while (len--)
		res *= num;
	return (res);
}

char				*ft_itoa(int n, char *res)
{
	int		len;
	int		i;

	len = num_symb(n);

	i = 0;
	if (n < 0 && ++i)
		res[0] = '-';
	if (n == 0 && ++i)
		res[0] = '0';
	while (--len >= 0)
	{
		if (n < 0)
			res[i++] = '0' - (n / pow(10, len)) % 10;
		else
			res[i++] = '0' + (n / pow(10, len)) % 10;
	}
	res[i] = 0;
	return (res);
}

void	init_color(void)
{
	start_color();
	init_pair(1, COLOR_RED, 6);
	init_pair(2, 4, 6);
}

void	max_win(int *maxheight, int *maxwidth)
{
	int t_maxh;
	int t_maxw;

	getmaxyx(stdscr, t_maxh, t_maxw);

	if (t_maxh < H)
		*maxheight = t_maxh;
	else
		*maxheight = H;

	if (t_maxw < W)
		*maxwidth = t_maxw;
	else
		*maxwidth = W;
}

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
	int	c = 0;
	int timer = 0;
	char buf[10];

	initscr();
	WINDOW * win = newwin(H, W, 0, 0);
	nodelay(stdscr,true);
	noecho();
	keypad(stdscr, true);
	init_color();

	bullets.initArray();


	while (c != 27)
	{
		enemies.createArray();

//		if (c == 32)
//			bullets.createArray(player.getX(), player.getY() - 1);
		enemies.move(0, 1);

		c = getch();

		if (c == 97 || c == 260)
			player.move(-1, 0);
		else if (c == 100 || c == 261)
			player.move(1, 0);
		else if (c == 119 || c == 259)
			player.move(0, -1);
		else if (c == 115 || c == 258)
			player.move(0, 1);

		max_win(&maxheight, &maxwidth);

		wattron(win,COLOR_PAIR(1));

		if (c == 32)
			bullets.createArray(player.getX(), player.getY());
		bullets.move(0, 0, player.getX(), player.getY());

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
		for (int j = 0; j < 200; ++j) {
			if (bullets.bulletsArray[j])
				mvwaddch(win, bullets.bulletsArray[j]->getY(), bullets.bulletsArray[j]->getX(), *bullets.bulletsArray[j]->getType());
			else
				break;
		}
		make_frame(win, maxheight, maxwidth, '$');
//
		mvwprintw(win, 0, 40, "time:");
		mvwprintw(win, 0, 45, ft_itoa(timer, buf));
		mvwprintw(win, 0, 80, "hp:");
		mvwprintw(win, 0, 83, ft_itoa(player.getCHP(), buf));
		wattroff(win,COLOR_PAIR(1));
		usleep(100000);
		timer += 1;
		refresh();
		wrefresh(win);
//
	}
	endwin();

	return 0;
}