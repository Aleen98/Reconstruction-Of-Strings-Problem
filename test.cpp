#include "l-balls-maximal-intersection.h"

int main() {
        map<string, set<string>> balls;
        int n = 14;

        // Calculate all balls
        calc_all_balls(balls, n);

        // Calculate largest intersection and maximizing words
        pair<int, set<string>> result = get_largest_intersection(balls, n);

        // Print results
        cout << "n: " << n << endl;
        cout << "Largest intersection is: " << result.first << endl;
        cout << "Maximizing couples are:" << endl;
        for (string word : result.second) {
            cout << word << endl;
    }

    return 0;
}