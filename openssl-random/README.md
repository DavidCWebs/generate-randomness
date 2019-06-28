Randomness
==========
Use the `<openssl/rand.h>` library to generate random data.

Getting Open SSL Working
------------------------
Note `Makefile`: `cc` requires `-lssl -lcrypto` flags.

References
----------

* [RAND_][1]: check for sufficient entropy
* [libgcrypt entropy loss][2]


[1]: https://www.openssl.org/docs/manmaster/man3/RAND_add.html
[2]: https://formal.iti.kit.edu/~klebanov/pubs/libgcrypt-cve-2016-6313.pdf
[3]: https://sockpuppet.org/blog/2013/07/22/applied-practical-cryptography/
