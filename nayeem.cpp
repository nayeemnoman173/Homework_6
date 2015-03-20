
///Md Nayeem Al Noman
///Homework-6
///Programming tools for Eanginners and scientists
///https://github.com/nayeemnoman173/Homework_6

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h> 
#include <fstream>
#include <ctype.h>

using namespace std;

enum months { January=1, February, March, April, May, June , July, August, September, October, November, December };
enum mag_type { ML=1, Ms, Mb, Mw };
enum nt_code { CE=1, CI, FA, NP, WR };
enum bd_type { LongPeriod=1, ShortPeriod, Broadband };
enum it_type { HighGain=1, LowGain, Accelerometer };

struct Earthquake  
{
	string EQID;
	string DATE;
	string DAY;
	string YEAR;
	string TIME;
	string T_ZONE;
	string EQ_NAME;
	string LAT;
	string LON;
	string DEP;
	string MAG_TYPE;
	string MAG;
	string E_CODE;	
};

struct Entries {
	string NCODE;
	string STAN; 
	string BAND;
	string INST;
	string ORTN;
};


///UPPER CASE CONVERSION:

string uppercase (string U) {
    string res = U;
    for (int i=0; i < (int)res.size(); i++)
        res[i] = toupper(res[i]);
    return res;
}


mag_type str2mag_enum(string MAG_TYPE) {
	
    if (MAG_TYPE == "ML") return ML;   
    else if (MAG_TYPE == "MS") return Ms;
    else if (MAG_TYPE == "MB") return Mb;
    else if (MAG_TYPE == "MW") return Mw;
}

/// CHECKING MAGNITUDE TYPE AND VALUE:

bool IsMAG(string& MAG_TYPE, string MAG) {
	
	int n;
	bool isMag;
	istringstream(MAG) >> n;
	if (n < 0) return false;
	
    mag_type magr = str2mag_enum(uppercase(MAG_TYPE));
    
	
    switch (magr) {
        case ML :
		{ isMag = true; MAG_TYPE = "ML" ; break;}
        case Ms :
		{ isMag = true; MAG_TYPE = "Ms" ; break;}
        case Mb :
		{ isMag = true; MAG_TYPE = "Mb" ; break;}
        case Mw : 
		{ isMag = true; MAG_TYPE = "Mw" ; break;}
        default :
			return false;
    }
	
    return isMag;
}


///CHECKING DATE FORMAT:

bool IsDATE(string Date, string& Day, string& Month_Name, string& Year) {
	
	for (int i = 0 ; i< 4; i++) Year += Date[i+6];
	if (!isdigit(Date[3]) && !isdigit(Date[4]))  
		return false;
    
    for (int i = 0 ; i< 2; i++) Day += Day[i+3];
	
    string Month ;
    for (int i = 0; i< 2; i++) Month += Date[i];
    int n;
    std::istringstream(Month) >> n;
	
    if      ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)1))  Month_Name = "January";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)2))  Month_Name = "February";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)3))  Month_Name = "March";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)4))  Month_Name = "April";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)5))  Month_Name = "May";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)6))  Month_Name = "June";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)7))  Month_Name = "July";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)8))  Month_Name = "August";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)9))  Month_Name = "September";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)10)) Month_Name = "October";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)11)) Month_Name = "November";
    else if ((isdigit(Date[0]) &&  (isdigit(Date[1])) && n == (months)12)) Month_Name = "December";
    else return false;
	
    return true;
}

// CHECKING TIME AND TIME ZONE FORMAT:

bool IsTIME (string TIME, string TIME_ZONE){
    
    if (TIME_ZONE.length() != 3) return false;
    
    string hh, mm, ss;
    for (int i = 0; i< 2; i++) {
        hh += TIME[i];
        mm += TIME[i+3];
        ss += TIME[i+6];
    }
	
    if (isdigit(hh[0]) == 0 || isdigit(hh[1]) == 0 ) return false;
    if (isdigit(mm[0]) == 0 || isdigit(mm[1]) == 0 ) return false;
    if (isdigit(ss[0]) == 0 || isdigit(ss[1]) == 0 ) return false;
	
    return true;
}


