# merkle trees

See discussion https://www.redwrasse.io/notes/merkletrees.html

Merkle root computation in c++ closely following the bitcoin implementation. SHA256 with the OpenSSL library.

tbd- explore the 'vulnerability' documented for identical last two elements at a given depth.
Read about in the bitcoin repo [here](https://github.com/bitcoin/bitcoin/blob/5bf45fe2a9642f8ae8f8a12bcbf8f8b4770421ad/src/consensus/merkle.cpp#L8-L42).


