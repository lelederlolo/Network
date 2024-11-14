#include <iostream>
#include <ws2tcpip.h>
#pragma comment(lib ,"ws2_32.lib")
using namespace std ;

int main(){
    string ipAddress = "127.0.0.1" ;
    int port ;

    //Strat Socket
    WSADATA data ;
    WORD wordVer = MAKEWORD(2, 2) ;
    int wsResult =WSAStartup(wordVer ,&data) ;
    if(wsResult != 0){
        cerr << "Error : Starting Socket - Err#" << wsResult <<endl ;
        return ;
    }

    //Create Socket
    SOCKET sock = socket (AF_INET ,SOCK_STREAM ,0) ;
    if(sock = INVALID_SOCKET){
        cerr << "Error : Creating Socket - Err#" << WSAGetLastError() <<endl ;
        return ;
    }

    sockaddr_in hint ;
    hint.sin_family = AF_INET ;
    hint.sin_port = htons(port) ;
    //inet_pton(AF_INET ,ipAddress.c_str() ,&hint.sin_addr) ;

    //Connect
    int connResult = connect(sock ,(sockaddr*)&hint ,sizeof(hint)) ;
    if (connResult == SOCKET_ERROR){
        cerr << "Error : Connect - Error#" << WSAGetLastError() <<endl ;
        closesocket(sock) ;
        WSACleanup() ;
        return ;
    }

    //Send and Receive
    char buf[4096] ;
    string userInput ;
    do{
        getline(cin ,userInput) ;

    }while(userInput.size() > 0) ;
}