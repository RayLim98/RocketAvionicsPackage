#include "armed.h"

int Armed::getData(){
  //assigns rawData to getData(), now accessible to public.
  return rawData;
}

void Armed::setData(int adcData){
  //assuming we're using something like an arduino with bluetooth to communicate to the software
  //adcData comes from the raw input of the board
  rawData = adcData;
}

void Armed::entry(){
  //Send "armed" signal   
  setPhase(LOOP);
     
}

void Armed::loop() {
  //Will idle until change in state; either through a command or a physical button etc  
  bool launchCommand = false;

  //while loop will continue to loop uuntil someone sends some sort of command
  while(!launchCommand){

    int data = getData();

    if(data == whateverLaunchCommandValue){
      flagLaunch = 10;
      launchCommand = true;
    }
    else if(data == goesBackStateCommandValue){
      flagLaunch = 20;
      launchCommand = false;
    }
    else{
      //keeps looping until above conditions are met
    }
  } 
  setPhase(EXIT);
}

    
void Armed::exit() {
  //Lunched signal received
  //Initiate state change Armed -> Lunched

  //Command signal is dependant on the LOOP case above 
  //and will run one of two state change function below
  //if flag = 1, changeState(Armed,Launch); will run if lunchReady signal is received 
  //if flag = 0, changeState(Armed,Unarmed); will run if lunchCancled signal is received

  if(flagLaunch = 10){
    //state change to launch here
  }
  else if(flagLaunch = 20){
    //state change to unarmed here
  }
}
