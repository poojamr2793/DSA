#include <iostream>
#include<vector>
using namespace std;

int josephusRec(vector<int> person, int k, int index){
    
    // Base case , when only one person is left
    if (person.size() == 1) { ;
        return person[0];
    }

    // find the index of first person which will die
    index = ((index + k) % person.size());

    // remove the first person which is going to be killed
    person.erase(person.begin() + index);

    // recursive call for n-1 persons
    return josephusRec(person, k, index);
}

int josephus(int n,int k){
    
    // The index where the person which will die
    int index= 0; 

    vector<int> person;
    
    // fill the person vector
    for (int i = 1; i <= n; i++) {
        person.push_back(i);
    }
    return josephusRec(person,k,index);
}

int main(){
    int n = 7; 
    int k = 3;
    
    // (k-1)th person will be killed
    k--;
    cout<<josephus(n, k)<<endl;
}
