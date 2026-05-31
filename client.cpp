#include <iostream>
#include<winsock2.h>

/* int  main()
{

  //   initialisation  de  winsock32

    std::cout << "Client" << std::endl;
  WSADATA WSAData;
  WSAStartup(MAKEWORD(2,0), &WSAData);

  //  creation des sockets  client
  SOCKET sock;
  SOCKADDR_IN sin;
 //  remplissage  de la structure adresse  client
  sock = socket(AF_INET, SOCK_STREAM, 0);
  sin.sin_addr.s_addr= inet_addr("127.0.0.1");
  sin.sin_family= AF_INET;
  sin.sin_port = htons(8889);


  //  connexion  du client  au   serveur

  if(connect(sock,(SOCKADDR *)&sin,sizeof(sin)) ==  -1)
  {
       std::cout<< "erreur  de connexion " << WSAGetLastError() <<  std::endl;
  }else  std::cout<< "le client a pu  se connecter  au  serveur  !"<<std::endl;

  char buffer[1024];
  char msg_client[1024] =  "bonjour  serveur  je  veux discuter";
  // int i = recv(sock,buffer,sizeof(buffer),0);
  // if (i != false)
  // {
  //    //  affichage du message recu  par le  serveur

  //   std::cout << buffer << std::endl;
  // }

  // getchar();


  int  sClientMessage  =  send(sock ,msg_client ,sizeof(msg_client) , 0);

  if(sClientMessage ==  -1)   std::cout<< "erreur  d'envoie"<< WSAGetLastError()<<std::endl;






 return  0;
}  */
