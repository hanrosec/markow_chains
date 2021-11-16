#include "markow_chains.h"

Chain::Chain() {}

void Chain::train(vector<int> array) {
    /**
     * @brief method to train model
     * 
     * @param array array of preprocessed data
     */
    vector<int> keys = get_unique_int(array);

    if (!this->model.empty()) {
        for (int i = 0; i < array.size()-1; i++) {
            map<int, vector<int>>::iterator model_iter = this->model.find(this->model.find(array[i])->first);
            this->model[model_iter->first].push_back(array[i+1]);
        }
    } else {
        for (auto i : keys)
            this->model.insert({i, vector<int>()}); // create empty model

        for (int i = 0; i < array.size()-1; i++) {
            map<int, vector<int>>::iterator model_iter = this->model.find(this->model.find(array[i])->first);
            this->model[model_iter->first].push_back(array[i+1]);
        }
    }
}

void Chain::preprocess_data(string data, string delimiter) {
    /**
     * @brief method to preprocess data (from string to int)
     * 
     * @param data string to preprocess and to teach model
     * @param delimiter string to split data by
     */

    //TODO add function deleting characters like . , ; : ' " { }
    vector<string> keys = get_unique_string(data, delimiter);
    vector<string> splitted_data = split(data, delimiter);
    map<string, int> tags_and_processed;

    for(int i = 0; i < keys.size(); i++){
        tags_and_processed.insert({keys[i], i});
        this->tags.insert({i, keys[i]});
    }

    for (string i : splitted_data)
        this->preprocessed_data.push_back(tags_and_processed[i]);
}

vector<int> Chain::generate(int first, int len) {
    /**
     * @brief create chain statring with first
     * 
     * @param first int to start chain with
     * @param len length of chain (not working properly)
     */

    vector<int> result = {first};
    int current = first;
    for (int i = 0; i < len; i++) {
        int s = (int)this->model[current].size();
        if (s == 0) {
            // i--;
            continue;
        }
        int index = random_int(i) % s;
        int element = this->model[current][index];
        result.push_back(element);
        current = element;
    }
    return result;
}

map<int, string> Chain::get_tags() {
    /**
     * @brief method to get tags
     */

    return this->tags;
}

vector<int> Chain::get_preprocessed_data() {
    /**
     * @brief method to get preprocessed data
     */

    return this->preprocessed_data;
}


int random_int(int seed, int magnitude, long long int iterations) {
    /**
     * @brief function to generate pseudorandom int
     * 
     * @param seed number for calculations
     * @param magnitude (i don't really know)
     * @param iterations number of iterations
     */

    double x = sin(seed++) * 0xffffff;
    int step = 128;
    for (long long int i = 0; i < iterations * step; i+=step) {
        x = sin(x++) * 0xffffff * cos(x--) * tan(x += 128);
    }
    return (x - floor(x)) * pow(10, magnitude) * (time(NULL) % 2137);
}


vector<int> get_unique_int(vector<int> array) {
    /**
     * @brief get unique ints from array
     */

    vector<int> result = {array[0]};
    for (int i : array) {
        if (!in(i, result)) {
            result.push_back(i);
        }
    }
    return result;
}

vector<string> get_unique_string(string data, string delimiter) {
    /**
     * @brief get unique words from string
     */

    vector<string> splitted_data = split(data, delimiter);
    vector<string> result = {splitted_data[0]};

    for (string i : splitted_data) {
        if (!in(i, result))
            result.push_back(i);
    }
    return result;
}

bool in(int what, vector<int> where) {
    /**
     * @brief check if int is in array
     * 
     * @param what int to check 
     * @param where array to check
     */

    for(int i : where) {
        if(what == i) return true;
    }
    return false;
}

bool in(string what, vector<string> where) {
    /**
     * @brief check if string is in array
     * 
     * @param what string to check 
     * @param where array to check
     */

    for(string i : where) {
        if(what == i) return true;
    }
    return false;
}

vector<string> split (string s, string delimiter) {
    /**
     * @brief split string by delimiter
     * 
     * @param s string to split
     * @param delimiter delimiter
     */
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}