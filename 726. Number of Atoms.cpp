#include <string>
#include <map>
#include <stack>
#include <cctype>
#include <algorithm>
#include <iostream>


class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        stk.push({});
        
        int n = formula.size();
        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                stk.push({});
                i++;
            } else if (formula[i] == ')') {
                map<string, int> top = stk.top();
                stk.pop();
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplicity = (i > start) ? stoi(formula.substr(start, i - start)) : 1;
                for (const auto &p : top) {
                    stk.top()[p.first] += p.second * multiplicity;
                }
            } else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                string name = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplicity = (i > start) ? stoi(formula.substr(start, i - start)) : 1;
                stk.top()[name] += multiplicity;
            }
        }
        
        map<string, int> final_count = stk.top();
        string result;
        for (const auto &p : final_count) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        
        return result;
    }
};
