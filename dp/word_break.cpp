/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

*/

#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict);

int main() {
	
	unordered_set<string> dict;
	
	dict.insert("a");
	dict.insert("abc");
	dict.insert("b");
	dict.insert("cd");
	
	string s="abcd";
	
	cout<<wordBreak(s,dict);
	
	
}

bool wordBreak(string s, unordered_set<string> &dict) {
        
        bool dyn[s.size()];
        for(int i=0;i<s.size();++i)
            dyn[i]=false;
        int i=0;
        int j;
        while(i<s.size()) {
            
            string t=s.substr(0,i+1);
            if(dict.find(t)!=dict.end()) {
             
             dyn[i]=true;   
                
            }
            
            if(dyn[i]==true) {
                j=i+1;
                while(j<s.size()) {
                string ts=s.substr(i+1,j-i);
                cout<<ts<<" ";
                if(dict.find(ts)!=dict.end()) {
                    dyn[j]=true;
                }
                j++;
                }
                
                if(dyn[j-1]==true) {
                    
                    return true;
                }
            
            }
            i++;
        }
        
        //for(int i=0;i<s.size();++i)
        	//cout<<dyn[i];
        return false;
    }
