#include "Patricia.h"
#include <ctime>
#include <random>
#include <chrono>

using namespace std;

const string FILENAME = "test.db";

void stressTest() {

    Patricia* patricia = new Patricia();
    ifstream keysFile("keys.db");
    string line;
    vector<string> keys;

    patricia->build(FILENAME);

    for(int i = 0; i < 200; i++) {
        auto index = rand() % 18386;
        while(index--) getline(keysFile,line);
        keysFile.seekg(0,ios::beg);
        keys.push_back(line);
    }
    cout<<"\n\n\n";
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < 200; i++) {
        auto test = patricia->search(keys[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto executionTime = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Execution time: " << executionTime.count() << " us.\n";
    cout << "Read count: " << SEARCH_COUNTER << "\n";


}

int main(){

    srand(time(nullptr));

    Patricia* patricia = new Patricia();

    patricia->build(FILENAME);

    //patricia->pNode(patricia->getRoot());

    patricia->print();
    
    //stressTest();

    // ifstream file(FILENAME);

    // auto test = patricia->search("hand");

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