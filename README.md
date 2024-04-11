# crypto

## RSA
https://sv.wikipedia.org/wiki/RSA
- private and public keys
- encrypt AES key

### GMP
https://gmplib.org

### BASE64
https://en.wikipedia.org/wiki/Base64

## AES
- encrypt message

## thoughts

```bash
./encrypt message.txt key.txt
```
this program creates a new file encrypted-message.txt

```bash
./decrypt encrypted-message.txt key.txt
```
this program creates a new file decrypted-message.txt

the encrypted message contains an encrypted AES key in the header
and then an encrypted message using that AES key

key.txt can be either public or private key
