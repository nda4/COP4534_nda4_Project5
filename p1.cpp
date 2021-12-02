#include <iostream>
#include <fstream>

class p1
{
public:
    std::string s1, s2;
    int **c;
    void runOne()
    {
        std::ifstream is;
        is.open("twoStrings.txt");
        
        is >> this->s1;
        is >> this->s2;
        
        // std::cout << s1 << std::endl << s2;
        int m = s1.length();
        int n = s2.length();
        this->c = new int* [m+1];
        for(int i = 0; i <= m; i++){
            this->c[i] = new int[n];
        }
        for (int i = 0; i <= m; i++)
            this->c[i][0] = 0;
        for (int i = 0; i <= n; i++)
            this->c[0][i] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1.at(i - 1) == s2.at(j - 1))
                {
                    this->c[i][j] = this->c[i - 1][j - 1] + 1;
                }
                else
                {
                    this->c[i][j] = 0;
                    if (this->c[i - 1][j] >= this->c[i][j - 1]){
                        this->c[i][j] = this->c[i - 1][j];
                        // std::cout << "\t this->c = " << this->c[i][j] << "\tc[i - 1][j] " << this->c[i - 1][j] << std::endl;
                    }
                    else{
                        this->c[i][j] = this->c[i][j - 1];
                    }
                }
            }
        }
        std::cout << std::endl << "LCS size = " << c[m][n] << std::endl;
        std::cout << "LCS = ";
        printLCS(m, n);
        std::cout << std::endl << std::endl;

                                            //Prints out grid...written just for major debugging problems smh
                                            // std::cout << "\t";
                                            // for(int i = 1; i <= m; i++)
                                            //     std::cout << s2.at(i - 1) << '\t';
                                            // std::cout << std::endl;
                                            // for(int i = 1; i <= m; i++){
                                            //     for(int j = 0; j <= n; j++){
                                            //         if(j == 0)
                                            //             std::cout << s1.at(i-1) << '\t';
                                            //         else
                                            //             std::cout << c[i][j] << '\t'; 
                                            //     }
                                            //     std::cout << std::endl;
                                            // }

                                            // for (int i = 0; i <= m; i++)
                                            //     for (int j = 0; j <= n; j++)
                                            //         std::cout << this->c[i][j];
                                            // std::cout << std::endl;
                                            // for(int i = 1; i <= m; i++){
                                            //     std::cout << s1.at(i - 1) << "\t" << s2.at(i - 1) << std::endl;
                                            // }
                                        

        //deletes disgusting allocated memory, not tryna have leaks bro
            for(int i = 0; i < m; i++){
                delete[] c[i];
            }
            delete[] c;
       
    }




    void printLCS(int i, int j){
        if(i > 0 && j > 0){
            if(this->s1.at(i - 1) == this->s2.at(j - 1)){
                printLCS(i - 1, j - 1);
                std::cout << this->s1.at(i - 1);
            }
            else if(this->c[i-1][j] >= this->c[i][j-1])
                printLCS(i-1, j);
            else
                printLCS(i, j-1);
    }
    }

};