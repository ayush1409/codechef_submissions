#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

vector<int> getMax(vector<string> operations) {
    stack<pair<int, int> > s ;
    vector<int> result ;
    int max = INT_MIN ;
    int val ;
    string val_str ;
    for(int i=0 ; i<operations.size() ; i++){
        if(operations[i][0] == '1'){
            // perform push
            
            val = stoi(operations[i].substr(2, operations[i].size())) ;    
            if(val > max){
                max = val ;
            }
            s.push(make_pair(val, max)) ;
                   
        }
        else if(operations[i][0] == '2'){
            // perform pop
            if(!s.empty())
                s.pop() ;
                
            if(s.empty())
                max = INT_MIN ;
        }
        else if(operations[i][0] == '3'){
            //cout<<s.top().second<<endl ;
            result.push_back(s.top().second) ;
        }
    }
    return result ;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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
