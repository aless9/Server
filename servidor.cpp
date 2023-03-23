#include <iostream>
#include <time.h>
#include <string>
#include <unistd.h>
using namespace std;

int main (){
string r1,r3;
char r2;
int respuestaconfig;
string backup = "sudo tar -czvf $(date +'%Y-%m-%d_%H-%M-%S')-backup.tar.gz ";
char respuesta,respuesta1,respuesta2,respuesta3,respuesta4;
string backups [3] = {"/home ","/etc ","/usr "};
int si = 0;    
system ("clear");
system ("figlet Servidor");

cout<<endl;
cout<<"Las opciones son:";
cout<<endl;
cout<<"-----------------";
cout<<endl;                                                                                 //interfaz de las selecciones de configuracion del servidor
cout<<"\033[31m[+]\033[0m"<<"\033[34mDHCP\033[0m";cout<<endl;
cout<<"\033[31m[+]\033[0m"<<"\033[34mBackUp\033[0m";cout<<endl;
cout<<"\033[31m[+]\033[0m"<<"\033[34mConfiguracion del server\033[0m";cout<<endl;
cout<<"\033[31m[+]\033[0m"<<"\033[34mFTP\033[0m";cout<<endl;
cout<<"\033[31m[+]\033[0m"<<"\033[34mSSH\033[0m";
cout<<endl;
cout<<endl;
cout<<"> ";cin>>r1;
cout<<endl;

if (r1=="DHCP"){                                    //que se instale y se configure (automaticamente)
    cout<<"Espere un segundo mientras le instalamos el dhcp...";
    system ("sudo apt-get install isc-dhcp-server"); //con este comando lo que hacemos es descargar el servidor DHCP
    cout<<endl;
    usleep (500000);
    cout<<"Mantengase a la espera...";
    system ("sudo cp ./dhcp1.txt /etc/dhcp/dhcpd.conf");
    system ("sudo cp ./dhcp2.txt /etc/default/isc-dhcp-server");
    system ("sudo systemctl restart isc-dhcp-server");
}
else if (r1=="BackUp"){                                  //.realizar una copia de seguridad y mostrar las copias realizadas  
    
    cout<<"¿Ha realizado anteriormente algun BackUp? Y/N";
    cout<<endl;
    cout<<"> ";
    cin>>respuesta;
    cout<<endl;
    cout<<endl;

    if (respuesta == 'Y'){
        cout<<"¿Desea ver sus BackUps? Y/N";
        cout<<endl;
        cout<<"> ";
        cin>>respuesta1;
        cout<<endl;
        if (respuesta1 == 'Y'){
            cout<<"De acuerdo espere...";
            cout<<endl;
            usleep (5000000);
            system ("ls");
        }
        else if (respuesta1 == 'N'){
            cout<<"¿Desea realizarlo? Y/N";
            cout<<endl;
            cout<<"> ";
            cin>>respuesta2;
            if (respuesta2 == 'Y'){
                cout<<"Realizando BackUp...";
                cout<<endl;
                usleep (50000);
                for (int i = 0 ; i < 2 ; i++){
                    backup += backups [i];
                }
                system (backup.c_str());
            }
            else if (respuesta2 == 'N'){
                cout<<"De acuerdo, espere mientras le reedirigimos...";
                cout<<endl;
                usleep (50000);
                main ();
            }
        }
    }
    if (respuesta == 'N'){
        if (si == 1){
            int sino;
            cout<<"Ya ha realizado un BackUp, ¿desea verlo? Y/N";
            cout<<endl;
            cout<<"> ";
            cin>>sino;
            cout<<endl;
            if (sino == 'Y'){
                usleep (50000);
                system ("ls");
            }
            else if (sino == 'N'){
                cout<<"¿Desea realizar un BackUp? Y/N";
                cout<<endl;
                cout<<"> ";
                cin>>respuesta3;
                if (respuesta3 == 'Y'){
                    cout<<"Muy bien, espere mientra realizamos el BackUp...";
                    cout<<endl;
                    usleep (50000);
                    cout<<endl;
                    for (int i = 0 ; i < 2 ; i++){
                        backup += backups [i];
                    }
                    system (backup.c_str());
                    cout<<"Quiere ver el proceso? Y/N";
                    cin>>r2;
                    if (r2 == 'Y'){
                        cout<<backup;
                    }
                    else if (r2 == 'N'){
                        cout<<"De acuerdo.";
                    }
                }
                else if (respuesta3 == 'N'){
                    usleep (5000);
                    main ();
                }
            }
        }
        if (si == 0){
            si = 1;
            cout<<"De acuerdo, ¿quiere realizarlo?";
            cout<<endl;
            cout<<"> ";
            cin>>respuesta4;
            if (respuesta4 == 'Y'){
                cout<<"Muy bien, espere mientra realizamos el BackUp...";
                usleep (50000);
                for (int i = 0 ; i < 2 ; i++){
                    backup += backups [i];
                }
                system (backup.c_str());
                cout<<endl;
                cout<<endl;
            }
            else if (respuesta4 == 'N'){
                cout<<"Espere mientras le reedirigimos...";
                usleep (50000);
                main ();
            }
        }
    }
}
else if (r1=="Configuracion"){                       //.Mostar la configuracion de nuestro servidor 
    cout<<"Configuraciones";
    cout<<"---------------";
    cout<<endl;
    cout<<"1. Informacion sobre la configuracion del DHCP\n2. Informacion sobre el FTP\n3. Informacion sobre el sistema\n4. Informacion sobre la red";
    cout<<endl;
    cout<<"> "; 
    cin>>respuestaconfig;
    cout<<endl;
                                            //me falta enseñar la configuracion de dhcp,ftp,informacion del sistema y la info de red
    switch (respuestaconfig){
        case 1:
            cout<<"INFORMACION DEL DHCP";
            cout<<endl;
            system ("sudo cat /etc/default/isc-dhcp-server");
            cout<<endl;
            cout<<endl;
            system ("sudo cat /etc/dhcp/dhcp.conf");
            cout<<endl;
            break;
        case 2: 
            cout<<"INFORMACION DEL FTP";
            cout<<endl;
            system ("sudo cat /etc/vsftpd.conf");
            cout<<endl;
            break;
        case 3:
            cout<<"INFORMACION DEL SISTEMA";
            cout<<endl;
            system ("sudo apt install screenfetch");
            cout<<endl;
            cout<<endl;
            system ("screenfetch");
            cout<<endl;
            break;
        case 4:
            cout<<"INFORMACION DE RED";
            cout<<endl;
            system ("sudo ip a");
            cout<<endl;
            break;

    }
    cin>>r3;
    if (r3 == "Y"){
        cout<<"Mostrando configuracion del servidor...";
        cout<<endl;
        usleep (500000);
        system ("sudo cat /etc/dhcp/dhcpd.conf");
        system ("ip a");
    }
    else if (r3 == "N"){
        cout<<"Muy bien espere mientras le reedirigimos...";
        usleep (50000);
        main ();
    }
}
else if (r1 == "FTP"){                                    //.instalar el servidor FTP y configurarlo haciendo un llamamiento al documento txt del FTP 
    usleep (50000);
    system ("sudo apt upgrade && sudo apt upgrade");
    system ("sudo apt-get install vsftpd");
    system ("sudo cp FTP.txt /etc/vsftpd.conf");
    system ("sudo systemctl restart vsftpd");
}
else if (r1 == "SSH"){                                   //.instalar el servidor ssh y reiniciarlo
    system ("sudo apt install openssh-server");
    system ("systemctl restart sshd");
    usleep (50000);
}


return 0;
}