nt_code str2nt_enum(string NCODE){
	
    if (NCODE == uppercase("CI")) return CI;   
    else if (NCODE == uppercase("CE")) return CE;
    else if (NCODE == uppercase("FA")) return FA;
    else if (NCODE == uppercase("NP")) return NP;
    else if (NCODE == uppercase("WR")) return WR;
	
}


///CHECKING NETWORK CODE:

bool IsNCODE(string NCODE) {
	
	
    nt_code NCode1 = str2nt_enum(uppercase(NCODE));
	
    switch (NCode1) {
        case CI :
		{ return true; break;}
        case CE :
		{ return true; break;}
        case FA :
		{ return true; break;}
        case NP : 
		{ return true; break;}
        case WR :
		{ return true; break;}
        default :
			return false;
    }
	
}

///CHECKING STATION NAME:

bool IsSTAN(string STAN){
	
    bool isStan = false;
    if (STAN.length() == 3 || STAN.length() == 5) {
        if (STAN.length() == 3) {
            for (int i =0; i< 3; i++){
                if (isalpha(STAN[i]) && isupper(STAN[i])) isStan = true;
                else return false;
            }
        }
        else if (STAN.length() == 5) {
            for (int i =0; i< 5; i++){
                if (isdigit(STAN[i])) isStan = true;
                else return false;
            }
        }
    }
    else return false;
    return isStan;
}


bd_type str2bd_enum(string BAND){
	
    if (BAND == uppercase("Long-Period")) return LongPeriod;   
    else if (BAND == uppercase("Short-Period")) return ShortPeriod;
    else if (BAND == uppercase("Broadband")) return Broadband;
}

// CHECKING BAND NAME

bool IsBAND(string BAND) {
    bool isBand = false;
    bd_type bandName1 = str2bd_enum(uppercase(BAND));
	
    switch (bandName1) {
        case LongPeriod : { isBand = true ; return true; }
        case ShortPeriod : { isBand = true ; return true; }
        case Broadband : { isBand = true ; return true; }
    }
    return isBand;
}


it_type str2it_enum(string INST) {
	
    if (INST == uppercase("High-Gain")) return HighGain;   
    else if (INST == uppercase("Low-Gain")) return LowGain;
    else if (INST == uppercase("Accelerometer")) return Accelerometer;
	
}

// CHECKING INSTRUMENT TYPE AND NAME

bool IsINST(string INST) {
	
    bool isInst = false;
    it_type instrumentName1 = str2it_enum(uppercase(INST));
    
    switch (instrumentName1) {
        case HighGain : { isInst = true ; return true; }
        case LowGain : { isInst = true ; return true; }
        case Accelerometer : { isInst = true ; return true; }
    }
    return isInst;
}



// CHECKING ORIENTATION OF SIGNAL

bool IsORTN(string ORTN){
    
    bool isAlp = false;
    bool isNum = false;
    string ORT = "123ENZ";
	
    for (int i = 0 ; i < ORTN.length(); i++){
        if      (ORTN[i] == ORT[0]) isNum = true;
        else if (ORTN[i] == ORT[1]) isNum = true;
        else if (ORTN[i] == ORT[2]) isNum = true;
        else if (ORTN[i] == ORT[3]) isAlp = true;
        else if (ORTN[i] == ORT[4]) isAlp = true;
        else if (ORTN[i] == ORT[5]) isAlp = true;
        else return false;
    }
	
    if ((isAlp) && (isNum)) return false;
    else return true;
	
}

// OPENING INPUT FILE

void open_input(ifstream& input, string inputFileName) {
	
	input.open(inputFileName.c_str());
	
	cout << "Opening file:" << " " << inputFileName.c_str() << endl;
	
    if (input.fail()) {
        cout << "Error reading the file  " << inputFileName << endl;
        exit(EXIT_FAILURE);
    }
}


// PROCESSING HEADER INFORMATION

