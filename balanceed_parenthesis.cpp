#include<bits/stdc++.h>
using namespace std;
bool isvalid(string s){
    int n=s.size();
    bool ans=true;
    stack <char> stk;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='{' or s[i]=='(' or s[i]=='[')
        {
            stk.push(s[i]);
        }
        else if(!(stk.empty()) and s[i]==')')
        {
            if(stk.top()=='('){
                stk.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        else if(!(stk.empty()) and s[i]=='}'){
            if(stk.top()=='{'){
                stk.pop();
            }
            else{
                ans=false;
                break;
            }
        }
        else if(!(stk.empty()) and s[i]==']'){
            if(stk.top()=='['){
                stk.pop();
            }
            else{
                ans=false;
                break;
            }
        }
    } 
    if(!(stk.empty())){
        return false;
    }
    return ans;
}
int main(){
    string s;
    cout<<"please enter your string which containes the character's ('{','}','(',')','[',']'): "<<endl;
    cin>>s;
    if(isvalid(s)){
        cout<<"valid string __true_"<<endl;
    }
    else{
        cout<<"invalid string__false_"<<endl;
    }
    return 0;
}