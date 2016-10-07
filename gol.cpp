/*
	Shofiqur Rahman
	Kevin Fuentes
	Bryan Gonzalez

 * CSc103 Project 3: Game of Life
 * See readme.html for details.
 * Please list all references you made use of in order to complete the assignment: your classmates, websites, etc.  Aside from the lecture notes and the book, please list everything.  And remember- citing a source does NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE YOUR OWN WORK**.
 * References:
 * instructions from senior CSC students
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 2+2+2+1+1+2+
 #hours: 2+2+2+2
 */

#include <iostream>
using namespace std;

#include <cstdio>
#include <stdlib.h> // for exit();
#include <getopt.h> // to parse long arguments.
#include <unistd.h> // sleep
#include <vector>
using std::vector;
#include <string>
using std::string;


static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Text-based version of Conway's game of life.\n\n"
"   --seed,-s     FILE     read start state from FILE.\n"
"   --world,-w    FILE     store current world in FILE.\n"
"   --fast-fw,-f  NUM      evolve system for NUM generations and quit.\n"
"   --help,-h              show this message and exit.\n";

size_t max_gen = 0; /* if > 0, fast forward to this generation. */
string wfilename =  "/tmp/gol-world-current"; /* write state here */

FILE* fworld = fopen("/tmp/gol-world-current","rb"); /* handle to file wfilename. */

string initfilename = "/tmp/gol-world-current"; /* read initial state from here. */

vector<vector<bool> > g;

size_t nbrCount(size_t i, size_t j, const vector<vector<bool> >& g)
{

	size_t n = 0;
	size_t length = g.size();
	size_t width = g[0].size();

	bool left = g[i][(j-1+ width)%width];
		if (left == true) ++n;
	bool right = g[i][(j+1)%width];
		if (right == true) ++n;
	bool upper = g[(i-1+ length)%length][j];
		if (upper == true) ++n;
	bool lower = g[(i+1)%length][j];
		if (lower == true) ++n;
	bool upperl = g[(i-1+ length)%length][(j-1+ width)%width];
		if (upperl == true) ++n;
	bool lowerl = g[(i+1)%length][(j-1+ width)%width];
		if (lowerl == true) ++n;
	bool upperr = g[(i-1+ length)%length][(j+1)%width];
		if (upperr == true) ++n;
	bool lowerr = g[(i+1)%length][(j+1)%width];
		if (lowerr == true) ++n;
	return n;
}

void update()
{
	for(size_t i=0; i<g.size(); ++i)
	{
		for(size_t j=0; i<g[0].size(); ++j)
		{
			if(nbrCount(i, j, g)<2) g[i][j] = false;
			else if(nbrCount(i, j, g)>3) g[i][j] = false;
			else if(nbrCount(i, j, g)==3) g[i][j] = true;}}
	for(size_t i=0; i<g.size(); ++i)
		{
			for(size_t j=0; i<g[0].size(); ++j)
			{ if(g[i][j] == true) cout<<"0";
				else if(g[i][j] == false) cout<<".";}}
}

int initFromFile(const string& fname)
{
	char c;
	for(size_t i=0; i<g.size(); ++i)
	{
		for(size_t j=0; i<g[0].size(); ++j)
		{fread(&c, 1, 1, fworld);
			g[i][j]=c;}}
	fclose(fworld);
	return 0;
}

void mainLoop();
void dumpState(FILE* f)
{

char state;
	char c;
	const int jsize = 8;
	const int isize = 8;
	const char* clist =".0\n";
	for(size_t j = 0; j < jsize; j++){
		for(size_t i = 0; i < isize; i++){
			state = nbrCount(i,j,vec2);
			if(state ==true){
					c= '0'; }
			else{
					c= '.'; }


		}
	}
}


char text[3] = ".O";

int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {
		{"seed",    required_argument, 0, 's'},
		{"world",   required_argument, 0, 'w'},
		{"fast-fw", required_argument, 0, 'f'},
		{"help",    no_argument,       0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "hs:w:f:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case 's':
				initfilename = optarg;
				break;
			case 'w':
				wfilename = optarg;
				break;
			case 'f':
				max_gen = atoi(optarg);
				break;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}

	mainLoop();
	return 0;
}

void mainLoop() {
	/* update, write, sleep */
}
