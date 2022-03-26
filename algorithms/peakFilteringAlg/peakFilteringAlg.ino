#include <PeakDetection.h> // import lib
// GitHub https://github.com/leandcesar/PeakDetection

PeakDetection peakDetection; // create PeakDetection object

float data = 0; // data from Arduino sensor, set to zero as placeholder
int lag = 0; // parameter that determines how much your data will be smoothed (the more stationary your data is, the more lags you should include)
int threshold = 0; // number of standard deviations from the moving mean above which the algorithm will classify a new datapoint as being a signal (the z-score is calculated at this point), so this parameter should be set based on how many signals you expect. 
int influence = 0; // z-score at which the algorithm signals (this parameter determines the influence of signals on the algorithm's detection threshold)

void setup() 
{
  Serial.begin(9600); // set the data rate for the Serial communication
  
  // UNCOMMENT when using Arduino
  // pinMode(A0, INPUT); // analog pin used to connect the sensor
  
  lag = 18;
  threshold = 1; 
  influence = 0.6;
  peakDetection.begin(lag, threshold, influence); // sets the lag, threshold and influence

  /* ASME NOTES 03-26-2022: 
   * YOUR CODE GOES BELOW THIS LINE FOR SETUP CODE
   */

   // Code goes below this line...

}

void loop() 
{
  // UNCOMMENT OUT WHEN USING WITH ARDUINO
  double data = (double)analogRead(A0)/512-1; // reads the value of the sensor and converts to a range between -1 and 1

  // COMMENT OUT WHEN USING ARDUINO
 // data = rand(100);
  
  peakDetection.add(data); // adds a new data point
  int peak = peakDetection.getPeak(); // returns 0, 1 or -1
  double filtered = peakDetection.getFilt(); // moving average
  Serial.print(data); // print data
  Serial.print(",");
  Serial.print(peak); // print peak status
  Serial.print(",");
  Serial.println(filtered); // print moving average

  /* ASME NOTES 03-26-2022: 
   * YOUR CODE GOES BELOW THIS LINE FOR LOOP CODE
   * DO NOT CHANGE THE CODE ABOVE WITHOUT DISUCSSING WITH ME PLEASE. 
   */

   // Code goes below this line...
}
