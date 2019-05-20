/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, pair<int, vector<int>>> emp;
        
        for(int i = 0; i < employees.size(); i++){
            emp[employees[i]->id] = make_pair(employees[i]->importance, employees[i]->subordinates);
        }
        
        int totalemp = 0;
        map<int, bool> seen;
        getSubordinatesDfs(emp, id, totalemp, seen);
        
        return totalemp;
    }
    
    void getSubordinatesDfs(map<int, pair<int, vector<int>>> emp, int id, int &totalemp, map<int, bool> &seen){
        seen[id] = true;
        totalemp += emp[id].first;
        
        for(int i = 0; i < emp[id].second.size(); i++){
            if(seen.count(emp[id].second[i]) == 0){
                getSubordinatesDfs(emp, emp[id].second[i], totalemp, seen);
            }
        }
    }
};