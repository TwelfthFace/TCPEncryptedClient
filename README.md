# TCPEncryptedClient
For usage with the TCPEncryptedServer from *yours truly* available [here](https://github.com/TwelfthFace/TCPEncryptedServer).

The private key on the server should have a public key counterpart, make sure this client has it or decryption will be impossible.

Only one-way communications are available atm.

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
