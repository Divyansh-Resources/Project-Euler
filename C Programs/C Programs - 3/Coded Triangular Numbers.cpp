#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const int MAX_N = 1000;
    vector <int> is_triangular(MAX_N, false);
    for(int i = 1; i*(i + 1) < 2*MAX_N; i++)
        is_triangular[(i*(i + 1))/2] = true;

    ifstream file;
    file.open("F:\\Project Euler\\Coded Triangular Numbers\\Input.txt");

    if(!file)
    {
        cout << "Could not open file";
        exit(1);
    }

    string text;
    while(file >> text) {cout << "Read File\n";}

    int triangular_words = 0;
    for(int i = 0; i < text.size(); i++)
    {
        if(text[i] == ',')
        {
            cout << "\n";
            continue;
        }

        int word = 0; string W; //Control reaches here on "
        int j;
        for(j = i + 1; text[j] != '\"'; j++)
            W += text[j], word += (text[j] - 'A' + 1);

        cout << W << " " << word;

        triangular_words += is_triangular[word]; cout << " " << triangular_words;

        i = j;
    }

    cout << "\nThere are " << triangular_words << " triangular words here.\n";

    file.close();
    return 0;
}
