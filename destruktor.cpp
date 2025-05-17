//DESTRUKTOR
#include <iostream>
using namespace std;

class angka 
{
    private:
        int *arr;
        int panjang;
    public:
        angka(int); //Constructor
        ~angka(); //Destructor
        void cetakData();
        void isiData();
};
// Definisikan memberr Function
angka:: angka (int i) // Constructor
{ 
    panjang = i;
    arr = new int[i];
    isiData();
}

angka::~angka()
{ 
    cout<<endl;
    cetakData();
    delete[]arr;
    cout<<"Alamat Array Sudah Dilepaskan"<<endl;
}
