#include "Patricia.h"
#include <ctime>
#include <random>
#include <chrono>
#include <unistd.h>

using namespace std;

const string FILENAME = "file.db";
const int FILENAME_LINE_COUNT = 3386;

void stressTest() {
    Patricia* patricia = new Patricia();
    ifstream keysFile("keys.db");
    string line;
    vector<string> keys;

    patricia->build(FILENAME);

    for(int i = 0; i < 100; i++) {
        auto index = rand() % FILENAME_LINE_COUNT;
        while(index--) getline(keysFile,line);
        keysFile.seekg(0,ios::beg);
        keys.push_back(line);
    }
    cout<<"\n\n\n";
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < 100; i++) {
        auto test = patricia->search(keys[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto executionTime = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Execution time: " << executionTime.count() << " us.\n";
    cout << "Read count (avg): " << SEARCH_COUNTER/200 << "\n";
}

int main(){

    srand(time(nullptr));

    cout << getpid() << endl;
    // string command = "top | grep " + to_string(getpid()) + " | awk '{print $8}'";
    // cout << command << endl;

    // system(command.c_str());

    // top | grep 9442 & sleep 10 && kill $!

    // sleep(100);

    // return 0;

    Patricia* patricia = new Patricia();

    patricia->build(FILENAME);

    cout << "word with prefix:\n";
    cout << patricia->prefix("Licens") << "\n";

    //patricia->pNode(patricia->getRoot());

    //patricia->print();
    
    // stressTest();

    // sleep(100);

    // ifstream file(FILENAME);

    // string line;

    // auto test = patricia->search("lefty.1");

    // if(test.size()) {
    //     for(auto e: test) {
    //         file.seekg(e.first, ios::beg);
    //         getline(file,line);
    //         cout<<line<<"\n";
    //     }
    // }
    // file.close();

    return 0;
}