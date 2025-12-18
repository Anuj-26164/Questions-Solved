#include <bits/stdc++.h>
using namespace std;

int main() {
    char c1[]={'h','i',' ','t','h','e','r','e',' ','a','b','c','\0'};
    char c2[]="hi there abc";
    cout<<c1<<endl;
    cout<<c2<<endl;
    cout<<sizeof(c1)<<endl;
    cout<<sizeof(c2)<<endl;
    cout<<strlen(c1)<<endl;
    cout<<strlen(c2)<<endl;

    return 0;
}