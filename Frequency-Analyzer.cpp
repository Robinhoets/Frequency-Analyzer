/*

	Does a frequency analysis of encrypted text.
	Text must be english alphabet

*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <iomanip>


#include <R.h>
#include <Rcpp.h>	
#include <RInside.h>


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



	// tests to see if increasing is working
	cout << "a was found: " << a << '\n';

	// create embeded R instance
	RInside R(argc, argv);
	
	R["a"] = a;
	R["b"] = b;
	R["c"] = c;
	R["d"] = d;
	R["e"] = e;

	string cmd = "tmpf <- tempfile('nums',fileext='.png');"
				 "png(tmpf);"
				 "counts <- c(a,b,c,d,e);"
				 "barplot(counts, main='My Plot', xlab='Letters');"
				 "dev.off();"
				 "tmpf";

	string tmpfile = R.parseEval(cmd);

	cout << "Using plot " << tmpfile << endl;
	//unlink(tmpfile.c_str());
	ifstream myfile2;
	myfile2.open("tmpfile");
	if (myfile.is_open()) {
		myfile.close();
		cout<< "function success";
	} else {
		cout<< "unable to open file";
	}


	// exit program
	return 0;

}
