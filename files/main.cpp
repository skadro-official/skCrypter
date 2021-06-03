#include "skCrypter.h"
#include <iostream>

int main()
{
	auto testString = skCrypt("TestString");	// encrypted at compile-time
	printf(testString);							// automatic decryption on usage (alternatively .decrypt())

	testString.encrypt();						// encrypt after usage if needed again
											// or
	testString.clear();							// set full string storage to 0

	getchar();
	return 0;
}
