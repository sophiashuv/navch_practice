#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

//      22.	У текстовому файлі задано зв’язний граф у вигляді матриці суміжності.
//      На основі пошуку вшир (BFS) обчислити найкоротшу відстань між двома заданими вершинами.

/*
 * The function reads matrix from file
 */
using namespace std;
void read_file(vector <vector<int>>&m, const int &r, const int &c){
    ifstream file {"/Users/sophiyca/ClionProjects/stack_task1/matrix.txt"};
    if (file.is_open()) {
        int k;
        for (int i = 0; i != r; ++i) {
            for (int j = 0; j != c; ++j) {
                file >> k;
                m[i].push_back(k);

            }
        }
    }
}


/*
 * The function searches the shortest way between two vertices using BFS.
 */
void BFS(const vector <vector<int>> &m, int ver, const int &ver2, int &l){
    vector<bool> visited(m.size(), false);
    queue<int> q;
    string result;
    q.push(ver);
    visited[ver] = true;
    while (!q.empty()){
        for (int i = 0; i < m[ver].size(); ++i) {
            if (m[ver][i] == 1){
                for (int j = 0; j < m.size(); ++j) {
                    if (m[j][i] == 1 && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
        result += "v" + to_string(q.front()) + " ";
        q.pop();
        ver = q.front();
        if (!visited[ver2]) l+=1;
        else {
            result += "v" + to_string(q.front()) + " " + "v" + to_string(ver2);
            cout << "All ver vertices are visited: " << result << "\n";
            return;
        }

    }
    cout << "There's no path between this two vertices: \n";
}


int main() {

    int r = 5, c = 6;
    vector <vector<int>>m(r);
    cout << "Enter number of vertexes from which to start and which to end (from 0 to " << r - 1 << "): ";
    int ver = 0, ver2 = 0, l = 0;
    cin >> ver >> ver2;
    read_file(m, r, c);

    BFS(m, ver, ver2, l);

    cout << "Path from " << ver << " to " << ver2 << " = " << l+1;

    return 0;
}