void processHeader (int EN, string EQID, string DAY, string Month_Name, string YEAR,
				   string TIME, string T_ZONE, string EQ_NAME, string LAT, string LON, 
				   string MAG_TYPE, string MAG, string E_CODE) {
	
    ofstream outputFile;
    string outputFileName = "nayeem.out" ;
    if (EN == 0)
		outputFile.open(outputFileName.c_str()); 
    else
		outputFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
	
	cout << "Header Read Correctly" << endl;
	outputFile << "# " << DAY << " " << Month_Name << " " << YEAR << "  "<< TIME << " " 
	<< T_ZONE << " " << MAG_TYPE << "  " << MAG << " " << EQ_NAME
	<< " [" <<EQID << "] " << " (" << LAT <<" , " << LON << " " << E_CODE << ")" << endl;
}

// PRINTING TO FILE

void PrintToFile(string marray[300], int T_Signal) {
    
    ofstream outputFile;
    string outputFileName = "nayeem.out" ;
    
    outputFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
	
    outputFile << T_Signal;
    outputFile << endl;
	
    for (int i = 0 ; i < 300; i++) { 
        if (marray[i].length() > 1) outputFile << marray[i] << endl;;
	}
}
		

// PRINTING ERROR TO A LOG FILE

void printError(int EN, int V_Entries, int IV_Entries, int T_Signal, 
                bool a, bool b, bool c, bool d, bool e, bool B1, bool B2, bool B3){
	
    ofstream outputErrorFile;
    string outputFileName = "nayeem.log" ;
    if (EN > 0)
		outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
    else
		outputErrorFile.open(outputFileName.c_str()); 
	
    if (B1 == false) {
        outputErrorFile << "Error # Wrong Date Format !" << endl;
        cout << "Error # Wrong Date Format !" << endl;
    }
    else if (B2 == false){
        outputErrorFile << "Error # Either Magnitude_Type or Magnitude Is Wrong !" << endl;
        cout << "Error # Either Magnitude_Type or Magnitude Is Wrong !" << endl;
    }
    else if (B3 == false) {
        outputErrorFile << "Error # Either Time Format or Time Zone Is Wrong !" << endl;
        cout << "Error # Either Time Format or Time Zone Is Wrong !" << endl;
    }
    else if (a == false) {
        outputErrorFile << "Entry # " << EN << " Invalid Network" << endl;
        cout << "Entry # " << EN << " Invalid Network" << endl;
    }
    else if (b == false) {
        outputErrorFile << "Entry # " << EN << " Invalid Station" << endl;
        cout << "Entry # " << EN << " Invalid Station" << endl;
    }
    else if (c == false) {
        outputErrorFile << "Entry # " << EN << " Invalid Band type" << endl;
        cout << "Entry # " << EN << " Invalid Band type" << endl;
    }
    else if (d == false) {
        outputErrorFile << "Entry # " << EN << " Invalid Instrument" << endl;
        cout << "Entry # " << EN << " Invalid Instrument" << endl;
    }
    else if (e == false) {
        outputErrorFile << "Entry # " << EN << " Invalid Orientation" << endl;
        cout << "Entry # " << EN << " Invalid Orientation" << endl;
    }
	
}


