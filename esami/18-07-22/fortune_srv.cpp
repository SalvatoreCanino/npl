#include "sockaddress.hpp"
#include "socket.hpp"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sys/socket.h>
#include "mex_format.hpp"
#include <random>
#include <ctime>
#include <vector>

std::string getRandomFortune() {
    // Array di "fortune" (messaggi casuali)
    std::vector<std::string> fortunes = {
        "Una nuova opportunità si presenterà presto.",
        "Le risposte che cerchi arriveranno al momento giusto.",
        "La tua perseveranza sarà premiata.",
        "Un amico fidato ti porterà buone notizie.",
        "Oggi è un buon giorno per iniziare qualcosa di nuovo.",
        "La felicità è più vicina di quanto pensi.",
        "Un cambiamento positivo sta per arrivare nella tua vita.",
        "Segui il tuo cuore e raggiungerai il successo.",
        "Un progetto che hai a cuore si realizzerà presto.",
        "La fortuna favorisce gli audaci.",
        "Un viaggio emozionante è all'orizzonte.",
        "La tua gentilezza ti condurrà a grandi ricompense.",
        "Sii aperto a nuove amicizie e connessioni.",
        "Un sogno che hai sarà presto una realtà.",
        "Il lavoro di squadra porterà grandi risultati.",
        "Un piccolo gesto di generosità avrà un grande impatto.",
        "Oggi è il giorno perfetto per prendersi una pausa e rilassarsi.",
        "La tua intuizione ti guiderà verso il successo.",
        "Un vecchio amico si farà vivo con notizie interessanti.",
        "La tua determinazione è la chiave per il successo futuro."
    };

    // Inizializzare il generatore di numeri casuali
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, fortunes.size() - 1);

    // Restituire una "fortune" casuale
    return fortunes[dis(gen)];
}


int main(){

    npl::socket<AF_INET, SOCK_DGRAM> sock;
    npl::sockaddress<AF_INET> srv_addr(12000);
    sock.bind(srv_addr);

    std::string snd, rcv;
    json j;
    mex m;

    for(;;)
    {
        auto [buff, client] = sock.recvfrom(512);

        rcv = std::string(buff.begin(),buff.end());
        j = json::parse(rcv);
        from_json(j, m);

        if(!m.type.compare("REQ"))
        {
            m.text = getRandomFortune();
        }
        else 
        {
            m.text = "Wrong Mex Type";
        }
        m.type ="";

        to_json(j, m);
        snd = j.dump();
        npl::buffer bb(snd.begin(),snd.end());
        sock.sendto(bb, client);

    }

    sock.close();
    return EXIT_SUCCESS;
}