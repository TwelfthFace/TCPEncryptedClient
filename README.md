# TCPEncryptedClient
For usage with the TCPEncryptedServer from *yours truely* available [here](https://github.com/TwelfthFace/TCPEncryptedServer).

The private key on the server should have a public key counter part, make sure this client has it or decryption will be impossible.

Only one-way communications available atm.

#### Usage
`./TCPEncryptedClient <IP> <PORT>`

### Dependencies
```
openssl-1.1.1
```

<h3>Compile Instructions</h3>

```
git clone "..."
cd TCPEncryptedClient
cmake -B build/ && cd build/ && make
./TCPEncryptedClient <IP> <PORT>
```