int main()
{
	int EN = 0;
    string line;
    string inputFileName;
	
	cout << "WELCOME" << endl;
    cout << "Please Provide Input File Name : "<< endl;
	
    cin >> inputFileName ;
    ifstream input;
    open_input(input, inputFileName);
	
	ofstream outputErrorFile;
    string outputFileName = "nayeem.log" ;
    outputErrorFile.open(outputFileName.c_str());
    cout << "Processing input ...." <<endl;
    outputErrorFile << "Processing input ...." <<endl;
    outputErrorFile.close();
    string marray[300];
    for (int i =0; i< 300; i++) marray[i] = "P" ;
    
    outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
    outputErrorFile << "Please provide the Input File Name : "<< endl;
    outputErrorFile.close();
	
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
	bss >> Event.LON >> Event.LAT >> Event.DEP >> Event.MAG_TYPE >> Event.MAG;
	
	
	string Month_Name, DAY, YEAR;
    int V_Entries = 0;
    int IV_Entries = 0;
    int T_Signal = 0;
    bool a, b, c, d, e, B1, B2, B3; 
	
    // CHECKING HEADER 
	
    if (IsDATE(Event.DATE, Event.DAY, Month_Name, Event.YEAR)) B1 = true;
    else B1 = false;
	
    if (IsMAG(Event.MAG_TYPE, Event.MAG)) B2 = true;
    else B2 = false;
	
    if (IsTIME (Event.TIME, Event.T_ZONE)) B3 = true;
    else B3 = false;
	
    if (B1 && B2 && B3) {
		
        outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
        outputErrorFile << "Header Read Correctly "<< endl;
        outputErrorFile.close();
		
        processHeader (EN, Event.EQID, Event.DAY, Month_Name, Event.YEAR, Event.TIME,
					 Event.T_ZONE, Event.EQ_NAME, Event.LAT, Event.LON, 
					 Event.MAG_TYPE, Event.MAG, Event.E_CODE);
		
    }
    else {
		
        outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);
        outputErrorFile << "Header Infromation Is Not Correct " << endl;
        outputErrorFile.close();
		
        printError(EN, V_Entries, IV_Entries, T_Signal, a, b, c, d, e, B1, B2, B3);
		
        exit(EXIT_FAILURE);
        
    }
	
    Entries Signal;
    EN = 1;
    while (getline(input, line) && !line.empty()) {
        
        istringstream n (line);
        n >> Signal.NCODE;
        n >> Signal.STAN;
        n >> Signal.BAND;
        n >> Signal.INST;
        n >> Signal.ORTN;
		
        if (IsNCODE(Signal.NCODE)) {
            Signal.NCODE = uppercase(Signal.NCODE);
            a = true;
        }
        else a = false;
		
        if (IsSTAN(Signal.STAN)) {
            Signal.STAN = uppercase(Signal.STAN);
            b = true;
        }
        else b = false;
		
        if (IsBAND(Signal.BAND)) {
            Signal.BAND = Signal.BAND[0];
            c = true;
        }
        else c = false;
		
        if (IsINST(Signal.INST)) {
            Signal.INST = Signal.INST[0];
            d = true;
        }
        else d = false;
		
        if (IsORTN(Signal.ORTN)) {
            Signal.ORTN = uppercase(Signal.ORTN);
            e = true;
        }
        else e = false;
        
        if ((a) && (b) && (c) && (d) && (e)) {
			
            string or_1 = Signal.ORTN; 
            for (int i = 0 ; i < or_1.length(); i++) {
				
                marray[T_Signal] = Event.EQID + "." + Signal.NCODE + "." + Signal.STAN + "." 
				+ uppercase(Signal.BAND) + uppercase(Signal.INST) + or_1[i] ;
                T_Signal += 1;
				
            }
			
			V_Entries ++;
        }
        else {
            printError(EN, V_Entries, IV_Entries, T_Signal, 
					   a, b, c, d, e, B1, B2, B3);
            IV_Entries ++;
        }
		
        EN++;
    }
	
	PrintToFile(marray, T_Signal);
	
	outputErrorFile.open(outputFileName.c_str(), ofstream::out | ofstream::app);

    outputErrorFile << "Total Invalid_Entries Ignored = " << IV_Entries << endl;
	outputErrorFile << "Total Valid_Entries Read = "   << V_Entries  << endl;
    outputErrorFile << "Total_Signals Produced = "    << T_Signal    << endl;
    outputErrorFile << "Finished " << endl;
    outputErrorFile.close();
	
    cout << "Total Invalid_Entries Ignored = " << IV_Entries << endl;
	cout << "Total Valid_Entries Read = "   << V_Entries   << endl;
    cout << "Total_Signals Produced = "    << T_Signal    << endl;
    cout << "Finished" << endl;
}	


