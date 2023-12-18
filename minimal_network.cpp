#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include<random>
#include <queue>
#include <unordered_map>
#include <cassert>

using namespace std;

// creating a 2D vector of input file as a representation of the network
vector<vector<int>> get_network(const string &filename)
{
    ifstream ifs(filename);
    if (ifs.fail())
    {
        cerr << "failed to open " << filename << endl;
        exit(-1);
    }
    string line;
    vector<vector<int>> network;

    while (getline(ifs, line))
    {       
        istringstream iss(line);
        vector<int> pairs;
        string distance;

        while (getline(iss, distance, ',') || getline(iss, distance, '-'))
            if (distance != "-")
                pairs.push_back(stoi(distance));
            else 
                pairs.push_back(0);
        
        network.push_back(pairs);
    }
    return network;
}

void print_network(vector<vector<int>> network)
{
    for(auto row : network)
    {
        for(auto k : row)
            cout << k << " ";
        cout << endl;
    }
    cout << endl;
}

// to choose the starting point
int get_random(int upper_border)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(0, upper_border);
    return distribution(gen);
}

vector<vector<int>> prim(vector<vector<int>> network)
{
    unordered_map<int, bool> visited_vertices;
    vector<vector<int>> minimal_network(network.size(), vector<int>(network.size(), 0));
    int vertex = get_random(network.size() - 1);

    // p has no usage, but it has to run for all vertices
    for(int p = 0; p < network.size();p++)
    {
        visited_vertices[vertex] = true;
        int min = INT_MAX;
        int minVertex;

        // searching for the min weighted edge in all visited vertices yet
        for(auto it = visited_vertices.begin(); it != visited_vertices.end(); ++it)
                for (int i = 0; i < network.size(); i++)
                    if (!visited_vertices[i] && network[it->first][i] != 0 && network[it->first][i] < min)
                    {
                        min = network[it->first][i];
                        minVertex = i;
                    }
        // building the symmetric quadratic adjacency matrix
        minimal_network[vertex][minVertex] = network[vertex][minVertex];
        minimal_network[minVertex][vertex] = network[minVertex][vertex];
        vertex = minVertex;
    }
    return minimal_network;
}

bool compare(vector<vector<int>> solution, vector<vector<int>> minimal_network)
{
    for(int i = 0; i < solution.size(); i++)
        for(int j = 0; j < solution[i].size(); j++)
            if(solution[i][j] != minimal_network[i][j])
                return false;
    return true;
}

int main()
{
    vector<vector<int>> testNull;
    assert(compare(prim(testNull), {}));

    // equally weighted network has four solutions with |V| = 4
    vector<vector<int>> testZero = prim({{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}});
    assert(
            compare(testZero, {{0,1,1,0},{1,0,0,0},{1,0,0,1},{0,0,1,0}}) ||
            compare(testZero, {{0,1,1,0},{1,0,0,1},{1,0,0,0},{0,1,0,0}}) ||
            compare(testZero, {{0,1,0,0},{1,0,1,0},{0,1,0,1},{0,0,1,0}}) ||
            compare(testZero, {{0,1,0,1},{1,0,1,0},{0,1,0,0},{1,0,0,0}})
            );

    vector<vector<int>> network = get_network("network.txt");
    //print_network(network);
    cout << "Minimal Network :" << endl;
    print_network(prim(network));
    return 0;
}

