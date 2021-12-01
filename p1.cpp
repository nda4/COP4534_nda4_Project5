#include <iostream>
#include <fstream>

class p1
{
public:
    void runOne()
    {
        std::ifstream is;
        is.open("twoStrings.txt");
        std::string s1, s2;
        is >> s1;
        is >> s2;
        // std::cout << s1 << std::endl << s2;
        int m = s1.length();
        int n = s2.length();
        int c[m][n];
        for (int i = 0; i <= m; i++)
            c[i][0] = 0;
        for (int i = 0; i <= n; i++)
            c[0][i] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1.at(i - 1) == s2.at(j - 1))
                {
                    c[i][j] = c[i - 1][j - 1] + 1;
                }
                else
                {
                    // c[i][j] = 0;
                    if (c[i - 1][j] >= c[i][j - 1]){
                        c[i][j] = c[i - 1][j];
                        // std::cout << "\t c = " << c[i][j] << "\tc[i - 1][j] " << c[i - 1][j] << std::endl;
                    }
                    else{
                        c[i][j] = c[i][j - 1];
                    }
                }
            }
        }

        //Prints out the result
        for (int i = 0; i <= m + 1; i++)
        {
            if (i == 0 || i == 1)
                std::cout << "\t";
            else if (i > 1)
                std::cout << s1.at(i - 2) << "\t";
            for (int j = 1; j <= n; j++)
            {
                if (i == 0)
                {
                    if (j == 0)
                    {
                        std::cout << "\t";
                    }
                    else if (j < s2.length() + 1)
                    {
                        std::cout << s2.at(j - 1) << "\t";
                    }
                }
                else if (i > 1)
                {
                    std::cout << c[i - 1][j] << "\t";
                }
            }
            std::cout << std::endl;
        }
        // for (int i = 0; i <= m; i++)
        //     for (int j = 0; j <= n; j++)
        //         std::cout << c[i][j];
    }
};