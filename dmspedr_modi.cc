#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(){

	string textline;
	int rec_no, EDR_no, Sat_ID, date,uttime;
	double geo_lat, geo_lon, apex_lat, apex_lon, apex_lt, sat_alt;
	double P_Den,HorIonDen,VerIonDen,DMIon;
	double O_den,tot_H_den,iontemp,ramidv,rpad_tot_ionden;
	int sweeptime,lionflag,aqflag;
	double e_den,e_temp,sat_pot,PEvalue;
	int epsweep,epaqflag;

	ifstream infile("PS.CKGWC_SC.U_DI.A_GP.SIES3-F16-R99990-B9999090-APGA_AR.GLOBAL_DD.20130301_TP.000001-235959_DF.EDR");

	ofstream outfile("record.txt");
	ofstream outfile1("ephemeris.txt");
	ofstream outfile2("plden.txt");
	ofstream outfile3("Hionden.txt");
	ofstream outfile4("Vionden.txt");
	ofstream outfile5("EPAdata.txt");
	ofstream outfile6("RPAdata.txt");
	ofstream outfile7("DMionden.txt");
	int count = 0,i=0;
	while(true){
		getline(infile, textline); 		
		if(infile.eof()) break;
		if(textline.find("RECORD")!=string::npos){
			infile>>rec_no>>EDR_no>>Sat_ID>>date>>uttime;
			//cout<<rec_no<<"\t"<<EDR_no<<"\t"<<Sat_ID<<"\t"<<date<<"\t"<<uttime<<endl;
			outfile<<rec_no<<"\t"<<EDR_no<<"\t"<<Sat_ID<<"\t"<<date<<"\t"<<uttime<<endl;

		}
		if(textline.find("EPHEMERIS")!=string::npos){
			for(int i=0;i<3;i++){
				infile>>geo_lat>>geo_lon>>apex_lat>>apex_lon>>apex_lt>>sat_alt;
				//cout<<geo_lat<<"\t"<<geo_lon<<"\t"<<apex_lat<<"\t"<<apex_lon<<"\t"<<apex_lt<<"\t"<<sat_alt<<endl;
				outfile1<<geo_lat<<"\t"<<geo_lon<<"\t"<<apex_lat<<"\t"<<apex_lon<<"\t"<<apex_lt<<"\t"<<sat_alt<<endl;
			}
		}
		if(textline.find("PRIMARY")!=string::npos){ 
			for(int i=0;i<60;i++){
				infile>>P_Den;
				//cout<<P_Den<<endl;	
				outfile2<<P_Den<<endl;
			}
		}
		if(textline.find("HORIZONTAL")!=string::npos){
			for(int i=0;i<60;i++){
				infile>>HorIonDen;
				//cout<<HorIonDen<<endl;
				outfile3<<HorIonDen<<endl;
			}
		}
		if(textline.find("VERTICAL")!=string::npos){
			for(int i=0;i<60;i++){
				infile>>VerIonDen;
				//cout<<VerIonDen<<endl;
				outfile4<<VerIonDen<<endl;
			}
	  }
		if(textline.find("EP SWEEP ANALYSES")!=string::npos){
			for(int i=0;i<15;i++){
				infile>>epsweep>>e_den>>e_temp>>sat_pot>>aqflag>>PEvalue;
				outfile5<<epsweep<<"\t"<<e_den<<"\t"<<e_temp<<"\t"<<sat_pot<<"\t"<<epaqflag<<"\t"<<PEvalue<<endl;
			}
		}
		if(textline.find("RPA SWEEP")!=string::npos){
			for(int i=0;i<15;i++){
				infile>>sweeptime>>O_den>>tot_H_den>>lionflag>>iontemp>>ramidv>>aqflag>>rpad_tot_ionden;
				outfile6<<sweeptime<<"\t"<<O_den<<"\t"<<tot_H_den<<"\t"<<lionflag<<"\t"<<iontemp<<"\t"<<ramidv<<"\t"<<aqflag<<"\t"<<rpad_tot_ionden<<endl;
			}
		}
	  if(textline.find("DM ION DENSITY")!=string::npos){
		    for(int i=0;i<60;i++){
			    infile>>DMIon;
			    //cout<<DMIon<<endl;
					outfile7<<DMIon<<endl;
		    }
	  }
		//outfile2<<P_Den<<"\t"<<HorIonDen<<"\t"<<DMIon<<endl;
  }  
	outfile.close();outfile1.close();	outfile2.close();
	outfile3.close(); outfile4.close(); outfile5.close();
	outfile6.close();outfile7.close();
  infile.close();

//Cobmining individual files.
	ifstream infile11("plden.txt");
	ifstream infile21("Hionden.txt");
	ifstream infile31("Vionden.txt");
	ifstream infile41("DMionden.txt");
	ifstream infile51("EPAdata.txt");
	ifstream infile61("RPAdata.txt");
	ofstream outfile11("density.txt");
	ofstream outfile21("EPA_RPAdata.txt");
	double plden,hionden,vionden,DMionden;	
	while(true){
		infile11>>plden;
		infile21>>hionden;
		infile31>>vionden;
		infile41>>DMionden;
		if(infile11.eof() & infile21.eof() & infile31.eof() & infile41.eof()) break;
		outfile11<<plden<<"\t"<<hionden<<"\t"<<vionden<<"\t"<<DMionden<<endl;
	}
	while(true){
		infile51>>epsweep>>e_den>>e_temp>>sat_pot>>aqflag>>PEvalue;
		infile61>>sweeptime>>O_den>>tot_H_den>>lionflag>>iontemp>>ramidv>>aqflag>>rpad_tot_ionden;
		if(infile51.eof() & infile61.eof()) break;
		outfile21<<epsweep<<"\t"<<e_den<<"\t"<<e_temp<<"\t"<<sat_pot<<"\t"<<epaqflag<<"\t"<<PEvalue<<"\t"<<sweeptime<<"\t"<<O_den<<"\t"<<tot_H_den<<"\t"<<lionflag<<"\t"<<iontemp<<"\t"<<ramidv<<"\t"<<aqflag<<"\t"<<rpad_tot_ionden<<endl;
	}

	infile11.close();infile21.close();infile31.close();
	infile41.close();infile51.close();infile61.close();
	outfile11.close(); outfile21.close();
	remove("plden.txt"); remove("Hionden.txt"); remove("Vionden.txt");
	remove("DMionden.txt"); remove("EPAdata.txt"); remove("RPAdata.txt");
  return 0;
}

