/*

	Does a frequency analysis of encrypted text.
	Text must be english alphabet

*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <cmath>


#include <R.h>
#include <Rcpp.h>	
#include <RInside.h>


int largest(int values2[]);
int shift(int movedBy);

// by declaring this, we include stuff like cout, cin, string, vector, map, etc
using namespace std;

// ints that will be incremented with each time its corresponding char is found
int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;


int main(int argc, char *argv[]) // include these to later create embedded instance
{


	
	// creates string to be read in
	string mystr;
	// prompt user
	cout << "Enter name of document to be read: ";

	// reads in user prompt to String mystr
	getline(cin,mystr);

	// opens file and changes input to char
	ifstream myfile(mystr.c_str());

	// enter statement if file is open
	if(myfile.is_open()) 
	{

		string line;	// line that gets read in
		char next;	// will be filled with each character in each line to be analyzed

		// continues getting lines from file until reaches end of file
		// stores lines in string line
		while(getline(myfile,line))
		{	
			// runs through each line, letter by letter
			for(int i=0; i<line.length(); i++)
			{
				// assing char next to each letter in line
				next = tolower(line[i]);

					if(next == 'a')
						a++;
					if(next == 'b')
						b++;
					if(next == 'c')
						c++;
					if(next == 'd')
						d++;
					if(next == 'e')
						e++;
					if(next == 'f')
						f++;
					if(next == 'g')
						g++;
					if(next == 'h')
						h++;
					if(next == 'i')
						i++;
					if(next == 'j')
						j++;
					if(next == 'k')
						k++;
					if(next == 'l')
						l++;
					if(next == 'm')
						m++;
					if(next == 'n')
						n++;
					if(next == 'o')
						o++;
					if(next == 'p')
						p++;
					if(next == 'q')
						q++;
					if(next == 'r')
						r++;
					if(next == 's')
						s++;
					if(next == 't')
						t++;
					if(next == 'u')
						u++;
					if(next == 'v')
						v++;
					if(next == 'w')
						w++;
					if(next == 'x')
						x++;
					if(next == 'y')
						y++;
					if(next == 'z')
						z++;

			} // End for

		} // End while

	} // End if

	// tells user that file isn't opened
	else cout << "unable to open file";

	// close the file
	myfile.close();
	myfile.clear();



	/*
		****************
		All R code:
		****************
	*/

	// create embeded R instance
	RInside R(argc, argv);
	
	// assign R instances of values collected in c++
	R["a"] = a;
	R["b"] = b;
	R["c"] = c;
	R["d"] = d;
	R["e"] = e;
	R["f"] = f;
	R["g"] = g;
	R["h"] = h;
	R["i"] = i;
	R["j"] = j;
	R["k"] = k;
	R["l"] = l;
	R["m"] = m;
	R["n"] = n;
	R["o"] = o;
	R["p"] = p;
	R["q"] = q;
	R["r"] = r;
	R["s"] = s;
	R["t"] = t;
	R["u"] = u;
	R["v"] = v;
	R["w"] = w;
	R["x"] = x;
	R["y"] = y;
	R["z"] = z;

	string cmd = "tmpf <- tempfile('nums',fileext='.png');"
				 "png(tmpf);"
				 "counts <- c(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z);"
				 "barplot(counts, main='My Plot', xlab='Letters');"
				 "dev.off();"
				 "tmpf";

	string tmpfile = R.parseEval(cmd);

	cout << "Using plot " << tmpfile << endl;
	unlink(tmpfile.c_str());

	cmd = "x11(); barplot(counts, main='My Plot', xlab='Letters', names.arg=c('a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z')); Sys.sleep(5);";
	R.parseEvalQ(cmd);

	/*
		End R code
	*/



	/*
		*******************
		Begin finding shift
		*******************
	*/

	// initialize our array with values found
	int lettersArray[26] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};

	// finds how far "e" has been shifted
	int ourIndex = largest(lettersArray);

	// shift over by:
	int shifted = shift(ourIndex);

	// To test if we shift correctly
	cout << "This is how much we shifted to largest" << shifted;
	cout << "\n";

	// opens file and changes input to char
	ifstream myfile2;
	myfile2.open(mystr.c_str());

	if(myfile2.is_open()) {


		string line;	// line that gets read in
		char next;	// will be filled with each character in each line to be analyzed
		int intOfNext;	// cast from char of input stream to int
		char toPrint;	// cast from inOfNext to char for shifted value

		// continues getting lines from file until reaches end of file
		// stores lines in string line
		while(getline(myfile2,line))
		{	


			// runs through each line, letter by letter
			for(int i=0; i<line.length(); i++)
			{
				
				// assing char next to each letter in line
				next = tolower(line[i]);
				intOfNext = (int) next + shifted;
				cout << (char) intOfNext;
			

			}
		}
	}






	
	// exit program
	return 0;

}



/*
	******************************************************
	Takes array of our values
	Returns the index that is closest to the largest value
	******************************************************

	333333333*****Pointless lol************33333333

int closest(int values[]) {
	
	// index value of closest
	int bestIndex = 0;
	// find largest value in our array
	int largeConst = largest(values[]);
	// find distance of first value and the largest
	int distance = abs(values[0] - largeConst);

	for(int j=1; j<values[].length(); j++) {
		if (abs(values[j] - largeConst) < distance) {
			bestIndex = j;
			distance = abs(values[j] - largeConst);
		}
	}
	return bestIndex;
}
*/

/*
	*************************************
	Takes array of our values
	Returns the largest index value in our array
	*************************************
*/
int largest(int values2[]) {

	int max = 0;
	int large = values2[0];
	for(int i=1; i<26; i++) {
		if(values2[i] > large) {
			max = i;
			large = values2[i];
		}
	}
	return max;
}


/*
	***********
	Takes index integer
	Returns integer value 'e' has been shifted by
	***********
*/

int shift(int movedBy) {

	int shiftedBy = movedBy -4;

	return shiftedBy;
}