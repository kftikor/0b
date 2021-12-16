#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

vector<string> split(const string& s);

int main(int argc, char* argv[])
{
    list <string> listlines;
    vector <string> veclines;
    string buff;
    ifstream txtFile;
    map <string, double> data;


    map <string, double> ::iterator it;

    txtFile.open(argv[1]);

    while (getline(txtFile, buff))
    {
        listlines.push_back(buff);
    }

    string alllines = "";

    for (string line : listlines) {
        alllines += line;
        alllines += " ";
    }

    alllines += "\n";

    for (int i = 0; alllines[i] != '\n'; i++) {
        if (isalnum(alllines[i]) == false) alllines[i] = ' ';
    }

    veclines = split(alllines);

    for (string word : veclines) {
        data[word]++;
    }

    ofstream out;
    out.open(argv[2]);

    it = max_element(data.begin(), data.end());
    for (int i = 0; data.size() != 0; it = max_element(data.begin(), data.end()), i++) {
        out << it->first << "\t" << it->second << "\t" << it->second * 100 / veclines.size() << '%' << endl;
        data.erase(it);
    }
    out.close();
    txtFile.close();
    cout << argv[1] << ' ' << argv[2];

    return 0;
}

vector<string> split(const string& s)
{
    vector<string> res;
    istringstream iss(s);
    std::copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(res));
    return res;
}