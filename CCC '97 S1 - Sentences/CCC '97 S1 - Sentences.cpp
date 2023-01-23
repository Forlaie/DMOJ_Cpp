#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num; ++i) {
        int s, v, o;
        cin >> s >> v >> o;
        vector<string> subjects, verbs, objects;

        for (int j = 0; j < s; ++j) {
            string word;
            getline(cin >> ws, word);
            subjects.push_back(word);
        }

        for (int j = 0; j < v; ++j) {
            string word;
            getline(cin >> ws, word);
            verbs.push_back(word);
        }

        for (int j = 0; j < o; ++j) {
            string word;
            getline(cin >> ws, word);
            objects.push_back(word);
        }

        for (int a = 0; a < s; ++a) {
            for (int b = 0; b < v; ++b) {
                for (int c = 0; c < o; ++c) {
                    cout << subjects[a] << " " << verbs[b] << " " << objects[c] << "." << endl;
                }
            }
        }
    }
}
