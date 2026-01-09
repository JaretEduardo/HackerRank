#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<vector<int>> mergeHighDefinitionIntervals(vector<vector<int>> intervals) {
    if (intervals.empty()){
        return {};
    }
    
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    });
    
    vector<vector<int>> merged;
    
    merged.push_back(intervals[0]);
    
    for (size_t i = 1; i < intervals.size(); i++){
        vector<int>& lastAdded = merged.back();
        
        vector<int>& current = intervals[i];
        
        if (current[0] <= lastAdded[1]){
            lastAdded[1] = max(lastAdded[1], current[1]);
        } else{
            merged.push_back(current);
        }
    }
    
    return merged;
}

int main()
{
    string intervals_rows_temp;
    getline(cin, intervals_rows_temp);

    int intervals_rows = stoi(ltrim(rtrim(intervals_rows_temp)));

    string intervals_columns_temp;
    getline(cin, intervals_columns_temp);

    int intervals_columns = stoi(ltrim(rtrim(intervals_columns_temp)));

    vector<vector<int>> intervals(intervals_rows);

    for (int i = 0; i < intervals_rows; i++) {
        intervals[i].resize(intervals_columns);

        string intervals_row_temp_temp;
        getline(cin, intervals_row_temp_temp);

        vector<string> intervals_row_temp = split(rtrim(intervals_row_temp_temp));

        for (int j = 0; j < intervals_columns; j++) {
            int intervals_row_item = stoi(intervals_row_temp[j]);

            intervals[i][j] = intervals_row_item;
        }
    }

    vector<vector<int>> result = mergeHighDefinitionIntervals(intervals);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];

            if (j != result[i].size() - 1) {
                cout << " ";
            }
        }

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
