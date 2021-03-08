//
// Created by ileen on 3/8/2021.
//

#ifndef PRO_TOSUB_L_BALLS_MAXIMAL_INTERSECTION_H
#define PRO_TOSUB_L_BALLS_MAXIMAL_INTERSECTION_H


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
void calc_l_ball(const string &vec, set<string> &ball);

/*
* Calculate all l-balls of binary strings size n, with radius 1
* Args:
*   balls: Will contain vec's l-ball at balls[vec]
*   n: vector size
*/
void calc_all_balls(map<string, set<string>> &balls, int n);

/*
* Returns intersecton size of balls s1 and s2
*/
int get_intersection_size(const set<string> &s1, const set<string> &s2);

/*
* Returns largest intersection of word s1
* Args:
*   balls: pre-calculation of all 2^n l-balls
* Returns:
*   Pair of int, set. Int is for the largest interection size and
*   the set are the words created this intersection
*/
pair<int, set<string>> get_largest_intersection(const string &s1, map<string, set<string>> &balls);

/*
* Returns the total largest intersection
* Args:
*   balls: pre-calculation of all 2^n l-balls
*   n: word size
* Returns:
*   Pair of int, set. Int is for the largest interection size and
*   the set are the words created this intersection
*/
pair<int, set<string>> get_largest_intersection(map<string, set<string>> &balls, int n);



#endif //PRO_TOSUB_L_BALLS_MAXIMAL_INTERSECTION_H
