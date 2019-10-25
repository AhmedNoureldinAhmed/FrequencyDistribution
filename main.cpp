#include <iostream>
#include<vector>
#include<algorithm> //log10()
#include<cmath>     //Max,Min in Vector
#include<iomanip>   //setw()

using namespace std;



int main()
{

  vector<double>_data
  { 22 ,37 ,28, 63, 32, 26 ,31, 27, 27, 28,
    30 ,26 ,29 ,24 ,38 ,25 ,29 ,41, 30 ,35,
    35 ,33 ,29 ,38 ,54 ,24 ,25 ,46 ,41 ,28,
    40 ,39 ,29 ,27 ,31 ,38 ,29 ,25 ,35 ,60,
    43 ,35 ,34 ,34 ,27 ,37 ,42 ,41 ,36 ,32,
    41 ,33 ,31 ,74 ,33 ,50 ,38 ,61 ,21 ,41,
    26 ,80 ,42 ,29 ,33 ,35 ,45 ,49 ,39 ,34,
    26 ,25 ,33 ,35 ,35 ,28
    }
,_lower,_upper;
double _max{},_min{},_sum{};

 // ==============  Sturges rule  ============== //
 const size_t _n{_data.size()}; //Number of Data in Vector
 const double _k{ round(1 + (3.322 *(log10(_n))))}; // Sturges Formula + Round Up Result
 const auto [min, max] = minmax_element(begin(_data), end(_data)); _max = *min ;_min = *min;//Max&Min in Vector
 const double _range{*max - *min }; // Calculate Range
 const double _classW{ceil(_range / _k)};// Calculate Class Width
 //double _classW{round(_range / 6)} // Another Method ;


// ============== Table Header ============== //
    cout<<"-------------------------"<<endl;
    cout<<"Class Limit "<<setw(12)<<"Frequency"<<endl;
    cout<<"-------------------------"<<endl;

// ============== Assigned Class Limit ============== //
    for(size_t i=0; i <_k;i++)
    {
        if( i==0 )
        {
         _lower.push_back(*min);
         _upper.push_back(*min + (_classW -1) );
        }
        // Assigned Value
    _min+=_classW ; //
    _max =_min + (_classW -1) ;
    _lower.push_back(_min);
    _upper.push_back(_max);
 }


// ============== Counter ============== //
vector<double>_count(_k);

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


    return 0;

}
