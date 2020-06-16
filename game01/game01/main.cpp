#include<ncurses.h>
#include<sys/time.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<unistd.h>
#include<iostream>

#include"Piece.h"

void swap(int& a,int& b) 
{
	int t = a;
	a = b;
	b = t;
}

int getrand(int min, int max)
{
	return (min + rand() % (max - min + 1));
}

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destory_win(WINDOW *local_win);

int game_win_height = 30;
int game_win_width = 45;

int hint_win_height = 10;
int hint_win_width = 20;
WINDOW * game_win, *hint_win, *score_win;
int key;

int main()
{
	initscr();
	//raw();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);

	refresh();

	game_win = create_newwin(game_win_height, game_win_width, 0, 0);
	wborder(game_win, '*', '*', '*', '*', '*', '*', '*', '*');
	wrefresh(game_win);

	hint_win = create_newwin(hint_win_height, hint_win_width, 0, game_win_width + 10);
	mvprintw(0, game_win_width + 10 + 2, "%s", "Next");
	refresh();

	score_win = create_newwin(hint_win_height, hint_win_width, 20, game_win_width + 10);
	mvprintw(20, game_win_width + 10 + 2, "%s", "Score");
	refresh();



	Piece* pp = new Piece;
	pp->initial();


	while (1)
	{
		pp->move();
		if (pp->game_over)
			break;
	}

	destory_win(game_win);
	destory_win(hint_win);
	destory_win(score_win);
	delete pp;
	system("clear");

	int row, col;
	getmaxyx(stdscr, row, col);
	mvprintw(row / 2, col / 2, "%s", "GAMER OVER ! \n ");
	mvprintw(row / 2 + 2, col / 2 - 2, "%s", "Wait 5s to return tthe erminal ! \n ");
	refresh();

	sleep(5);
	endwin();
	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);
	wrefresh(local_win);
	return local_win;
}

void destory_win(WINDOW *local_win)
{
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}