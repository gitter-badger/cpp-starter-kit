#include "app.h"
#include "appinfo.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

#include <openssl/sha.h>
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

int main() {
    cout << sha256("1234567890_1") << endl;
    cout << sha256("1234567890_2") << endl;
    cout << sha256("1234567890_3") << endl;
    cout << sha256("1234567890_4") << endl;
    return 0;
}

string App::getProjectName() const {
    return APPLICATION_NAME;
}

string App::getProjectCodeName() const {
    return APPLICATION_CODENAME;
}

string App::getProjectVendorID() const {
    return APPLICATION_VENDOR_ID;
}

string App::getProjectVendorName() const {
    return APPLICATION_VENDOR_NAME;
}

string App::getProjectID() const {
    return APPLICATION_ID;
}

int App::getProjectMajorVersion() const {
    return APPLICATION_VERSION_MAJOR;
}

int App::getProjectMinorVersion() const {
    return APPLICATION_VERSION_MINOR;
}

int App::getProjectPatchVersion() const {
    return APPLICATION_VERSION_PATCH;
}

string App::getProjectVersion() const {
    return APPLICATION_VERSION_STRING;
}

string App::getProjectCopyrightYears() const {
    return APPLICATION_COPYRIGHT_YEARS;
}