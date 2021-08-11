#include <iostream>
using namespace std;


int main()
{
    float x,x1,x2,x3,x4;
    float atas,bawah,j;
    int bagi;
  
    cout<<"Konstanta X^4 = "; cin>>x4;
    cout<<"Konstanta X^3 = "; cin>>x3;
    cout<<"Konstanta X^2 = "; cin>>x2;
    cout<<"Konstanta X   = "; cin>>x1;
    cout<<"Konstanta     = "; cin>>x;
    cout<<"  F(X) = ";
    if (x4 != 0) cout<<"("<<x4<<"X^4)";
    if (x3 != 0) cout<<"+("<<x3<<"X^3)";
    if (x2 != 0) cout<<"+("<<x2<<"X^2)";
    if (x1 != 0) cout<<"+("<<x1<<"X)";
    if (x != 0) cout<<"+("<<x<<")";
    
    cout<<"\nMasukan Batas Atas  =";
    cin>>atas;
    cout<<"Masukan Batas Bawah =";
    cin>>bawah;
    cout<<"Masukan Banyak Partial  ="; cin>>bagi;
    
    float fx[bagi],tj[bagi],jumlah=0;
    
    j=(atas-bawah)/bagi;
    cout<<j<<endl;
    
    tj[0]=bawah+j/2;
    cout<<tj[0]<<" "; 
    for(int i=1;i<bagi;i++){
    tj[i]=tj[i-1]+j;
    cout<<tj[i]<<" ";
    }
    cout<<endl;
    for(int k=0;k<bagi;k++){
     fx[k]=x4*tj[k]*tj[k]*tj[k]*tj[k]+x3*tj[k]*tj[k]*tj[k]+x2*tj[k]*tj[k]+x1*tj[k]+x;
    cout<<fx[k]<<" ";
    }
    cout<<endl;
    for(int l=0;l<bagi;l++){
    jumlah=jumlah+fx[l]*j;
    cout <<" + "<<jumlah;
    
    }
   
    cout<<"\n\nJadi Hasil Integral dari \n  F(X) = ";
    if (x4 != 0) cout<<"("<<x4<<"X^4)";
    if (x3 != 0) cout<<"+("<<x3<<"X^3)";
    if (x2 != 0) cout<<"+("<<x2<<"X^2)";
    if (x1 != 0) cout<<"+("<<x1<<"X)";
    if (x != 0) cout<<"+("<<x<<")";
    cout<<"dengan titik atas "<<atas<<" dan titik bawah "<<bawah<<" adalah "<<jumlah;


}
