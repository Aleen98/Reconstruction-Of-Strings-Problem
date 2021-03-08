//
// Created by ileen on 3/8/2021.
//

#include "l-balls-maximal-intersection.h"



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

int get_intersection_size(const set<string> &s1, const set<string> &s2) {
    int count = 0;
    for (string s : s1) {
        if (s2.find(s) != s2.end())
            count++;
    }
    return count;
}

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

