#include <cassert>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

/**********************************************************************
 * Prompt user for desired number of sides for dice
 ***********************************************************************/
int diceSidesPrompt()
{
   int diceSides;
   cout << "\tNumber of Sides: ";
   cin >> diceSides;
   return diceSides;
}

/**********************************************************************
 * Determine the number of dice to be used
 ***********************************************************************/
int numDicePrompt()
{
   int numDice;
   cout << "\tNumber of Dice: ";
   cin >> numDice;
   return numDice;
}

/**********************************************************************
 * Select between random scientific sampling or dice functionality 
 ***********************************************************************/
char cODPrompt()
{
   char cOD;
   cout << "Welcome to Dice Generator 1.0\n";
    cout << "Would you like to perform scientific sampling(s) or"
         <<" dynamic(d) dice: ";
    cin >> cOD;
    return cOD;
}

/**********************************************************************
 * If sampling, determine sample size
 ***********************************************************************/
int promptSampleSize()
{
   int sample;
   cout << "\tSample Size: ";
   cin >> sample;
   return sample;
}

/**********************************************************************
 * Determine number of samples to be taken
 ***********************************************************************/
int promptNumSamples()
{
   int numSamples;
   cout << "\tNumber of Samples: ";
   cin >> numSamples;
   return numSamples;
}

/**********************************************************************
 * reset array values to 0
 ***********************************************************************/
void setZero(int dDice[], int zero)
{
   for(int i = 0; i <= zero; i++)
   {
      dDice[i] = 0;
   }
}

/**********************************************************************
 * determine random values to be sampled
 ***********************************************************************/
int computeSampling(int argc, char **argv, int dDice[])
{
   srand(argc == 1 ? time(NULL) : (int)argv[1][1]);
   int sample = promptSampleSize();
   int randomNumber;
         int numSamples = promptNumSamples();
         int x = 0;
         while(x < numSamples)
         {
            randomNumber = ((rand() % sample)+1); 
               if(dDice[randomNumber] == 0)
               {
                  dDice[randomNumber]++;
                  x++;
               }
         }
         //cout << "Selected samples are:\n";
         for (int y = 0; y <= 1000; y++)
          {
             if (dDice[y] > 0)
             {
                cout << "\t" << y << endl;
             }
          }
          setZero(dDice, 1001);  
}

/**********************************************************************
 * determine the random values of the dice
 ***********************************************************************/
int computeDice(int argc, char **argv, int dDice[])
{
   int diceSides = diceSidesPrompt();
         int numDice = numDicePrompt();
         
          for (int i = 1; i <= numDice; i++)
         {
            dDice[((rand() % diceSides)+1)] += 1;
         }
          for (int j = 0; j <= 1000; j++)
          {
             if (dDice[j] > 0)
             {
                cout << dDice[j] << " " << j << "'s\n";
             }
          }
          setZero(dDice, 1001);
}
/**********************************************************************
 * sampling or random dice generator
 ***********************************************************************/
int main(int argc, char **argv)
{

   char play = 'y';
   int numDice = 0;
   int diceSides = 0;
   int randomNumber = 0;

   
   char cOD = cODPrompt();
   

   while (play == 'y')
   {
      
      
      int dDice[1001];
      setZero(dDice, 1001);
   
      // this code is necessary to set up the random number generator.
      srand(argc == 1 ? time(NULL) : (int)argv[1][1]);
  
      if(cOD == 's')
      {
         computeSampling(argc, argv, dDice);
      }
      else
      {
         computeDice(argc, argv, dDice);
         
      }
   }

    
   return 0;
}
