Randomness in Linux
===================
Educational project using various methods to generate pseudo random numbers/strings that are cryptograpically secure.

Random numbers have many important uses in applied cryptography. Yet you can't compute true randomness arithmetically:

>Anyone who considers arithmetical methods of producing random digits is, of course, in a state of sin. For, as has been pointed out several times, there is no such thing as a random number — there are only methods to produce random numbers, and a strict arithmetic procedure of course is not such a method.
>[John Von Neumann][4]

Computers are deterministic - and predictable. So you can't expect a computer to produce randomness arithmetically. There are many "random" number generators built into programming languages, but these usually produce outputs that have a flavour of randomness - they are not cryptographically secure. You should NOT use such methods to generate random numbers that will be used for non-trivial purposes (e.g. generating private keys).

This repo contrasts random number generation by mean of different userspace libraries and accessing `/dev/urandom` directly. `/dev/urandom` is the interface to the Linux kernel random number generator.

At the moment, I've included random number generation by means of libgcrypt, and I'll add openssl shortly.

/dev/urandom
------------
* Has access to raw device entropy
* Won't share state between applications


OpenSSL
-------
C project that uses the `<openssl/rand.h>` library to generate random data. I found this a bit tricky to set up.

Note that in the `Makefile`, `cc` requires `-lssl -lcrypto` flags.

[RAND_][7] is used to check for sufficient entropy. Note issues re: [libgcrypt entropy loss][8]

Resources
---------

* [/dev/random vs /dev/urandom][6]
* [Base 64 Wiki article][1]
* [RFC 1421][2]: Privacy Enhancement for Internet Electronic Mail: Part I: Message Encryption and Authentication Procedures
* [https://en.wikipedia.org/wiki/Binary-to-text_encoding#ASCII_armor][3]
* [https://en.wikiquote.org/wiki/John_von_Neumann][4]
* [https://github.com/DavidCWebs/radix-64-encoding][5]
* [https://www.openssl.org/docs/manmaster/man3/RAND_add.html][7]
* [Entropy Loss & Predictability, Libgcrypt PRNG][8]


[1]: https://en.wikipedia.org/wiki/Base64
[2]: https://tools.ietf.org/html/rfc1421
[3]: https://en.wikipedia.org/wiki/Binary-to-text_encoding#ASCII_armor
[4]: https://en.wikiquote.org/wiki/John_von_Neumann
[5]: https://github.com/DavidCWebs/radix-64-encoding
[6]: https://sockpuppet.org/blog/2014/02/25/safely-generate-random-numbers/
[7]: https://www.openssl.org/docs/manmaster/man3/RAND_add.html
[8]: https://formal.iti.kit.edu/~klebanov/pubs/libgcrypt-cve-2016-6313.pdf

