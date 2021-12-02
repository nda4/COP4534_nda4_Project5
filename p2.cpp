
#include "p2.hpp"

const int POSLEN = 20;
const int LINELEN = 120;
int positions[POSLEN];
int totStrings = 0;

p2::p2(){
    this->lengths = computeLengths("multiStrings.txt");
    // std::cout << "\t";
    std::cout << LCM("123456789012345", "123456789012345");
    // directAccess("multiStrings.txt");
}

std::vector<int> p2::computeLengths(std::string file){
    std::vector<int> len;    
    std::ifstream in;
    char line[LINELEN];
    in.open(file);
        positions[0] = 0; 
    while(in.getline(line, LINELEN))
    {
        positions[totStrings] = strlen(line)+1;
        len.push_back(positions[totStrings++]);
        line[strlen(line)] = '\0';
        // std::cout << "string = [" << line << "]" << std::endl;
    }
    in.close();
    return len;
}

void p2::directAccess(std::string file)
{
    std::string temp1, temp2;
    int i, j, currentPos = positions[0];
    char line[LINELEN];
    std::ifstream in;
    in.open(file);
    in.seekg(currentPos);
    for(i = 1; i < totStrings-1; i++)
    {
        in.getline(line, LINELEN);
        line[strlen(line)] = '\0'; 
        temp1 = line;
        for(j = i+1; j < totStrings; j++)  
        {	
            in.getline(line, LINELEN);
            line[strlen(line)] = '\0';
            temp2 = line;
            std::cout << temp1 << "\t" << temp2 << std::endl;
            std::cout << calculateSimilarity(temp1, temp2) << "\t";
        }
        std::cout << std::endl;
        currentPos += positions[i];
        in.seekg(currentPos);
    }
}



void p2::showPositionsArray()
{
  int i;
  for(i = 0; i < totStrings; i++)
  {
    std::cout << " line " << i << " position " << positions[i] << std::endl;
  }
}

char p2::calculateSimilarity(std::string s1, std::string s2){
    float greater, lower;
    if(s1.length() > s2.length()){
        greater = (float)s1.length();
        lower = (float)s2.length();
    }
    else{
        greater = (float)s2.length();
        lower = (float)s1.length();
    }
    if(lower / greater * 100 >= 90 && (float)LCM(s1, s2) / lower * 100 >= 90){
        return 'H';
    }
    else if(lower / greater * 100 >= 80 && (float)LCM(s1, s2) / lower * 100 >= 80){
        return 'M';
    }
    else if(lower / greater * 100 >= 60 && (float)LCM(s1, s2) / lower * 100 >= 50){
        return 'L';
    }
    else
        return 'D';
}

int p2::LCM(std::string s1, std::string s2){
    int **c = new int*[2];
    std::string greatest, lowest;
    int lowLen, greLen, temp = 0;

    if(s1.length() > s2.length()){
        lowest = s2;
        lowLen = s2.length();
        greLen = s1.length();
        greatest = s1;
    }
    else if(s2.length() > s1.length()){
        lowest = s1;
        lowLen = s1.length();
        greLen = s2.length();
        greatest = s2;
    }
    else if(s2.length() == s2.length()){
        lowest = s1;
        lowLen = s2.length() - 1;
        greLen = s1.length() - 1;
        greatest = s2;
        temp = 1;
    }
    c[0] = new int[greLen + 1];
    c[1] = new int[greLen + 1];

    for (int i = 0; i <= greLen; i++)
        c[0][i] = 0;
    for (int i = 0; i <= lowLen; i++)
        c[1][i] = 0;

    for(int lol = 1; lol <= greLen; lol++){
        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= lowLen; j++)
            {
                // std::cout << *c[5] << "\t";
                // std::cout <<"\nTEST\ti = " << i << "\nj = " << j << std::endl;
                // std::cout << greatest.at(lol - 1) << "\t" << lowest.at(j-1) << std::endl;
                if (greatest.at(lol - 1) == lowest.at(j - 1))
                {
                    c[i][j] = c[i - 1][j - 1] + 1;
                }
                else
                {
                    if (c[i - 1][j] >= c[i][j - 1]){
                        // c[i][j] = c[i - 1][j];
                        // std::cout << "\t c = " << c[i][j] << "\tc[i - 1][j] " << c[i - 1][j] << std::endl;
                    }
                    else{
                        // c[i][j] = c[i][j - 1];
                    }
                }
            }
        }
        c[0] = c[1];
    }
    // std::cout << std::endl;
    // for (int i = 0; i < 2; i++){
    //     for (int j = 0; j < lowest.length(); j++)
    //         std::cout << c[i][j] << "\t";
    //     std::cout << std::endl;
    // }
    int ret = c[1][lowLen] + temp;
    // delete c[0];

    return ret;
}