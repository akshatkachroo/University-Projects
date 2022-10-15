#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int main();
#endif
unsigned int add_checksum( unsigned int n );
void add_checksum( unsigned int array[], std::size_t capacity );
bool verify_checksum( unsigned int n );
unsigned int remove_checksum( unsigned int n );
void remove_checksum( unsigned int array[], std::size_t capacity );


unsigned int add_checksum( unsigned int n ) {
  if ( n > 99999999){
    return UINT_MAX;
    }  
 
int divide = 1;
int digit = 0;
  
  while (n/divide != 0){
    divide *= 10;
    digit += 1;    
  }

  int size[digit]; int count{0};
  for (int i = divide/10; i > 0; i /=10)
    {
    size[count] = (n / i) % 10;
    count++; 
    }  

  for (int i{digit - 1}; i >= 0 ; i-=2 ) {
    size[i] *= 2;
  }
  
  int add_watnum{};
  for (int i{0}; i < digit; i++){
    if ( size [i] >= 10 ) {
      add_watnum = (size[i]/10) + (size[i]%10);
      size [i] = add_watnum;     
      }
    }

    int add_all{};
    for (int i{0}; i < digit; ++i){
      add_all += size[i];
      }

    add_all *= 9;
    add_all %= 10;
    int final = (n * 10) + add_all;
    return final;
   }





void add_checksum( unsigned int array[], std::size_t capacity ){
  for (int i = 0; i< capacity; ++i){
    array[i] = add_checksum(array[i]);
  }
  }


bool verify_checksum( unsigned int n ){
  if ((n <= 999999999) && (add_checksum(n/10) == n)) {
    return true;
  }  else {
    return false;
  }
}



unsigned int remove_checksum( unsigned int n ){
  if (n > 999999999) return UINT_MAX;
  if (verify_checksum(n)) return n/10;
  return UINT_MAX;
}



void remove_checksum( unsigned int array[], std::size_t capacity ) {
  for (int i{0}; i < capacity; ++i){
    array[i] = remove_checksum(array[i]);
  }
}

#ifndef MARMOSET_TESTING
int main() {
	unsigned int value_to_protect{1};
	unsigned int protected_value = add_checksum(value_to_protect);
	std::cout << "The value " << value_to_protect
		<< " with the checksum added is " << protected_value
		<< "." << std::endl;
	
	if (verify_checksum(protected_value))
	{
		std::cout << "The checksum is valid." << std::endl;
	}
	else   {
		std::cout << "The checksum is invalid." << std::endl;
	} 
	const std::size_t QTY_VALUES {3};
	unsigned int value_series[QTY_VALUES] {20201122, 20209913, 20224012};
	
	add_checksum(value_series, QTY_VALUES);
	
	std::cout << "Series with checksums added: ";
	for (std::size_t series_index {0};
		series_index < QTY_VALUES; series_index++)
	{
		std::cout << value_series[series_index] << " ";
	}

    std::cout << std::endl;
    return 0;
}
#endif