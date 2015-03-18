#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h> 
#include <fstream>
#include <ctype.h>

using namespace std;

struct Earthquake  
{
	string EQID;
	string DATE;
	string TIME;
	string T_ZONE;
	string EQ_NAME;
	string LAT;
	string LON;
	string DEP;
	string MAG;
	string mag_type;
	enum MAG_TYPE { ML, Ms, Mb, Mw };
	enum MONTH {January = 1, February, March, April, May, June , July, 
		August, September, October, November, December};
};

struct Entries {
	enum NT_CODE { CE, CI, FA, NP, WR };
	string ST_CODE; 
	enum BD_TYPE { LP, SP, BB };
	enum IT_TYPE { HG, LG, AC };
	string ORT;
}


size_t readData( ifstream& input, struct Earthquake data[], size_t max_items )
{
	Earthquake Event;
	getline(input, Event.EQID);
	
	string line_2;
	getline(input, line_2);
	istringstream ass(line_2);
	ass >> Event.DATE >> Event.TIME >> Event.T_ZONE;
	
	string line_3;
	getline(input, line_3);
	Event.EQ_NAME=line_3;
	
	string line_4;
	getline(input, line_4);
	istringstream bss(line_4);
	bss >> Event.LON >> Event.LAT >> Event.DEP >> Event.mag_type >> Event.MAG;
	
}

void Process_Header (struct Earthquake Event) {
	
    ofstream outputFile;
    string outputFileName = "nayeem.out" ;
	
	outputFile.open(outputFileName.c_str());
	outputFile << Event.DATE << " " << Event.TIME << " " << Event.T_ZONE << " " << Event.mag_type << " " << Event.EQ_NAME << " [" << Event.EQID << "] " << endl;
	outputFile << "(" << Event.LAT <<" , " << Event.LON << " " << Event.DEP << ")" << endl;
}


int main()
{
    ifstream input;
    char filename[15];
    Earthquake data[300];
	Earthquake Event;
	
    cout << "Enter input file name: ";
    cin >> filename;
	
    input.open( filename );
	
    if ( input.fail() )
    {
        cout << "Input file does not exist." << endl;
        exit(1);
    }
	
    readData(input, data, sizeof data / sizeof data[0]);
	
	Process_Header (Event);
	
	cout << "Opening file:" << " " << filename << endl;
	cout << "Header read correctly !" << endl;

    return(0);
}


