// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

// formula is a set of clauses
// each formula is a vector of int
vector<vector<int>> formula;
// each variable has an assignment
// 1 means true, -1 means false and 0 means unassigned
vector<int> assignments;

//read formulas 
//each formula is a vector of int
//so return a vector<vector<int>>

//decision
//take an unassigned variable assign it to 1 (or 0, does not make a difference) 
void assign(){

}

//unit propagation
//search unit clause... a formula where unassigned varibale must be true
//if finds conflict returns true
void unit_propagate(){
    bool unit_prop_happenned=false;
    if(check_conflict()==false) {}
        resolve_conflict();

    for(auto clause: formula){
        int num_unassigned=0;
        bool is_unit_clause=true;

        for (auto literal : clause){
            int index=abs(literal)-1;
            if(assignments[index]==literal) { //the clause is sat, not a unit clause
                is_unit_clause=false;
                break; 
            }
            if(assignments[index]==0) num_unassigned++;
        }
        if(!is_unit_clause) continue; // go to next

        if(num_unassigned==1){
            //found a unit clause
            for(auto literal : clause){
                int index=abs(literal)-1;
                if(assignments[index]==0){
                    assignments[index]=literal;
                    break;
                }
            }
            unit_prop_happenned=true;
        }
    }
    if(unit_prop_happenned) unit_propagate();
}

//check conflict
//check if any clause becomes false
bool check_conflict(){
    for (auto clause: formula){
        bool is_clause_sat=false;
        for(auto literal: clause){
            int index=abs(literal)-1;
            if(assignments[index]==literal || assignments[index]==0){
                is_clause_sat=true;
                break;
            }
        }
        if(!is_clause_sat) return false;
    }
    return true;
}

//resolve conflict
//decision made is reversed

//dpll
//run a for loop : unit propagation->check conflict->decision
//


int main(){
    return 0;
}