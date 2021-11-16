/**
 * @file markow_chains.h
 * @author Hanrose
 * @brief C++ implemetation of markov chain (https://en.wikipedia.org/wiki/Markov_chain)
 * @version 0.1
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef __CHAIN
#define __CHAIN

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <ctime>

using namespace std;

vector<int> get_unique_int(vector<int> array); // function to get non repeated ints in vector
vector<string> get_unique_string(string data, string delimiter=" "); // function to get non repeated stringss in vector
bool in(int what, vector<int> where); // function to check if int is in vector
bool in(string what, vector<string> where); // function to check if string is in vector
vector<string> split (string s, string delimiter); // function to split string by delimiter
int random_int(int seed, int magnitude=2, long long int iterations=1); // function to get random int

class Chain {
    private:
        map<int, vector<int>> model; // includes unique words and words after them
        vector<int> preprocessed_data; //includes data translated to ints
        map<int, string> tags; // includes int keys and corresponding string
    public:
        Chain(); // constructor (does nothing)

        void train(vector<int> array); // method to create model
        vector<int> generate(int first, int len); // method to create chain of words

        vector<int> get_preprocessed_data(); // method to get preprocessed data
        map<int, string> get_tags(); // method to get tags
        void preprocess_data(string data, string delimiter); // method to preprocess data
};

#endif // __CHAIN