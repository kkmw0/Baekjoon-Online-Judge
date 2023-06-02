#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    string name;
    int kor, eng, math;
};

int n;
vector<Student> st;

bool cmp(Student a, Student b){
    if(a.kor != b.kor) return a.kor > b.kor;
    else{
        if(a.eng != b.eng) return a.eng < b.eng;
        else{
            if(a.math != b.math) return a.math > b.math;
            else return a.name < b.name;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        int kor, eng, math;
        cin >> str >> kor >> eng >> math;
        st.push_back({str, kor, eng, math});
    }
    sort(st.begin(), st.end(), cmp);
    for(int i = 0; i < st.size(); i++){
        cout << st[i].name << '\n';
    }
    return 0;
}