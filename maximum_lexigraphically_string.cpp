#include <string>
//
// Created by vinay on 04-06-2025.
//
using namespace std;

string answerString(string word, int numFriends) {
    int n = word.length();
    if( numFriends == 1)
        return word;

    string result;

    int longestPossible = n - (numFriends - 1);

    for(int i = 0; i < n; i++) {
        int canTakeLength = min(longestPossible, n-i);

        result = max(result, word.substr(i, canTakeLength));
    }

    return result;
}