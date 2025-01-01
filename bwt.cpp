#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto customCompare = [](const std::string& a, const std::string& b) {
    for (std::size_t i = 0; i < std::min(a.size(), b.size()); ++i)
    {
        if (a[i] < b[i])
        {
            return true;
        }
        else if (a[i] > b[i])
        {
            return false;
        }
        // If characters are equal, continue to the next character
    }
    // If all compared characters are equal, the shorter string comes first
    return a.size() < b.size();
};

string BWT(const string& text) {
    string result = "";

    // vector<vector<char>> M(textDollarAdded.length(), vector<char>(textDollarAdded.length()));
    vector<string> M(text.length());

    M[0] = "$" + text;
    //cout << M[0] << endl;

    M[0].pop_back();
    //cout << M[0] << endl;
    for (size_t i = 1; i < text.length(); i++)
    {

        //M[i].insert( M[i].begin(), M[i - 1][text.length() - 1]);
        M[i] = M[i - 1][text.length() - 1] + M[i - 1];

        //cout << M[i] << endl;
        M[i].pop_back();

    }

    std::sort(M.begin(), M.end(), customCompare);



    for (size_t i = 0; i < text.length(); i++)
    {
        result = result + M[i][text.length() - 1];

    }


    // write your code here

    return result;
}

int main() {
    string text;
    cin >> text;
    cout << BWT(text) << endl;
    return 0;
}