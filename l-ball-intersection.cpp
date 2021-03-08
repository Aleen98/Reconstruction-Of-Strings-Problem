//
// Created by ileen on 3/5/2021.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

/*
* Calculates l-ball of radius 1
* Args:
*   vec: binary string - origin of the l-ball
*   ball: empty set of strings. Will contain vec's l-ball.
*/
void calc_l_ball(const string &vec, set<string> &ball) {
    int n = vec.size();
    int del_index, insert_index;
    for (int del = 0; del < n; ++del) {
        string cp = vec;
        cp.erase(del, 1);
        for (int ins = 0; ins < n - 1; ++ins) {
            string val = cp[ins] == '1' ? "0" : "1";
            cp.insert(ins, val);
            ball.insert(cp);
            cp.erase(ins, 1);
        }
        cp.insert(n - 1, "0");
        ball.insert(cp);
        cp.erase(n - 1, 1);
        cp.insert(n - 1, "1");
        ball.insert(cp);
    }
}

/*
* Calculate all l-balls of binary strings size n, with radius 1
* Args:
*   balls: Will contain vec's l-ball at balls[vec]
*   n: vector size
*/
void calc_all_balls(map<string, set<string>> &balls, int n) {
    string s;
    for (int i = 0; i < n; ++i)
        s += '0';

    // add zero word ball
    set<string> ball;
    calc_l_ball(s, ball);
    balls[s] = ball;

    // loop over all 2^n words
    while (true) {
        int i = 0;
        for (; i < n; ++i) {
            if (s[i] == '0') {
                s[i] = '1';
                for (int j = 0; j < i; ++j) {
                    s[j] = '0';
                }
                set<string> ball;
                calc_l_ball(s, ball);
                balls[s] = ball;
                break;
            }
        }
        if (i == n)
            break;
    }
}

/*
* Returns intersecton size of balls s1 and s2
*/
int get_intersection_size(const set<string> &s1, const set<string> &s2) {
    int count = 0;
    for (string s : s1) {
        if (s2.find(s) != s2.end())
            count++;
    }
    return count;
}

/*
* Returns largest intersection of word s1
* Args:
*   balls: pre-calculation of all 2^n l-balls
* Returns:
*   Pair of int, set. Int is for the largest interection size and
*   the set are the words created this intersection
*/
pair<int, set<string>> get_largest_intersection(const string &s1, map<string, set<string>> &balls) {
    set<string> ret;
    int maximum = 0;
    for (string s : balls[s1]) {
        if (s != s1) {
            int intersection = get_intersection_size(balls[s], balls[s1]);
            if (intersection > maximum) {
                maximum = intersection;
                ret.clear();
                string val = s < s1 ? s + "-" + s1 : s1 + "-" + s;
                ret.insert(val);
            } else if (intersection == maximum) {
                string val = s < s1 ? s + "-" + s1 : s1 + "-" + s;
                ret.insert(val);
            }
        }
    }

    return make_pair(maximum, ret);
}

/*
* Returns the total largest intersection
* Args:
*   balls: pre-calculation of all 2^n l-balls
*   n: word size
* Returns:
*   Pair of int, set. Int is for the largest interection size and
*   the set are the words created this intersection
*/
pair<int, set<string>> get_largest_intersection(map<string, set<string>> &balls, int n) {
    string s;
    set<string> ret;
    int maximum = 0;
    for (int i = 0; i < n; ++i)
        s += '0';

    // Check zero word
    auto val1 = get_largest_intersection(s, balls);
    maximum = max(maximum, val1.first);

    // Loop over all other words
    while (true) {
        int i = 0;
        for (; i < n; ++i) {
            if (s[i] == '0') {
                s[i] = '1';
                for (int j = 0; j < i; ++j) {
                    s[j] = '0';
                }
                auto val = get_largest_intersection(s, balls);
                if (val.first > maximum) {
                    maximum = val.first;
                    ret = val.second;
                } else if (val.first == maximum) {
                    for (string word : val.second)
                        ret.insert(word);
                }
                break;
            }
        }
        if (i == n)
            break;
    }
    return make_pair(maximum, ret);
}

int main() {
    for (int i = 1; i <= 18; i++) {
        map<string, set<string>> balls;
        int n = i;

        // Calculate all balls
        calc_all_balls(balls, n);

        // Calculate largest intersection and maximizing words
        pair<int, set<string>> result = get_largest_intersection(balls, n);

        // Print results
        cout << "n: " << i << endl;
        cout << "Largest intersection is: " << result.first << endl;
        cout << "Maximizing couples are:" << endl;
        for (string word : result.second) {
            cout << word << endl;
        }
        cout << endl;

    }

    return 0;
}
