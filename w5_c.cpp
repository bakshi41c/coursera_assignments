//
// Created by Shubham Bakshi on 17/06/2018.
//

#include <iostream>
#include <string>
#include <vector>

using std::string;

void print2dVec(std::vector<std::vector<int>>  grid) {

    std::cout << "Printing " << grid.size() << "x" << grid[0].size() << ":" << std::endl;
    for ( std::vector<std::vector<int>>::size_type i = 0; i < grid.size(); i++ )
    {
        for ( std::vector<int>::size_type j = 0; j < grid[i].size(); j++ )
        {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int edit_distance(const string &str1, const string &str2) {

    std::vector<std::vector<int>> ed;
//
//    std::cout << "Str1: " << str1.size() << std::endl;
//    std::cout << "Str2: " << str2.size() << std::endl;

    for (int i = 0; i <= str1.size(); i++){
        ed.push_back({});
        for (int j = 0; j <= str2.size(); j++){

            // The first row and column are for empty strings so can be hardcoded
            // https://www.youtube.com/watch?v=We3YDTzNXEk

            if (i == 0) {
                ed[i].push_back(j);
                continue;
            }

            if (j == 0) {
                ed[i].push_back(i);
                continue;
            }

            int min =100000;

            if (i-1 >= 0) {
                if ((ed[i-1][j] + 1) < min) {
                    min = ed[i-1][j] + 1;
                }
            }

            if (j-1 >= 0) {
                if ((ed[i][j-1] + 1) < min) {
                    min = ed[i][j-1] + 1;
                }
            }

            if (i-1 >= 0 && j-1 >= 0) {
                bool isSame = str1[i-1] == str2[j-1];
//                std::cout <<  isSame << std::endl;
                if (isSame) {
                    if ((ed[i-1][j-1]) < min) {
                        min = ed[i-1][j-1];
                    }
                } else {
                    if ((ed[i-1][j-1] + 1) < min) {
                        min = ed[i-1][j-1] + 1;
                    }
                }
            }

//            std::cout << i << "," << j << std::endl;
//            std::cout << ed.at(i).size() << std::endl;
            ed.at(i).push_back(min);
        }
    }

//    print2dVec(ed);
    return ed[str1.size()][str2.size()];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
