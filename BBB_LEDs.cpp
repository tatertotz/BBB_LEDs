/*
 * BBB_LEDs.cpp
 *
 *  Created on: Dec 13, 2015
 *      Author: tati
 */
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define LED0_PATH "/sys/class/leds/beaglebone:green:usr0"
#define LED1_PATH "/sys/class/leds/beaglebone:green:usr1"
#define LED2_PATH "/sys/class/leds/beaglebone:green:usr2"
#define LED3_PATH "/sys/class/leds/beaglebone:green:usr3"

void removeTrigger()
{
   // remove the trigger from the LED
   std::fstream fs;
   fs.open( LED0_PATH "/trigger", std::fstream::out);
   fs << "none";
   fs.close();
}

int main(int argc, char* argv[])
{
   if(argc!=2)
   {
	   cout << "Requires one parameter: on, off, flash, heartbeat, status, offall, or flashall" << endl;
	   cout << "e.g. ./BBBLED flash" << endl;
   }

   string cmd(argv[1]);
   std::fstream fs;
   cout << "Starting the LED program" << endl;

   if(cmd=="on")
   {
	   removeTrigger();
	   fs.open (LED0_PATH "/brightness", std::fstream::out);
	   fs << "1";
	   fs.close();
   }
   else if (cmd=="off")
   {
	   removeTrigger();
	   fs.open (LED0_PATH "/brightness", std::fstream::out);
	   fs << "0";
	   fs.close();
   }
   else if (cmd=="flash")
   {
	   fs.open (LED0_PATH "/trigger", std::fstream::out);
	   fs << "timer";
	   fs.close();
	   fs.open (LED0_PATH "/delay_on", std::fstream::out);
	   fs << "50";
	   fs.close();
	   fs.open (LED0_PATH "/delay_off", std::fstream::out);
	   fs << "50";
	   fs.close();
   }
   else if (cmd=="heartbeat")
   {
	   fs.open (LED0_PATH "/trigger", std::fstream::out);
	   fs << "heartbeat";
	   fs.close();
   }
   else if (cmd=="status")
   {
	   // display the current trigger details
	   fs.open( LED0_PATH "/trigger", std::fstream::in);
	   string line;
	   while(getline(fs,line)) cout << line;
	   fs.close();
   }
   else if(cmd=="offall")
   {
	   removeTrigger();
	   fs.open (LED0_PATH "/brightness", std::fstream::out);
	   fs << "0";
	   fs.close();

	   fs.open( LED1_PATH "/trigger", std::fstream::out);
	   fs << "none";
	   fs.close();
	   fs.open (LED1_PATH "/brightness", std::fstream::out);
	   fs << "0";
	   fs.close();

	   fs.open( LED2_PATH "/trigger", std::fstream::out);
	   fs << "none";
	   fs.close();
	   fs.open (LED2_PATH "/brightness", std::fstream::out);
	   fs << "0";
	   fs.close();

	   fs.open( LED3_PATH "/trigger", std::fstream::out);
	   fs << "none";
	   fs.close();
	   fs.open (LED3_PATH "/brightness", std::fstream::out);
	   fs << "0";
	   fs.close();

   }
   else if (cmd=="flashall")
      {
   	   fs.open (LED0_PATH "/trigger", std::fstream::out);
   	   fs << "timer";
   	   fs.close();
   	   fs.open (LED0_PATH "/delay_on", std::fstream::out);
   	   fs << "500";
   	   fs.close();
   	   fs.open (LED0_PATH "/delay_off", std::fstream::out);
   	   fs << "500";
   	   fs.close();

   	   fs.open (LED1_PATH "/trigger", std::fstream::out);
  	   fs << "timer";
   	   fs.close();
  	   fs.open (LED1_PATH "/delay_on", std::fstream::out);
  	   fs << "500";
   	   fs.close();
   	   fs.open (LED1_PATH "/delay_off", std::fstream::out);
   	   fs << "500";
   	   fs.close();

   	   fs.open (LED2_PATH "/trigger", std::fstream::out);
   	   fs << "timer";
   	   fs.close();
   	   fs.open (LED2_PATH "/delay_on", std::fstream::out);
   	   fs << "500";
   	   fs.close();
   	   fs.open (LED2_PATH "/delay_off", std::fstream::out);
   	   fs << "500";
   	   fs.close();

   	   fs.open (LED3_PATH "/trigger", std::fstream::out);
   	   fs << "timer";
   	   fs.close();
   	   fs.open (LED3_PATH "/delay_on", std::fstream::out);
   	   fs << "500";
   	   fs.close();
   	   fs.open (LED3_PATH "/delay_off", std::fstream::out);
       fs << "500";
   	   fs.close();

      }
   else
   {
	   cout << "Invalid command" << endl;
   }
   	   cout << "Finished the LED program" << endl;
   return 0;
}




