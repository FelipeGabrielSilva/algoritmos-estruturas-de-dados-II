#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main()
{
    ifstream File;
    string line = "";

    File.open("venda.csv");
    
    getline(File, line);
    getline(File, line);

    cout << line << endl;

    return 0;
}