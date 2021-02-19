#include <iostream>
#include "Stock00.h"
int main()
{
	using std::cout;

	cout << "Using constructors to create new objects\n";
	Stock stock1("NanoSmart", 12, 20.0);				// Explicit Constructor Called; No temporary object here.
	stock1.show();

	Stock stock2 = Stock("Boffo Objects", 2, 2.0);	// Explicit Constructor Called; No temporary object here.			
	stock2.show();

	cout << "Assigning stock1 to stock2:\n";
	stock2 = stock1;		// Assignment, not initialization. NO Constructor Called here, because stock2已经存在

	cout << "Listing stock1 and stock2:\n";
	stock1.show();
	stock2.show();

	cout << "Using a constructor to reset an object\n";
	stock1 = Stock("Nifty Foods", 10, 50.0);	// Explicit Constructor Called for temporary object, then Destructor Called for temporary object.
	cout << "Revised stock1:\n";							// 这里之所以有temporary object，而创建stock1时没有temporary object，是因为这里stock1已经存在了.
	stock1.show();													// 用constructor去修改一个已经存在的object，只能用这种形式，不能用stock1.Stock("Nifty Foods", 10, 50.0)这种形式；
																					// 因为这种形式只能用于初始化一个还不存在的object.
	cout << "Done\n";	
	// 先释放stock2，是NanoSmart；然后释放stock1，是Nifty Foods. 按照创建的顺序，而不是修改的顺序.
	return 0;

	// 如果Object是new出来的, 那么在你delete时, destructor会被调用, 而不是在destructor中去delete.
	// 因为destructor是同一个class的不同object公用的.
}
