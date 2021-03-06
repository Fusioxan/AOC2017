#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  string lvInput;
  int lvCaptcha = 0;

  if(argc < 2)
  {
    cout << "Please provide input:\t";
    cin >> lvInput;
  }
  else
  {
    lvInput = argv[1];
  }

  int lvCompareInterval = 1;
  int lvInputLength = lvInput.length();

  for(int i = 0; i < lvInput.length(); i++)
  {
    int lvCurrentNumber = lvInput[i] - '0';
    int lvCompareNumber = 0;

    if(i + lvCompareInterval >= lvInputLength)
      lvCompareNumber = lvInput[i + lvCompareInterval - lvInputLength] - '0';
    else
      lvCompareNumber = lvInput[i + lvCompareInterval] - '0';

    if(lvCurrentNumber == lvCompareNumber)
      lvCaptcha += lvCurrentNumber;
  }

  cout << "Your captcha is " << lvCaptcha << endl;


  return 0;
}
