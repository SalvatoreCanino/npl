#include <iostream>
#include <thread>

//////////////////////////// 29 - 04 /////////////////////////

std::mutex m;

int a;

// tipo che si usa davvero perché ottimizzato
std::atomic<int> b;

void increment()
{
    for(auto i=0;i<10000;i++){
       m.lock();
       a++;
       m.unlock();
    }
}

void increment2()
{
    for(auto i=0;i<10000;i++){
       std::lock_guard<std::mutex> l(m);
       a++;
    }
}
void increment3()
{
    for(auto i=0;i<10000;i++){
       b++;
    }
}


void decrement()
{
    for(auto i=0;i<10000;i++){
       m.lock();
       a--;
       m.unlock();
    }
}

void decrement2()
{
    for(auto i=0;i<10000;i++){
        // essendo lock locale quando finisce un iter 
        // del ciclo (scope {♦}) l'oggetto lock viene distrutto 
        std::lock_guard<std::mutex> l(m);
        a--;
    }
}

void decrement3()
{
    for(auto i=0;i<10000;i++){
       b--;
    }
}


int main()
{
    // usano i mutex (variabile)
    std::thread t1(increment);
    std::thread t2(decrement);

    // usano i lock (oggetto)
    std::thread t3(increment2);
    std::thread t4(decrement2);

    // usano tipi atomici (variabile atomica -> thread safe)
    std::thread t5(increment3);
    std::thread t6(decrement3);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    std::cout<<"Valore finale di a:\t"<< a <<std::endl;
    std::cout<<"Valore finale di b:\t"<< b <<std::endl;

    return EXIT_SUCCESS;
}
