#include <iostream>
#include <fstream>
#include<string>
#include<string.h>

const int POSLEN = 20;
const int LINELEN = 120;

int positions[POSLEN];

int totStrings = 0;

void computeLengths()
{
  std::ifstream in;
  char line[LINELEN];
  in.open("t.txt");
     positions[0] = 0; 
  while(in.getline(line, LINELEN))
  {
    positions[totStrings] = strlen(line)+1;
    std::cout << "number of chars = " << positions[totStrings++] << std::endl;
    line[strlen(line)] = '\0';
    std::cout << "string = [" << line << "]" << std::endl;
  }
  in.close();
}

void directAccess()
{
   int i, j, currentPos = positions[0];
   char line[LINELEN];
   std::ifstream in;
   in.open("t.txt");
   in.seekg(currentPos);
   for(i = 1; i < totStrings-1; i++)
   {
     in.getline(line, LINELEN);
     line[strlen(line)] = '\0'; 
     std::cout << "this string [" << line << "]" << std::endl;
     for(j = i+1; j < totStrings; j++)  
     {	
       in.getline(line, LINELEN);
       line[strlen(line)] = '\0';
       std::cout << "  compared with [" << line << "]" << std::endl;
     }
     currentPos += positions[i];
     in.seekg(currentPos);
   }
}

void showPositionsArray()
{
  int i;
  for(i = 0; i < totStrings; i++)
  {
    std::cout << " line " << i << " position " << positions[i] << std::endl;
  }
}
  
// int main()
// {	
//   computeLengths();
//   showPositionsArray();
//   directAccess();
//   return 0;
// }
