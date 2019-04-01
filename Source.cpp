#include <iostream>
#include<fstream>
#include <conio.h>

using namespace std;

long int Map[1010][1010];
long int direction = 0;
long int x, y;
long int AlienSpawnTime[1000010];
float Speed=1;

ifstream in("level3_4.in");
ofstream out("level2_1_sol.out");
ofstream path("path3_1.out");

void readPath() {
	
}

void sim(long int alienId, long int tickTarget, long int spawnTime) {
	ifstream pin("path3_1.out");
	long int times = floor((tickTarget-spawnTime)*Speed);
	for (long int i = 0; i <= times; i++) {
		pin >> x >> y;
	}
	out << tickTarget << " " << alienId << " " << x << " " << y << '\n';
	pin.close();
}

void forward(long int n) {
	for (long int i = 0; i < n; i++)
	{
		if (direction == 0) {
			x++;
		}
		else if (direction == 1) {
			y++;
		}
		else if (direction == 2) {
			x--;
		}
		else if (direction == 3) {
			y--;
		}
		path << x << ' ' << y << '\n';
	}
}

void turn(long int n) {
	long int dir = direction;
	for (long int i = 0; i < n; i++) {
		if (dir + 1 == 4) {
			dir = 0;
		}
		else {
			dir++;
		}
	}
	direction = dir;
}

void citire1() {

	char command;
	long int steps = 0;
	long int wx, wy;

	in >> wx >> wy;
	in >> x >> y;

	path << x << ' ' << y << '\n';

	while (in >> command) {
		if (command == '?') {
			path.close();
			break;
		}

		in >> steps;
		if (command == 'F')
			forward(steps);
		else
			turn(steps);
	}

}

long int main()
{
	citire1();
	long int alienId;
	long int tickTarget;
	long int spawnTime;
	long int NAlien;
	
	in >> Speed >> NAlien;
	for (long int i = 0; i < NAlien; i++) {
		in >> AlienSpawnTime[i];
	}
	long int query;
	in >> query;
	for (long int i = 0; i < query; i++) {
		in >> tickTarget;
		in >> alienId;
		sim(alienId, tickTarget, AlienSpawnTime[alienId]);
	}
	cout << "winner winner chicken dinner";
	in.close();
	out.close();
	
	_getch();
	return 0;
}
