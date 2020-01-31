# skCrypter

# Compile-time, Usermode + Kernelmode, safe and lightweight string crypter library for C++11+

- Compile time string encryption

      The plain string is not visible in the binary
- Protected against bruteforcing
			
      The string is randomly(key+algorithm) XOR´ed protecting against default XOR bruteforcing
- Usermode + Kernelmode
			
      Ready to use solution for both Usermode and Kernelmode
- Traceless
			
      The string storage can be fully cleared if necessary
- C++11+ support
- Unicode support
- Lightweight
			
      Smallest amount of overhead	in comparison to plain text binary
- Easy to use
			
      Intuitive functions
- Full control
			
      You can access and manipulate the string storage at any time
- Global lifetime
			
      The encrypted string has static lifetime until cleared
- Auto decrypt
		
      You can pass the returned class into a function

# Example:
    auto testString = skCrypt(L"TestString");	// encrypted at compile-time

    wprintf(testString);                            // automatic decryption on usage (alternatevly .decrypt())

    testString.encrypt();	                        // encrypt after usage if needed again
                                                // or                   
    testString.clear();	                        // set full string storage to 0
