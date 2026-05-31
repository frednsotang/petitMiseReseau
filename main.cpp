#include <iostream>
#include<winsock2.h>

using namespace std;


#define   LISTENING_PORT  4500  



void purger()
{
	int c;
	while ((c = getchar()) != '\0' && c != '\n');
}

int askport()
{
	int port;	
	printf("Port : ");
	scanf("%i",&port);
	purger();
	return port;
}

void askIP(char ip[15])
{
	printf("Ip : ");
	scanf("%s",ip);	
	purger();
}

int dialogue(SOCKET sock,int tour)
{
	int err = 0;
	char buffer[500];
	while(err>=0)
	{
		memset(buffer,0,sizeof(buffer));
		if (tour==1)
		{
			printf("A vous > ");
			scanf("%500[^\n]",buffer);
			purger();
			err = send(sock,buffer,sizeof(buffer),0);
			tour = 0;
		}
		else
		{
			printf("Attente : ");
			err = recv(sock,buffer,sizeof(buffer),0);
			printf("%s\n",buffer);
			tour = 1;
		}
	}
	return 0;
}

int serveur()
{
	SOCKET sock_attente;	
	SOCKET sock_dialogue;
	SOCKADDR_IN csin;
	int len;
	char buffer[50];
	int err=0;
	int port = askport();
	csin.sin_family=AF_INET;
	csin.sin_addr.s_addr=htonl(INADDR_ANY);
	csin.sin_port=htons(port);
	sock_attente = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (sock_attente == INVALID_SOCKET)
		return -1;
	if (bind(sock_attente,(SOCKADDR*)&csin,sizeof(csin)) == SOCKET_ERROR)
		return -2;
	printf("Listen...\n");
	if (listen(sock_attente, 1) == SOCKET_ERROR)
		return -3;
	len = sizeof(csin);
	printf("Attente client...\n");
	sock_dialogue = accept(sock_attente, (SOCKADDR *)&csin, &len);
	if (sock_dialogue==INVALID_SOCKET)
		return -4;
	printf("Connection ok\n");
	dialogue(sock_dialogue,0);
	return 0;
}

int client()
{
	char ip[15];
	int port;
	SOCKET sock;	
	SOCKADDR_IN sin;
	askIP(ip);
	port = askport();
	sin.sin_family=AF_INET;
	sin.sin_addr.s_addr=inet_addr(ip);
	sin.sin_port=htons(port);
	sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
		return -1;
	printf("Connection...\n");
	if(connect(sock,(SOCKADDR*)&sin,sizeof(sin)) == SOCKET_ERROR)
		return -2;
	printf("Connection ok\n");
	dialogue(sock,1);
	return 0;
}

int main()
{ 
std::cout << "Serveur" << std::endl;  
//   bool  IsConnecting =  true; 
//   int clientCount =0; 
//   char count[15];
  

//    //   initialisation  de  winsock32

//   WSADATA WSAData;
//   WSAStartup(MAKEWORD(2,0), &WSAData);
  
//   //  creation des sockets  client  et serveur  


//   SOCKET sock;
//   SOCKET csock;
//   SOCKADDR_IN sin;
//   SOCKADDR_IN csin; 

  
//  //  remplissage  de la structure adresse serveur
//   sock = socket(AF_INET, SOCK_STREAM, 0);
//   sin.sin_addr.s_addr         = INADDR_ANY;
//   sin.sin_family                                = AF_INET;
//   sin.sin_port        = htons(8889);
  
//   //  lier  le socket  client  avec  la  structure qui  contient les informations sur  son  host

//   bind(sock, (SOCKADDR *)&sin, sizeof(sin)); 

//   //  ecoute  du serveur des tentatives de connexion  
//    listen(sock,5);

//   std::cout<<  "le serveur ecoute  au  port "  <<  " " << sin.sin_port <<  "................"<<std::endl;  
//   int lenAddrClient =  sizeof(csin);
//   csock  =  accept(sock ,NULL ,  NULL);

//   if(csock   ==  INVALID_SOCKET)  
//   {
//      std::cout<<  "connexion  echouee  car  le client n'a  pas ete acceptee par le serveur"<<std::endl;
//   }else  
//   {
//        send(csock, "salut client  :) ", 125, 0);
//   } 

  

//    //  if(csock  ==  INVALID_SOCKET) 
//    //     {
//    //        std::cout <<  "connexion  echouee car le  client n'a  pas  ete  accepter"<<std::endl; 
//    //     }else 
//    //     {   
//    //        send(csock ,"salut  client  :)",125,0);
//    //     }
 
//   closesocket(sock);
//   closesocket(csock);
//   WSACleanup();




















   
//      int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

//     // specifying the address
//     sockaddr_in serverAddress;
//     serverAddress.sin_family = AF_INET;
//     serverAddress.sin_port = htons(8080);
//     serverAddress.sin_addr.s_addr = INADDR_ANY;

//     // binding socket.
//     bind(serverSocket, (struct sockaddr*)&serverAddress,
//          sizeof(serverAddress));

//     // listening to the assigned socket
//     listen(serverSocket, 5);

//     // accepting connection request
//     int clientSocket
//         = accept(serverSocket, nullptr, nullptr); 

//       if(clientSocket ==   INVALID_SOCKET)   std::cout<< "erreur " <<WSAGetLastError()<<std::endl; 
//       else  std::cout<< "  le  serveur  est en  attente  de connexion  et  ecoute au  port   8080"<<std::endl;

//     // receiving data
//     // char buffer[1024] = "SALUT CLIENT";
//     // recv(clientSocket, buffer, sizeof(buffer), 0);
//     // cout << "Message from client: " << buffer
//     //           << endl;

//     // closing the socket.
//     closesocket(serverSocket);  


	int choix;
	int ret;
#ifdef WIN32
	WSADATA wsa; 
	WSAStartup(MAKEWORD(2,0),&wsa);	
#endif
	printf("Serveur = 0 ; Client = 1 : ");
	scanf("%d",&choix);
	if (choix==0)
		ret = serveur();
	else
		ret = client();
	printf("Retour : %d\n",ret);
#ifdef WIN32
	WSACleanup();
#endif

  

    return 0;
}
