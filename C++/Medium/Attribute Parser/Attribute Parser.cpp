#include <map>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();
    
    map<string, string> database;
    
    vector<string> current_tags;
    
    for (int i = 0; i < n; i++){
        string line;
        getline(cin, line);
        
        for (char &c : line){
            if (c == '\"' || c == '=' || c == '>') c = ' ';
        }
        
        stringstream ss(line);
        string word;
        ss >> word;
        
        if (word.substr(0, 2) == "</"){
            if (!current_tags.empty()) current_tags.pop_back();
        }
        else {
            string tagName = word.substr(1);
            
            current_tags.push_back(tagName);
            
            string full_path = "";
            
            for (string tag : current_tags){
                if (full_path != "") full_path += ".";
                full_path += tag;
            }
            
            string attr_name, attr_val;
            
            while (ss >> attr_name >> attr_val){
                database[full_path + "~" + attr_name] = attr_val;
            }
        }
    }
    
    for (int i = 0; i < q; i++){
        string query;
        getline(cin, query);
        
        if (database.find(query) != database.end()){
            cout << database[query] << endl;
        }
        else {
            cout << "Not Found!" << endl;
        }
    }
     
    return 0;
}
