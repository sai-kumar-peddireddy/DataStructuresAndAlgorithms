#include <iostream>
#include <array>

using namespace std;

static constexpr size_t len = 10;

void print(const array<char, len>& arr);
void insertAt(size_t pos, array<char, len>& arr, char val);

int main()
{	
	array<char, len> arr;
	fill(arr.begin(), arr.end(), '*');
	
	
	insertAt(1, arr, '1');
	cout<<'\n';	
	print(arr);
	
	insertAt(1, arr, '2');
    cout<<'\n' <<'\n';	
	print(arr);
	
	insertAt(0, arr, '6');
    cout<<'\n' <<'\n';	
	print(arr);
}

void print(const array<char, len>& arr)
{
  for(const auto& element : arr)
  	cout<<element <<'\t';
}


void insertAt(size_t pos, array<char, len>& arr, char val)
{
	if(pos > arr.size())
	{
		cout<<pos <<" is not a vaild pos";
		return ;
	}
	
	
	for(size_t i  = arr.size() -1; i > pos ; --i )
		arr[i] = arr[i-1];
       
   arr[pos] = val;	
		
}
