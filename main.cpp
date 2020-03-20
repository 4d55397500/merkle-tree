#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/sha.h>
#include <vector>

using namespace std;


string sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}


vector<string> merkleRow(vector<string> v) {
    for (int i = 0; i < v.size(); i+= 2) {
        v[i/2] = sha256(v[i] + v[i + 1]);
    }
    v.resize(v.size() / 2);
    return v;
}

string ComputeMerkleRoot(vector<string> hashes, bool *mutated) {
    bool mutation = false;
    while (hashes.size() > 1) {
        if (mutated) {
            for (size_t pos = 0; pos + 1 < hashes.size(); pos += 2) {
                if (hashes[pos] == hashes[pos + 1]) mutation = true;
            }
        }
        if (hashes.size() & 1) { // odd number of elements in row
            hashes.push_back(hashes.back());
        }
        hashes = merkleRow(hashes);
    }
    if (mutated) *mutated = mutation;
    if (hashes.size() == 0) return string();
    return hashes[0];
}


int main() {


    // example of different sequences leading to same root if last two
    // elements identical with an even number of total elements given

    vector<string> v1{"foo", "bar", "goo", "far", "tar"};
    vector<string> v2{"foo", "bar", "goo", "far", "tar", "tar"};

    bool mutated1 = false;
    string merkleRoot1 = ComputeMerkleRoot(v1, &mutated1);
    cout << "Computed Merkle root 1: " << merkleRoot1 << endl;

    bool mutated2 = false;
    string merkleRoot2 = ComputeMerkleRoot(v2, &mutated2);
    cout << "Computed Merkle root 2: " << merkleRoot2 << endl;

    cout << "(Identical roots)" << endl;

    return 0;


}