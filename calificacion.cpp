#include <iostream>

using namespace std;

int main(){
    int calificacion;
    cout<<"Cual fue tu calificacion del semestre?"<<endl;
    cin>>calificacion;
    cout<<(calificacion>=6 ? "pasaste" : "reprobaste");
    cin.ignore();
    cin.get();
    return 0;
}