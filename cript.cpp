#include <iostream>
#include <string>
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>

// Función para cifrar un mensaje con AES-CBC
std::string cifrar(const std::string& mensaje, const byte* clave, const byte* iv) {
    std::string cifrado;
    CryptoPP::AES::Encryption aesEncryption(clave, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);
    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(cifrado));
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(mensaje.c_str()), mensaje.length() + 1);
    stfEncryptor.MessageEnd();
    return cifrado;
}

// Función para descifrar un mensaje con AES-CBC
std::string descifrar(const std::string& cifrado, const byte* clave, const byte* iv) {
    std::string descifrado;
    CryptoPP::AES::Decryption aesDecryption(clave, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);
    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(descifrado));
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(cifrado.c_str()), cifrado.size());
    stfDecryptor.MessageEnd();
    return descifrado;
}

int main() {
    std::string mensaje = "Información sensible de la tarjeta de crédito";
    byte clave[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];

    // Generar una clave e IV aleatorios
    CryptoPP::AutoSeededRandomPool prng;
    prng.GenerateBlock(clave, sizeof(clave));
    prng.GenerateBlock(iv, sizeof(iv));

    std::cout << "Mensaje original: " << mensaje << std::endl;
    
    // Cifrar el mensaje
    std::string mensajeCifrado = cifrar(mensaje, clave, iv);
    std::cout << "Mensaje cifrado: " << mensajeCifrado << std::endl;

    // Descifrar el mensaje
    std::string mensajeDescifrado = descifrar(mensajeCifrado, clave, iv);
    std::cout << "Mensaje descifrado: " << mensajeDescifrado << std::endl;

    return 0;
}
