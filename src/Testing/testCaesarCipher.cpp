//! Unit Tests for MPAGSCipher CaesarCipher interface

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CaesarCipher.hpp"
#include <string>

//testing encryption by consecutive encryption and decryption of some text for a variety of keys defined in a vector array

// for i in range 0, 100 key, test input text encyption followed by output text decryption is the same
TEST_CASE("Encryption followed by decryption is successful for various key", "[CaesarCipher]") {
    
    // set up vector containing elements of key
    const std::string input("TESTINGABCDEFGHIJKLMNOPQRSTUVWXYZ");
    
    std::vector<std::string> key = {"0", "1", "2", "15", "20"};
    for (size_t i=0; i < key.size(); i++)
    {
        CaesarCipher Cipher{key[i]};
        REQUIRE( Cipher.applyCipher(Cipher.applyCipher(input, CipherMode::Encrypt), CipherMode::Decrypt) == input);
    }
}   


