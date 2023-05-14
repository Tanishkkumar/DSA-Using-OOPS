// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     float a;
//     string arr="1234.56263";
//     stringstream geek(arr);
//     geek>>a;
//     cout<<a;
// }

            ///////////string into  interger value---------

#include<bits/stdc++.h>
using namespace std;
int main(){
    float a;
   const char* arr="1234.256";
     sscanf(arr,"%f",&a);
     printf("%f",a);
     return 0;
}