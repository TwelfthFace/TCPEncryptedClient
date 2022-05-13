#include "cipher.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

using namespace std;

void char_to_int(char* in, int& out){
    int pv = 1;
    for(size_t i = 0; i < strlen(in); i++){
        int unit = reinterpret_cast<int>(in[(strlen(in)-1)-i] - '0');
        if(unit != 0){
            out += unit * pv;
        }
        pv = pv*10;
    }
}

int main(int argc, char** argv)
{
    RSA* public_key = cipher::get_public_key();

    if(!(argc == 3)){
        cerr << "Usage: TCPEncryptedClient <IP> <PORT>" << endl;
        exit(EXIT_FAILURE);
    }

    //create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        cerr << "It's fucked from the getgo bro." << endl;
        return -1;
    }

    const char* ip_address = argv[1];
    int port = 0;
    char_to_int(argv[2], port);

    //create hint for server details
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &hint.sin_addr);

    //connect to server using the socket
    int connection = connect(sock, (sockaddr*) &hint, sizeof(hint));
    if(connection == -1){
        cerr << "Connection failure!" << endl;
        return -2;
    }

    //use the connection
    char buf[4096];
    std::string user_input;
    do {
        //clear buf
        memset(buf, 0, 4096);
        cout << "> ";

        getline(cin, user_input);

        const char* em = cipher::encryptRSA(public_key, user_input);

        int send_result = send(sock, em, 256 + 1, 0);

        if(send_result == -1){
            cerr << "Couldn't connect to the server." << endl;
            break;
        }

        cout << buf;

    } while(true);

    close(sock);

    return 0;
}
