# skCrypter

# Compile-time, Usermode + Kernelmode, safe and lightweight string crypter library for C++11+

What is the problem?

#1 Strings
- Having plain strings stored in the binary file or in memory can help reversering attempts to be much easier.
- If the program is targeted by string detection scans you had to change the strings everytime you get detected.

#2 Some crypters
- Decrypt the string on the current stack location. Even though in some situations the stack location is overwritten on returning from a function, especially when the decryption is called from the main function the decrypted string stays on the stack for the lifetime of the stack/program thus leaking it
- Do not work with both Usermode and Kernelmode
- Greater overhead
- Require compiler optimizations enabled
- Vulnerable against default bruteforcing

Why this crypter?

skCrypter works out of the box with both Usermode + Kernelmode and compiler optimizations on/off (tested with msvsc++19). The overhead is very low and the storage of the string is at a fixed address which is controlable at every time and clearable traceless(builtin function). The encryption is randomized at every compilation and protected against default bruteforcing.


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
			
      Smallest amount of overhead in comparison to plain text binary
- Easy to use
			
      Intuitive functions
- Full control
			
      You can access and manipulate the string storage at any time
- Global lifetime
			
      The encrypted string has static lifetime until cleared
- Auto decrypt
		
      You can pass the returned class into a function

# Example:

Include skCrypter.h


    auto testString = skCrypt(L"TestString");	// encrypted at compile-time
							// or skCrypt_key to set the keys manually

    wprintf(testString);                            // automatic decryption on usage (alternatively .decrypt())

    testString.encrypt();	                        // encrypt after usage if needed again
                                                // or                   
    testString.clear();	                        // set full string storage to 0
    
Important:
- Compiler Optimization /02 might cause wrong decryption, so use /01 or disable it
- For Kernel mode `__TIME__` has to be enabled by setting "Project properties" -> "Driver Setting" -> "Driver Model" -> "Allow Date, Time and TimeStamp". Alternatively replace `__TIME__` with your own keys
