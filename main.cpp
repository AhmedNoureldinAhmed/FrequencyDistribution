#include <iostream>
#include<vector>
#include<fstream>
#include<algorithm> //log10()
#include<cmath>     //Max,Min in Vector
#include<iomanip>   //setw()

using namespace std;



int main()
{

vector<double>_data,_lower,_upper;
double _max{},_min{},_re{};

// =========== FileHandling Read =========== //
ifstream input;;
 input.open("input.txt",ios::in | ios::app);

 if (input.fail())
    cout<<"Error in input File"<<endl;
 input.seekg(168, ios::beg); // Skip Positions (Text in Begin File)
char sign{};
 while(input){
    input>>_re; // Read Number
    input>>sign; // Read Colon
    _data.push_back(_re); // Assigned Data To Vector
}
// =========== FileHandling =========== //

 // ==============  Sturges rule  ============== //
 const size_t _n{_data.size()}; //Number of Data in Vector
 const double _k{ round(1 + (3.322 *(log10(_n))))}; // Sturges Formula + Round Up Result
 const auto [min, max] = minmax_element(begin(_data), end(_data)); _max = *min ;_min = *min;//Max&Min in Vector
 const double _range{*max - *min }; // Calculate Range
 const double _classW{ceil(_range / _k)};// Calculate Class Width
 //double _classW{round(_range / 6)} // Another Method ;

// ============== Assigned Class Limit ============== //
 for(size_t i=0; i <_k;i++)
 {
    if( i==0 )
    {    _lower.push_back(*min);
         _upper.push_back(*min + (_classW -1) );}
  // Assigned Lower & Upper Data
    _min+=_classW ; //
    _max =_min + (_classW -1) ;
    _lower.push_back(_min);
    _upper.push_back(_max);
 }
// ============== Counter & Sum ============== //
vector<double>_count(_k);
double _sum{};

 for(size_t i=0; i <_data.size();i++)
 {
    for (size_t j=0 ; j < _k ;j++)
    {
        if( _data[i] >= _lower[j] &&  _data[i] <= _upper[j]  )
        {
            _count[j] += 1;
        }
    }
 }
 for(size_t i=0 ; i<_count.size();i++)
    _sum+=_count[i];

// ============== Print ============== //
    cout<<"Frequency Distribution Table"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Class Limit "<<setw(12)<<"Frequency"<<endl;
    cout<<"-------------------------"<<endl;
    for (size_t i=0 ; i < _count.size();i++)
    {
    cout<<"|"<<setw(4)
    <<_lower[i]<<"-"<<_upper[i]
    <<setw(3)<<"|"<<setw(10)
    <<_count[i]
    <<setw(4)<<"|"<<endl;
    }
 cout<<"-------------------------"<<endl;
     cout<<setw(9)<<" Total "<<
     setw(2)<<"|"<<
     setw(10)<<_sum<<
     setw(4)<<"|"<<endl;
 cout<<"-------------------------"<<endl;

// ============== Print ============== //

// =========== FileHandling OutPut =========== //
    ofstream Freq;
    Freq.open("output.txt",ios::out  | ios::app);

    if (Freq.fail())
    cout<<"Error in output File"<<endl;

    Freq<<"Frequency Distribution Table"<<endl;
    Freq<<"-------------------------"<<endl;
    Freq<<"Class Limit "<<setw(12)<<"Frequency"<<endl;
    Freq<<"-------------------------"<<endl;
    for (size_t i=0 ; i < _count.size();i++)
    {
    Freq<<"|"<<setw(4)
    <<_lower[i]<<"-"<<_upper[i]
    <<setw(3)<<"|"<<setw(10)
    <<_count[i]
    <<setw(4)<<"|"<<endl;
    }
     Freq<<"-------------------------"<<endl;
     Freq<<setw(9)<<" Total "<<
     setw(2)<<"|"<<
     setw(10)<<_sum<<
     setw(4)<<"|"<<endl;
 Freq<<"-------------------------"<<endl;
 // =========== FileHandling =========== //


    return 0;

}
